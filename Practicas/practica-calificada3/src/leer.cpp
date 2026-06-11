#include "../include/leer.h"
#include <vector>
#include <string>
#include <cctype>

using namespace std;

vector<vector<int>> leerMatriz(const string& entrada) {
    vector<vector<int>> matriz;
    vector<int> fila;

    int numero = 0;
    bool leyendoNumero = false;

    for (char c : entrada) {
        if (isdigit(c)) {
            numero = numero * 10 + (c - '0');
            leyendoNumero = true;
        } else {
            if (leyendoNumero) {
                fila.push_back(numero);
                numero = 0;
                leyendoNumero = false;
            }

            if (c == ']') {
                if (!fila.empty()) {
                    matriz.push_back(fila);
                    fila.clear();
                }
            }
        }
    }

    return matriz;
}