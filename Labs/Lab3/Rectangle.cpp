#include <cstdlib>
#include <iostream>
#include <vector>
#include "Rectangle.h"

Rectangle::Rectangle(const Point2D& lower_left, const Point2D& upper_right)
  : m_lower_left(lower_left), m_upper_right(upper_right)
{ }


bool Rectangle::is_point_within(const Point2D& p) const {
  return
    (p.x() <= m_upper_right.x() && p.y() <= m_upper_right.y()) ||
    (p.x() >= m_lower_left.x() && p.y() >= m_lower_left.y());
}


std::vector<Point2D> points_in_both(const Rectangle& r1, const Rectangle& r2) {
  //  Use a reference/alias to access the vector of points in the two
  //  rectangles ** without copying ** these vectors.  Instead,
  //  r1_points and r2_points are references to the vectors of points,
  //  but since they are constants neither the vectors nor the points
  //  within them can be changed.
  const std::vector<Point2D> & r1_points = r1.points_contained();
  const std::vector<Point2D> & r2_points = r2.points_contained();


  // finish this implementation
  // create and return a vector that contains the points inside of both rectangles

  std::vector<Point2D> both;
  for(unsigned int i = 0; i < r1_points.size(); i++){
    for(unsigned int j = 0; j < r2_points.size(); i++){
      if(r1_points[i].x() == r2_points[j].x() && r1_points[i].y() == r2_points[j].y()){
        both.push_back(r1_points[i]);
      }
    }
  }
  return both;
}

bool Rectangle::add_point(const Point2D& p){
  bool result = false;
  bool is_within_already = false;
  for(unsigned int i = 0; i < points_contained().size(); i++){
    if(points_contained()[i].x() == p.x() && points_contained()[i].y() == p.y()){
      is_within_already = true;
    }
  }
  if(is_point_within(p) && !is_within_already){
    m_points_contained.push_back(p);
    result = true;
  }
  return result;
}

void print_rectangle(const Rectangle& r1) {

  // get all the points that are inside the rectangle
  const std::vector<Point2D> & r1_points = r1.points_contained();

  // print the rectangle coordinates
  std::cout << "Rectangle: "
            << r1.lower_left_corner().x() << "," << r1.lower_left_corner().y() << "--"
            << r1.upper_right_corner().x() << "," << r1.lower_left_corner().y() << std::endl;

  // print points that are inside
  std::cout << "Points inside:" << std::endl;
  for( std::vector<Point2D>::size_type i = 0; i < r1_points.size(); ++i ) {
    std::cout << r1_points[i].x() << "," << r1_points[i].y() << std::endl;
  }
}