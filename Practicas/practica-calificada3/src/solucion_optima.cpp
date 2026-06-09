#include "../include/solucion_optima.h"
#include "../include/PQ_ComplHeap.h"
#include "../include/PQ_ComplHeap_insert.h"
#include "../include/PQ_ComplHeap_delMax.h"
#include "../include/PQ_ComplHeap_getMax.h"
#include "../include/PQ_ComplHeap_macro.h"

#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

bool esValida(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

int calcularAguaAtrapada(vector<vector<int>>& heightMap) {
    int filas = heightMap.size();
    int cols  = heightMap[0].size();

    if (filas < 3 || cols < 3) return 0;

    ods::PQ_ComplHeap<Celda, CompararCelda> minHeap;

    vector<vector<bool>> visitado(filas, vector<bool>(cols, false));

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == filas-1 || j == 0 || j == cols-1) {
                minHeap.insert({heightMap[i][j], i, j});
                visitado[i][j] = true;
            }
        }
    }

    int nivel        = 0;
    int aguaAtrapada = 0;

    vector<int> direcciones = {-1, 0, 1, 0, -1};

    while (!minHeap.empty()) {
        Celda actual = minHeap.getMax();
        minHeap.delMax();

        nivel = max(nivel, actual.altura);

        for (int i = 0; i < 4; i++) {
            int nuevaFila = actual.fila + direcciones[i];
            int nuevaCol  = actual.col  + direcciones[i+1];

            if (esValida(nuevaFila, nuevaCol, filas, cols) && !visitado[nuevaFila][nuevaCol]) {
                visitado[nuevaFila][nuevaCol] = true;
                minHeap.insert({heightMap[nuevaFila][nuevaCol], nuevaFila, nuevaCol});

                if (heightMap[nuevaFila][nuevaCol] < nivel)
                    aguaAtrapada += nivel - heightMap[nuevaFila][nuevaCol];
            }
        }
    }

    return aguaAtrapada;
}