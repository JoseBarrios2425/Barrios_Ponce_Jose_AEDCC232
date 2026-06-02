## Actividad 5 - CC232

### Estudiante

- Nombre: Jose Carlos Barrios Ponce

### Bloque 1 - Núcleo conceptual

1) En un  arbol binario enlazado la relación entre padre e hijo se da mediante dos punteros, uno al hijo izquierdo y otro al hijo derecho, mientras que en el arbol binario almacenado en un arreglo no hay punteros, la posición del índice codifica la relacion entre padre-hijo mediante formulas matematicas.

2) 
dato: Es el valor que almacena el nodo.

padre: Puntero al nodo que lo contiene.

hijoIzq: Puntero al hijo izquierdo.

hijoDer: Puntero al hijo derecho.

altura: Es la profundidad del subárbol.

3) El puntero parent permite moverse hacia arriba en el árbol. Sin él, desde un nodo solo se podria bajar hacia los hijos, quedando atrapado en esa rama. En succ(), pred() y la actualizacion ascendente de alturas es necesario subir por las ramas del arbol, sin parent es imposible aplicar estas funciones.

4) Se puede decir que BinNode trabaja desde la perspectiva de un nodo mientras que BinTree administra el árbol completo.

5) BinaryTree hereda todo de BinTree y agrega 2 cosas: iteradores y consultas de posición.

6) La propiedad es el invariante de orden, para todo nodo n, todos los valores en su subarbol izq son menores  y todos en su subarbol derecho son mayores. El invariante garantiza que buscar, insertar y eliminar cuesten O(h) en lugar de O(n). 

7) La propiedad es que todo nodo es menor o igual que sus hijos.

8) 
Propiedad BST: izquierda < nodo < derecha

Propiedad Heap (mínimo): padre <= ambos hijos

El BST ordena todos los elementos entre si. Saber que un valor está a la izquierda te dice su relación con los demas nodos. El heap solo ordena hacia arriba. Saber que unj nodo es hijo de otro solo te dice que el padre es menor.

9) El recorrido inorden visita los nodos en el orden de izquierda, nodo y derecha (esta en orden), en inorden se aplica esto en cada nodo entonces los subarboles producen valores ordenados, lo que da la secuencia ordenada completa.

10) Porque el heap no tiene orden global, solo garantiza que el padre es menor que sus hijos pero dos hermanos pueden estar en cualquier orden entre sí.

### Bloque 2 - Navegación, altura, profundidad y tamaño

1) Todos son metodos de consulta

hasLeft(): Tiene hijo izquierdo?

hasRight(): Tiene hijo derecho?

isRoot(): es la raiz del arbol?

isLeaf(): es una hoja (no tiene hijos)?

isLeaftChild(): es el hijo izquierdo de su padre?

isRightChild(): es el hijo derecho de su padre?

2) En el método succ(), si el nodo actual tiene hijo derecho, el sucesor inorder será el nodo más pequeño de ese subárbol derecho. Por eso primero se baja al hijo derecho y luego se continúa avanzando por los hijos izquierdos hasta llegar al nodo más a la izquierda; ese nodo es el siguiente que se visitaría en un recorrido inorder.

3) Si el nodo no tiene hijo derecho, succ() sube por los ancestros mientras el nodo actual sea hijo derecho de su padre. Cuando encuentra el primer ancestro del que proviene por la izquierda, ese ancestro es el sucesor inorder, porque es el siguiente nodo que se visitaría después de terminar todo el subárbol donde se encontraba el nodo original.

4) El método pred() funciona de manera simétrica a succ(). Si el nodo tiene hijo izquierdo, el predecesor inorder es el nodo más grande de ese subárbol izquierdo, por lo que baja al hijo izquierdo y luego avanza por los hijos derechos hasta llegar al más a la derecha. Si no tiene hijo izquierdo, sube por los ancestros mientras sea hijo izquierdo de su padre; cuando encuentra el primer ancestro del que proviene por la derecha, ese ancestro es el predecesor inorder, ya que es el nodo visitado inmediatamente antes en un recorrido inorder.

5) 

6) depth(u) calcula la profundidad de un nodo, es decir, la cantidad de aristas que lo separan de la raíz. Se implementa subiendo mediante el puntero parent porque cada nodo conoce a su padre; entonces basta con avanzar desde el nodo hasta la raíz contando cuántos niveles se recorren.

7) height(u) calcula la altura de un nodo, es decir, la longitud del camino más largo desde ese nodo hasta una hoja. Se implementa recursivamente bajando por los hijos porque para conocer la altura de un nodo es necesario conocer primero las alturas de sus subárboles izquierdo y derecho; luego se toma la mayor de ambas y se suma 1. En esta implementación, un nodo nulo tiene altura -1 y una hoja tiene altura 0. 

8) subtreeSize(u) calcula la cantidad total de nodos que existen en el subárbol cuya raíz es el nodo u, incluyendo al propio nodo. Se implementa de forma recursiva sumando 1 (el nodo actual) más el tamaño del subárbol izquierdo y el tamaño del subárbol derecho. Si el nodo es nullptr, el tamaño es 0.

9) Sea u un nodo cualquiera. La profundidad depth(u) es la distancia desde la raíz hasta u, y la altura height(u) es la distancia desde u hasta la hoja más profunda de su subárbol. Si unimos ambos recorridos obtenemos un camino desde la raíz hasta una hoja del árbol que pasa por u, cuya longitud es depth(u) + height(u). Como la altura del árbol height(T) es la longitud máxima de cualquier camino desde la raíz hasta una hoja, necesariamente se cumple que depth(u) + height(u) ≤ height(T).

10) La igualdad depth(u) + height(u) = height(T) se cumple si y solo si el nodo u pertenece a un camino de longitud máxima desde la raíz hasta una hoja más profunda del árbol. Es decir, u debe estar sobre alguna de las ramas que determinan la altura del árbol; en caso contrario, el camino que pasa por u será más corto que la altura máxima y la desigualdad será estricta.



### Bloque 3 - Recorridos y trazado guiado

| Recorrido | Versión revisada | Estructura auxiliar usada | Secuencia producida en el árbol de prueba | Argumento de correctitud y costo |
|------------|-----------------|---------------------------|------------------------------------------|----------------------------------|
| Preorden | Recursivo (`travPre`) | Pila implícita de recursión | 7, 3, 1, 5, 4, 6, 10, 8, 12 | Visita primero la raíz, luego el subárbol izquierdo y finalmente el derecho. Tiempo O(n), espacio O(h). |
| Preorden | Iterativo (`travPreIterative2`) | Pila explícita (`stack`) | 7, 3, 1, 5, 4, 6, 10, 8, 12 | Inserta primero el hijo derecho y luego el izquierdo para mantener el orden raíz-izquierda-derecha. Tiempo O(n), espacio O(h). |
| Inorden | Recursivo (`travInRecursive`) | Pila implícita de recursión | 1, 3, 4, 5, 6, 7, 8, 10, 12 | Recorre izquierda-raíz-derecha. Produce los elementos en orden creciente para un BST. Tiempo O(n), espacio O(h). |
| Inorden | Iterativo #1 (`travInIterative1`) | Pila explícita (`stack`) | 1, 3, 4, 5, 6, 7, 8, 10, 12 | Simula la recursión apilando el camino izquierdo y visitando al retroceder. Tiempo O(n), espacio O(h). |
| Inorden | Iterativo #2 (`travInIterative2`) | Punteros `parent`, `prev` y `curr` | 1, 3, 4, 5, 6, 7, 8, 10, 12 | Navega por el árbol usando relaciones padre-hijo sin pila adicional. Tiempo O(n), espacio O(1). |
| Inorden | Iterativo #3 (`travInIterative3`) | Sucesor inorder (`succ`) | 1, 3, 4, 5, 6, 7, 8, 10, 12 | Comienza en el nodo más a la izquierda y avanza mediante sucesores hasta terminar el recorrido. Tiempo O(n), espacio O(1). |
| Postorden | Recursivo (`travPost`) | Pila implícita de recursión | 1, 4, 6, 5, 3, 8, 12, 10, 7 | Visita izquierda-derecha-raíz. Garantiza que un nodo se procesa después de sus hijos. Tiempo O(n), espacio O(h). |
| Postorden | Iterativo (`travPostIterative`) | Dos pilas (`stack`) | 1, 4, 6, 5, 3, 8, 12, 10, 7 | La primera pila genera un orden inverso y la segunda restaura el orden postorden correcto. Tiempo O(n), espacio O(n). |
| Por niveles | Level Order (`travLevel`) | Cola (`queue`) | 7, 3, 10, 1, 5, 8, 12, 4, 6 | Visita los nodos nivel por nivel utilizando una cola FIFO. Tiempo O(n), espacio O(w), donde w es el ancho máximo del árbol. |

1) Visitar un nodo en preorden significa procesarlo antes que a sus hijos. Esto ocurre cuando se ejecuta visit(*this) al inicio del recorrido, por lo que el orden es raíz → subárbol izquierdo → subárbol derecho.

2) Visitar un nodo en inorden significa procesarlo después de recorrer completamente su subárbol izquierdo y antes de recorrer su subárbol derecho. El orden es subárbol izquierdo → raíz → subárbol derecho.

3) Visitar un nodo en postorden significa procesarlo únicamente después de haber recorrido completamente sus dos subárboles. El orden es subárbol izquierdo → subárbol derecho → raíz.

4) Visitar un árbol por niveles significa recorrer sus nodos nivel por nivel, de arriba hacia abajo y de izquierda a derecha dentro de cada nivel. Primero se visita la raíz, luego todos sus hijos, después todos los nietos, y así sucesivamente.

5) Los recorridos recursivos tienen tiempo O(n) porque cada nodo del árbol se visita exactamente una vez y en cada visita se realiza una cantidad constante de trabajo (procesar el nodo y hacer llamadas a sus hijos). Como hay n nodos y ninguno se procesa más de una vez, el tiempo total es proporcional al número de nodos del árbol.

6) Las versiones iterativas también tienen tiempo O(n) porque, aunque utilizan estructuras auxiliares como pilas o colas, cada nodo del árbol se procesa una sola vez. Las operaciones de insertar o retirar un nodo de una pila o cola cuestan O(1), por lo que al realizarse una cantidad proporcional a los n nodos, el tiempo total sigue siendo O(n).

7) 


### Bloque 4 - Demos

| Archivo | Salida u observable importante | Idea estructural | Argumento de costo, espacio o diseño |
|----------|-------------------------------|------------------|--------------------------------------|
| `demo_binary_tree.cpp` | Muestra recorridos, sucesor, predecesor, altura y profundidad del árbol. | Uso de un árbol binario general con enlaces a padre e hijos. | Todos los recorridos visitan cada nodo una vez: O(n). El espacio auxiliar depende de la altura del árbol. |
| `demo_bst.cpp` | Muestra búsquedas, eliminación, rotaciones y construcción balanceada de un BST. | Mantiene la propiedad BST: izquierda < nodo < derecha. | Las operaciones de búsqueda, inserción y eliminación cuestan O(h), donde h es la altura del árbol. |
| `demo_heap.cpp` | Verifica el heap, inserta elementos y extrae mínimos en orden creciente. | Heap mínimo implementado sobre un vector. | `add()` y `remove()` cuestan O(log n); `top()` cuesta O(1); `heapify()` cuesta O(n). |
| `demo_capitulo5_panorama.cpp` | Integra BinaryTree, BST y Heap en un único ejemplo de uso. | Muestra cómo las estructuras comparten interfaces y utilidades comunes. | El iterador del BST permite recorrido STL-like en tiempo O(n) y espacio O(1) adicional. |

1) La salida que permite verificarlo son las líneas impresas por printVector() para cada recorrido, como "Preorden recursivo", "Inorden recursivo", "Postorden recursivo", "Niveles" y sus versiones iterativas. Al comparar las secuencias obtenidas con el árbol construido en el demo, se puede comprobar que cada algoritmo visita los nodos exactamente en el orden que define su recorrido correspo

### Bloque 5 - Pruebas e invariantes

[Respuestas]

### Bloque 6 - Lectura cercana de código

[Respuestas]

### Bloque 7 - BST

[Respuestas, trazados y argumentos]

### Bloque 8 - Heap

[Respuestas, trazados y argumentos]

### Bloque 9 - Cierre comparativo

[Respuesta final]

### Autoevaluación breve

- Qué puedo defender con seguridad:
- Qué todavía confundo:
- Qué evidencia usaría en una sustentación:
- Qué parte del código me parece más importante para revisar otra vez:

## Blocks of code

```
let message = 'Hello world';
alert(message);
```