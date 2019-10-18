#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <list>

//node class
class HashNode
{
public:
	//key and value for each data entry. Key being the integer, k, letters. Second, string from DNA alphabet.
	int key_;
	std::string val_;

	HashNode(std::string val, int key)
	{
		key_ = key;
		val_ = val;
	}
};

//hashtable
class HashTable
{
private:
	std::vector<HashNode>* keyVal;
	//initial size of the hashtable.
	int containerLimit;
	int tSize;
	std::string inFile;
	float maxOccupancy;
	int kmer;
public:
	////////////////////////////////////////////////***PROTOTYPES***////////////////////////////////////////////////////////////////
	HashTable(int size, std::string file, float occupancy, int k);
	~HashTable();
	//MODIFIERS
	void clear();
	int insertion(const char* str, unsigned int size);
	//void insert(int key, std::string val);
	void resize();
	std::vector<int> find(std::string seg);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
};
	//implementation of the array used for the hashmap.
	HashTable::HashTable(int size, std::string file, float occupancy, int k)
	{
		///////////////////////////////////INITIALIZE VALUES///////////////////////////////
		tSize = size;
		inFile = file;
		//creating table to enter vals.
		containerLimit = 0;
		maxOccupancy = occupancy;
		///////////////////////////////////////////////////////////////////////////////////
		//create a new hash table with the appropriate size. size is up for future debate
		keyVal = new std::vector<HashNode>[size];
		kmer = k;
		//copying the space necessary to put in the kmer string
		std::string tmpString = "";
		for(unsigned int i = 0; i < kmer; i++)
			tmpString += " "; //creating the spaces necessary to find in the sequence of genome kmer times.
		for(unsigned int i = 0; i < inFile.length(); i++)
		{
			//going for the length of the kmers given and shifting them backwards.
			for(unsigned int j = 0; j < kmer-1; j++)
			{
				tmpString[j] = tmpString[j+1];
			}
			//keeps loading the temp until ultimately temp is filled with the kmer string.
			tmpString[kmer - 1] = inFile[i];
			//find location to insert the "val"
			int loc = insertion(tmpString.c_str(), tmpString.length());
			if(i+1 >= kmer)
			{
				//check if the size of the container is larger than 0 so it can occupy spaces
				if(keyVal[loc].size() > 0)
				{
					if(keyVal[loc][0].val_ == tmpString)
						keyVal[loc].push_back(HashNode(tmpString, i-(kmer)+1));
				}
				//linear probing for when a value is already found.
				else
				{
					while(keyVal[loc].size() > 0 && keyVal[loc][0].val_ != tmpString)
						loc = (loc+1)%tSize;
					if(keyVal[loc].size() == 0)
						containerLimit++;
					keyVal[loc].push_back(HashNode(tmpString, i - (kmer)+1));
				}
			}
			//handles if the list is empty, therefore pushing it back into the list
			else
			{
				keyVal[loc].push_back(HashNode(tmpString, i - (kmer) + 1));
				containerLimit++;
			}
			//handles if the occupancy is over
			if(containerLimit >= maxOccupancy * tSize)
				break;
		}
		if(containerLimit >= maxOccupancy * tSize)
			resize();
	}
	//DESCTRUCTOR
	HashTable::~HashTable()
	{
		//destroyed a hashtable. Useful when rehashing.
		clear();
	}

	//function to clear the memory allocated; used for destructor and resize.
	void HashTable::clear()
	{
		//deletes the new vectors made.
		delete[] keyVal;
	}

	//function that returns the location to insert a key/val./
	//TAKEN FROM http://partow.net/programming/hashfunctions/index.html#JSHashFunction
	//HASHING FUNCTION
	int HashTable::insertion(const char *str, unsigned int size)
	{
		unsigned int hash = 1315423911;
   		unsigned int i = 0;
 
	    for (i = 0; i < size; ++str, ++i)
	    {
	      hash ^= ((hash << 5) + (*str) + (hash >> 2));
	    }
	    return hash%tSize;
	}

	void HashTable::resize()
	{
		//since information is fed in completely via the insert function, no loop is required.

		//when capacity reaches a certain point, double the size of the table and rehash it
		HashTable temp = HashTable(tSize*2, inFile, maxOccupancy, kmer);
		//clear the table and rehash all of the information into the larger hash table.
		clear();
		*this = temp;
	}

	std::vector<int> HashTable::find(std::string seg)
	{
		//FIND DOES NOT WORK PROPERLY.
		//saving the location of insertion.
		int loc = insertion(seg.c_str(), seg.length());
		//what I'm returning
		std::vector<int> ind;
		if(keyVal[loc].size() == 0) return ind;
		//find if moved
			loc = (loc+1)&tSize;
		return ind;
	}