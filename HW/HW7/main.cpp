#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <cmath> 
#include <vector>
#include <iomanip>
#include <stdlib.h>
#define earthRadiusKm 6371.0

//TODO: You must fill in all ?????? with the correct types.
typedef long ID_TYPE; //Type for user IDs
typedef std::pair<double, double> COORD_TYPE; //Type for a coordinate (latitude and longitude)
typedef std::map<ID_TYPE, std::vector<ID_TYPE> > ADJ_TYPE; //Adjacency Lists type
typedef std::map<ID_TYPE, COORD_TYPE> GEO_TYPE; //Positional "dictionary"

//Function forward declarations. DO NOT CHANGE these. 
double deg2rad(double deg);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);
void loadConnections(ADJ_TYPE& adj_lists, std::ifstream& loadfile);
void loadLocations(GEO_TYPE& locations, std::ifstream& loadfile);
void printAllUsersWithinDistance(const GEO_TYPE& locations, std::ofstream& outfile,
                                 const ID_TYPE& start_id, double max_distance);
void printDegreesHistogram(const ADJ_TYPE& adj_lists, std::ofstream& outfile);
void printDegreesOfAll(const ADJ_TYPE& adj_lists, std::ofstream& outfile);
void printFriendsWithDegree(const ADJ_TYPE& adj_lists, std::ofstream& outfile,
                            const ID_TYPE& start_id, unsigned int degree);
void printFriendsWithinDistance(const ADJ_TYPE& adj_lists, const GEO_TYPE& locations, 
                                std::ofstream& outfile, const ID_TYPE& start_id, 
                                double max_distance);
void printUsersWithinIDRange(std::ofstream& outfile, ADJ_TYPE::const_iterator begin, 
                             ADJ_TYPE::const_iterator end, 
                             ADJ_TYPE::const_iterator start_it, unsigned int offset);


// DO NOT CHANGE THIS FUNCTION
int main(int argc, char** argv){
    ADJ_TYPE adj_lists;
    GEO_TYPE locations;

    if(argc != 3){
        std::cout << "Correct usage is " << argv[0] 
                  << " [commands file] [output file]" << std::endl;
        return -1;
    }

    std::ifstream commands(argv[1]);
    if(!commands){
        std::cerr << "Problem opening " << argv[1] << " for reading!" 
                  << std::endl;
        return -1;
    }

    std::ofstream outfile(argv[2]);
    if(!outfile){
        std::cerr << "Problem opening " << argv[2] << " for writing!" 
                  << std::endl;
        return -1;
    }

    std::string token; //Read the next command
    while(commands >> token){
        if(token == "load-connections"){
            std::string filename;
            commands >> filename;

            std::ifstream loadfile(filename.c_str());
            if(!loadfile){
                std::cerr << "Problem opening " << filename 
                          << " for reading connections." << std::endl;
                return -1;
            }

            loadConnections(adj_lists, loadfile);
        }
        else if(token == "load-locations"){
            std::string filename;
            commands >> filename;

            std::ifstream loadfile(filename.c_str());
            if(!loadfile){
                std::cerr << "Problem opening " << filename 
                          << " for reading locations." << std::endl;
                return -1;
            }

            loadLocations(locations, loadfile);
        }
        else if(token == "print-degrees"){
            printDegreesOfAll(adj_lists, outfile);
        }
        else if(token == "print-degree-histogram"){
            printDegreesHistogram(adj_lists, outfile);
        }
        else if(token == "all-users-within-distance"){
            ID_TYPE start_id;
            double max_distance; //In kilometers
            commands >> start_id >> max_distance;

            printAllUsersWithinDistance(locations, outfile, start_id, 
                                        max_distance);
        }
        else if(token == "friends-within-distance"){
            ID_TYPE start_id;
            double max_distance; //In kilometers
            commands >> start_id >> max_distance;

            printFriendsWithinDistance(adj_lists, locations, outfile, 
                                       start_id, max_distance);
        }
        else if(token == "friends-with-degree"){
            ID_TYPE start_id,degree;
            commands >> start_id >> degree;

            printFriendsWithDegree(adj_lists, outfile, start_id, degree);
        }
        else if(token == "nodes-within-ID-range"){
            ID_TYPE start_id,offset;
            commands >> start_id >> offset;

            printUsersWithinIDRange(outfile, adj_lists.begin(), adj_lists.end(),
                                    adj_lists.find(start_id), offset);
        }
        else{
            std::cerr << "Unknown token \"" << token << "\"" << std::endl;
            return -1;
        }
    }

    return 0;
}




// This function converts decimal degrees to radians
// From https://stackoverflow.com/a/10205532
// DO NOT CHANGE THIS FUNCTION
double deg2rad(double deg) {
  return (deg * M_PI / 180);
}

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * Taken from https://stackoverflow.com/a/10205532
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 * DO NOT CHANGE THIS FUNCTION
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

//////////////////TODO: IMPLEMENT ALL FUNCTIONS BELOW THIS POINT////////////////////

/**
 * Loads a list of connections in the format "a b" meaning b is a friend of a
 * into the adjacency lists data structure. a and b are IDs.
 * @param adj_lists Adjacency lists structure
 * @param loadfile File to read from
 */
void loadConnections(ADJ_TYPE& adj_lists, std::ifstream& loadfile){
  unsigned int tempConnect;
  std::vector<unsigned int> load;
  ID_TYPE tempKey;
  while(loadfile >> tempKey >> tempConnect)
  {
    //adj_lists[tempKey] = 0;
    adj_lists[tempKey].push_back(tempConnect);
  }
}

/**
 * Loads a list of locations in the format "id latitude longitude"
 * @param locations Location lookup table
 * @param loadfile File to read from
 */
void loadLocations(GEO_TYPE& locations, std::ifstream& loadfile){
  //x,y coordinates loaded into pair
  double x;
  double y;
  ID_TYPE tempKey;

  while(loadfile >> tempKey >> x >> y)
  {
    //temporary pair of the x and y coordinates in the txt file.
    COORD_TYPE tempPair = std::make_pair(x,y);
    locations[tempKey] = tempPair;
  }
}

/**
 * Prints all users within a certain distance of a particular user.
 * Sorted from shortest distance to user to longest distance to user.
 * Rounds down to the next lowest km if the difference is a decimal
 * @param locations Location lookup table
 * @param outfile File to write output to
 * @param start_id User we are using as our "origin" (i.e. 0 distance)
 * @param max_distance Maximum distance from start_id that a printed user can be
 */
void printAllUsersWithinDistance(const GEO_TYPE& locations, std::ofstream& outfile,
                                 const ID_TYPE& start_id, double max_distance){
  //holds the distance to compare against max_distance.
  double distance;
  GEO_TYPE::const_iterator p;
  std::map<unsigned int, std::vector<ID_TYPE> > sorted;
  p = locations.find(start_id);

  //counter to see if there are none in order to print accordingly.
  int counter = 0;

  if(p != locations.end())
  {
    //accesses the locations of the original location.
    double startLocationX = p->second.first;
    double startLocationY = p->second.second;
    for(std::map<ID_TYPE, COORD_TYPE>::const_iterator itR = locations.begin(); itR != locations.end(); ++itR)
    {
      //calculating all distances in the for loop in order to change every iteration.
      double endLocationX = itR->second.first;
      double endLocationY = itR->second.second;
      distance = distanceEarth(startLocationX, startLocationY, endLocationX, endLocationY);
      if(distance <= max_distance && distance != 0)
      {
        sorted[distance].push_back(itR->first);
        counter++;
      }
    }
    if(counter > 0)
    {
      outfile << "User IDs within " << max_distance << " km of user " << start_id << ":\n";
      for(std::map<unsigned int, std::vector<ID_TYPE> >::const_iterator it = sorted.begin(); it != sorted.end(); ++it)
      {
        outfile << " " << it->first << " km: ";
        for(unsigned int i = 0; i < it->second.size(); i++)
          {
            outfile << it->second[i];
            if (i != it->second.size()-1)
            {
              outfile << " ";
            }
          }
        outfile << std::endl;
      }
    }
    else
      outfile << "There are no users within " << max_distance << " km of user " << start_id << std::endl;
  }
  else
    outfile << "User ID " << start_id << " does not have a recorded location." << std::endl;
}

/**
 * Prints a sorted list of degrees (smallest to largest) along with how many users
 * have that degree. Only prints for degree >=1.
 * @param adj_lists Adjacency lists structure
 * @param outfile File to write output to
 */

//DONEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

void printDegreesHistogram(const ADJ_TYPE& adj_lists, std::ofstream& outfile){
  //have to iterate through adj_lists to find the size of the vector for each person.
  
  int userCounter = 0;
  //count the number of unique users
  for(ADJ_TYPE::const_iterator it = adj_lists.begin(); it != adj_lists.end(); ++it)
  {
    userCounter++;
  }

  outfile << "Histogram for " << userCounter << " users:\n";

  //Counts the number of occurrences of each degree.
  std::map<unsigned int, unsigned int> countOccurences;
  for(ADJ_TYPE::const_iterator it = adj_lists.begin(); it != adj_lists.end(); ++it)
      countOccurences[it->second.size()]++;

  //printing the histogram details.
  for(std::map<unsigned int, unsigned int>::const_iterator it = countOccurences.begin(); it != countOccurences.end(); ++it)
  {
    outfile << " Degree " << it->first << ": " << it->second << "\n";
  }
  outfile.close();

}

/**
 * Prints a sorted list of user IDs (smallest to largest) along with the degree for
 * each user. Only prints for degree >=1.
 * @param adj_lists Adjacency lists structure
 * @param outfile File to write output to
 */
void printDegreesOfAll(const ADJ_TYPE& adj_lists, std::ofstream& outfile){

  int userCounter = 0;
  //count the number of unique users
  for(std::map<ID_TYPE, std::vector<ID_TYPE> >::const_iterator it = adj_lists.begin(); it != adj_lists.end(); ++it)
  {
    userCounter++;
  }
  outfile << "Degrees for " << userCounter << " users:\n";

  for(std::map<ID_TYPE, std::vector<ID_TYPE> >::const_iterator it = adj_lists.begin(); it != adj_lists.end(); ++it)
    outfile << " " << it->first << ": Degree " << it->second.size() << "\n";
}

/**
 * Prints all friends of a particular user who have a particular degree.
 * Sorted by user ID (from smallest to largest).
 * @param adj_lists Adjacency lists structure
 * @param outfile File to write output to
 * @param start_id User whose friends we are looking at
 * @param degree The degree of friends we want to print. Will be >=1.
 */
void printFriendsWithDegree(const ADJ_TYPE& adj_lists, std::ofstream& outfile,
                            const ID_TYPE& start_id, unsigned int degree){


  std::vector<ID_TYPE> counter;

  ADJ_TYPE::const_iterator p = adj_lists.find(start_id);
  if(p != adj_lists.end())
  {
    for(unsigned int i = 0; i < p->second.size(); i++)
    {
      //current friend I'm looking at
      ID_TYPE current = p->second[i];
      ADJ_TYPE::const_iterator itR = adj_lists.find(current);
      if(degree == itR->second.size())
        counter.push_back(itR->first);
    }
    if(counter.size() > 0)
    {
      outfile << "User " << start_id << " has " << counter.size() << " friend(s) with degree " << degree << ": "; 
      for(unsigned int i = 0; i < counter.size(); i++)
      {  
        outfile << counter[i];
        if (i != counter.size()-1)
        {
          outfile << " ";
        }
      }
      outfile << std::endl;
    }
    else if(counter.size() == 0)
      outfile << "User " << start_id << " has " << counter.size() << " friend(s) with degree " << degree << std::endl;
  }
  else
    outfile << "There is no user with friends and ID " << start_id << std::endl;
}

/**
 * Prints friends of a particular user within a certain distance of that user.
 * Sorted from shortest distance to user to longest distance to user.
 * @param adj_lists Adjacency lists structure
 * @param locations Location lookup table
 * @param outfile File to write output to
 * @param start_id User we are using as our "origin" (i.e. 0 distance)
 * @param max_distance Maximum distance from start_id that a printed user can be
 */
void printFriendsWithinDistance(const ADJ_TYPE& adj_lists, const GEO_TYPE& locations, 
                                std::ofstream& outfile, const ID_TYPE& start_id, 
                                double max_distance){
  double distance;
  //used for finding the coordinates
  GEO_TYPE::const_iterator p;
  std::map<double, ID_TYPE> sorted;
  p = locations.find(start_id);

  //used for finding friends
  ADJ_TYPE::const_iterator f;
  f = adj_lists.find(start_id);

  //counter to see if there are none in order to print accordingly.
  int counter = 0;
  if(p == locations.end() && f != adj_lists.end())
  {
    outfile << "User ID " << start_id << " does not have a recorded location." << std::endl;
    return;
  }

  if(f == adj_lists.end() || f->second.size() == 0)
  {
    outfile << "There is no user with friends and ID " << start_id << std::endl;
    return;
  }

  //accesses the locations of the original location.
  double startLocationX = p->second.first;
  double startLocationY = p->second.second;
  GEO_TYPE::const_iterator it;

  for(unsigned int i = 0; i < f->second.size(); ++i)
  {
    it = locations.find(f->second[i]);
    //calculating all distances in the for loop in order to change every iteration.
    double endLocationX = it->second.first;
    double endLocationY = it->second.second;

    distance = distanceEarth(startLocationX, startLocationY, endLocationX, endLocationY);
    if(distance <= max_distance && distance != 0)
    {
      sorted[distance] = it->first;
      counter++;
    }
  }
  if(counter > 0)
  {
    outfile << "Friends within " << int(max_distance) << " km of user " << start_id << ":\n";
    for(std::map<double, ID_TYPE>::const_iterator itR = sorted.begin(); itR != sorted.end(); ++itR)
    {
      outfile << " " << itR->first << " km: " << itR->second << "\n";
    }
  }
  else
    outfile << "There are no friends within " << max_distance << " km of user " << start_id << std::endl; 
}

/**
 * Prints users with an ID that is "close" to a particular user's ID.
 * Sorted from smallest to largest user ID.
 * Only prints for degree >=1.
 *
 * If there are M IDs that should be printed this function should only use
 * ADJ_TYPE::const_iterator::operator++ / ADJ_TYPE::const_iterator::operator-- O(M) times
 *
 * @param outfile File to write output to
 * @param begin The .begin() iterator for the adjacency lists structure
 * @param end The .end() iterator for the adjacency lists structure
 * @param start_it Iterator for user we are using as our baseline (i.e. 0 diifference)
 *        It is possible that the start_it was not found in the data.
 * @param offset Maximum absolute difference from start_id that a printed user's
 *               ID can have
 */
void printUsersWithinIDRange(std::ofstream& outfile, ADJ_TYPE::const_iterator begin, 
                             ADJ_TYPE::const_iterator end, 
                             ADJ_TYPE::const_iterator start_it, unsigned int offset){
  //holds the ID's that are within the bounds
  std::vector<ID_TYPE> counter;
  if(start_it != end)
  {
    for(ADJ_TYPE::const_iterator it = begin; it != end; it++)
    {
      if (it == start_it)
        continue;
      //check if it is within the bounds given by offset
      if(start_it->first >= it->first - offset && start_it->first <= it->first + offset)  
      {
        counter.push_back(it->first);
      }
    }

    if(counter.size() != 0)
    {
      outfile << "Users with an ID within +/-" << offset << " of " << start_it->first << ": ";
      for(unsigned int i = 0; i < counter.size(); i++)
        {
          outfile << counter[i];
          if (i != counter.size()-1)
          {
            outfile << " ";
          }
        }
      outfile << std::endl;
    }
    else
      outfile << "There are no users with an ID within +/-" << offset << " of " << start_it->first << std::endl; 
  }
  else
    outfile << "There is no user with the requested ID" << std::endl;
}
