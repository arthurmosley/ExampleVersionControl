#ifndef __Matrix_h_
#define __Matrix_h_

#include <iostream>
#include <iomanip>
#include <string>
#include <iterator>
#include <sstream>
#include <fstream>

class Matrix
{
public:
  //CONSTRUCTOR
  Matrix();
  Matrix(unsigned int rows, unsigned int columns, double fill);
  void operator=(const Matrix& copy);

  //COPY CONSTRUCTOR
  Matrix(Matrix const& copy);


  //DECONSTRUCTOR
  ~Matrix();

  //ACCESSORS
  //returns the number of rows in the matrix.
  int num_rows() const;

  //returns the number of columns in the matrix.
  int num_cols() const;

  //returns true if the element exists and passes the value by reference
  bool get(const int row, const int col, double &val) const;

  //returns a pointer to a row in the Matrix
  double *get_row(unsigned int r);

  //returns a pointer to a column in the Matrix
  double *get_col(unsigned int c);



  //MODIFIERS
  //deallocates memory and clears the values pointed to
  void clear();

  //returns true if the element exists and if true, sets the value to val.
  bool set(int row, int col, double val);

  //adds matrix "a" and "b" if the dimensions match and modify matrix "a".
  bool add(Matrix &b);

  //subtracts matrix "a" and "b" if the dimensions match and modifies matrix "a"
  bool subtract(Matrix &b);

  //multiplies each value in the matrix by a double value, coefficient.
  void multiply_by_coefficient(double coefficient);

  //swaps row, r1, with row, r2.
  bool swap_row(unsigned int r1, unsigned int r2);

  //trasposes the matrix (# rows = #column, # columns = # rows)
  void transpose();

  //returns the contents of a all 4 quadrants of a matrix
  Matrix* quarter();

  //resizes the matrix (EXTRA CREDIT OPP). Takes in #rows #columns and a fill val.
  void resize(unsigned int r, unsigned int c, double fill);


  //COMPARITORS
  //compare if two matrices are identical.
  bool operator==(Matrix &m1);
  //compare if two matrices are not identical
  bool operator!=(Matrix &m1);

private:
  //REPRESENTATION
  unsigned int rows_;
  unsigned int columns_;
  double** m;

};



//overloading << to display the information to print
std::ostream& operator<< (std::ostream& out, const Matrix& m);

#endif
