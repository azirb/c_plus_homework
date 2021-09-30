#include <iostream>
#include <algorithm>
#include <vector>

bool checkgreaternumber(std::vector<int> array, int number, int index) {
    std::vector<int> copiedarray;
    copiedarray = std::vector<int>(array.begin() + index, array.end());
    for (long unsigned int i = 0; i < copiedarray.size(); ++i) {
        if (copiedarray[i] < number) {
            return true;
        }
    }
    return false;
}

int min(std::vector<int> array, long unsigned int index, int number) {
    int result = array[index];
    for (long unsigned int i = index; i < array.size(); ++i) {
        if (array[i] < result && number != array[i]) {
            result = array[i];
        }
    }
    return result;
}

int findmingreaternumber(long unsigned int start_index,
                         std::vector<int> result,
                         std::vector<int> array) {
    int last_number = result.back();
    for (long unsigned int i = start_index - 1; i < array.size(); ++i) {
        if (last_number < array[i] &&
            array[i] == min(array, start_index, last_number)) {
            return array[i];
        }
    }
    return -1;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    int arraysize, inputvalue;
    int rem_index = 0;

    std::cin >> arraysize;

    std::vector<int> array, result;

    for (int i = 0; i < arraysize; ++i) {
        std::cin >> inputvalue;
        array.push_back(inputvalue);
    }

    if (arraysize == 1) {
        result.push_back(array[0]);
        goto final;
    }

    if (arraysize == 0) {
        goto final;
    }

    for (long unsigned int index = 0; index < array.size(); ++index) {
        if (index == 0) {
            result.push_back(array[index]);
            continue;
        }
        if (result.size() <= 1 && result.back() != array[index]) {
            result.push_back(array[index]);
            continue;
        }
        if (result.back() > result[result.size() - 2] && array[index] != result.back()) {
            if (array[index] < result.back()) {
                result.push_back(array[index]);
            }
        } else {
            if (checkgreaternumber(array, array[index], index) && array[index] > result.back()) {
                result.push_back(array[index]);
                rem_index = 0;
            } else {
                if (rem_index == 0) {
                    rem_index = index;
                }
            }
            if (rem_index != 0 && index == array.size() - 1) {
                int insert_value = findmingreaternumber(rem_index, result, array);
                if (insert_value != -1) {
                    result.push_back(insert_value);
                }
            }
        }
    }

    final:
    if (result.size() == 0) {
        std::cout << "";
        array.clear();
        result.clear();
        return 0;
    }


    if (result.size() == 1) {
        for (long unsigned int i = 0; i < result.size(); ++i) {
            std::cout << result[i] << " ";
        }
        array.clear();
        result.clear();
        return 0;
    }

    for (long unsigned int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }

    array.clear();
    result.clear();
    return 0;
}
