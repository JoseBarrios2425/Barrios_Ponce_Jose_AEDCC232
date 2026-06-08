#include "../include/solucion_ingenua.h"
#include <algorithm>
using namespace std;

int solucionIngenua(vector<vector<int>>& heightMap) {
    int m = heightMap.size();
    int n = heightMap[0].size();
    int total = 0;

    for (int i = 1; i < m - 1; i++) {
        for (int j = 1; j < n - 1; j++) {

            int maxArriba = 0;
            for (int k = 0; k <= i; k++)
                maxArriba = max(maxArriba, heightMap[k][j]);

            int maxAbajo = 0;
            for (int k = i; k < m; k++)
                maxAbajo = max(maxAbajo, heightMap[k][j]);

            int maxIzquierda = 0;
            for (int k = 0; k <= j; k++)
                maxIzquierda = max(maxIzquierda, heightMap[i][k]);

            int maxDerecha = 0;
            for (int k = j; k < n; k++)
                maxDerecha = max(maxDerecha, heightMap[i][k]);

            int barrera = min({maxArriba, maxAbajo, maxIzquierda, maxDerecha});

            if (barrera > heightMap[i][j])
                total += barrera - heightMap[i][j];
        }
    }

    return total;
}