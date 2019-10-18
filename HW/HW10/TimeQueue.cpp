#include "Job.h"

TimeQueue::TimeQueue() {}

const Job* TimeQueue::top() const
{
	assert(!time.empty());
	return time[0];
}

Job* TimeQueue::pop()
{
	//for given codes sake, must keep track of the initial value. Also reestablishing heap standards.
	Job* popped = time[0];
	time[0] = time.back();
	time.pop_back();
	percolateDown(0);
	return popped;
}

void TimeQueue::push(Job* add)
{
	//put it into the vector and into the proper location.
	time.push_back(add);
	add->time_hook = percolateUp();
	add->time_ptr = this;
}

void TimeQueue::Swap(std::vector<Job*>& tim, int firstInd, int lastInd)
{
	std::vector<Job*> tmp = tim;

	//swap first and last items in the array.
	tim[firstInd] = tim[lastInd];
	tim[lastInd] = tmp[firstInd];
}

int TimeQueue::percolateUp()
{
	tq_hook i = time.size() - 1;
	tq_hook par = (i - 1)/2;
	while(par >= 0)
	{
		//accessing the time used to determine the priority order. Otherwise time would use 
		if(time[par]->getTime() > time[i]->getTime())
		{
			Job* tmp = time[par];
			time[par] = time[i];
			time[i] = tmp;
			i = par;
			par = (i - 1)/2;
		}
		else
			break;
	}
	return i;
}

void TimeQueue::percolateDown(int i)
{
	Job* val = time[i];
	tq_hook lastLeaf = tq_hook((time.size() - 1))/2;
	while(i <= lastLeaf)
	{
		int childLeft = 2 * i + 1;
		int childRight = 2 * i + 2;
		if(childLeft < time.size() && time[childLeft]->getTime() > time[childRight]->getTime())
			childLeft = childRight;
		//location of swapping to move up
		if(time[childLeft]->getTime() < val->getTime()) {
			time[i] = time[childLeft];
			i = childLeft;
		}
		else break;
	}
	time[i] = val;
}

void TimeQueue::remove_from_index(int loc)
{
	//erase the index at the specific location of location. Start at the beginning and just add
	//if that index
	std::swap(time[loc], time[time.size()-1]);
	time.pop_back();
	//urgency.erase(urgency.begin() + loc);
	percolateDown(0);
}

void TimeQueue::printHeap(std::ostream& outfile)
{
    outfile << "TQ " << time.size() << " jobs:" << std::endl;
    for(std::size_t i=0; i<time.size(); i++)
    {
        outfile << "\t" << time[i];
    }
}