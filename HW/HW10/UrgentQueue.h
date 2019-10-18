#ifndef __URGENTQ_H_
#define __URGENTQ_H_
//You can change/add to these #includes
#include <ctime>
#include <vector>
#include <iostream>
#include <cassert>

typedef int uq_hook; //Used to point to a location in the heap, fill in the "???"

//Forward declaration of Job class, do not remove this line, do not change.
class Job;

//Promise to declare stream output operator for internal vector heap representation
std::ostream& operator<<(std::ostream& out, const std::vector<Job*>& heap);

class UrgentQueue{
private:
	//vector used to hold the heap data.
	std::vector<Job*> urgency;
public:
	UrgentQueue();
	const Job* top() const;
	Job* pop();
	void push(Job* add);
	void Swap(std::vector<Job*>& urg, int firstInd, int lastInd);
	//restore the heap properties for proper run time O(logN)
	int percolateUp();
	void percolateDown(int i);
	//removes a specific value from index.
	void remove_from_index(uq_hook loc);
	void printHeap(std::ostream& outfile);
};

//////////FILL THIS IN///////////


#endif
