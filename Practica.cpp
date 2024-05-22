#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Ejercicio 1

vector<int> interseccion_ordenada(const vector<int> &v1, const vector<int> &v2) {
    int i = 0; int j = 0;
    vector<int> res = {};
    
    while(i < v1.size() && j < v2.size()) {
        if(v1[i] == v2[j]) {
            res.push_back(v1[i]);
            i++;
            j++;
        } else if(v1[i] < v2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return res;

}

// Ejercicio 2

bool es_menor_a(const vector<int> &v1, const vector<int> &v2) {
    int i = 0;
    
    while(i < v1.size()) {
        if(v1[i] > v2[i]) {
            return false;
        } else if(v1[i] < v2[i]) {
            return true;
        } else {
            i++;
        }
    }

    return false;
}

void insertion_sort(vector<vector<int>> &vs) {
    vector<int> key;
    int j;
    int i = 1;
    while(i < vs.size()) {
        key = vs[i];
        j = i - 1;
        while (j >= 0 && !es_menor_a(vs[j], key)) {
            vs[j + 1] = vs[j];
            j = j - 1;
        }
        vs[j + 1] = key;
        i++;
    }
}

// Ejercicio 3

int maximo(const vector<int> &v) {
    int i = 0;
    int max = v[0];

    while(i < v.size()) {
        if(max < v[i]) {
            max = v[i];
        }
        i++;
    }

    return max;
}

vector<int> counting_sort(const vector<int> &v) {
    vector<int> contadores(maximo(v)+1);

    // Inicializo los contadores en 0;
    for(int i = 0; i < maximo(v)+1; i++) {
        contadores[i] = 0;
    }

    // Recorro v y actualizo el contador correspondiente.
    for(int i = 0; i < v.size(); i++) {
        contadores[v[i]] = contadores[v[i]] + 1;
    }

    return contadores;
}

bool de_cuentas(const vector<int> &v) {
    vector<int> contador = counting_sort(v);
    int i = 0;

    while(i < contador.size()) {
        if(i == 0 && contador[0] == 0) {
            i++;
        } else if(i != contador[i] && contador[i] != 0) {
            return false;
        } else {
            i++;
        }
    }
    
    return true;
}


int main() {
    vector<int> a1 = {0, 0, 5, 8, 8, 8, 11, 20};
    vector<int> a2 = {0, 0, 0, 8, 8, 6, 20};
    vector<int> res_a = interseccion_ordenada(a1, a2);
    for (int i = 0; i < res_a.size(); i++) {
        cout << res_a[i] << " ";
    }
    cout << endl;

    vector<int> b1 = {15, 15, 0};
    vector<int> b2 = {15, 15, 2};
    bool res_b = es_menor_a(b1, b2);
    if(res_b) {
        cout << "Es menor" << endl;
    } else {
        cout << "Es mayor" << endl;
    }

    vector<vector<int>> c = {{15,15,2}, {5,0,0}, {4,9,85}, {15,15,0}};
    insertion_sort(c);
    for(int i = 0; i < c.size(); i++) {
        for (int j = 0; j < c[i].size(); j++) {
            cout << c[i][j] << " ";
        }
        cout << "  ";
    }
    cout << endl;
    
    vector<int> d = {4, 1, 5, 5, 4, 4, 4, 5, 5, 5};
    vector<int> res_d = counting_sort(d);
    for (int i = 0; i < res_d.size(); i++) {
        cout << res_d[i] << " ";
    }
    cout << endl;

    bool res_d2 = de_cuentas(d);
    if(res_d2) {
        cout << "Esta de cuentas" << endl; 
    } else {
        cout << "No esta de cuentas" << endl;
    }

}