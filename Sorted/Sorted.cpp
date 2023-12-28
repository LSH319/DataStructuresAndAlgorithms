#include <iostream>
#include <random>

#include "SortAlgorithms.h"

using namespace std;

void printMember(vector<int> arr)
{
    cout << "\n---------------------------------\n";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n---------------------------------\n";
}

int main(int argc, char* argv[])
{
    vector<int> arr;

    std::random_device rd; 
    std::mt19937 mt(rd()); 
    std::uniform_int_distribution<int> dist(0, 99); 
    const int random_vector_size = dist(mt);

    for(int i=0; i<random_vector_size; i++)
    {
        arr.push_back(dist(mt));
    }
    printMember(arr);
    
    SortAlgorithms::bubble_sort(arr);
    printMember(arr);

    shuffle(arr.begin(), arr.end(), mt);
    printMember(arr);

    
    return 0;
}
