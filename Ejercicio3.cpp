#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> merge(const vector<int> & v1, const vector<int> & v2){
    vector<int> res; int i = 0; int j = 0;

    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            res.push_back(v1[i]);
            i++;
        } else {
            res.push_back(v2[j]);
            j++;
        }
    }

    while(i < v1.size()){
        res.push_back(v1[i]);
        i++;
    }
    
    while(j < v2.size()){
        res.push_back(v2[j]);
        j++;
    }
        
    return res;
}


vector<int> mergesort(const vector<vector<int>> & v, int d, int h){
    // Ordena los elementos desde d hasta h (sin incluir)
    // Si hay 0 o 1 elementos, ya están ordenados
    
    if(h - d == 0) {
        return {};
    }
    if(h - d == 1) {
        return v[d];
    }

    // Divide y ordena cada mitad
    int med = (d+h)/2;
    vector<int> izq = mergesort(v, d, med);
    vector<int> der = mergesort(v, med, h);

    // Devuelve la unión ordenada de ambas mitades
    return merge(izq, der);
}

int main() {
    vector<vector<int>> a = {{1,2,5,9},{6,8,10,11},{-1,6,9}};
    vector<int> res = mergesort(a, 0, a.size());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}