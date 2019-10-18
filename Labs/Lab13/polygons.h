#ifndef __POLYGONS_H_
#define __POLYGONS_H_

#include <iostream>
#include <string>
#include <vector>

#include "utilities.h"

class Polygon{
public:
	Polygon (const std::string &name_, const std::vector<Point> &points_){
		name = name_; // create the member variable name and set it equal to the name given
		points = points_; //create the member variable point_ and vector of Points
	}

	virtual ~Polygon() {} //virtual function used once- just for polygon here

	std::string getName() { return name; }

	bool HasAllEqualSides();
	bool HasAllEqualAngles();
	bool allRightAngles();
	bool HasARightAngle();
	bool HasAnObtuseAngle();
	bool HasAnAcuteAngle();
	bool HasRightEqualSides();

protected:
	std::string name;
	std::vector<Point> points;
};



//Order: Polygon --> Triangle --> IsoscelesTriangle --> EquilateralTriangle

class Triangle : public Polygon{
public:
	Triangle (const std::string &name_, const std::vector<Point> &points_) : Polygon (name_, points_){
		if (points.size() != 3)
			throw -1;
	}
};


class IsoscelesTriangle : virtual public Triangle{
public:
	IsoscelesTriangle (const std::string &name_, const std::vector<Point> &points_) : Triangle (name_, points_){
		std::vector<double> temp_angles;
    if (points.size() != 3)
      throw -1;
		for (int i = 0; i < points.size(); ++i)
			temp_angles.push_back( Angle(points[i], points[(i+1) % points.size()], points[(i+2) % points.size()] ) );

    //At least two angles must be equal.
		if (temp_angles[0] != temp_angles[1] && temp_angles[0] != temp_angles[2] && temp_angles[1] != temp_angles[2])
			throw -1;
	}
};
class RightTriangle : virtual public Triangle{
public:
	RightTriangle(const std::string &name, const std::vector<Point> &points) :Triangle(name,points){
		if(!HasARightAngle()){
			throw -1;
		}
	}
};

class IsoscelesRightTriangle : public RightTriangle, public IsoscelesTriangle {
public:
	IsoscelesRightTriangle(const std::string &name, const std::vector<Point> &points): RightTriangle(name, points), IsoscelesTriangle(name,points), Triangle (name, points){

	}
};

class EquilateralTriangle:  public IsoscelesTriangle{
public:
	EquilateralTriangle (const std::string &name_, const std::vector<Point> &points_) : IsoscelesTriangle(name_, points_), Triangle (name_, points_){
		if (points.size() != 3)
      throw -1;
    if (!HasAllEqualSides())
      throw -1;
	}
};


//Order: Polygon --> Quadrilateral --> Rectangle --> Square

class Quadrilateral : public Polygon{
public:
  Quadrilateral (const std::string &name_, const std::vector<Point> &points_) : Polygon (name_, points_){
		if (points.size() != 4)
			throw -1;
	}
};

class Rectangle : public Quadrilateral{
public:
  Rectangle (const std::string &name_, const std::vector<Point> &points_): Quadrilateral (name_, points_){
    if (points.size() != 4)
      throw -1;
		if (!allRightAngles()){
			throw -1;
    }
	}
};

class Square : public Rectangle{
public:
  Square (const std::string &name_, const std::vector<Point> &points_): Rectangle(name_, points_){
    if (points.size() != 4)
      throw -1;
		if (!HasAllEqualSides())
			throw -1;
		if (!allRightAngles())
			throw -1;
	}
};


#endif
