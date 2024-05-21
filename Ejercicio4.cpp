#include <vector>
#include <string>
#include <iostream>
#include <tuple>
using namespace std;

tuple<int, int> dividir(vector<int> & v, int d, int h){
    int p = v[h-1]; int i1 = d; int i2 = d; int j = d; int k = d; int q; int z;

    while(j < h - 1) {
        if(v[j] <= p) {
            swap(v[i1], v[j]);
            i1++;
        }
        j++;
    }
    swap(v[i1], v[h-1]);

    if(i1 == h-1) {
        z = h-2;
    } else {
        z = h-1;
    }
    q = v[z];

    while(k < z) {
        if(v[k] <= q) {
            swap(v[i2], v[k]);
            i2++;
        }
        k++;
    }
    swap(v[i2], v[z]);

    tuple<int, int> res(i1, i2);
    return res;
}


void quicksort(vector<int> & v, int d, int h){
    if(d < h - 2){
        tuple<int, int> pos_tupla = dividir(v, d, h);
        int pos = get<0>(pos_tupla);
        int pos2 = get<1>(pos_tupla);
        quicksort(v,d,pos);
        quicksort(v,pos+1,pos2);
        quicksort(v,pos2+1,h);
    }
}

int main() {
    vector<int> a = {7, 41, 2, 50, 59, 280, 123, 388};
    quicksort(a, 0, a.size());
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
