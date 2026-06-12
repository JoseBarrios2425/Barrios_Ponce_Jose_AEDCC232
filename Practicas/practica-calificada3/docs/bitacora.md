# Bitácora de desarrollo

## Sábado 06/06/2026
1) lectura y analisis del problema.

## Domingo 07/06/2026
1) Se crearon los siguientes archivos:
- solucion_ingenua.h
- solucion_ingenua.cpp
- demo_ingenua.cpp

2) Creación de una solución ingenua utilizando fuerza bruta recorriendo cada celda interior y calculando la altura máxima en sus cuatro direcciones.

3) La demo incluye matrices predeterminadas, debo agregar la lectura de matrices luego.

4) Probablemente la solucion ingenua tenga limitaciones.

## Martes 09/06/2026
1) Se crearon los siguientes archivos.
- solucion_optima.h
- solucion_optima.cpp
- demo_optima.cpp

2) Se reutilizaron los archivos:
- PQ.h
- PQ_ComplHeap.h
- PQ_ComplHeap_insert.h
- PQ_ComplHeap_delMax.h
- PQ_ComplHeap_getMax.h
- PQ_ComplHeap_macro.h
- PQ_ComplHeap_percolateUp.h
- PQ_ComplHeap_percolateDown.h
- PQ_ComplHeap_heapifyFloyd.h

3) Creación de una solución optima utilizando un min-heap a partir de PQ_ComplHeap.

4) El demo es identica a la de la solución ingenua, solo deseo comparar el resultado con el que se mueestra en leetCode.

5) Agregamos un .gitignore

## Miercoles 10/06/2026
1) Se creo el archivo:
- test.cpp

2)  Incluye 6 pruebas que verifican: 
- Casos mínimos (matriz 3x3)
- Casos sin agua acumulable
- Matrices uniformes
- Casos extremos verificables
- Comparación entre solución óptima e ingenua en las matrices predeterminadas. 
- Verificar el invariante del heap en una matriz 5x5 con pozo central.

## Jueves 11/06/2026
1) Se crearon los siguientes archivos.
- CMakeLists.txt
- benchmark.cpp
- test.cpp
- leer.h
- leer.cpp

2) Se crearon los archivos include/leer.h y leer.cpp que implementan una función para leer matrices desde la entrada estándar (primero filas y columnas, luego la matriz fila por fila). Se actualizaron demo_ingenua.cpp y demo_optima.cpp para utilizar esta función, permitiendo ahora ingresar matrices manualmente en lugar de usar solo las predeterminadas.

3) Se creó el archivo CMakeLists.txt para estructurar la compilación del proyecto. Se creó benchmark.cpp que compara la velocidad de ejecución entre la solución ingenua y la solución óptima en matrices de diferentes tamaños.

## Viernes 12/06/2026
1) Se crearon los archivos.
- bitacora.md
- respuestas_obligatorias.md
- casos_bordes.txt
- ejecucion_pc3.txt
- tests_pc3.txt

2) Se agregaron 2 pruebas más.

3) Se agrego el video explicativo de la pc3
