#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>


double countLength(int dotx, int ox, int oy) {
    return sqrt(pow((ox - dotx), 2) + pow(oy, 2));
}

double minLength(std::vector<std::vector<int>> dotsArray,
                 long unsigned int count,
                 int max,
                 int min) {

    std::vector<double> tempArray, result;
    for (int dots = min; dots <= max; ++dots) {
        for (long unsigned int index = 0; index < dotsArray.size(); ++index) {
            if (dots == min) {
                result.push_back(countLength(dots, dotsArray[index][0], dotsArray[index][1]));
                continue;
            }
            tempArray.push_back(countLength(dots, dotsArray[index][0], dotsArray[index][1]));
        }
        if (dots == min) {
            sort(result.begin(), result.end());
            continue;
        }
        sort(tempArray.begin(), tempArray.end());
        if (result[count] > tempArray[count]) {
            result = tempArray;
        }
        tempArray.clear();
    }
    return result[count];
}


int main() {
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(6);

    std::vector<int> tempArray, duplicateCheck;
    std::vector<std::vector<int>> dots;
    long unsigned int countInside;
    int dotsCount, inputx, inputy;
    int max = 0;
    int min = 1000;

    std::cin >> dotsCount >> countInside;

    for (int index = 0; index < dotsCount; ++index) {
        std::cin >> inputx;
        std::cin >> inputy;
        if (inputx > max) {
            max = inputx;
        }
        if (inputx < min) {
            min = inputx;
        }
        tempArray.push_back(inputx);
        tempArray.push_back(inputy);
        dots.push_back(tempArray);
        tempArray.clear();
    }

    sort(dots.begin(), dots.end());
    dots.erase(std::unique(dots.begin(), dots.end()), dots.end());

    std::cout << minLength(dots, countInside - 1, max, min);

    return 0;
}
