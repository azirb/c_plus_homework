#include <iostream>
#include <vector>



int main() {
    std::vector<int> array; 
    int arraySize, input;

    std::cin >> arraySize; 

    for (int i = 0; i < arraySize; ++i) {
        std::cin >> input; 
        array.push_back(input);
    }



    return 0; 
}