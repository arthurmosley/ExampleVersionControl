#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Enter values where the first value is the total number of numbers to be averaged" << endl;
    int length=0;
    cin >> length;
    float sequence[length];
    cout <<length << endl;
    for(unsigned int i=0; i < length; i++){
        cin >> sequence[i];
    }
    for(unsigned int i = 0; i < length; i++)
        cout << sequence[i] << endl;
    float sum=0;
    for (unsigned int i=0; i < length; i++){
        sum = sum + sequence[i];
    }
    float average;
    average = sum/length;
    cout << "The average is:  " << average << "\n";
    float closest;
    closest = fabs(sequence[0]-average);
    int spot;
    for(unsigned int position=0; position < length; position++){
        if (fabs(sequence[position] - average) < closest) {
            closest = fabs(sequence[position] - average);
            spot = position;
        }
    }
    return 0;
}