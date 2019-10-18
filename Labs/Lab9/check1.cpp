#include <fstream>
#include <map>
#include <vector>
#include <iostream>

int main(int argc, char* argv[])
{
    std::ifstream in_str(argv[1]);
    if (!in_str.good())
    {
        std::cerr << "Can't open " << argv[1] << " to read.\n";
        return 1;
    }

    std::map<int, unsigned int> modes;
    int input;
    std::map<int, unsigned int>::iterator itr;

    while(in_str >> input)
        ++modes[input];

    int numModes = 0;;
    for(itr = modes.begin(); itr != modes.end(); ++itr)
    {
        std::cout << itr->first << " " <<std::cout << itr->second << std::endl;
        if(itr-> second> numModes)
            numModes = itr->second;
    }

    for(itr = modes.begin(); itr!= modes.end(); ++itr)
    {
        if(itr->second == numModes)
            std::cout << itr->first <<std::endl;

    }
}