#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_set>

using namespace std;


/*
 * 379.    Дубликаты.
 * Дан массив целых чисел.
 * Определить есть ли в нём два и более одинаковых элемента.
 * Если есть, вывести 1, если нет вывести 0.

    Примеры
    входные данные 1 2 3 4 - выходные данные 0
    входные данные 1 2 2 4 - выходные данные 1
    входные данные 2 1 3 2 - выходные данные 1
 *
 * */

// 1 2 3 4
bool have_duplicates(vector<int> &vect) {
    for (int i = 0; i < vect.size(); ++i) {
        for (int j = i + 1; j < vect.size(); ++j) {
            if (vect[j] == vect[i]) {
                return true;
            }
        }
    }
    return false;
}

bool have_duplicates_with_set(vector<int> &vect) {
    unordered_set<int> the_set;
    for (auto item : vect) {
        if (the_set.find(item) == the_set.end()) {
            the_set.insert(item);
        } else {
            return true;
        }
    }
    return false;
}

int main(void) {
    auto vect1 = vector<int>{1, 2, 3, 4};
    auto vect2 = vector<int>{1, 2, 2, 4};
    auto vect3 = vector<int>{2, 1, 3, 2};

    cout << have_duplicates(vect1) << endl;
    cout << have_duplicates(vect2) << endl;
    cout << have_duplicates(vect3) << endl;
//
    assert(have_duplicates(vect1) == 0);
    assert(have_duplicates(vect2) == 1);
    assert(have_duplicates(vect3) == 1);
}


