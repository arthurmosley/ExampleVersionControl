#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

/***CONSTRUCTORS***/

Matrix::Matrix()
{
  rows_ = 0;
  columns_ = 0;
  m = NULL;
}

Matrix::Matrix(unsigned int rows, unsigned int columns, double fill)
{
  rows_ = rows;
  columns_ = columns;
  m = new double*[rows_];
  //handles if size of either the rows or columns is 0.
  if(rows_ == 0 || columns_ == 0)
  {
    rows_ = 0;
    columns_ = 0;
  }
  //creating the dynamic memory
  for(unsigned int i = 0; i < rows_; i++)
  {
    m[i] = new double[columns_];
  }

  //filling the Matrix
  for(unsigned int j = 0; j < rows_; j++)
  {
    for(unsigned int k = 0; k < columns_; k++)
    {
      m[j][k] = fill;
    }
  }
}

Matrix::Matrix(const Matrix &copy)
{

  //clear();
  rows_ = copy.num_rows();
  columns_ = copy.num_cols();
  if(rows_ == 0 || columns_ == 0)
  {
    rows_ = 0;
    columns_ = 0;
  }

  m = new double*[rows_];
  for (unsigned int i = 0; i < rows_; i++)
  {
    m[i] = new double[columns_];
    for (unsigned int j = 0; j < columns_; j++)
    {
      copy.get(i,j,m[i][j]);
    }
  }
}
void Matrix::operator=(const Matrix& copy)
{
  //clear();
  rows_ = copy.num_rows();
  columns_ = copy.num_cols();
  if(rows_ == 0 || columns_ == 0)
  {
    rows_ = 0;
    columns_ = 0;
  }
  m = new double*[rows_];
  for (unsigned int i = 0; i < rows_; i++)
  {
    m[i] = new double[columns_];
    for (unsigned int j = 0; j < columns_; j++)
    {
      copy.get(i,j,m[i][j]);
    }
  }
}

Matrix::~Matrix()
{
  clear();
}

/***ACCESSORS***/

int Matrix::num_rows() const
{
  return rows_;
}

int Matrix::num_cols() const
{
  return columns_;
}

bool Matrix::get(int row, int col, double &val) const
{
  if(row < num_rows() && col < num_cols())
  {
    val = m[row][col];
    return true;
  }
  return false;
}

double* Matrix::get_row(unsigned int r)
{
  //handles out of bounds of matrix row size
  if(r > num_rows())
  {
    return NULL;
  }

  double* goal = new double[columns_];
  for(unsigned int i = 0; i < columns_; i++)
  {
    goal[i] = m[r][i];
  }
  return goal;
  delete[] goal;
}

double* Matrix::get_col(unsigned int c)
{
  //handles out of bounds of matrix column size
  if(c > num_cols())
  {
    return NULL;
  }

  double* goal = new double[rows_];
  for(unsigned int i = 0; i < rows_; i++)
  {
    goal[i] = m[i][c];
  }
  return goal;
  delete[] goal;
}

/***MODIFIERS***/

void Matrix::clear()
{
  //checking if its a null pointer
  if (m == NULL)
  {
    return;
  }
  //Otherwise, clear/delete the dynamic memory.
  for(unsigned int i = 0; i < rows_; i++)
  {
    if (m[i] != NULL)
    {
      delete [] m[i];
    }
  }

  delete [] m;
  m = NULL;
  rows_ = 0;
  columns_ = 0;
}

bool Matrix::set(int row, int col, double val)
{
  //checking if they are in bounds
  if(row < num_rows() && col < num_cols())
  {
    m[row][col] = val;
    return true;
  }
  return false;
}

bool Matrix::add(Matrix &b)
{
  if(rows_ == b.num_rows() && columns_ == b.num_cols())
  {
    for(unsigned int i = 0; i < rows_; i++)
    {
      for(unsigned int j = 0; j < columns_; j++)
      {
        double tmp;
        b.get(i, j, tmp);
        //addding
        m[i][j] += tmp;
      }
    }
    return true;
  }
  return false;
}

bool Matrix::subtract(Matrix &b)
{
  if(rows_ == b.num_rows() && columns_ == b.num_cols())
  {
    for(unsigned int i = 0; i < rows_; i++)
    {
      for(unsigned int j = 0; j < columns_; j++)
      {
        double tmp;
        b.get(i, j, tmp);
        //subtracting
        m[i][j] -= tmp;
      }
    }
    return true;
  }
  return false;
}

void Matrix::multiply_by_coefficient(double coefficient)
{
  for(unsigned int i = 0; i < rows_; i++)
  {
    for(unsigned int j = 0; j < columns_; j++)
    {
      //essentially dot product on the values currently stored by a double, coefficient.
      m[i][j] *= coefficient;
    }
  }
}

bool Matrix::swap_row(unsigned int r1, unsigned int r2)
{
  //holder variable to store one row that I'll be swapping.
  double* tmp;
  if(r1 < num_rows() && r2 < num_rows())
  {
    //holding original val
    tmp = m[r1-1];
    //swapping original val
    m[r1-1] = m[r2-1];
    m[r2-1] = tmp;
    return true;
  }
  return false;
}

void Matrix::transpose()
{
  //holder for original rows and column sizes, respectively.
  int tmpR;
  int tmpC;
  //temporary array
  double** tmpA = new double*[columns_];
  //switching rows and columns
  for(unsigned int i = 0; i < columns_; i++)
  {
    tmpA[i] = new double[rows_];
  }

  for(unsigned int i = 0; i < rows_; i++)
  {
    for(unsigned int j = 0; j < columns_; j++)
    {
      tmpA[j][i] = m[i][j];
    }
  }
  tmpR = rows_;
  tmpC = columns_;
  clear();
  rows_ = tmpC;
  columns_ = tmpR;
  m = tmpA;
}

Matrix* Matrix::quarter()
{
	Matrix* temp = new Matrix[4];
	// For the case of an empty matrix
	if (rows_ != 0)
  {
    //ceil in order to assure rounding up.
    int end_row = ceil(float(rows_) / 2);
		int end_col = ceil(float(columns_) / 2);
		int start_row = rows_ / 2;
		int start_col = columns_ / 2;

		Matrix a(end_row,end_col,0);
		Matrix b(end_row,end_col,0);
		Matrix c(end_row,end_col,0);
		Matrix d(end_row,end_col,0);
		for (unsigned int i = 0; i < end_row; i++)
    {
			for (unsigned int j = 0; j < end_col; j++)
      {
				a.set(i,j,m[i][j]);
			}
		}
		for (unsigned int i = 0; i < end_row; i++)
    {
			for (unsigned int j = start_col; j < columns_; j++)
      {
				b.set(i,j - start_col,m[i][j]);
			}
		}
		for (unsigned int i = start_row; i < rows_; i++)
    {
			for (unsigned int j = 0; j < end_col; j++)
      {
				c.set(i - start_row,j,m[i][j]);
			}
		}
		for (unsigned int i = start_row; i < rows_; i++)
    {
			for (unsigned int j = start_col; j < columns_; j++)
      {
				d.set(i - start_row,j - start_col,m[i][j]);
			}
		}
		temp[0] = a;
		temp[1] = b;
		temp[2] = c;
		temp[3] = d;
	}
	else
  {
    //empty matrix.
    Matrix a;
		Matrix b;
		Matrix c;
		Matrix d;
		temp[0] = a;
		temp[1] = b;
		temp[2] = c;
		temp[3] = d;
	}
	return temp;
}

void Matrix::resize(unsigned int r, unsigned int c, double fill)
{
  int tmpR;
  int tmpC;
  //create the memory for allocating values.
  double** t = new double*[r];
  for(unsigned int i = 0; i < r; i++)
  {
    t[i] = new double[c];
  }

  //fill the matrix with a default value, fill.
  for(unsigned int i = 0; i < r; i++)
  {
    for(unsigned int j = 0; j < c; j++)
    {
      t[i][j] = fill;
    }
  }
  //r smaller/equal than rows_ and c smaller/equal than columns_
  if(r <= rows_ && c <= columns_)
  {
    for(unsigned int i = 0; i < r; i++)
    {
      for(unsigned int j = 0; j < c; j++)
      {
        t[i][j] = m[i][j];
      }
    }
  }
  //r larger than rows_ and c larger than columns_
  if(r > rows_ && c > columns_)
  {
    for(unsigned int i = 0; i < rows_; i++)
    {
      for(unsigned int j = 0; j < columns_; j++)
      {
        t[i][j] = m[i][j];
      }
    }
  }
  //r smaller than rows_ and c smaller/equal than columns_
  if(r > rows_ && c <= columns_)
  {
    for(unsigned int i = 0; i < rows_; i++)
    {
      for(unsigned int j = 0; j < c; j++)
      {
        t[i][j] = m[i][j];
      }
    }
  }
  //r smaller/equal than rows_ and c larger than columns_
  if(r <= rows_ && c > columns_)
  {
    for(unsigned int i = 0; i < r; i++)
    {
      for(unsigned int j = 0; j < columns_; j++)
      {
        t[i][j] = m[i][j];
      }
    }
  }
  tmpR = r;
  tmpC = c;
  clear();
  rows_ = r;
  columns_ = c;
  m = t;
}

bool Matrix::operator==(Matrix &m1)
{
  if (rows_ != m1.rows_ || columns_ != m1.columns_)
  {
    return false;
  }
  for(unsigned int i = 0; i < rows_; i++)
  {
    for(unsigned int j = 0; j < columns_; j++)
    {
      double tmp;
      m1.get(i, j, tmp);
      if(m[i][j] != tmp)
      {
        return false;
      }
    }
  }
  return true;
}

bool Matrix::operator!=(Matrix &m1)
{
  if (rows_ != m1.rows_ || columns_ != m1.columns_)
  {
    return true;
  }
  for(unsigned int i = 0; i < rows_; i++)
  {
    for(unsigned int j = 0; j < columns_; j++)
    {
      double tmp;
      m1.get(i, j, tmp);
      if(m[i][j] != tmp)
      {
        return true;
      }
    }
  }
  return false;
}

std::ostream& operator<< (std::ostream& out, const Matrix& m)
{
  out << m.num_rows() << " x " << m.num_cols() << " matrix:\n";
  out << "[ ";
  for(unsigned int i = 0; i < m.num_rows(); i++)
  {
    if (i != 0)
    {
      out << "  ";
    }
    for(unsigned int j = 0; j < m.num_cols(); j++)
    {
      double tmp;
      m.get(i, j, tmp);
      out << tmp << " ";
    }
    if (i != m.num_rows() - 1)
    {
      out << "\n";
    }
  }
  out << "]" << std::endl;
  return out;
}
