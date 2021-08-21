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


/*
bool vect_contains(vector<int> &v, int x) {
	auto is_exists = std::find(v.begin(), v.end(), x) != v.end();
	cout << x << " is contains? : " << is_exists << endl;
	return is_exists;
}*/


int get_new_rand_int(vector<int> &vect, int N) {
	auto res =  1 + rand() % N;

	if(vect_contains(vect, res)) {
		cout << "search again" << endl;
		get_new_rand_int(vect, N);
	} 
	return res;
}

return fibonachi(n  - 1, n);

1 + f(2)
1 +	2 + f(3)

f(1,2)
f(2,3)



void fill_rand_vect(vector<int> &vect, int N) {
	for (int i = 0; i < vect.size(); ) {
		int num =  1 + rand() % N;

		auto is_exists = std::find(vect.begin(), vect.end(), num) != vect.end();

		// auto res = get_new_rand_int(vect, N);

		if (!is_exists) {
			vect[i] = num;
			i++;
		} 
	}
}

int main(void) {
	vector<int> vect(20);

	fill_rand_vect(vect, 30);

	for( auto x : vect) {
		cout << x << ", ";
	}
	cout << endl;
}
