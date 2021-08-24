#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
 * 451.    Символы подряд. Дана строка произвольной длины.
 *
 * В программу вводится целое число n.
 * Определите, есть ли в данной строке n, идущих подряд, одинаковых символа.
 * Если есть выведите 1, иначе 0. Оформите программу в функцию nInRow.
 *
 * Примеры
 *    входные данные 3  “a bbb cd” - выходные данные - 1
 *    входные данные 4  “ab cdddd” - выходные данные - 1
 *    входные данные 4  “a bcddd”  - выходные данные - 0
 *    входные данные 2  “aabc ddd” - выходные данные - 1
 * */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
void print_vector(const vector<T> &vect);

bool symbols_in_raw(string str, int n) {
    char prev_char = str[0];
    int counter = 1;

    for (int i = 1; i < str.size(); ++i) {
        char current_char = str[i];
        if (current_char == prev_char) {
            counter++;
            if(counter == n) return true;
            prev_char = current_char;
        } else {
            counter = 1;
            prev_char = current_char;
        }
    }

    return false;
}

void check_3() {
    vector<int> num_in_raw = {3, 4, 4, 2};
    vector<string> input_strs = {"a bbb cd", "ab cdddd", "a bcddd", "aabc ddd"};


    for (int i = 0; i < num_in_raw.size(); ++i) {
        auto v = symbols_in_raw(input_strs[i], num_in_raw[i]);
        cout << v << ", ";
    }

    cout << endl;
    cout << "Should be" << endl;
    cout << "1, 1, 0, 1" << endl;
}

int main() {
    check_3();
}

template<typename T>
void print_vector(const vector<T> &vect) {
    for (auto item : vect) {
        cout << item << ", ";
    }
    cout << endl;
}
