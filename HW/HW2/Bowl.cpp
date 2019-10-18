#include "Bowl.h"
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <fstream>

Bowl::Bowl(){
  first = "";
  last = "";
  score = 0;
}

Bowl::Bowl(std::string firstN, std::string lastN, std::vector<int> pinHits, std::vector<std::string> tracker){
  first = firstN;
  last = lastN;
  score = 0;
  pins = pinHits;
  track = tracker;
}

int Bowl::getScore(){
  return score;
}

std::string Bowl::getFirstName(){
  return first;
}

std::string Bowl::getLastName(){
  return last;
}

std::vector<int> Bowl::getHits(){
  return pins;
}

std::vector<std::string> Bowl::getTracker(){
  return track;
}

int Bowl::getAverage(){
  return average;
}

void Bowl::frameByFrame(){
  frameScore.clear();
  int counter = 0;
  //curent score
  int temp = 0;
  for(unsigned int i = 0; i < track.size(); i++){
    if(track[i] == "standard"){
      temp += pins[counter] + pins[counter + 1];
      counter += 2;
    }
    else if(track[i] == "spare"){
      temp += pins[counter] + pins[counter + 1] + pins[counter + 2];
      counter += 2;
    }
    else{
      temp += pins[counter] + pins[counter + 1] + pins[counter + 2];
      counter ++;
    }
  frameScore.push_back(temp);
  score = temp;
  }
}

void Bowl::calcAverage(){
  average = (double)score/10.0;
}

std::ostream& Bowl::outscores(std::ostream &outTxt, int LongNameFormatter) const{
  int counter = 0;
  std::string fullName = first + " " + last;
  std::string formatSpaces = std::string((LongNameFormatter - fullName.size()) - 1, ' ');
  //number of dashes after the dashes above the names are printed.
  std::string numDashes = std::string(62, '-');
  //number of dashes over the names.
  std::string numDashesName = std::string(LongNameFormatter + 3, '-');

  outTxt << numDashesName << numDashes << "\n";
  outTxt << "| " << fullName + formatSpaces ;
  for(unsigned int i = 0; i < track.size(); i++){
    if(track[i] == "standard"){
      if(pins[counter] != 0 && pins[counter + 1] != 0){
        outTxt << " | " << pins[counter] << " " << pins[counter + 1];

      }
      else if(pins[counter] == 0 && pins[counter + 1] != 0){
        outTxt << " | " << "-" << " " << pins[counter + 1];

      }
      else if (pins[counter] != 0 && pins[counter + 1] == 0){
        outTxt << " | " << pins[counter] << " " << "-";
      }
      else{
        outTxt << " | " << "-" << " " << "-";
      }
      counter += 2;
    }
  }
  outTxt << "   |" << "\n";
  //outing the cumulative scores from frame to frame (aka the second line of each players stats).
  std::string amountNameSpace = std::string(LongNameFormatter-1, ' ');
  outTxt << "| " << amountNameSpace;


  for(unsigned int i = 0; i < track.size()-1; i++){

    outTxt << " |" << std::setw(4) << frameScore[i];
  }
  outTxt << " |" << std::setw(6) << frameScore[track.size()-1];
  outTxt << " |" << "\n";
  return outTxt;
}


bool Bowl::operator< (const Bowl &player1) const{
  if(last < player1.last){
    return true;
  }
  else if(player1.last < last){
    return false;
  }
  else{
    if(last == player1.last){
      if(first < player1.first){
        return true;
      }
      else if(player1.first < first){
        return false;
      }
    }
  }
  return false;
}
