#pragma once

#include <vector>
#include <functional>
#include <algorithm>
#include "PQ_ComplHeap.h"

using namespace std;

struct Celda {
    int altura;
    int fila;
    int col;
};

struct CompararCelda {
    bool operator()(const Celda& a, const Celda& b) const {
        return a.altura > b.altura;
    }
};

bool esValida(int x, int y, int m, int n);

int calcularAguaAtrapada(vector<vector<int>>& heightMap);