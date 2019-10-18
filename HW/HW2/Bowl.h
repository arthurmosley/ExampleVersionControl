#ifndef __Bowl_h_
#define __Bowl_h_

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <fstream>

class Bowl{
public:
  Bowl();
  //constructor initialized with the relavent info needed for outputting.
  Bowl(std::string firstN, std::string lastN, std::vector<int> pinHits, std::vector<std::string> tracker);

  //ACCESSORS
  //gets the score of a singular player.
  int getScore();

  //gets the first name of a singular player.
  std::string getFirstName();

  //gets the last name of a singular player.
  std::string getLastName();

  //gets the vector of scores for each singular player.
  std::vector<int> getHits();

  //contains the information on whether each fram contained a spare/strike/other.
  std::vector<std::string> getTracker();

  //custom case
  int getAverage();

  //MODIFIERS

  //Computes the length of the longest name which is used for formatting purposes when printing the scoreboard.
  int longestName(std::vector<std::string> names);

  //keeps track of the score in each frame (2 throws per frame) and finds the cumulative score as it goes through the scoreboard.
  void frameByFrame();

  //calculates the average throw by a bowl object for my creative aspect
  void calcAverage();


  //PRINT HELPER FUNCTIONS
  

  //Printing out the score grid... including names and frame scores.
  std::ostream& outscores(std::ostream &outTxt, int LongNameFormatter) const;

  //overridded the < operator so it worked well with objects.
  bool operator< (const Bowl &player1) const;

private:
  //Representation
  std::string first;
  std::string last;
  std::vector<int> pins;
  int score;
  //tracks the individual scores for special cases (spares/strikes).
  std::vector<std::string> track;
  //keeps track of the individual frame total scores.
  std::vector<int> frameScore;
  double average;

};


#endif
