#include <iostream>
#include <vector>

using namespace std;


float calculateLocation(vector<int> house_distances) {
    int sum = 0;
    for (int dist : house_distances) {
        sum += dist;
    } 
    return (float)sum / house_distances.size();
}


int main(void) {
    auto distances = vector<int>{2, 4, 5, 1, 1, 2};

    cout <<  calculateLocation(distances) << endl;
}


float calculateLocation2(vector<int> house_distances) {
    int sum = 0;
    for (int dist : house_distances) {
        sum += dist;
    } 
    return (float)sum / house_distances.size();
}