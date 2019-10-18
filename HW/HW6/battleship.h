#ifndef __BATTLESHIP_H_
#define __BATTLESHIP_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cassert>
#include <sstream>
#include <streambuf>
#include <vector>

class Battleship
{
public:
	//CONSTRUCTOR
	Battleship(std::vector<int> rows, std::vector<int> cols, int r, int c, std::vector<int> ships);

	//ACCESSORS
	//returns the number of rows
  	int num_rows() const;

  	//returns the number of columns
  	int num_cols() const;

  	void print_board();

	//MODIFIERS
  	//fills unkowns in solution boards with 0 (water)
  	void fillWater();

  	void deduct(int i, int j);

  	/*************OPTIMIZATION FUNCTIONS*******************/
  	//attempted to write but what these do is they check if there are no more ships left on a row or column, then fill it accordingly. 
  	//At the same time, with fillships you see if the next ship can fit and you just slap the entire ship onto the board to see if it works
  	bool fillWater(int i, int j);

  	bool fillShips(int i, int j);

	//print the board for testing purposes.


	std::vector<int> rows_;
	std::vector<int> cols_;
	int r_;
	int c_;
	std::vector<int> ships_;
	std::vector<std::vector<int> > d;
	std::vector<int> Orows_;
	std::vector<int> Ocols_;
};



//overloading << to display the information to print for testing purposes
//std::ostream& operator<< (std::ostream& out, const Matrix& m);

#endif