### PC3 - CC232

#### Estudiante

- Nombre: Jose Carlos Barrios Ponce
- Código: 20232296K
- Problema asignado: Trapping Rain Water II
- Enlace oficial: https://leetcode.com/problems/trapping-rain-water-ii/

#### Referencia oficial

- CSV oficial:
  https://github.com/kapumota/CC-232/blob/main/Practicas/Practica3_CC232/Problemas-Evaluacion3.csv

#### Relación con Semanas 4-6

- Semana principal: Semana 6
- Estructura usada: Min-Heap (Priority Queue)
- Estructura de la librería `cc232` relacionada: `PQ_ComplHeap` con comparador `CompararCelda`

#### Resumen de la solución

El problema consiste en calcular el volumen total de agua atrapada en una grilla 2D de alturas después de llover, considerando que el agua puede fluir en las 4 direcciones y escapa por los bordes.

La solución utiliza BFS con frontera mínima: se inicializa un min-heap con todas las celdas del borde, y se expande hacia el interior siempre desde la celda de menor altura disponible. Para cada vecino no visitado, si su altura es menor que el nivel actual, se acumula la diferencia como agua atrapada. El min-heap garantiza que siempre se conoce la barrera mínima real antes de procesar cualquier celda interior.

#### Invariante principal

El heap mantiene la propiedad de que la raíz siempre contiene la celda de menor altura disponible en la frontera. Durante el BFS, el nivel de agua nunca disminuye: se actualiza con `nivel = max(nivel, actual.altura)` garantizando que el agua calculada para cada vecino es siempre correcta respecto a la barrera mínima real que la rodea.

#### Complejidad

- Tiempo por operación: O(log(m·n)) para insert y delMax del heap
- Tiempo total: O(m·n·log(m·n)) ya que cada celda se inserta y extrae exactamente una vez
- Espacio: O(m·n) para el heap y la matriz de visitados

#### Archivos relevantes

- `include/` — Cabeceras de la solución: `solucion_optima.h`, `solucion_ingenua.h`, `leer.h` y los archivos de la librería `cc232`: `PQ.h`, `PQ_ComplHeap.h` y sus auxiliares
- `src/` — Implementaciones: `solucion_optima.cpp`, `solucion_ingenua.cpp`, `leer.cpp`
- `tests/` — Pruebas con assert: `test.cpp` con 9 pruebas incluyendo casos borde
- `demos/` — Programas demostrativos con entrada manual: `demo_optima.cpp`, `demo_ingenua.cpp`
- `docs/respuestas_obligatorias.md` — Respuestas a las preguntas comunes y específicas del problema
- `docs/bitacora.md` — Bitácora de desarrollo por días
- `resultados/` — Evidencia reproducible: `ejecucion_pc3.txt`, `tests_pc3.txt`, `casos_borde.txt`

#### Limpieza del repositorio

El repositorio no debe versionar builds, ejecutables ni archivos generados.

No deben aparecer archivos como:

- `build/`
- `cmake-build-*`
- `.exe`
- `.out`
- `.o`
- `.obj`
- `CMakeCache.txt`
- `CMakeFiles/`
- `__pycache__/`

Comando sugerido para verificar archivos generados versionados:

```bash
git ls-files | grep -E "(^build/|cmake-build|\.exe$|\.out$|\.o$|\.obj$|CMakeCache.txt|CMakeFiles|__pycache__)"
```

Si el comando muestra resultados, deben eliminarse del repositorio y agregarse al `.gitignore`.

#### Compilación

El proyecto debe compilar desde una copia limpia del repositorio.

```bash
cmake -S . -B build
cmake --build build
```

#### Ejecución

```bash
./build/demo_optima.exe
./build/demo_ingenua.exe
./build/unit_tests.exe
./build/benchmark.exe
```

#### Pruebas

1. **Caso mínimo 3x3** — entrada: grilla 3x3 con bordes altura 3 e interior altura 1 — salida esperada: 2 — salida obtenida: 2 — valida el caso mínimo posible para retener agua
2. **Sin agua acumulable** — entrada: grilla con interior más alto que los bordes — salida esperada: 0 — salida obtenida: 0 — valida que no se calcule agua negativa
3. **Todas las celdas iguales** — entrada: grilla 4x4 con todas las celdas en altura 2 — salida esperada: 0 — salida obtenida: 0 — valida el manejo de empates de altura
4. **Caso extremo verificable a mano** — entrada: grilla 5x5 con bordes altura 4 e interior alternado entre 1 y 2 — salida esperada: 23 — salida obtenida: 23 — valida el cálculo correcto en un caso complejo
5. **Comparación contra solución ingenua** — entrada: mapa irregular 5x6 — salida óptima: 13 — salida ingenua: 23 — valida que la ingenua falla en mapas irregulares y la óptima da el resultado correcto
6. **Invariante del heap** — entrada: grilla simétrica 5x5 — salida esperada: 10 — salida obtenida: 10 — valida que el nivel nunca disminuye durante el procesamiento
7. **Grilla menor a 3x3** — entrada: grilla 2x2 — salida esperada: 0 — salida obtenida: 0 — valida el caso borde de grilla sin celdas interiores
8. **Grilla de una sola fila** — entrada: vector de 5 elementos — salida esperada: 0 — salida obtenida: 0 — valida el caso borde de grilla sin dimensión vertical

#### Evidencia Git

El video debe iniciar mostrando el historial de commits, fechas, archivos modificados y explicación del proceso real de desarrollo.

Comandos obligatorios:

```bash
git status
git log --date=short --pretty=format:"%ad - %h - %an - %s"
git log --date=short --pretty=format:"%ad" | sort | uniq -c
git log --graph --oneline --decorate --all
git log --date=short --name-status --pretty=format:"%ad - %h - %s" -- Semana4 Semana5 Semana6 Practicas practica-calificada3
git log --date=short --stat --pretty=format:"%ad - %h - %s"
```

#### Preguntas obligatorias

Las respuestas completas se encuentran en `docs/respuestas_obligatorias.md`. Se responde explícitamente:

- Las preguntas comunes del curso
- Las preguntas específicas del problema Trapping Rain Water II
- La relación con Semanas 4-6
- El invariante del heap
- La complejidad por operación y total
- Los casos borde
- La modificación grabada

#### Bitácora obligatoria

El archivo `docs/bitacora.md` resume el proceso real de desarrollo día a día, incluyendo la elección de estructura, implementación, errores encontrados y pruebas agregadas. Las entradas coinciden con los commits del repositorio.

#### Respuestas obligatorias

El archivo `docs/respuestas_obligatorias.md` contiene respuestas claras y numeradas a las preguntas comunes y específicas del problema asignado, vinculadas a funciones concretas del repositorio.

#### Declaración de autoría

Declaro que entiendo el código entregado, que puedo explicarlo, compilarlo, ejecutarlo y modificarlo sin ayuda externa durante la grabación.
También declaro que el repositorio entregado corresponde al trabajo mostrado en el video y que no contiene builds, ejecutables ni archivos generados usados para aparentar funcionamiento.
