#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {

    std::vector<int> array;
    long unsigned int arraySize, left, right, maxIndex = 0;
    char input;
    int elemInput, commandCount, max = 0;

    std::cin >> arraySize;

    for (long unsigned int i = 0; i < arraySize; ++i) {
        std::cin >> elemInput;
        array.push_back(elemInput);
    }

    std::cin >> commandCount;

    left = 0;
    right = 0;    
    if (array[0] > array[1]) {
        max = array[0]; 
        maxIndex = 0; 
    } else {
        max = array[1]; 
        maxIndex = 1; 
    }

    for (int index = 0; index < commandCount; ++index) {
        std::cin >> input;
        if (input == 'R') {
            right++;
            if (left == right) {
                maxIndex = left;
                max = array[maxIndex];
                continue; 
            }
            if (maxIndex >= left) {
                if (array[right] > max) {
                    max = array[right];
                    maxIndex = right;
                }
            } else {
                maxIndex = *std::max(array.begin() + left, array.begin() + right);
                max = array[maxIndex];
            }
        } else {
            left++;  
            if (left == right) {
                maxIndex = left;
                max = array[maxIndex];
                continue;
            }
            if (maxIndex < left) {
                maxIndex = *std::max(array.begin() + left, array.begin() + right);
                max = array[maxIndex];
            }
        }
        std::cout << max << " ";
    }

    return 0;
}
