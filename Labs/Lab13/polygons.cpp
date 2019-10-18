#include "polygons.h"


bool Polygon::HasARightAngle(){
  //for loop through all the points
	for (int i = 0; i < points.size(); ++i)
		if (RightAngle( Angle(points[i], points[(i+1) % points.size()], points[(i+2) % points.size()] )))
			return true;
	return false;
}

bool Polygon::allRightAngles(){ //Triangle can not have all right angles
	if (points.size() == 3)
		return false;
	for (int i = 0; i < points.size(); ++i)
		if (!RightAngle( Angle(points[i], points[(i+1) % points.size()], points[(i+2) % points.size()] )))
			return false;
	return true;
}


// If all sides are equal
bool Polygon::HasAllEqualSides(){ // can work for either an triangle or a square
	for (int i = 0; i < points.size(); ++i)
		if (!EqualSides( DistanceBetween(points[i], points[(i+1) % points.size()]),
			DistanceBetween(points[(i+1) % points.size()], points[(i+2) % points.size()]) ))
			return false;
	return true;
}


bool Polygon::HasAllEqualAngles(){//Thus can work for a square or a triangle
	for (int i = 0; i < points.size(); ++i)
		if (!EqualAngles( Angle(points[i], points[(i+1) % points.size()], points[(i+2) % points.size()] ),
		Angle(points[(i+1) % points.size()], points[(i+2) % points.size()], points[(i+3) % points.size()] ) ))
			return false;
	return true;
}


bool Polygon::HasAnObtuseAngle(){
	std::vector<double> temp_angles;
	for (int i = 0; i < points.size(); ++i)
		temp_angles.push_back( Angle(points[i], points[(i+1) % points.size()], points[(i+2) % points.size()] ) );

	for (int i = 0; i < temp_angles.size(); ++i)
		if (temp_angles[i] > 90 && temp_angles[i] < 180)
			return true;
	return false;
}

bool Polygon::HasAnAcuteAngle(){
	std::vector<double> temp_angles;
	for (int i = 0; i < points.size(); ++i)
		temp_angles.push_back( Angle(points[i], points[(i+1) % points.size()], points[(i+2) % points.size()] ) );

	for (int i = 0; i < temp_angles.size(); ++i)
		if (temp_angles[i] < 90)
			return true;
	return false;
}

bool Polygon::HasRightEqualSides(){
	for (int i = 0; i < points.size(); ++i)
		if (RightAngle( Angle(points[i], points[(i+1) % points.size()], points[(i+2) % points.size()] ))){
			
		}
}