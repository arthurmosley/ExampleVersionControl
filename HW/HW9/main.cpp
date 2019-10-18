#include "hashNode.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

//respectively, vector that contains vals, query string, number of max possible mismatches allowed, file that is used to extract data from.
void match(std::vector<int> &q,  const std::string &inFile, std::string query_string, const int mismatches)
{
	std::string seg = "";
	int totalMatches = 0;
	for(unsigned int i = 0; i < q.size(); i++)
	{
		int miss = 0;
		if(mismatches >= miss)
		{
			totalMatches++;
		}
		//reset the segment for future purposes.
		seg = "";
	}
	//if it doesn't find anything.
	if(totalMatches == 0)
		std::cout << "No Match" << std::endl;
}

int main()
{
	//////////////////////////////////////////////INITIALIZING VALUES TO BE PASSED IN FOR THE HASH OBJECT////////////////////////////////
	/////////////////////////////////////////Also used to set up reading values from the file////////////////////////////////////////////
	//default values as described in the HW description
	int tSize = 100;
	float occ = 0.5;
	//no default so just initializing to 0.
	int kmer = 0;
	int error = 0;
	std::string query_string = "";
	std::string temp;
	std::cin >> temp;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	std::string file;
	std::cin >> file;
	std::ifstream inFile(file.c_str());

	//checking if the file isn't valid in that case just get out of the program and repeat the name they gave.
	if(!inFile.good())
		std::cout << file << std::endl;
		return 1;

	std::string streamOfData;
	std::string fileStream;

	//while there is data still available and filtering it appropriately.
	while(inFile >> streamOfData)
		fileStream += streamOfData;
	std::string data;
	std::cin >> data;
	//feeding all of the data in from the genome files for completing assignment.
	if(data == "table_size")
		std::cin >> tSize >> data;
	if(data == "occupancy")
		std::cin >> occ >> data;
	if(data == "kmer")
		std::cin >> kmer >> data;




	//INITIALIZE hash table for usage.
	HashTable use(tSize, file, occ, kmer);
	while(data == "query")
	{
		std::string part = "";
		std::cout << "Query: " << query_string << std::endl;
		for(unsigned int i = 0; i < kmer; i++)
			part += query_string[i];
		//ABOVE IS TO APPEND ALL OF THE INFORMATION FOR MATCHING ANALYSIS.
		//was eventually goign to implement find but couldn't get it. It finds the proper location of the values to compare if it matches.
		std::vector<int> indices = use.find(part);
		//used for finding purposes also for printing out the relevant information as shown in the function above.
		match(indices,file, query_string, error);

		//check if the user quits.
		std::cin >> data;
		if(data == "quit")
			return 0;
		else
			return 1;
	}
}