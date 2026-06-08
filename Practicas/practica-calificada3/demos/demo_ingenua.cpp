#include "../include/solucion_ingenua.h"
#include <iostream>
using namespace std;

int main() {
    // Caso 1
    vector<vector<int>> heightMap1 = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}
    };

    // Caso 2
    vector<vector<int>> heightMap2 = {
        {3, 3, 3, 3, 3},
        {3, 2, 2, 2, 3},
        {3, 2, 1, 2, 3},
        {3, 2, 2, 2, 3},
        {3, 3, 3, 3, 3}
    };

    cout << "=== Demo Solución Ingenua ===" << endl;
    cout << "Caso 1: " << solucionIngenua(heightMap1)  << endl;
    cout << "Caso 2: " << solucionIngenua(heightMap2) << endl;

    return 0;
}