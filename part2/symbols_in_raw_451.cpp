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

template<typename T>
bool vector_contains(const vector<T> &v, T x);

bool have_in_raw(int n, string str) {
    char prev_letter = str[0];
    int in_raw = 1;
    for (int i = 1; i < str.size(); ++i) {
        if (str[i] == prev_letter) {
            in_raw++;
        }
        if (in_raw == n) {
            return true;
        }
    }
    return false;
}

vector<int> in_raw_char_counter(string str) {
    vector<int> res;
    char prev_char = str[0];
    int counter = 1;

//    "a bbb cd"
    for (int i = 1; i < str.size(); ++i) {
        char current_char = str[i];
        if (current_char == prev_char) {
            counter++;
            prev_char = current_char;
        } else {
            res.push_back(counter);
            counter = 1;
            prev_char = current_char;
        }
    }

    res.push_back(counter);
    return res;
}

void check_1() {
    vector<int> num_in_raw = {3, 4, 4, 2};
    vector<string> input_data = {"a bbb cd", "ab cdddd", "a bcddd", "aabc ddd"};

    for (int i = 0; i < num_in_raw.size(); ++i) {
        cout << have_in_raw(num_in_raw[i], input_data[i]) << ", ";
    }
    cout << endl;

    cout << "Should be" << endl;
    cout << "1, 1, 0, 1" << endl;
}

void check_3() {
    vector<int> num_in_raw = {3, 4, 4, 2};
    vector<string> input_strs = {"a bbb cd", "ab cdddd", "a bcddd", "aabc ddd"};


    for (int i = 0; i < num_in_raw.size(); ++i) {
//        cout << vector_contains(in_raw_char_counter(input_strs[i]), ) << ", ";

        auto v = in_raw_char_counter(input_strs[i]);
        auto x = num_in_raw[i];
        auto res = find(v.begin(), v.end(), x) != v.end();
        cout << res << ", ";
    }

    cout << endl;
    cout << "Should be" << endl;
    cout << "1, 1, 0, 1" << endl;
}

void check_2() {
    vector<string> input_data = {
            "a bbb cd",
            "ab cdddd",
            "a bcddd",
            "aabc ddd"
    };

    for (auto str : input_data) {
        print_vector(in_raw_char_counter(str));
    }
}

int main() {
//    check_1();
//    check_2();
    check_3();
}

template<typename T>
void print_vector(const vector<T> &vect) {
    for (auto item : vect) {
        cout << item << ", ";
    }
    cout << endl;
}

bool vector_contains_int(const vector<int> &v, int x) {
    return find(v.begin(), v.end(), x) != v.end();
}

template<typename T>
bool vector_contains(vector<T> &v, T x) {
    return find(v.begin(), v.end(), x) != v.end();
}