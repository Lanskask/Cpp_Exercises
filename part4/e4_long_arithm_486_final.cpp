/*
 * 486.    *Длинная арифметика.
 *
 * Дано две строки, представляющие целые числа.
 * Сложите эти два строковых числа,
 * используя приёмы длинной арифметики.
 * В этом случае переводить каждую строку сначала в число,
 * а потом складывать, не нужно,
 * т.к. строки могут быть очень длинными, 100-200 символов.
 * В результате итоговое число может не поместиться в целочисленные типы данных.
 * Вместо этого  нужно попарно складывать символы строк,
 * предварительно переводя их в числа, как при сложении чисел столбиком.
 * Нужно учесть, что в результате поразрядного сложения
 * может появиться перенос из разряда в разряд.
 * Итоговый результат должен быть строковым.
 *
 * Примеры
 * Входные данные "2"  "23"   - выходные данные  "25"
 * Входные данные "23" "2"    - выходные данные  "25"
 * Входные данные "50" "51"   - выходные данные  "101"
 * Входные данные "55" "55"   - выходные данные  "110"
 * Входные данные "50" "1000" - выходные данные  "1050"
 *
 * */

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

struct LongEqualSrings {
    string string_one;
    string string_two;
};

template<typename Input, typename T>
struct TestData {
    Input input;
    T expected;
};

struct InputStruct {
    string num1;
    string num2;
};


string repeate_char_n(int n, char ch);

string add_trailing_zeros(string &num, int zeros_num);

LongEqualSrings get_equal_long_strings(string &str1, string &str2);

/*
 * 000
 * 157
 * 045
 * ---
 * 192
 *
 * 0000
 * */
string get_long_equal_sum_str(string str1, string str2) {
    int res_size = str1.size() + 1;
    string res = repeate_char_n(res_size, '0');

    for (int i = str1.size() - 1; i >= 0; --i) {
        int first_num_digit = str1[i] - '0';
        int second_num_digit = str2[i] - '0';
        int current_reminder = res[i + 1] - '0';

        int int_sum = first_num_digit + second_num_digit + current_reminder;

        int value_index = i + 1;
        int reminder_index = i;

        if (int_sum < 10) {
            res[value_index] = int_sum + '0'; // value
            res[reminder_index] = '0'; // reminder
        } else {
            res[value_index] = (int_sum - 10) + '0'; // value
            res[reminder_index] = '1'; // reminder
        }
    }

    return res;
}

string get_sum_str(string &str1, string &str2) {
    auto equal_long_strings = get_equal_long_strings(str1, str2);

    string res = get_long_equal_sum_str(equal_long_strings.string_one, equal_long_strings.string_two);

    if (res[0] == '0') {
        res.erase(0, 1);
    }

    return res;
}

void check_1() {
    string str1 = "45";
    string str2 = "157";

    auto equal_long_strings = get_equal_long_strings(str1, str2);

    string res = get_long_equal_sum_str(equal_long_strings.string_one, equal_long_strings.string_two);
    cout << res << endl;

    if (res[0] == '0') {
        res.erase(0, 1);
    }
    cout << res << endl;
}

void check_2() {
    vector<TestData<InputStruct, string>> testData = {
            {{"45", "157"},  "202"},
            {{"2",  "23"},   "25"},
            {{"23", "2"},    "25"},
            {{"50", "51"},   "101"},
            {{"55", "55"},   "110"},
            {{"50", "1000"}, "1050"},
    };

    for (auto testItem : testData) {
        auto res = get_sum_str(testItem.input.num1, testItem.input.num2);
        cout << "get_sum_str(" << testItem.input.num1 << ", " << testItem.input.num2 << ") = "
             << res << ": expected: " << testItem.expected << endl;
        assert(res == testItem.expected);
    }
}

int main() {
    check_2();
}

/**
 * `add_trailing_zeros("5", 3)` -> "0005"
 * */
string add_trailing_zeros(string &num, int zeros_num) {
    return repeate_char_n(zeros_num, '0') + num;
}

string repeate_char_n(int n, char ch) {
    string res = "";
    for (int i = 0; i < n; ++i) {
        res += ch;
    }
    return res;
}

LongEqualSrings get_equal_long_strings(string &str1, string &str2) {
    int diff = str1.size() - str2.size();

    if (diff > 0) { // str1.size() > str2.size(1)
        return LongEqualSrings{
                str1,
                add_trailing_zeros(str2, diff)
        };
    } else if (diff < 0) { // str2.size() > str1.size()
        return LongEqualSrings{
                str2,
                add_trailing_zeros(str1, -diff)
        };
    } else {
        return LongEqualSrings{str1, str2};
    }
}

