#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>

inline bool isRight(char bracket) {
    return (')' == bracket || '}' == bracket || ']' == bracket);
}

inline bool LeftBracket(char bracket) {
    return ('(' == bracket || '{' == bracket || '[' == bracket);
}

inline bool Fit(char lb, char rb) {
    return ('(' == lb && ')' == rb) || ('[' == lb && ']' == rb) || ('{' == lb && '}' == rb);
}

static std::string trim(std::string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

int main() {
    std::string input, str;
    std::getline(std::cin, input);
    str = trim(input);
    std::stack<char> stack;
    std::vector<char> memory;
    if (isRight(str[0])) {
        std::cout << "0" << std::endl;
        return 0;
    }
    for (std::string::const_iterator it(str.begin()), itEnd(str.end()); it != itEnd; ++it) {
        if (std::isspace(*it)) {
            continue;
        }
        if (LeftBracket(*it)) {
            stack.push(*it);
            memory.push_back(*it);
        } else if (!stack.empty() && Fit(stack.top(), *it)) {
            stack.pop();
            memory.push_back(*it);
        } else {
            stack.push(*it);
            break;
        }
    }

    if (stack.empty()) {
        std::cout << "CORRECT" << std::endl;
        return 0;
    } else {
        std::cout << memory.size() << std::endl;
    }

    return 0;
}
