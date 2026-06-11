#include "../include/solucion_optima.h"
#include "../include/solucion_ingenua.h"
#include <iostream>
#include <chrono>
using namespace std;

int main() {
    // Mapa pequeño 5x6
    vector<vector<int>> mapaP = {
        {4, 4, 4, 4, 4, 4},
        {4, 1, 1, 1, 1, 4},
        {4, 1, 2, 2, 1, 4},
        {4, 1, 1, 1, 1, 4},
        {4, 4, 4, 4, 4, 4}
    };

    // Mapa grande 10x10
    vector<vector<int>> mapaG = {
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
        {5, 1, 2, 3, 1, 2, 3, 1, 2, 5},
        {5, 2, 3, 4, 2, 3, 4, 2, 3, 5},
        {5, 3, 1, 2, 3, 1, 2, 3, 1, 5},
        {5, 1, 2, 3, 1, 2, 3, 1, 2, 5},
        {5, 2, 3, 4, 2, 3, 4, 2, 3, 5},
        {5, 3, 1, 2, 3, 1, 2, 3, 1, 5},
        {5, 1, 2, 3, 1, 2, 3, 1, 2, 5},
        {5, 2, 3, 1, 2, 3, 1, 2, 3, 5},
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
    };

    vector<vector<int>> mapaP2 = mapaP;
    vector<vector<int>> mapaG2 = mapaG;

    cout << "=== Benchmark: Solucion Ingenua vs Optima ===" << endl << endl;

    // Benchmark mapa pequeño
    cout << "--- Mapa pequeño 5x6 ---" << endl;

    auto ini1 = chrono::high_resolution_clock::now();
    int resIngenuaP = solucionIngenua(mapaP);
    auto fin1 = chrono::high_resolution_clock::now();
    double tIngenuaP = chrono::duration<double, milli>(fin1 - ini1).count();

    auto ini2 = chrono::high_resolution_clock::now();
    int resOptimaP = calcularAguaAtrapada(mapaP2);
    auto fin2 = chrono::high_resolution_clock::now();
    double tOptimaP = chrono::duration<double, milli>(fin2 - ini2).count();

    cout << "Solucion Ingenua - Resultado: " << resIngenuaP << " | Tiempo: " << tIngenuaP << " ms" << endl;
    cout << "Solucion Optima  - Resultado: " << resOptimaP  << " | Tiempo: " << tOptimaP  << " ms" << endl;
    cout << endl;

    // Benchmark mapa grande
    cout << "--- Mapa grande 10x10 ---" << endl;

    auto ini3 = chrono::high_resolution_clock::now();
    int resIngenuaG = solucionIngenua(mapaG);
    auto fin3 = chrono::high_resolution_clock::now();
    double tIngenuaG = chrono::duration<double, milli>(fin3 - ini3).count();

    auto ini4 = chrono::high_resolution_clock::now();
    int resOptimaG = calcularAguaAtrapada(mapaG2);
    auto fin4 = chrono::high_resolution_clock::now();
    double tOptimaG = chrono::duration<double, milli>(fin4 - ini4).count();

    cout << "Solucion Ingenua - Resultado: " << resIngenuaG << " | Tiempo: " << tIngenuaG << " ms" << endl;
    cout << "Solucion Optima  - Resultado: " << resOptimaG  << " | Tiempo: " << tOptimaG  << " ms" << endl;

    return 0;
}