#ifndef __TIMEQ_H_
#define __TIMEQ_H_
//You can change/add to these #includes
#include <ctime>
#include <vector>
#include <iostream>
#include <cassert>

typedef int tq_hook; //Used to point to a location in the heap, fill in the "???"

//Forward declaration of Job class, do not remove this line, do not change.
class Job;

//Promise to declare stream output operator for internal vector heap representation
std::ostream& operator<< (std::ostream& out, const std::vector<Job*>& heap);

class TimeQueue{

//////////FILL THIS IN///////////

private:
	std::vector<Job*> time;
public:
	TimeQueue();
	const Job* top() const;
	Job* pop();
	void push(Job* add);
	void Swap(std::vector<Job*>& tim, int firstInd, int lastInd);
	int percolateUp();
	//restore the heap properties for proper run time O(logN)
	void percolateDown(int i);
	void remove_from_index(tq_hook loc);
	void printHeap(std::ostream& outfile);
};

//////////FILL THIS IN///////////


#endif
