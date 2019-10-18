#include <iostream>	// library for reading & writing from the console/keyboard
#include <fstream>	// library for reading & writing to files
#include <string> //library for the string object
#include <vector> //used for vectors
#include <sstream>
#include <streambuf>
#include <algorithm>
#include "Bowl.h"

/*reading in the data with one parameter being the text file and the other being a vector of
type Bowl with player names and respective bowling stats*/
void read(const std::string &textIn, std::vector<Bowl> &players){
  std::ifstream inTxt(textIn.c_str());
  //error checking to see if the read-in function can open.
  if (!inTxt){
    std::cerr << "ERROR! Can't open the file, bud." << textIn << std::endl;
    exit(1);
  }
  //used to store the current bowling player's first and last name
  std::string firstName;
  std::string lastName;
  //used to store the current bowling objects hits.
  std::vector<int> pinHits;

  //isSpare  different paths for determining the scores of the players bowling.
  bool first = true;
  //hold the value of the throw previously thrown if it is a spare or a strike.
  int tempLastThrow;

  //tracks each "Box" for special cases.
  std::vector<std::string> tracker;

  //Continue to read in the players in the file until the end of file is reached.
  while (!inTxt.eof()){
    inTxt >> firstName;
    inTxt >> lastName;


    int maxBowls = 20;
    int counter = 0;
    while(counter < maxBowls){

      //scores are initially string type
      int scores;
      inTxt >> scores;

      if(scores == 10 && first){
        tracker.push_back("strike");
      }
      else if(first && scores != 10){
        tempLastThrow = scores;
        first = false;
      }
      else if(first == false && scores + tempLastThrow == 10){
        tracker.push_back("spare");
        first = true;
        tempLastThrow = 0;
      }
      else if (first == false){
        tracker.push_back("standard");
        first = true;
      }

      //Handles when a strike occurs.
      if(scores == 10 && maxBowls > 12){
        maxBowls --;
      }
      if(scores == 10 && maxBowls - counter == 1){
        maxBowls += 2;
      }


      //Checking if the input file may have more than 10 pins knocked down.
      if(scores > 10){
        std::cerr << "ERROR! Can't have more than 10 pins knocked down in a single throw" << std::endl;
        exit(1);
      }

      pinHits.push_back(scores);
      counter ++;
    }
    //A Bowl object declared that stores the current Bowl information from the text file.

    Bowl current(firstName, lastName, pinHits, tracker);
    players.push_back(current);
    tracker.clear();
    pinHits.clear();
    //stores each players vector of scores/throw in a vector so it has the same length as the name vector
  }
  players.pop_back();
}

void printAverages(std::vector<Bowl>& players, int ln, std::ostream &outTxt){
  for (unsigned int i = 0; i < players.size(); i++){
    players[i].calcAverage();
  }
  outTxt << std::endl;

  while (players.size() > 0){
    std::string topName;
    double topAverage = 0.0;
    unsigned int j = 0;

    for (unsigned int i = 0; i < players.size(); i++){
      if (players[i].getAverage() > topAverage){
        topAverage = players[i].getAverage();
        j = i;
        topName = players[i].getFirstName() + " " + players[i].getLastName();
      }
    }
    players.erase(players.begin() + j);
    std::string properSpaces = std::string((ln - topName.size()) + 2, ' ');
    outTxt << topName << properSpaces << std::setw(2) << topAverage << std::endl;
  }
}

int longestName(std::vector<Bowl> &players){
  //dynamic variable that changes if the length of any other name is longer than the first name in the vector.
  unsigned int tempLongest = (players[0].getFirstName() + "  " + players[0].getLastName()).size();
  for(unsigned int i = 0; i < players.size(); i++){
    if((players[i].getFirstName() + "  " + players[i].getLastName()).size() > tempLongest){
      tempLongest = (players[i].getFirstName() + "  " + players[i].getLastName()).size();
      }
    }
    return tempLongest;
}

int main(int argc, char* argv[]){

  std::ifstream inTxt(argv[1]);
  //testing to see if the text file can open and be read. Else, throw error message.
  if(!inTxt){
    std::cerr << "Could not open " << argv[1] << " to read." << std::endl;
    return 1;
  }
  std::vector<Bowl> bowlers;

  read(argv[1], bowlers);

  //Use my modified version of the operator.
  std::sort(bowlers.begin(), bowlers.end());

  //fills up the frames vector
  for(unsigned int i = 0; i < bowlers.size(); i++){
    bowlers[i].frameByFrame();
  }

  //finds the longest name out of everybody.
  int ln = longestName(bowlers);
  //checking if the program can write to a file, outTXT.
  std::ofstream outTxt(argv[2]);
  std::string third(argv[3]);
  std::ofstream custom(argv[4]);
  if(!outTxt){
    std::cerr << "Could not open " << argv[2] << " to write." << std::endl;
    return 1;
  }

  std::string numDashes = std::string(62, '-');
  //number of dashes over the names.
  std::string numDashesName = std::string(ln + 3, '-');

  /***WRITING TO THE OUT FILE***/


  for(unsigned int i = 0; i < bowlers.size(); i++){
    bowlers[i].outscores(outTxt, ln);
  }
  outTxt << numDashesName << numDashes;

  //putting the simple data visualization in the proper location in outTxt.
  outTxt << "\n";
  outTxt << "\n";

  //Orders the second aspect of the expected output in order of their scores.
  std::vector<Bowl> players_ = bowlers;
  while(bowlers.size() > 0){
    std::string topName;
    int topScore = 0;
    unsigned int j = 0;
    for(unsigned int i = 0; i < bowlers.size(); i++){
      if(bowlers[i].getScore() > topScore){
        topScore = bowlers[i].getScore();
        topName = bowlers[i].getFirstName() + " " + bowlers[i].getLastName();
        j = i;
      }
    }
    bowlers.erase(bowlers.begin() + j);
    std::string properSpaces = std::string((ln - topName.size()) + 2, ' ');
    outTxt << topName << properSpaces << std::setw(2) << topScore;
    outTxt << "\n";
  }
  //used to write to the creative file I created.
  if (third == "custom"){
    printAverages(players_, ln, custom);
  }
  return 0;
}
