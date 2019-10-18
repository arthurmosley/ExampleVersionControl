#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cassert>
#include <sstream>
#include <streambuf>
#include <vector>
#include "battleship.h"
#include <cstdlib>


//Calculates the length of the ships and stores it in a pass my reference parameter, length. ALso, bool to see where it ends or if it's a valid ship
bool lengthShips(Battleship &board, int i, int j, std::string direction, int &length)
{
	length = 0;
	if(direction == "down")
	{
		while(i < board.num_rows() && board.d[i][j] == 1)
		{
			board.d[i][j] = 2;

			//check right
			if(j+1 < board.num_cols() && board.d[i][j+1] == 1) return false;
			//check left
			else if(j-1 >=0 && board.d[i][j-1] ==1) return false;
			//check bottom diagonal
			else if(j+1 < board.num_cols() && i+1 < board.num_rows() && board.d[i+1][j+1] == 1) return false;
			//check upper diagonal
			else if(j+1 < board.num_cols() && i-1 >= 0 && board.d[i-1][j+1] == 1) return false;

			//add to length and move iterator
			i++;
			length++;
		}
	}
	if(direction == "right")
	{
		while(j < board.num_cols() && board.d[i][j] == 1)
		{
			board.d[i][j] = 2;

			//check up
			if(i-1 >= 0 && board.d[i-1][j] == 1) return false;
			//check down
			else if(i+1 < board.num_rows() && board.d[i+1][j] == 1) return false;
			//check right diagonal down.
			else if(i+1 < board.num_rows() && j+1 < board.num_cols() && board.d[i+1][j+1] == 1) return false;
			//check right diagonal up
			else if(i-1 >= 0 && j-1 >= 0 && board.d[i-1][j-1] == 1) return false;

			//add to length and move iterator
			j++;
			length++;
		}
	}
	return true;
}

//Surrounds a boat by water which saves run time by getting rid of the opportunity for the recursive function to check nearby to ships when water is already placed.
void surroundByWater(Battleship &board, int i, int j, std::string direction)
{
	int l = 0;
	if(direction == "<")
	{
		//handling left behind the piece of the ship
		if(j-1 >= 0)
		{
			board.d[i][j-1] = 0;
			//check top left
			if(i - 1 >= 0)
				board.d[i-1][j-1] = 0;
			//check bottom left
			if(i + 1 < board.num_rows())
				board.d[i+1][j-1] = 0;
		}
		//check right above
		if(i-1 >= 0)
		{
			board.d[i-1][j] = 0;
			//above right
			if(j+1 < board.num_cols())
				board.d[i-1][j+1] = 0;
		}
		//check below
		if(i+1 < board.num_rows())
		{
			board.d[i+1][j] = 0;
			//below right
			if(j+1 < board.num_cols())
				board.d[i+1][j+1] = 0;
		}
		
		board.d[i][j+1] = 1;
		board.deduct(i,j+1);
	}
	else if(direction == ">")
	{
		//right
		if(j+1 < board.num_cols())
		{
			board.d[i][j+1] = 0;
			//down diagonal
			if(i-1 >= 0)
				board.d[i-1][j+1] = 0;
			//upper right diagonal
			if(i + 1 < board.num_rows())
				board.d[i+1][j+1] = 0;
		}
		//directly below
		if(i+1 < board.num_rows())
		{
			board.d[i+1][j] = 0;
			//bottom left diagonal
			if(j-1 >= 0)
				board.d[i+1][j-1] = 0;
		}
		if(i-1 >= 0)
		{
			//directly above
			board.d[i-1][j] = 0;
			if(j -1 >= 0)
				board.d[i-1][j-1] = 0;
		}
	
		board.d[i][j-1] = 1;
		board.deduct(i,j-1);
	}
	else if(direction == "o")
	{
		//right
		if(j+1 < board.num_cols())
		{
			board.d[i][j+1] = 0;
			//down diagonal
			if(i-1 >= 0)
				board.d[i-1][j+1] = 0;
			//upper right diagonal
			if(i + 1 < board.num_rows())
				board.d[i+1][j+1] = 0;
		}
		//directly below
		if(i+1 < board.num_rows())
		{
			board.d[i+1][j] = 0;
			//bottom left diagonal
			if(j-1 >= 0)
				board.d[i+1][j-1] = 0;
		}
		if(i-1 >= 0)
		{
			//directly above
			board.d[i-1][j] = 0;
			if(j -1 >= 0)
				board.d[i-1][j-1] = 0;
		}
		//left
		if(j-1 >= 0)
		{
			board.d[i][j-1] = 0;
		}
	}
	else if(direction == "X")
		return;
	else if(direction == "^")
	{
		//directly above
		if(i - 1 >= 0)
		{
			board.d[i-1][j]= 0;
			//above left
			if(j-1 >=0)
				board.d[i-1][j-1]= 0;
			//above right
			if(j+1 < board.num_cols())
				board.d[i-1][j+1] = 0;
		}
		if(j-1 >= 0)
		{
			//directly left
			board.d[i][j-1] = 0;
			//bottom left
			if(i+1 < board.num_rows())
				board.d[i+1][j-1] = 0;
		}
		if(j+1 < board.num_cols())
		{
			//directly right
			board.d[i][j+1] = 0;
			//bottom right
			if(i+1 < board.num_rows())
				board.d[i+1][j+1] = 0;
		}
		board.d[i+1][j] = 1;
		board.deduct(i+1,j);
	}
	else if(direction == "v")
	{
		//ddirectly below
		if(i + 1 < board.num_rows())
		{
			board.d[i+1][j] = 0;
			//below right
			if(j+1 < board.num_cols())
				board.d[i+1][j+1] = 0;
			//below left
			if(j-1 >= 0)
				board.d[i+1][j-1] = 0;
		}
		if(j + 1 < board.num_cols())
		{
			//directly right
			board.d[i][j+1] = 0;
			if(i+1 < board.num_rows())
				board.d[i+1][j+1];
		}
		if(j -1 >= 0)
		{
			//directly left
			board.d[i][j-1];
			if(i+1 < board.num_rows())
				board.d[i+1][j-1];
		}
		board.d[i-1][j] = 1;
		board.deduct(i-1, j);
	}
}

//uses fill water in order to set the constraints that are necessary.
void constraints(Battleship &board, std::vector<std::vector<std::string> > constr)
{
	std::string temp;
	for(unsigned int i= 0; i <board.num_rows(); i++)
	{
		for(unsigned int j = 0; j < board.num_cols(); j++)
		{
			temp = constr[i][j];
			if(temp != " ")
			{
				if(temp == "_") 
					board.d[i][j] = 0;

				board.d[i][j] = 1;
				board.deduct(i, j);
				surroundByWater(board, i, j, temp);
			}

			
		}
	}
	return;
}

//checks if the board is a solid solution and if so then tells you true or false.
bool ifSol(Battleship board)
{
	//checks if the rows doesnt equal 0
	for (unsigned int i = 0; i < board.num_rows(); i++)
	{
		if(board.rows_[i] != 0)
			return false;
	}
	//checks if the columns doesnt equal zero
	for (unsigned int i = 0; i < board.num_cols(); i++)
	{
		if(board.cols_[i] != 0)
			return false;
	}


	int l = 0;
	std::vector<int> temp(7, 0);
	for(unsigned int i = 0; i < board.num_rows(); i++)
	{
		for(unsigned int j = 0; j < board.num_cols(); j++)
		{
			if(board.d[i][j] == 1)
			{
				if(j+1 < board.num_cols() && board.d[i][j+1] == 1)
				{
					if(!lengthShips(board, i, j, "right", l))
					{
						return false;
					}
					temp[l-1]++;
					l = 0;
				}
				else
				{
					if(!lengthShips(board, i, j, "down", l))
					{
						return false;
					}
					temp[l-1]++;
					l = 0;
				}
			}
		}
	}
	return temp == board.ships_;
}

//checks if the board fails.
bool failed(Battleship board, int i, int j)
{
	if (board.rows_[i] < 0)
	{
		return true;
	}
	if (board.cols_[j] < 0)
	{
		return true;
	}
	return false;
}

//function to print the really annoying board that we have to print out.
void printBoard(std::vector<Battleship> solutions, int rows_, int cols_)
{
	for(unsigned int i = 0; i < solutions.size(); i++)
	{
		int length = 0;
		std::cout << "Solution:" << std::endl;
		for(unsigned int j = 0; j < solutions[i].d.size(); j++)
		{
			for(unsigned int k = 0; k < solutions[i].d[j].size(); k++)
			{
				if(solutions[i].d[j][k] == 1)
				{
					if(j+1 < solutions[i].num_cols() && solutions[i].d[i][j+1] == 1)
					{
						lengthShips(solutions[i], j, k, "right", length);
						if(length == 1)
						{
							std::cout << "submarine " << j << " " << k << std::endl;
						}
						else if(length == 2)
						{
							std::cout << "destroyer " << j << " " << k << " horizontal" << std::endl;
						}
						else if(length == 3)
						{
							std::cout << "cruiser " << j << " " << k << " horizontal" << std::endl;
						}
						else if(length == 4)
						{
							std::cout << "battleship " << j << " " << k << " horizontal" << std::endl;
						}
						else if(length == 5)
						{
							std::cout << "carrier " << j << " " << k << " horizontal" << std::endl;
						}
						else if(length == 6)
						{
							std::cout << "cargo " << j << " " << k << " horizontal" << std::endl;
						}
						else if(length == 7)
						{
							std::cout << "tanker " << j << " " << k << " horizontal" << std::endl;
						}
						j = j + length;
						length = 0;
					}
					else
					{
						lengthShips(solutions[i], j, k, "down", length);
						if(length == 1)
						{
							std::cout << "submarine " << j << " " << k << std::endl;
						}
						else if(length == 2)
						{
							std::cout << "destroyer " << j << " " << k << " vertical" << std::endl;
						}
						else if(length == 3)
						{
							std::cout << "cruiser " << j << " " << k << " vertical" << std::endl;
						}
						else if(length == 4)
						{
							std::cout << "battleship " << j << " " << k << " vertical" << std::endl;
						}
						else if(length == 5)
						{
							std::cout << "carrier " << j << " " << k << " vertical" << std::endl;
						}
						else if(length == 6)
						{
							std::cout << "cargo " << j << " " << k << " vertical" << std::endl;
						}
						else if(length == 7)
						{
							std::cout << "tanker " << j << " " << k << " vertical" << std::endl;
						}
						i = i + length;
						length = 0;
					}
				}
			}
		}
		solutions[i].print_board();
	}
}


//my recursive function
void recurse(Battleship board, int i, int j, int value, std::vector<Battleship> &solutions)
{
	/*
	0 = water
	1 = ship
	9 = unknown
	*/

	//assigning a value to the first element in the board
	if (board.d[i][j] == 9)
	{
		board.d[i][j] = value;
	}

	if (value)
	{
		board.deduct(i, j);
		// board.fillShips(i,j);
		// board.fillWater(i,j);
	}
	//check if it fails
	if(failed(board, i, j))
		return;
	else if (ifSol(board))
	{
		board.fillWater();
		solutions.push_back(board);
		return;
	}


	// if you get to the end of a column, make sure you filled the column with enough ships
	if (i+1 == board.num_rows())
	{
		if (board.cols_[j] != 0)
		{
			return;
		}
	}

	//Handles the situations where I hit the end of the board
	if(j+1 == board.num_cols())
	{
		// if you get to the end of the row, make sure you filled the row with enough ships
		if (board.rows_[i] != 0)
		{
			return;
		}
		i++;
		j = 0;
		if (i == board.num_rows())
			return;
	}
	else
		j++;

	//while loop to find next unknown tile
	// while (board.d[i][j] != 9)
	// {
	// 	std::cout << i<< j << board.d[i][j] << std::endl;
	// 	j++;
	// 	// if you get to the end of a column, make sure you filled the column with enough ships
	// 	if (i+1 == board.num_rows())
	// 	{
	// 		if (board.cols_[j] != 0)
	// 		{
	// 			return;
	// 		}
	// 	}

	// 	//Handles the situations where I hit the end of the board
	// 	if(j+1 == board.num_cols())
	// 	{
	// 		// if you get to the end of the row, make sure you filled the row with enough ships
	// 		if (board.rows_[i] != 0)
	// 		{
	// 			return;
	// 		}
	// 		i++;
	// 		j = 0;
	// 		if (i == board.num_rows())
	// 			return;
	// 	}
	// }
	
	//what is the next value
	recurse(board, i, j, 1, solutions);
	recurse(board, i, j, 0, solutions);
	return;
}




int main(int argc, char* argv[])
{
	//most of the following is the reading in of all of the information I need
	std::ifstream in_str(argv[1]);
	//testing to see if the text file can be open and be read.
	if(!in_str.good())
	{
		std::cerr << "Could not open " << argv[1] << " to read" << std::endl;
		return 1;
	}	

	std::string flag;
	std::string tmpSTR;
	int rows;
	int cols;

	//stores the number of each type of ship where index is ship length - 1
	std::vector<int> ships(7, 0);

	in_str >> tmpSTR >> rows >> cols >> tmpSTR;
	
	std::vector<int> r(rows);
	std::vector<int> c(cols);

	for(unsigned int i = 0; i < rows; i++)
		in_str >> r[i];

	in_str >> tmpSTR;

	for(unsigned int i = 0; i < cols; i++)
		in_str >> c[i];

	std::vector<std::vector<std::string> > con;
	for(unsigned int i = 0; i < rows; i++)
	{
		std::vector<std::string> temp(cols, " ");
		con.push_back(temp);
	}

	std::vector<std::string> holdShips;
	//while in_str not EOF then keep iterating through and put dem ships in der
	while (in_str >> tmpSTR)
	{
		if(tmpSTR == "submarine")
		{
			ships[0]++;
			holdShips.push_back("submarine");
		}
		else if(tmpSTR == "destroyer")
		{
			ships[1]++;
			holdShips.push_back("destroyer");
		}
		else if(tmpSTR == "cruiser")
		{
			ships[2]++;
			holdShips.push_back("cruiser");
		}
		else if(tmpSTR == "battleship")
		{
			ships[3]++;
			holdShips.push_back("battleship");
		}
		else if(tmpSTR == "carrier")
		{
			ships[4]++;
			holdShips.push_back("carrier");
		}
		else if(tmpSTR == "cargo")
		{
			ships[5]++;
			holdShips.push_back("cargo");
		}
		else if(tmpSTR == "tanker")
		{
			ships[6]++;
			holdShips.push_back("tanker");
		}
		else if(tmpSTR == "constraint")
		{
			flag = "constraint";
			in_str >> tmpSTR;
			int i = atoi(tmpSTR.c_str());
			in_str >> tmpSTR;
			int j = atoi(tmpSTR.c_str());
			in_str >> tmpSTR;
			con[i][j] = tmpSTR;
		}
	}


	Battleship board = Battleship(r, c, rows, cols, ships);
	std::vector<Battleship> solutions;
	
	if (flag == "constraint") 
	{	
		constraints(board, con);
	}
	recurse(board, 0, 0, 1, solutions);
	recurse(board, 0, 0, 0, solutions);

	//printBoard(solutions, rows, cols);
	for (unsigned int i = 0; i < solutions.size(); i++)
		solutions[i].print_board();
	std::cout << "Found " << solutions.size() << " solution(s)" << std::endl;

	return 0;
}