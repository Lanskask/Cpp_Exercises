/*
 * 454.    Количество слов и избыточные пробелы.
 * Дано предложение.
 * Cлова в нём разделены одним или несколькими пробелами.
 * В предложении могут присутствовать начальные и конечные пробелы.
 * Определите количество слов в предложении. Оформите программу в функцию countWords.
 *
 * Примеры
 *    входные данные "   abbb bbcd"      - выходные данные - 2
 *    входные данные "abc dd dd"         - выходные данные - 3
 *    входные данные "  abc dd dd "      - выходные данные - 3
 *    входные данные "   "               - выходные данные - 0
 */

#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

string empty_str = "";

string &ltrim(string &str);

string &ltrim_simp(string &str);

void check_2() {
    string str1 = "   a";
    string str2 = "a";
    string str3 = "   ";
    cout << "|" << ltrim_simp(str1) << "|" << endl;
    cout << "|" << ltrim_simp(str2) << "|" << endl;
    cout << "|" << ltrim_simp(str3) << "|" << endl;
}

int main() {
    check_2();
}

string &ltrim_simp(string &str) {
    if (str.empty())
        return empty_str;

    int cut_of = 0;

    for (int i = 0; i < str.size(); ++i) {
        //char current_char = ;

        if (str.at(i) == ' ') {
            cut_of++;
        }
    }

    return str.erase(0, cut_of);
}

string &ltrim(string &str) {
    if (str.empty())
        return empty_str;

    char current_char = str.at(0);

    if (current_char == ' ') {
        str.erase(0, 1);
        return ltrim(str);
    } else {
        return str;
    }
}
