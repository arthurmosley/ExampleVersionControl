#include "Job.h"

UrgentQueue::UrgentQueue() {}

const Job* UrgentQueue::top() const
{
	assert(!urgency.empty());
	return urgency[0];
}

Job* UrgentQueue::pop()
{
	//reutnring the object that is getting removed from the vector. and reestablish heap standard.
	Job* popped = urgency[0];
	urgency[0] = urgency.back();
	urgency.pop_back();
	percolateDown(0);
	return popped;
}

void UrgentQueue::push(Job* add)
{
	//put it into the vector.
	urgency.push_back(add);
	add->urgent_hook = percolateUp();
	add->priority_ptr = this;
}

void UrgentQueue::Swap(std::vector<Job*>& urg, int firstInd, int lastInd)
{
	std::vector<Job*> tmp = urg;

	//swap first and last items in the array.
	urg[firstInd] = urg[lastInd];
	urg[lastInd] = tmp[firstInd];
}

int UrgentQueue::percolateUp()
{
	uq_hook i = urgency.size() - 1;
	uq_hook par = (i - 1)/2;
	while(par >= 0)
	{
		//basically sorts in terms of priority going up.
		if(urgency[par]->getPriority() < urgency[i]->getPriority())
		{
			Job* tmp = urgency[par];
			urgency[par] = urgency[i];
			urgency[i] = tmp;
			i = par;
			par = (i - 1)/2;
		}
		else
			break;
	}
	return par;
}
void UrgentQueue::percolateDown(int i)
{
	Job* val = urgency[i];
	uq_hook lastLeaf = uq_hook((urgency.size() - 1)/2);
	while(i <= lastLeaf)
	{
		//sortiing.
		int childLeft = 2 * i + 1;
		int childRight = 2 * i + 2;
		if(childLeft < urgency.size() && urgency[childLeft]->getPriority() < urgency[childRight]->getPriority())
			childLeft = childRight;
		if(urgency[childLeft]->getPriority() > val->getPriority())
		{
			urgency[i] = urgency[childLeft];
			i = childLeft;
		}
		else break;
	}
	urgency[i] = val;
}

void UrgentQueue::remove_from_index(uq_hook loc)
{
	//swaps the index that is in the location specified with the back location of the vector and percolate to maintain heap standard.
	std::swap(urgency[loc], urgency[urgency.size()-1]);
	urgency.pop_back();
	percolateDown(0);
}

void UrgentQueue::printHeap(std::ostream& outfile)
{
    outfile << "UQ " << urgency.size() << " jobs:" << std::endl;
    for(std::size_t i=0; i<urgency.size(); i++)
    {
        outfile << "\t" << urgency[i];
    }
}