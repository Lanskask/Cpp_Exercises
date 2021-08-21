/*
382.    *Неповторяющиеся случайные числа. 
Дан массив из N целых чисел, заполненный нулями. 
Заполните массив неповторяющимися случайными числами. 
Диапазон изменения случайных чисел от 1 до N.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool vect_contains(vector<int> &v, int x) {
    auto is_exists = std::find(v.begin(), v.end(), x) != v.end();
    cout << x << " is contains? : " << is_exists << endl;
    return is_exists;
}

int get_new_rand_int(vector<int> &vect, int N) {
    auto res = 1 + rand() % N;

    if (vect_contains(vect, res)) {
        cout << "search again" << endl;
        return get_new_rand_int(vect, N);
    }
    return res;
}

void fill_rand_vect(vector<int> &vect, int N) {
    for (int i = 0; i < vect.size(); i++) {

        auto res = get_new_rand_int(vect, N);
        vect[i] = res;
    }
}

int main(void) {
    int N = 5;
    vector<int> vect(N);

    fill_rand_vect(vect, N);

    for (auto x : vect) {
        cout << x << ",\n ";
    }
    cout << endl;
}
