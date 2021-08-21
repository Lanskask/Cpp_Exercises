# Some C++ Exercises


## Useful funcs

```c++
template<typename T>
void print_vector(const vector<T> &vect) {
    for (auto item : vect) {
        cout << item << ", ";
    }
    cout << endl;
}
```
