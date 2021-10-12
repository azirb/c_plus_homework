#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::vector<int>> arrayOfAArrays, arrayOfBArrays;
    std::vector<int> tempArray;
    std::vector<int> commandA, commandB;
    int arrayACount, arrayBCount, arraySize, requestsCount, input, fst_arr, scd_arr, minIndex;
    std::cin >> arrayACount >> arrayBCount >> arraySize;

    for (int index = 0; index < arrayACount; ++index) {
        for (int subIndex = 0; subIndex < arraySize; ++subIndex) {
            std::cin >> input;
            tempArray.push_back(input);
        }
        arrayOfAArrays.push_back(tempArray);
        tempArray.clear();
    }

    for (int index = 0; index < arrayBCount; ++index) {
        for (int subIndex = 0; subIndex < arraySize; ++subIndex) {
            std::cin >> input;
            tempArray.push_back(input);
        }
        arrayOfBArrays.push_back(tempArray);
        tempArray.clear();
    }

    std::cin >> requestsCount;

    for (int i = 0; i < requestsCount; ++i) {
        std::cin >> input;
        commandA.push_back(input - 1);
        std::cin >> input;
        commandB.push_back(input - 1);
    }

    tempArray.clear();

    for (int index = 0; index < requestsCount; ++index) {
        fst_arr = commandA[index];
        scd_arr = commandB[index];
        minIndex = arraySize / 2;

        if (arrayOfAArrays[fst_arr][minIndex] > arrayOfBArrays[scd_arr][minIndex]) {
            while (minIndex > 0 &&
                   (arrayOfAArrays[fst_arr][minIndex] > arrayOfBArrays[scd_arr][minIndex - 1])) {
                minIndex--;
            }
        } else if (arrayOfAArrays[fst_arr][minIndex] < arrayOfBArrays[scd_arr][minIndex]) {
            while ((minIndex < arraySize - 1) &&
                   (arrayOfAArrays[fst_arr][minIndex + 1] < arrayOfBArrays[scd_arr][minIndex])) {
                minIndex++;
            }
        }
        tempArray.push_back(minIndex + 1);
    }

    for (int i: tempArray) {
        std::cout << i << std::endl;
    }

    return 0;
}
