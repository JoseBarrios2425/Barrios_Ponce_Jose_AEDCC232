#include "../include/solucion_optima.h"
#include "../include/solucion_ingenua.h"
#include <iostream>
#include <cassert>
using namespace std;

void prueba1() {
    vector<vector<int>> heightMap = {
        {3, 3, 3},
        {3, 1, 3},
        {3, 3, 3}
    };
    int resultado = calcularAguaAtrapada(heightMap);
    assert(resultado == 2);
    cout << "PRUEBA 1 PASADA - Caso minimo 3x3: " << resultado << endl;
}

void prueba2() {
    vector<vector<int>> heightMap = {
        {1, 1, 1},
        {1, 2, 1},
        {1, 1, 1}
    };
    int resultado = calcularAguaAtrapada(heightMap);
    assert(resultado == 0);
    cout << "PRUEBA 2 PASADA - Sin agua acumulable: " << resultado << endl;
}

void prueba3() {
    vector<vector<int>> heightMap = {
        {2, 2, 2, 2},
        {2, 2, 2, 2},
        {2, 2, 2, 2},
        {2, 2, 2, 2}
    };
    int resultado = calcularAguaAtrapada(heightMap);
    assert(resultado == 0);
    cout << "PRUEBA 3 PASADA - Todas las celdas con la misma altura: " << resultado << endl;
}

void prueba4() {
    vector<vector<int>> heightMap = {
        {4, 4, 4, 4, 4},
        {4, 1, 2, 1, 4},
        {4, 2, 1, 2, 4},
        {4, 1, 2, 1, 4},
        {4, 4, 4, 4, 4}
    };
    int resultado = calcularAguaAtrapada(heightMap);
    assert(resultado == 23);
    cout << "PRUEBA 4 PASADA - Caso extremo verificable: " << resultado << endl;
}

void prueba5() {
    vector<vector<int>> heightMap1 = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}
    };
    vector<vector<int>> heightMap2 = {
        {3, 3, 3, 3, 3},
        {3, 2, 2, 2, 3},
        {3, 2, 1, 2, 3},
        {3, 2, 2, 2, 3},
        {3, 3, 3, 3, 3}
    };

    int optima1  = calcularAguaAtrapada(heightMap1);
    int ingenua1 = solucionIngenua(heightMap1);
    if (optima1 == ingenua1)
        cout << "PRUEBA 5a PASADA - Optima e ingenua coinciden en caso 1: " << optima1 << endl;
    else
        cout << "PRUEBA 5a FALLIDA - Optima: " << optima1 << " Ingenua: " << ingenua1 << endl;

    int optima2  = calcularAguaAtrapada(heightMap2);
    int ingenua2 = solucionIngenua(heightMap2);
    if (optima2 == ingenua2)
        cout << "PRUEBA 5b PASADA - Optima e ingenua coinciden en caso 2: " << optima2 << endl;
    else
        cout << "PRUEBA 5b FALLIDA - Optima: " << optima2 << " Ingenua: " << ingenua2 << endl;
}

void prueba6() {
    vector<vector<int>> heightMap = {
        {3, 3, 3, 3, 3},
        {3, 2, 2, 2, 3},
        {3, 2, 1, 2, 3},
        {3, 2, 2, 2, 3},
        {3, 3, 3, 3, 3}
    };
    int resultado = calcularAguaAtrapada(heightMap);
    assert(resultado == 10);
    cout << "PRUEBA 6 PASADA - Invariante del heap cumplido: " << resultado << endl;
}

int main() {
    cout << "=== Ejecutando pruebas PC3 ===" << endl << endl;
    prueba1();
    prueba2();
    prueba3();
    prueba4();
    prueba5();
    prueba6();
    cout << endl << "=== Todas las pruebas completadas ===" << endl;
    return 0;
}