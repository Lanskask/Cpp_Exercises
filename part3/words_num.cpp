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

string &rtrim(string &str);

string &trim(string &str);

string replace_mine(string &str, string replace_from_reg, string replace_to) {
    regex re(replace_from_reg);
    return regex_replace(str, re, replace_to);
}

int count_words(string &str) {
    string cleaned = replace_mine(trim(str), "\\s+", " ");
    int count_spaces = count(cleaned.begin(), cleaned.end(), ' ');
    if (count_spaces == 0) {
        return 0;
    }
    return count_spaces + 1;
}

void check_1() {
    vector<string> input_data = {
            "   abbb bbcd",
            "abc dd dd",
            "  abc dd dd ",
            "   "
    };

    for (auto item : input_data) {
        cout << count_words(item) << ", ";
    }
    cout << endl;
    cout << "Should be: " << endl;
    cout << "2, 3, 3, 0" << endl;
}

void check_2() {
    string str1 = "   a";
    string str2 = "a";
    cout << ltrim(str1) << endl;
    cout << ltrim(str2) << endl;

    string str3 = "b   ";
    string str4 = "   b";
    cout << rtrim(str3) << endl;
    cout << rtrim(str4) << endl;

    string str5 = "   c   ";
    string str6 = "c";
    string str7 = "   c";
    string str8 = "c   ";
    cout << trim(str5) << endl;
    cout << trim(str6) << endl;
    cout << trim(str7) << endl;
    cout << trim(str8) << endl;
}

void check_3() {
    string str1 = "a           b";
    string reg = "\\s+";
    string repl_to = " ";
    cout << replace_mine(str1, reg, repl_to) << endl;

//    regex re("\\s+");
//    cout <<  << endl;
}

void check_4() {
    vector<string> input_data = {
            "   abbb bbcd",
            "abc dd dd",
            "  abc dd dd ",
            "   "
    };

    for (auto item : input_data) {
        cout << item << ": " << endl << trim(item) << endl;
    }
    cout << endl;
}

int main() {
    check_1();
//    check_2();
//    check_3();
//    check_4();
}


string &ltrim_simp(string &str) {
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

string &rtrim(string &str) {
    if (str.empty())
        return empty_str;

    char current_char = str.at(str.size() - 1);
    if (current_char == ' ') {
        str.erase(str.size() - 1, 1);
        return rtrim(str);
    } else {
        return str;
    }
}

string &trim(string &str) {
    return rtrim(ltrim(str));
}
