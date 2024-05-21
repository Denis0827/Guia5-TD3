#include <vector>
#include <string>
#include <iostream>
using namespace std;

void merge(vector<int> &v, int d, int med, int h){
    int i = 0; int j = 0; int k = d;
    vector<int> v1 = {};
    vector<int> v2 = {};

    for(int n = d; n < med; n++) {
        v1.push_back(v[n]);
    }

    for(int n = med; n < h; n++) {
        v2.push_back(v[n]);
    }

    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            v[k] = v1[i];
            i++;
            k++;
        } else {
            v[k] = v2[j];
            j++;
            k++;
        }
    }

    while(i < v1.size()){
        v[k] = v1[i];
        i++;
        k++;
    }

    while(j < v2.size()){
        v[k] = v2[j];
        j++;
        k++;
    }
}

void mergesort(vector<int> & v, int d, int h){
    // Ordena los elementos desde d hasta h (sin incluir)
    // Si hay 0 o 1 elementos, ya están ordenados
    if(h - d <= 1) {
        return ;
    }

    // Divide y ordena cada mitad
    int med = (d+h)/2;
    mergesort(v, d, med);
    mergesort(v, med, h);

    // Devuelve la unión ordenada de ambas mitades
    merge(v, d, med, h);
}


int merge_inversiones(const vector<int> & v, int d, int med, int h){
    int i = 0; int j = 0; int res = 0;
    vector<int> v1 = {};
    vector<int> v2 = {};

    for(int n = d; n < med; n++) {
        v1.push_back(v[n]);
    }

    for(int n = med; n < h; n++) {
        v2.push_back(v[n]);
    }

    while(i < v1.size() && j < v2.size()) {
        if(v1[i] < v2[j]) {
            i++;
        } else {
            res += v1.size() - i;
            j++;
        }
    }

    return res;
}

int inversiones(const vector<int> & v, int d, int h){
    if(h - d <= 1) {
        return 0;
    }

    int med = (d+h)/2;
    int izq = inversiones(v, d, med);
    int der = inversiones(v, med, h);
    int suma = merge_inversiones(v, d, med, h);

    return izq + der + suma;
}

// OTRA RESOLUCION CON MAYOR COMPLEJIDAD
/* 
int merge_inversiones(const vector<int> & v, int d, int med, int h){
    int res = 0; int i = 0;
    vector<int> v1 = {};
    vector<int> v2 = {};

    for(int n = d; n < med; n++) {
        v1.push_back(v[n]);
    }

    for(int n = med; n < h; n++) {
        v2.push_back(v[n]);
    }

    while(i < v1.size()) {
        int j = 0;
        while(j < v2.size()) {
            if(v1[i] > v2[j]) {
                res++;
            }
            j++;
        }
        i++;
    }

    return res;
}

int inversiones(const vector<int> & v, int d, int h){
    if(h - d <= 1) {
        return 0;
    }

    int med = (d+h)/2;
    int izq = inversiones(v, d, med);
    int der = inversiones(v, med, h);
    int suma = merge_inversiones(v, d, med, h);

    return izq + der + suma;
}
*/

int main() {
    vector<int> a = {7, 5, 6, 1, 4, 8, 2, 10, 12};
    mergesort(a, 0, a.size());
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    vector<int> b = {12,10,8,5,3,1};
    cout << inversiones(b, 0, b.size()) << endl;
}
