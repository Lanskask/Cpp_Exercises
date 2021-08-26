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

using namespace std;

struct ValueReminder {
    char value;
    char reminder;
};

struct LongEqualSrings {
    string string_one;
    string string_two;
};

template<typename Input, typename T>
struct TestData {
    Input input;
    T result;
    T expected;
};

string repeate_char_n(int n, char ch);

string add_trailing_zeros(string &num, int zeros_num);

ValueReminder sum_two_chars(char ch1, char ch2);

string enlarge_shortest_str(string &str1, string &str2);

LongEqualSrings get_equal_long_strings(string &str1, string &str2);

/*
 * 157
 * 045
 *
 * 01
 * 157
 * 045
 * ---
 * 192
 *
 * */
string sum_to_str_ints(string str1, string str2) {
//    vector<ValueReminder> reminders(str1.size());
    vector<char> reminders(str1.size());
    vector<char> values(str1.size());

    for (int i = str1.size() - 1; i > 0; --i) {
        auto res = sum_two_chars(str1[i], str2[i]);
        reminders[i + 1] = res.reminder;
        values[i] = res.value;
    }

    reminders;
    values;

    return "asfasf";
}


/*
 * 157
 * 045
 * ---
 * 192
 *
 * */
string get_sum_str_var1(string str1, string str2) {
    string res = "";

    for (int i = str1.size() - 1; i > 0; --i) {
        int int_sum = (str1[i] - '0') + (str2[i] - '0');

        if (int_sum < 10) {
            char ch1 = int_sum + '0';
            res = ch1 + res;
            //            res[res.size() - 1 - i] = ;
        } else {
            char ch1 = (int_sum - 10) + '0';
            res = ch1 + res;

            res[res.size() - 1 - i] = (int_sum - 10) + '0'; // reminder
            res[res.size() - 1 - i - 1] = '1'; // reminder
        }

    }
    return res;
}

/*
 * 000
 * 157
 * 045
 * ---
 * 192
 *
 * 0000
 * */
string get_sum_str_var2(string str1, string str2) {
    string res = repeate_char_n(str1.size() + 1, '0');

    for (int i = str1.size() - 1; i > 0; --i) {
        int int_sum = (str1[i] - '0') + (str2[i] - '0') + (res[i + 1] - '0');

        if (int_sum < 10) {
            int value_in_res_index = i + 1;

            res[value_in_res_index] = int_sum + '0';
        } else {
            int value_in_res_index = i + 1;
            int reminder_in_res_index = i;

            res[value_in_res_index] = (int_sum - 10) + '0'; // reminder
            res[reminder_in_res_index] = '1'; // reminder
        }

    }
    return res;
}

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
    string res = repeate_char_n(str1.size() + 1, '0');

    for (int i = str1.size() - 1; i > 0; --i) {
        int int_sum = (str1[i] - '0') + (str2[i] - '0') + (res[i + 1] - '0');

        int value_in_res_index = i + 1;
        int reminder_in_res_index = i - 1;

        if (int_sum < 10) {
            res[value_in_res_index] = int_sum + '0';
            res[reminder_in_res_index] = '0'; // reminder
        } else {
            res[value_in_res_index] = (int_sum - 10) + '0'; // reminder
            res[reminder_in_res_index] = '1'; // reminder
        }
    }
    return res;
}

void check_1() {
    //    cout << atoi("23") + atoi("23") << endl;
    //    cout << to_string(123) << endl;
    //    cout << ('5' - '0') - ('3' - '0') << endl;
    string str1 = "45";
    string str2 = "157";
    //    cout << add_trailing_zeros(str1, 3) << endl;

    //    auto res1 = sum_two_chars('6', '7');
    //    cout << "sum_two_chars('6', '7'): " << res1.value << ": " << res1.reminder << endl;

    //    cout << enlarge_shortest_str(str1, str2) << " - should be `005`" << endl;

    auto equal_long_strings = get_equal_long_strings(str1, str2);

    //    sum_to_str_ints(equal_long_strings.string_one, equal_long_strings.string_two);

    string res = get_long_equal_sum_str(equal_long_strings.string_one, equal_long_strings.string_two);
    cout << res << endl;

    if(res[0] == '0') {
        res.erase(0, 1);
    }
    cout << res << endl;
}

struct InputStruct {
    string num1;
    string num2;
};

int check_2() {

}

int main() {

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

ValueReminder sum_two_chars(char ch1, char ch2) {
    int sum = (ch1 - '0') + (ch2 - '0');
    if (sum < 10) {
        char value = sum + '0';
        return ValueReminder{value, '0'};
    } else {
        char value = (sum - 10) + '0';
        return ValueReminder{value, '1'};
    }
}

string enlarge_shortest_str(string &str1, string &str2) {
    int diff = str1.size() - str2.size();

    if (diff > 0) { // str1.size() > str2.size(1)
        return add_trailing_zeros(str2, diff);
    } else if (diff < 0) { // str2.size() > str1.size()
        return add_trailing_zeros(str1, -diff);
    } else {
        return str2;
    }
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

