#include <fstream>    // file stream library
#include <cstdlib>    // library with the exit function
#include <iostream>   // library for reading & writing from the console/keyboard
#include <string> //Library for the string object
#include <vector> //Used for the vector object
#include <fstream> //Used for ifsteam
#include <algorithm> //used for replace function

std::vector<std::vector<std::string> > newLine (unsigned int width, std::vector<std::string> words) { //makes a new line for future words to go on
  std::vector<std::string> wordsInLine;
  unsigned int numChar = 0;
  std::vector<std::vector<std::string> > lines;
  for(unsigned int i = 0; i < words.size(); i++){ //for loop to add words to a line if there is enough space.

    if(numChar + words[i].size() > width){
      lines.push_back(wordsInLine);
      wordsInLine.clear();
      numChar = 0;
    }
    wordsInLine.push_back(words[i]);
    numChar += words[i].size() + 1;
  }
  lines.push_back(wordsInLine);
  return lines;
}

std::string& new_lines(std::string &s){ //Attemping to fix the new line error
  while(s.find("\\n") != std::string::npos){
    s.replace(s.begin(), s.end(), "\\n", ' ');
  }
  return s;
}
//Organzing the text into a vector of vectors
std::vector<std::string> getWords(std::string txtfile, bool isFullJ, int width){ //gets the input words into a vector
  std::ifstream file(txtfile.c_str());

  std::string line;
  std::string str;
  std::vector<std::string> words;
  std::string word = "";

  while(getline(file, line)){
    str += line;
  }

  str = new_lines(str);

  for(unsigned int i = 0; i < str.size(); i++){
    if (str[i] == ' '){
      words.push_back(word);
      word = "";
    }else{
      word += str[i];
    }
  }
  if (word.size() != 0){
    std::string temp = word;
    while(isFullJ && temp.size() > width){ // my attemp at multi line text
      words.push_back(temp.substr(0, width-1) + "-");
      temp = temp.substr(width-1);
    }
    words.push_back(temp);
  }
  return words;
}

std::string leftJustify(std::vector<std::string> words, int width){
  std::string line; //variable returned
  std::string space = " ";
  for(unsigned int i = 0; i < words.size(); i++){
    line += words[i] + space;

  }
  int remaining = width - line.size();

  while (remaining > 0){ //fill in the rest of the line with spaces.
    line += space;
    remaining --;
  }



  if(line.size() > width){
    line = line.substr(0, width);
  }
  if(line.size() != width){
    for(unsigned int i = 0; i < (width) - line.size(); i++){
      line += space;
    }
  }
  return line;
  }

std::string rightJustify(std::vector<std::string> words, int width){
  std::string line; //variable returned
  std::string space = " "; // adding space to the words that are appended to the string, line.
  int numSpace = 0;
  std::string espace; //spaces I'll need before the words

  for(unsigned int i = 0; i < words.size(); i++){
    line += space + words[i];
  }
  numSpace += words.size() - 1;
  int remaining = width - line.size();
  while (remaining > 0){ //fill in the rest of the line with spaces.
    espace += space;
    remaining --;
  }
  if(line.size() > width){
    line = line.substr(1, width);
  }
  return espace + line;
  }

std::string fullJustify(std::vector<std::string> words, int width){
  if(words.size() == 1){
    return leftJustify(words, width); //just in case there is a single word on a line, it needs to left justify
  }
  std::string line;
  std::string espace;
  std::string space = "";
  unsigned int wordlenCount = 0;
  unsigned int remain = 0;
  unsigned int numSpace = 0;
  unsigned int fullspace = 0;
  unsigned int extra = 0; //spaces that were not distributed evenly among the words.

  for(unsigned int i = 0; i < words.size(); i++){
    wordlenCount += words[i].size();
  }
  remain = width - wordlenCount;
  numSpace += words.size()-1;
  fullspace = remain/numSpace;
  extra = remain%numSpace;


  for(unsigned int i = 0; i < fullspace; i++){
    space += " ";
  }

  for(unsigned int i =0; i < words.size(); i++){
    line += words[i] + space;
    if(extra != 0){
      line += " ";
      extra --;
    }
  }
  return line.substr(0,line.size()-space.size());
}

int main(int argc, char* argv[]){
  int width;
  std::ofstream output;
  std::string inputWords = argv[1];
  output.open(argv[2]);
  width = atoi(argv[3]); //Converts a string to an integer (converting the input width (given as string))
  std::string flushStyle = argv[4];

  for(unsigned int i = 0; i < width + 4; i++){
    output << "-"; //printed at the beginning of the text statements
  }
  output << "\n";

  std::vector<std::vector<std::string> > lines = newLine(width, getWords(inputWords, flushStyle.compare("full_justify"),width));

  for(unsigned int i = 0; i < lines.size(); i++){
    if(flushStyle.compare("flush_left") == 0){
      output << "| " << leftJustify(lines[i], width) << " |" << std::endl; //following three outputs are the formatted lines that are printed properly
    }else if(flushStyle.compare("flush_right") == 0){
      output << "| " << rightJustify(lines[i], width) << " |" << std::endl;
    }else{
      output << "| " << fullJustify(lines[i], width) << " |" << std::endl;
      }
    }
  for(unsigned int i = 0; i < width + 4; i++){
    output << "-"; //printed at the end of the text statements
  }
  return 0;
}
