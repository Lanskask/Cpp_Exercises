#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


/*
 * 360.
 * Одинокие единицы.
 * Дан массив целых чисел из N элементов, заполненный нулями.
 * Напишите программу, которая случайным образом заполняет массив единицами,
 * при условии что ни одна единица не граничит с любой другой.
 * Программа должна поставить максимально возможное количество единиц.
 *
 * Примеры заполнения для массива из 7 элементов
 * выходные данные 1010101
 * выходные данные 1001001
 * выходные данные 0101001
 * */
vector<int> get_lonely_ones_vect_2(int N);

int get_new_rand_pos(vector<int> &vect, int N);

int get_new_rand_pos(vector<int> &vect, int N) {
    auto i = 1 + rand() % N;

    if (i == 0) {
        if (vect[i + 1] == 1) {
            cout << "search again" << endl;
            return get_new_rand_pos(vect, N);
        } else {
            return i;
        }
    } else if (i == vect.size() - 1) {
        if (vect[i - 1] == 1) {
            cout << "search again" << endl;
            return get_new_rand_pos(vect, N);
        } else {
            return i;
        }
    } else {
        if (vect[i - 1] == 1 || vect[i + 1]) {
            cout << "search again" << endl;
            return get_new_rand_pos(vect, N);
        }
    }

//    return 0;
}

// 1 2 3 4

bool can_i_put_a_one_to_this_position(vector<int> &vect, int i) {
    if (i == 0) {
        return vect[i + 1] != 1;
    } else if (i == vect.size() - 1) {
        return vect[i - 1] != 1;
    } else {
        return vect[i - 1] != 1 && vect[i + 1] != 1;
    }
}

// Могу ли я положить в массив вообще единицы
bool can_i_put_a_one_in_the_vector_again(vector<int> &vect) {
    for (int i = 0; i < vect.size(); ++i) {
        if (can_i_put_a_one_to_this_position(vect, i) && vect[i] != 1) {
            return true;
        }
    }
    return false;
}

vector<int> get_lonely_ones_vect(int N) {
    vector<int> vect(N);

//    for (int i = 0; i < vect.size(); ++i) {
    while (can_i_put_a_one_in_the_vector_again(vect)) {
        auto pos = rand() % N;

        vect[pos] = can_i_put_a_one_to_this_position(vect, pos);
    }

    return vect;
}

int main(void) {
    srand(time(0));
    vector<int> vect1 = {1, 0, 1, 0, 1, 0, 1};
    vector<int> vect2 = {1, 0, 0, 1, 0, 0, 1};
    vector<int> vect3 = {0, 1, 0, 1, 0, 0, 1};

    int size = 7;
    auto res_vect = get_lonely_ones_vect(size);

    for (auto item : res_vect) {
        cout << item;
    }
    cout << endl;
}

// ------------
vector<int> get_lonely_ones_vect_2(int N) {
    vector<int> vect(N);

    for (int i = 0; i < vect.size(); ++i) {
        int position = get_new_rand_pos(vect, N);
        vect[position] = 1;
    }

    return vect;
}