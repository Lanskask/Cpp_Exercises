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

//int[4][4] translate_matrix() {
//    return int[4][4]{};
//}

void print_matrix(vector<vector<int>> matrix);

vector<vector<int>> translate_matrix(vector<vector<int>> &matrix) {
    vector<vector<int>> translated_matrix(4,  vector<int>(4, 0));

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            translated_matrix[i][j] = matrix[j][i];
        }
    }

    return translated_matrix;
}

void check_1() {
    vector<vector<int>> matrix = {
            {2, 2, 8, 1},
            {4, 2, 7, 3},
            {1, 8, 3, 4},
            {1, 1, 2, 7},
    };

    print_matrix(matrix);
    auto res = translate_matrix(matrix);
    print_matrix(res);
}

int main() {
    check_1();

    return 0;
}

void print_matrix(vector<vector<int>> matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }
}
