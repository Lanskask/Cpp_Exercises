/*
 * 369.    Пирамида.
 * В программу вводится одно число n - размер фигуры из звёздочек.
 * Напишите программмуу,
 * которая по заданному числу n выводит на экран следующую фигуру
 *
n = 3
  *
 ***
*****

n = 5
    *
   ***
  *****
 *******
*********
 * */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string repeate_char_n(int n, char ch) {
    string res = "";
    for (int i = 0; i < n; ++i) {
        res += ch;
    }
    return res;
}

void print_piramid_n(int n) {
    vector<string> levels(n);

    for (int i = 1; i < n + 1; ++i) {
        cout << repeate_char_n(n - i, ' ') + repeate_char_n(i * 2 - 1, '*') << endl;
    }
}

int main() {
    print_piramid_n(3);
    cout << "------" << endl;
    print_piramid_n(5);
}


