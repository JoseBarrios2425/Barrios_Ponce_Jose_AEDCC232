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
    cout << "PRUEBA 4 PASADA - Caso extremo verificable a mano: " << resultado << endl;
}

void prueba5() {
    // 5a: Mapa simetrico, ambas soluciones deben coincidir
    vector<vector<int>> mapaSimétrico = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}
    };

    // 5b: Caso 2 LeetCode, ambas soluciones deben coincidir
    vector<vector<int>> mapaSimétrico2 = {
        {3, 3, 3, 3, 3},
        {3, 2, 2, 2, 3},
        {3, 2, 1, 2, 3},
        {3, 2, 2, 2, 3},
        {3, 3, 3, 3, 3}
    };

    // 5c: Mapa irregula
    vector<vector<int>> mapaIrregular = {
        {3, 5, 4, 5, 3, 4},
        {5, 1, 2, 3, 1, 5},
        {4, 2, 1, 2, 3, 3},
        {5, 3, 2, 1, 2, 5},
        {3, 5, 4, 5, 3, 4}
    };

    int optima1  = calcularAguaAtrapada(mapaSimétrico);
    int ingenua1 = solucionIngenua(mapaSimétrico);
    if (optima1 == ingenua1)
        cout << "PRUEBA 5a PASADA - Mapa simetrico, ambas coinciden: " << optima1 << endl;
    else
        cout << "PRUEBA 5a FALLIDA - Optima: " << optima1 << " Ingenua: " << ingenua1 << endl;

    int optima2  = calcularAguaAtrapada(mapaSimétrico2);
    int ingenua2 = solucionIngenua(mapaSimétrico2);
    if (optima2 == ingenua2)
        cout << "PRUEBA 5b PASADA - Mapa simetrico, ambas coinciden: " << optima2 << endl;
    else
        cout << "PRUEBA 5b FALLIDA - Optima: " << optima2 << " Ingenua: " << ingenua2 << endl;

    int optima3  = calcularAguaAtrapada(mapaIrregular);
    int ingenua3 = solucionIngenua(mapaIrregular);
    if (optima3 != ingenua3)
        cout << "PRUEBA 5c PASADA - Mapa irregular, ingenua falla | Optima: "
             << optima3 << " Ingenua: " << ingenua3 << endl;
    else
        cout << "PRUEBA 5c FALLIDA - Ambas coinciden cuando no deberian" << endl;
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

void prueba7() {
    
    vector<vector<int>> heightMap = {
        {3, 3},
        {3, 3}
    };
    int resultado = calcularAguaAtrapada(heightMap);
    assert(resultado == 0);
    cout << "PRUEBA 7 PASADA - Grilla menor a 3x3: " << resultado << endl;
}

void prueba8() {
    // Grilla con una sola fila, sin interior posible
    vector<vector<int>> heightMap = {
        {3, 3, 3, 3, 3}
    };
    int resultado = calcularAguaAtrapada(heightMap);
    assert(resultado == 0);
    cout << "PRUEBA 8 PASADA - Grilla de una sola fila: " << resultado << endl;
}

int main() {
    cout << "=== Ejecutando pruebas PC3 ===" << endl << endl;
    prueba1();
    prueba2();
    prueba3();
    prueba4();
    prueba5();
    prueba6();
    prueba7();
    prueba8();
    cout << endl << "=== Todas las pruebas completadas ===" << endl;
    return 0;
}