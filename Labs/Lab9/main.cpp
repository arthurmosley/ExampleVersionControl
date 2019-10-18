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

    while (in_str >> input)
    {
        itr = modes.find(input);
        if (itr == modes.end())
        {
            modes.insert(std::make_pair(input, 1));
        }
        else
        {
            itr->second++;
        }
    }
    std::map<int, unsigned int>::const_iterator itr2;
    std::vector<int> maxes;
    int max = 0;

    for (itr2 = modes.begin(); itr2 != modes.end(); itr2++)
    {
        if (itr2->second > max)
        {
            max = itr2->second;
        }
    }

    for (itr2 = modes.begin(); itr2 != modes.end(); itr2++)
    {
        if (itr2->second == max)
        {
            maxes.push_back(itr2->first);
        }
    }

    for (unsigned int i = 0; i < maxes.size(); i++)
    {
        std::cout << maxes[i] << std::endl;
    }
}