#ifndef priority_queue_h_
#define priority_queue_h_

#include <iostream>
#include <vector>
using namespace std;


template <class T>
class priority_queue {
private:
  vector<T> m_heap;

public:
  priority_queue() {}

  priority_queue( vector<T> const& values )
  {
    for (unsigned int i = 0; i < values.size(); i++) {
      m_heap.push_back(values[i]);
      percolate_up();
    }
  }

  const T& top() const 
  {
    assert( !m_heap.empty() );
    return m_heap[0]; 
  }

  void push( const T& entry )
  {
    m_heap.push_back(entry);
    percolate_up();
    check_heap();
  }

  void pop() 
  {
    assert( !m_heap.empty() );
    m_heap[0] = m_heap.back();
    m_heap.pop_back();
    percolate_down(0);
    check_heap();
  }

  int size() { return m_heap.size(); }
  bool empty() { return m_heap.empty(); }


  //  The following three functions are used for debugging.

  //  Check to see that internally the heap property is realized.
  bool check_heap( )
  {
    return this->check_heap( this->m_heap );
  }

  //  Check an extrernal vector to see that the heap property is realized.
  bool check_heap( const vector<T>& heap )
  {
    if (heap.size() < 2) {
      return true;
    }
    for ( unsigned int i=0; i<heap.size()/2; ++i ) {
      int l_child = 2 * i + 1;
      int r_child = l_child + 1;
      if (l_child < heap.size() && (heap[i] > heap[l_child]) ) 
        return false;
      if (r_child < heap.size() && (heap[i] > heap[r_child]) )
        return false;
    }
    return true;
  }
  //  A utility to print the contents of the heap.  Use it for debugging.
  void print_heap( ostream & ostr )
  {
    for ( unsigned int i=0; i<m_heap.size(); ++i )
      ostr << i << ": " << m_heap[i] << endl;

    ostr << endl;
  }
  
private:
  void percolate_up() {
    int index = m_heap.size()-1;
    int parent = ((index-1)/2);
    while (parent >= 0) 
    {
      if (m_heap[parent] > m_heap[index]) 
      {
        T tmp = m_heap[parent];
        m_heap[parent] = m_heap[index];
        m_heap[index] = tmp;
        index = parent;
        parent = ( (index-1 )/2);
      }
      else
        break;
    }
  }

  void percolate_down(int i) 
  {
  T value = m_heap[i];
  int last_non_leaf = int(m_heap.size()-1)/2;
  while (i <= last_non_leaf) 
  {
    int child = 2*i+1, rchild = 2*i+2;
    if (rchild < m_heap.size() && m_heap[child] > m_heap[rchild])
      child = rchild;
    if (m_heap[child] >= value) break; // found right location
    m_heap[i] = m_heap[child];
    i = child;
  }
  m_heap[i] = value;
  }
};

template <class T>
void maxHeapify(vector<T>& A, int i, int n)
{
int largest;
int l = (2 * i) + 1;
int r = (2 * i) + 2;

  if ((l <= n) && (A[l-1] > A[i-1]))
      largest = l;
  else
      largest = i;

  if ((r <= n) && (A[r-1] > A[largest-1]))
      largest = r;

  if (largest != i)
  {
      swap(A[i-1], A[largest-1]);
      maxHeapify(A, largest, n);
  }
}
template <class T>
void swap(vector<T>& A, int firstItemIndex, int lastItemInde) {
  vector<T> tmp = A;
  
  // Swap first and last items in the array.
  A[firstItemIndex] = A[lastItemInde];
  A[lastItemInde] = tmp[firstItemIndex];
}

template <class T>
void heap_sort( vector<T> & A)
{
  if (A.size() == 0)
    return;

  for (int i = A.size(); i >= 2; i--)
  {
    swap(A,0, i);
    maxHeapify(A, 1, i - 1);
  }

  /*
  priority_queue<T> pq_tmp(v);

  v.clear();
  while (pq_tmp.size() > 0) 
  {
    //pushing back value from the temp
    v.push_back( pq_tmp.top() );
    //takes off the last value.
    pq_tmp.pop();
  }*/
}

#endif
