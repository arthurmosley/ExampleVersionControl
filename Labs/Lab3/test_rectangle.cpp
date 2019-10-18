#include "Rectangle.h"
#include "Point2D.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

	Point2D pt = Point2D(0,0);
	pt.set(1,1);
	Point2D pt1 = Point2D(5,5);
	Point2D pt2 = Point2D(10,10);
	Point2D pt3 = Point2D(15,15);
	Point2D pt4 = Point2D(1,1);
	Point2D pt5 = Point2D(20,20);
	Point2D pt6 = Point2D(3,2);
	Point2D pt7 = Point2D(5,6.5);
	Point2D pt8 = Point2D(7,0);
	Rectangle rect1 = Rectangle( pt1, pt2);
	print_rectangle(rect1);
	cout << endl;
	cout << "Upper right is actually: " << rect1.upper_right_corner().x() << "," << rect1.upper_right_corner().y() << endl;
	cout << "Lower left is actually: " << rect1.lower_left_corner().x() << "," << rect1.lower_left_corner().y()	<< endl;
	cout << endl;
	rect1.add_point(pt7);
	print_rectangle(rect1);
	cout << endl;
	rect1.add_point(pt3);
	print_rectangle(rect1);
	cout << endl;
	rect1.add_point(pt4);
	print_rectangle(rect1);
	cout << endl;
	cout << "Points contained: ";
	for(int i = 0; i < rect1.points_contained().size(); i++)
	{
		cout << rect1.points_contained()[i].x() << "," << rect1.points_contained()[i].y() << " ";
	}
	cout << endl;
	cout << endl;
	cout << "Is " << pt4.x() << "," << pt4.y() << " within: " << rect1.is_point_within(pt4) << endl;
	cout << "Is " << pt5.x() << "," << pt5.y() << " within: " << rect1.is_point_within(pt4) << endl;
	cout << "Is " << pt3.x() << "," << pt3.y() << " within: " << rect1.is_point_within(pt4) << endl;
	cout << "Is " << pt8.x() << "," << pt8.y() << " within: " << rect1.is_point_within(pt4) << endl;
	cout << endl;
	
	Rectangle rect2 = Rectangle(pt2, pt1);
	print_rectangle(rect2);
	cout << endl;
	cout << "Upper right is actually: " << rect2.upper_right_corner().x() << "," << rect2.upper_right_corner().y() << endl;
	cout << "Lower left is actually: " << rect2.lower_left_corner().x() << "," << rect2.lower_left_corner().y()	<< endl;
	cout << endl;
	rect2.add_point(pt1);
	print_rectangle(rect2);
	cout << endl;
	rect2.add_point(pt3);
	print_rectangle(rect2);
	cout << endl;
	
	Rectangle rect3 = Rectangle (pt1, pt1);
	print_rectangle(rect2);
	cout << endl;
	cout << "Upper right is actually: " << rect3.upper_right_corner().x() << "," << rect3.upper_right_corner().y() << endl;
	cout << "Lower left is actually: " << rect3.lower_left_corner().x() << "," << rect3.lower_left_corner().y()	<< endl;
	cout << endl;
	rect3.add_point(pt1);
	print_rectangle(rect3);
	cout << endl;
	rect3.add_point(pt3);
	print_rectangle(rect3);
	cout << endl;
	
	
	
	return 0;
}