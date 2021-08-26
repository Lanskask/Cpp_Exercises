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

vector<vector<int>> translate_matrix(vector<vector<int>> matrix) {
    vector<vector<int>> translated_matrix;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }
    return translated_matrix;
}

vector<vector<int>> translate_matrix2(vector<vector<int>> &matrix) {
    vector<vector<int>> translated_matrix;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            cout << matrix[j][i] << ", ";
        }
        cout << endl;
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

    translate_matrix(matrix);
    translate_matrix2(matrix);
}

int main() {
    check_1();

    return 0;
}
