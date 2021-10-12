#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>


long double countLength(double dotx, double ox, double oy) {
    double fstNumber = ox * ox - 2 * ox * dotx + dotx * dotx;
    double sndNumber = oy * oy;
    double tempNumber = fstNumber + sndNumber;
    return sqrt(tempNumber);
}

long double minLength(std::vector<std::vector<int>> dotsArray,
                      long unsigned int count,
                      double max,
                      double min,
                      int dotsCount) {
    double point = 0;
    long double length;
    int flag;
    std::vector<long double> result;
    for (double dots = min; dots <= max; dots = dots + 0.1) {
        // первый цикл определяющий точку примерно
        std::vector<long double> tempArray;
        flag = 1;
        for (int index = 0; index < dotsCount; ++index) {
            if (dots == min) { // первый инпут закидываем дабы с ним сравнивать
                result.push_back(
                        countLength(dots,
                                    static_cast<double>(dotsArray[index][0]),
                                    static_cast<double>(dotsArray[index][1])));
                continue;
            }
            length = countLength(
                    dots,
                    static_cast<double>(dotsArray[index][0]),
                    static_cast<double>(dotsArray[index][1]));
            if (result[count] > length) {
                flag = 0; // флаг откидывает совсем экстремальные значения
            }
            tempArray.push_back(length);
        }
        if (dots == min) {
            point = dots;
            sort(result.begin(), result.end());
            continue;
        }
        if (flag == 1) {
            continue;
        }
        sort(tempArray.begin(), tempArray.end()); // сортируем дабы получить радиусы по порядку
        if (result[count] >
            tempArray[count]) { // если в новом массиве радиус по счету нужной точки меньше
            // значит это новый минимальный радиус
            point = dots; // запоминаем точку которую потом рассматривать будем более подробно
            result = tempArray;
            // идея в том что по счету нужный радиус будет вклучать все предыдущие точки,
            // тем самым мы будем получать минимальный радиус покрывающий count точек
        }
    }
    for (double dot = point - 0.8;
         dot <= point + 0.8; dot = dot + 0.01) { // делаем все тоже самое но уточняем значение,
        std::vector<long double> tempArray; // например из цикла выше у нас вышло 2.6 а релаьное
        // значение должно быть до 10е-3 поэтому проходимся в определенной бласти
        flag = 1;
        for (int index = 0; index < dotsCount; ++index) {
            length = countLength(
                    dot,
                    static_cast<double>(dotsArray[index][0]),
                    static_cast<double>(dotsArray[index][1]));
            if (result[count] > length) {
                flag = 0;
            }
            tempArray.push_back(length);
        }
        if (flag == 1) {
            continue;
        }
        sort(tempArray.begin(), tempArray.end());
        if (result[count] > tempArray[count]) {
            result = tempArray;
        }
    }
    return result[count];
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(6);
    std::vector<std::vector<int>> dots;
    long unsigned int countInside;
    int dotsCount, inputx, inputy;
    double max = 0;
    double min = 1000;

    std::cin >> dotsCount >> countInside;

    if (dotsCount == 0 || countInside == 0) {
        std::cout << "0";
        return 0;
    }

    for (int index = 0; index < dotsCount; ++index) {
        std::vector<int> tempArray;
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
    }

    std::cout << minLength(dots, countInside - 1, max, min, dotsCount);

    return 0;
}
