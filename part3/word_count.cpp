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

bool is_pair_of_spaces(char ch1, char ch2) {
    return ch1 == ' ' && ch2 == ' ';
}

bool is_pair_of_chars(char ch1, char ch2) {
    return ch1 != ' ' && ch2 != ' ';
}

int count_words(string &str) {
    int word_count = 0;

    if(str.empty()) return 0;

    for (int i = 0; i < str.size() - 1; ++i) {
        char current_char = str.at(i);
        char next_char = str.at(i + 1);


    }

    for (int i = 1; i < str.size(); ++i) {
        char prev_char = str.at(i - 1);
        char current_char = str.at(i);

        // if begins with spaces - dont count
        // if ends with sparces - dont count
        if(is_pair_of_spaces(prev_char, current_char) || is_pair_of_chars(prev_char, current_char)) {
            continue;
        } else {

        }

        if(current_char == ' ' && prev_char == ' ') {
            continue;
        } else if(current_char == ' ' && prev_char != ' ') {
            word_count++;
        } else if(current_char != ' ' && prev_char != ' ') {
            continue;
        } else { // if(current_char != ' ' && prev_char != ' ')
            word_count++;
        }
    }

    return word_count;
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

int main() {
    check_1();
}

