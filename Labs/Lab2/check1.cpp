// File: check1.cpp

#include <iostream>
#include <vector>
#include <string>

void find_path(unsigned int x, unsigned int y, unsigned int& path_numbers) {
    if (x == 0) {
        if (y == 0) {
            path_numbers++;
        }
        else {
            y--;
            find_path(x,y,path_numbers);
        }
    }
    else if (y == 0) {
        x--;
        find_path(x,y,path_numbers);
    }
    else {
        x--;
        find_path(x,y,path_numbers);
        x++;
        y--;
        find_path(x,y,path_numbers);
    }
    return;
}

int main() {
    unsigned int a;
    unsigned int b;
    unsigned int path_numbers = 0;
    std::cout << "Enter an x: " << std::endl;
    std::cin >> a;
    std::cout << "Enter a y: " << std::endl;
    std::cin >> b;
    find_path(a,b,path_numbers);
    std::cout << path_numbers << std::endl;
}