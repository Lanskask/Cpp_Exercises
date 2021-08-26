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

bool only_chars(string &str) {
    bool res = false;
    for (char i : str) {
        res = i != ' ';
        if(!res) return false; // if a one char is a space - then return false immediately
    }
    return res;
}

bool only_spaces(string &str) {
    bool res = false;
    for (char i : str) {
        res = i == ' ';
        if(!res) return false; // if a one char is a space - then return false immediately
    }
    return res;
}

int count_words(string &str) {
    int word_count = 0;

    if(str.empty()) return 0;

    if(only_chars(str)) return 1;
    if(only_spaces(str)) return 0;

    for (int i = 1; i < str.size(); ++i) {
        char prev_char = str.at(i - 1);
        char current_char = str.at(i);

        if(prev_char == ' ' && current_char == ' ') { // if pair of spaces
            continue;
        } else if(prev_char != ' ' && current_char == ' ') { // if switch from word to space
            continue;
        } else if(prev_char == ' ' && current_char != ' ') { // if switch from space to word
            word_count++;
        } else { // if(current_char != ' ' && prev_char != ' ') // if chars
            continue;
        }

    }
    if(str[0] != ' ') {
        word_count++;
    }

    return word_count;
}

void check_1() {
    vector<string> input_data = {
            "   abbb bbcd",
            "abc dd dd",
            "  abc dd dd ",
            "dd"
    };

    for (auto item : input_data) {
        cout << count_words(item) << ", ";
    }
    cout << endl;
    cout << "Should be: " << endl;
    cout << "2, 3, 3, 0" << endl;
}

int main() {
    check_1();
}

