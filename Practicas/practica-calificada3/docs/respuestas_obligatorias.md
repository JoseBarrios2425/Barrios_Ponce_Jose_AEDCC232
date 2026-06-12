## Preguntas comunes obligatorias

1) ¿Qué recibe la entrada y qué produce la salida?

La función recibe un heightMap, que es una matriz 2D de enteros de tamaño m x n donde cada valor representa la altura del terreno en esa celda. Produce un entero que representa el volumen total de agua atrapada después de llover, considerando que el agua puede fluir en las 4 direcciones (arriba, abajo, izquierda, derecha) y escapa libremente por los bordes de la grilla.

2) ¿Cuál es la restricción que vuelve insuficiente una solución ingenua?

El agua no fluye solo en línea recta. En una grilla 2D, el agua puede escapar por caminos diagonales o irregulares que rodean las paredes. La solución ingenua asume que la barrera de cada celda es el máximo en sus 4 direcciones lineales, ignorando que el agua puede encontrar un camino de escape más bajo que no está alineado horizontalmente ni verticalmente. Esto hace que la solución ingenua falle en mapas irregulares.

3) ¿Cuál sería la solución ingenua y cuál es su complejidad?

La solución ingenua recorre cada celda interior y para cada una busca el máximo en las 4 direcciones usando 4 recorridos lineales. La barrera de esa celda es el mínimo de esos 4 máximos. Si la barrera es mayor que la altura de la celda, acumula la diferencia como agua. Su complejidad es O(m · n · (m + n)) porque para cada una de las m·n celdas se hacen recorridos de longitud m o n.

4) ¿Qué estructura de datos elegiste?

Se eligió un min-heap implementado mediante PQ_ComplHeap de la librería cc232, configurado con el comparador CompararCelda que ordena las celdas por altura de menor a mayor. Esta estructura permite siempre extraer la celda de menor altura disponible en la frontera, que es exactamente lo que necesita el algoritmo BFS con frontera mínima.

5) ¿Qué estructura de la librería cc232 se parece más?

La estructura más cercana es PQ_ComplHeap, que es un heap completo basado en arreglo (vector).

6) ¿Qué operación domina el tiempo?

La operación que domina es el insert y delMax del heap, ambas de complejidad O(log(m·n)) porque cada operación puede recorrer toda la altura del árbol. 

7) ¿Qué invariante mantiene tu estructura?

El heap mantiene el invariante de que la raíz siempre contiene la celda de menor altura disponible en la frontera. Esto garantiza que el nivel de agua nunca disminuye durante el procesamiento.

8) ¿Dónde se actualiza ese invariante en el código?

El invariante se actualiza en esta línea dentro del bucle principal de solucion_optima.cpp: nivel = max(nivel, actual.altura);

9) ¿Qué caso borde puede romper una solución superficial?

Un mapa donde el camino de escape del agua no es recto sino diagonal o irregular. Por ejemplo si hay una celda baja en el interior pero conectada a un borde por un camino que rodea las paredes, una solución superficial como la ingenua asume que está bloqueada en las 4 direcciones lineales y sobreestima el agua.

10) ¿Cómo manejas duplicados, empates o elementos obsoletos?

Los duplicados y empates de altura se manejan naturalmente porque el heap simplemente los ordena por altura y los procesa en cualquier orden entre ellos, sin afectar el resultado final. No hay elementos obsoletos porque la matriz visitado garantiza que cada celda se inserta al heap exactamente una vez, evitando que una misma celda sea procesada dos veces.

11) ¿Cuál es la complejidad temporal por operación?
- insert: O(log(m·n)) — agrega al final del vector y sube con percolateUp
- delMax: O(log(m·n)) — mueve la raíz al final y baja con percolateDown
- getMax: O(1) — solo retorna el primer elemento del vector

12) ¿Cuál es la complejidad total?

La complejidad total es O(m·n·log(m·n)),cada una de las m·n celdas se inserta y extrae del heap exactamente una vez, y cada operación cuesta O(log(m·n)).

13) ¿Cuál es la complejidad espacial?

La complejidad espacial es O(m.n), se usan tres estructuras auxiliares proporcionales al tamaño de la grilla:
- El heap almacena como máximo m·n celdas
- La matriz visitado ocupa m·n booleanos
- El vector direcciones es constante O(1)

## Preguntas específicas 

1) ¿Por qué se usa un min-heap en lugar de una cola simple?

Con una cola simple (BFS normal) las celdas se procesan en orden de llegada, no en orden de altura. Esto significa que podrías procesar una celda alta antes que una celda baja adyacente, calculando mal el nivel de agua para sus vecinos. El min-heap garantiza que siempre se procesa primero la celda de menor altura disponible en la frontera, lo que asegura que cuando se evalúa un vecino, ya se conoce la barrera mínima real que lo rodea hacia el exterior.

2) ¿Qué representa la frontera actual de celdas procesadas?

La frontera representa el conjunto de celdas que forman el "muro" más bajo conocido entre el exterior (bordes) y el interior no procesado aún. Al inicio la frontera son todos los bordes de la grilla. A medida que el algoritmo avanza, la frontera se expande hacia el interior, siempre desde la celda de menor altura disponible.

3) ¿Qué caso falla si se procesa una celda antes de conocer la menor barrera posible?

Supón una grilla donde hay dos caminos hacia el exterior desde una celda interior: uno con barrera de altura 5 y otro con barrera de altura 2. Si se procesa esa celda usando la barrera de altura 5 porque llegó primero a la cola, se calcularía 5 - altura_celda unidades de agua, cuando en realidad el agua escaparía por el camino de altura 2, acumulando solo 2 - altura_celda unidades. El resultado sería una sobreestimación del agua retenida.