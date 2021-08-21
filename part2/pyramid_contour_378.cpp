#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_set>

using namespace std;


/*
 * 369.    Пирамида.
 * В программу вводится одно число n - размер фигуры из звёздочек.
 * Напишите программмуу,
 * которая по заданному числу n выводит на экран следующую фигуру
 *
n = 3
  *
 * *
*****

n = 5
    *
   * *
  *   *
 *     *
*********
 * */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_vect(vector<string> vect);

string repeate_char_n(int n, char ch) {
    string res = "";
    for (int i = 0; i < n; ++i) {
        res += ch;
    }
    return res;
}

string first_level(int n) {
    return repeate_char_n(n - 1, ' ') + '*';
}

string last_level(int n) {
    return repeate_char_n(n * 2 - 1, '*');
}

vector<string> get_piramid_n_vect(int n) {
    vector<string> levels;

    string first_l = first_level(n);
    levels.push_back(first_l);

    for (int i = 1 + 1; i < n; ++i) {
        string levelX = repeate_char_n(n - i, ' ') + '*' + repeate_char_n(i * 2 - 3, ' ') + '*';
        levels.push_back(levelX);
    }

    string last_l = last_level(n);
    levels.push_back(last_l);

    return levels;
}

int main() {
    print_vect(get_piramid_n_vect(3));
    cout << "------" << endl;
    print_vect(get_piramid_n_vect(5));
}

void print_vect(vector<string> vect) {
    for (auto item : vect) {
        cout << item << endl;
    }
}