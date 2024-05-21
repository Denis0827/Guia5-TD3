#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<char> counting_sort(const vector<char> & v){
    vector<int> contadores(28);
    vector<char> res;

    for(int i = 0; i <= 27; i++) {
        contadores[i] = 0;
    }

    for(int i = 0; i < v.size(); i++) {
        int letra = v[i];
        contadores[letra - 97] = contadores[letra - 97] + 1;
    }

    for(int i = 0; i <= 27; i++) {
        for(int j = 0; j < contadores[i]; j++) {
            char letra = static_cast<char>(i + 97);
            res.push_back(letra);
        }
    }

    return res;
}

int main() {
    vector<char> a = {'b', 'c', 'a', 'f', 'e'};
    vector<char> res = counting_sort(a);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}