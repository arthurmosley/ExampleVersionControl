#include "battleship.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cassert>
#include <sstream>
#include <streambuf>
#include <vector>

Battleship::Battleship(std::vector<int> rows, std::vector<int> cols, int r, int c, std::vector<int> ships)
{
	rows_ = rows;
	cols_ = cols;
	Orows_ = rows;
	Ocols_ = cols;
	r_ = r;
	c_ = c;
	ships_ = ships;
	for(unsigned int i = 0; i < r_; i++)
	{
		std::vector<int> temp(c_, 9);
		d.push_back(temp);
	}
}
void Battleship::fillWater()
{
	for (unsigned int i = 0; i < rows_.size(); i++)
	{
		for(unsigned int j =0; j < cols_.size(); j++)
		{
			if(d[i][j] == 9)
				d[i][j] = 0;
		}
	}
}

bool Battleship::fillWater(int i, int j)
{
	bool change = false;
	if (rows_[i] == 0)
	{
		for (unsigned int k = 0; k < cols_.size(); k++)
		{
			if (d[i][k] == 9)
			{
				d[i][k] = 0;
				change = true;
			}

		}
	}
	if (cols_[j] == 0)
	{
		for (unsigned int k = 0; k < rows_.size(); k++)
		{
			if (d[k][j] == 9)
			{
				change = true;
				d[k][j] = 0;
			}
		}
	}
	return change;
}

bool Battleship::fillShips(int i, int j)
{
	bool change = false;
	if (cols_[j] == rows_.size() - (1+i))
	{
		for (unsigned int k = i; k < rows_.size(); k++)
		{
			if (d[k][j] == 9)
			{
				change = true;
				d[k][j] = 1;
			}
		}
	}
	if (rows_[i] == cols_.size() - (1+j))
	{
		for (unsigned int k = j; k < cols_.size(); k++)
		{
			if (d[i][k] == 9)
			{
				change = true;
				rows_[i]--;
				d[i][k] = 1;
			}
		}
	}
	return change;
}

void Battleship::deduct(int i, int j)
{
	rows_[i]--;
	cols_[j]--;
}

/***ACCESSORS***/
//gets the number of rows in the battleship board
int Battleship::num_rows() const
{
  return rows_.size();
}

//gets the number of columns in the battleship board
int Battleship::num_cols() const
{
  return cols_.size();
}

void Battleship::print_board()
{
	std::cout << "Solution:" << std::endl;
	for (unsigned int i = 0; i < rows_.size(); i++)
	{
		for(unsigned int j =0; j < cols_.size(); j++)
		{
			std::cout << d[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "\nRows:" << std::endl;
	for(unsigned int i = 0; i < Orows_.size(); i++)
	{
		std::cout << Orows_[i];
	}
	std::cout << std::endl << "Columns:" << std::endl;;
	for(unsigned int i = 0; i < Ocols_.size(); i++)
	{
		std::cout << Ocols_[i];
	}
	std::cout << std::endl;
	std::cout << "\n\n";
}