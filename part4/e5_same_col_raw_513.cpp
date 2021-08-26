/*
 * 513.    *Одинаковый столбец и строка.
 *
 * Определите, существуют ли в квадратной матрице строка и столбец с совпадающими элементами.
 * Если существуют,
 * выведите номера строки и столбца, которые совпадают.
 * В противном случае выведите 0.
 *
 * Примеры
 * Входные данные  Выходные данные
 * 2 2 8 1         0 1
 * 4 2 7 3
 * 1 8 3 4
 * 1 1 2 7
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

using Matrix = vector<vector<int>>;

void print_matrix(Matrix matrix);

Matrix translate_matrix(Matrix &matrix) {
    Matrix translated_matrix(4,  vector<int>(4, 0));

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            translated_matrix[i][j] = matrix[j][i];
        }
    }

    return translated_matrix;
}

template <typename T>
bool are_same_vectors(vector<T> &vect1, vector<T> &vect2) {
    if(vect1.size() != vect2.size()) return false;

    for (int i = 0; i < vect1.size(); ++i) {
        if(vect1.at(i) != vect2.at(i))
            return false;
    }

    return true;
}

struct SameRawCol {
    int raw_num;
    int col_num;
};

SameRawCol find_same_raw_col(Matrix &matr1, Matrix &matr2) {
    for (int i = 0; i < matr1.size(); ++i) {
        for (int j = 0; j < matr1.size(); ++j) {

        }
    }
}

void check_1() {
    Matrix matrix = {
            {2, 2, 8, 1},
            {4, 2, 7, 3},
            {1, 8, 3, 4},
            {1, 1, 2, 7},
    };

    print_matrix(matrix);
    auto res = translate_matrix(matrix);
    print_matrix(res);

    // compare matrix and translated_matrix
    // compara rows in them
    // which raws in them are the same
}

void check_2() {
    vector<int> vect1 = {1,2,3,4};
    vector<int> vect2 = {1,2,3,4};
    vector<int> vect3 = {1,2,3};

    cout << are_same_vectors(vect1, vect2) << endl;
    cout << are_same_vectors(vect2, vect3) << endl;
}

int main() {
//    check_1();
    check_2();

    return 0;
}

void print_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }
}
