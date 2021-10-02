#include <iostream>
#include <algorithm>
#include <vector>

bool checkgreaternumber(std::vector<int> array, int number, long unsigned int index) {
    std::vector<int> copiedarray;
    copiedarray = std::vector<int>(array.begin() + index, array.end());
    for (long unsigned int i = 0; i < copiedarray.size(); ++i) {
        if (copiedarray[i] < number) {
            return true;
        }
    }
    return false;
}

int fmin(std::vector<int> array, long unsigned int index, int number) {
    int result = array[index];
    for (long unsigned int i = index; i < array.size(); ++i) {
        if (array[i] < result && number != array[i]) {
            result = array[i];
        }
    }
    return result;
}

int min(std::vector<int> array, long unsigned int index, int number) {
    int result = array[index];
    for (long unsigned int i = index; i < array.size(); ++i) {
        if (array[i] < result && number != array[i]) {
            return array[i];
        }
    }
    return result;
}

long unsigned int getIndex(std::vector<int> array, int value) {
    auto it = find(array.begin(), array.end(), value);
    if (it != array.end()) {
        long unsigned int index = it - array.begin();
        return index;
    }
    return 1;
}

int findmingreaternumber(long unsigned int start_index,
                         std::vector<int> result,
                         std::vector<int> array) {
    int last_number = result.back();
    for (long unsigned int i = start_index - 1; i < array.size(); ++i) {
        if (last_number < array[i] &&
            array[i] == min(array, i, last_number)) {
            return array[i];
        }
    }
    return -1;
}

std::vector<int> solve(std::vector<int> array,
                       std::vector<int> answer,
                       long unsigned int start_index) {
    long unsigned int rem_index = 0;
    long unsigned int rem_low_index = 0;
    std::vector<int> result;
    std::vector<int> answ = answer;
    result.clear();
    for (long unsigned int i = 0; i < start_index; ++i) {
        result.push_back(answ[i]);
    }
    if (result.size() > array.size() - start_index) {
        return answ;
    }
    long unsigned int calc_index =
            start_index >= getIndex(array, result.back()) ?
            start_index : getIndex(array, result.back()) + 1;
    for (long unsigned int sub_index = calc_index; sub_index < array.size(); ++sub_index) {
        result.push_back(array[sub_index]);
        for (long unsigned int index = sub_index + 1; index < array.size(); ++index) {
            if (result.back() > result[result.size() - 2]) {
                if (array[index] < result.back() && checkgreaternumber(array,array[index],index)) {
                    result.push_back(fmin(array,index,result.back()));
                    rem_low_index = 0;
                } else {
                    if (rem_low_index == 0) {
                        rem_low_index = index;
                    }
                    if (rem_low_index != 0 && index == array.size() - 1) {
                        int insert_value = fmin(array,rem_low_index,result.back());
                        if (insert_value != -1) {
                            result.push_back(insert_value);
                        }
                    }
                }
            } else {
                if (checkgreaternumber(array, array[index], index)
                && array[index] > result.back()) {
                    result.push_back(array[index]);
                    rem_index = 0;
                } else {
                    if (rem_index == 0) {
                        rem_index = index;
                    }
                    if (rem_index != 0 && index == array.size() - 1) {
                        int insert_value = findmingreaternumber(rem_index, result, array);
                        if (insert_value != -1) {
                            result.push_back(insert_value);
                        }
                    }
                }
            }
        }
        if (result.size() > answ.size()) {
            answ = result;
        }
        result.erase(std::next(result.begin(), start_index), std::end(result));
        rem_index = 0;
    }
    return answ;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    int arraysize, inputvalue;
    int flag = 0;

    std::cin >> arraysize;

    std::vector<int> array, answer_array;

    for (int i = 0; i < arraysize; ++i) {
        std::cin >> inputvalue;
        array.push_back(inputvalue);
    }

    if (arraysize == 1) {
        answer_array.push_back(array[0]);
        goto final;
    }

    if (arraysize == 0) {
        goto final;
    }

    answer_array.push_back(array[0]);

    for (long unsigned int index = 1; index < array.size(); ++index) {
        std::vector<int> returned_array = solve(array, answer_array, index);
        if (returned_array.size() > answer_array.size()) {
            answer_array = returned_array;
        }
        if (returned_array.size() == answer_array.size()) {
            flag = 0;
            for (long unsigned int j = 0; j < answer_array.size(); ++j) {
                if (returned_array[j] <= answer_array[j]) {
                    continue;
                } else {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                answer_array = returned_array;
            }
        }
    }


    final:
    if (answer_array.empty()) {
        std::cout << "";
        array.clear();
        answer_array.clear();
        return 0;
    }


    if (answer_array.size() == 1) {
        for (long unsigned int i = 0; i < answer_array.size(); ++i) {
            std::cout << answer_array[i] << " ";
        }
        array.clear();
        answer_array.clear();
        return 0;
    }

    for (long unsigned int i = 0; i < answer_array.size(); ++i) {
        std::cout << answer_array[i] << " ";
    }

    array.clear();
    answer_array.clear();
    return 0;
}
