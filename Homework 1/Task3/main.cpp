#include <iostream>
#include <vector>
#include <algorithm>

int findMinIndex(std::vector<int> arrayA, std::vector<int> arrayB) {

    std::vector<int> result;
    int min = result[0];
    long unsigned int minIndex = 0;
    for (long unsigned int i = 0; i < arrayA.size(); ++i) {
        result.push_back(std::max(arrayA[i], arrayB[i]));
        if (result[i] < min) {
            min = result[i];
            minIndex = i + 1;
        }
    }
    return static_cast<int>(minIndex);
}

int main() {

    std::vector<std::vector<int>> arrayOfAArrays, arrayOfBArrays;
    std::vector<int> tempArray;
    std::vector<int> command;
    std::vector<std::vector<int>> stackArray;
    int arrayACount, arrayBCount, arraySize, requestsCount, input;
    std::cin >> arrayACount >> arrayBCount >> arraySize;

    for (int index = 0; index < arrayACount + arrayBCount; ++index) {
        for (int subIndex = 0; subIndex < arraySize; ++subIndex) {
            std::cin >> input;
            tempArray.push_back(input);
        }
        if (index >= arrayACount) {
            arrayOfBArrays.push_back(tempArray);
        } else {
            arrayOfAArrays.push_back(tempArray);
        }
        tempArray.clear();
    }

    std::cin >> requestsCount;

    for (int i = 0; i < requestsCount; ++i) {
        std::cin >> input;
        command.push_back(input - 1);
        std::cin >> input;
        command.push_back(input - 1);
        stackArray.push_back(command);
        command.clear();
    }

    for (long unsigned int index = 0; index < stackArray.size(); ++index) {
        std::cout << findMinIndex(arrayOfAArrays[stackArray[index][0]],
                                  arrayOfBArrays[stackArray[index][1]]) << std::endl;
    }

    return 0;
}
