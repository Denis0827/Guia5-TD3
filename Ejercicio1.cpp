#include <vector>
#include <string>
#include <iostream>
using namespace std;

void selection_sort(vector<int> & v) {
    int i = 0;
    while(i < v.size()) {
        int j = i;
        while(j < v.size()) {
            if(v[i] > v[j]) {
                swap(v[i], v[j]);
            }
            j++;
        }
        i++;
    }
}

void insertion_sort(vector<int> & v) {
    int i, key, j;
    
    while(i < v.size()) {
        int pos_min = i;
        int j = 0;
        while(j < i) {
            if(v[pos_min] > v[j]) {
                pos_min = j;
            }
            j++;
        }
        i++;
    }
}

void insertionSort(vector<int> &v) {
    int key, j;
    int i = 1;
    while(i < v.size()) {
        key = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
        i++;
    }
}

int main() {
    vector<int> a = {6, 5, 7, 3, 2, 1};
    selection_sort(a);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}