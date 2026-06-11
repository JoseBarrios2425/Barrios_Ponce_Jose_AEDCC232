#include "../include/solucion_ingenua.h"
#include "../include/leer.h"

#include <iostream>
#include <string>

using namespace std;

int main() {

    /*
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
    */

    cout << "Ingrese la matriz mxn:" << endl;

    string entrada;
    getline(cin, entrada);

    vector<vector<int>> heightMap = leerMatriz(entrada);

    cout << "\n=== Demo Solucion Ingenua PC3 ===" << endl;
    cout << "Resultado: " << solucionIngenua(heightMap) << endl;

    return 0;
}