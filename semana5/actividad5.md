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

2) 

### Bloque 3 - Recorridos y trazado guiado

[Tabla y respuestas]

### Bloque 4 - Demos

[Tabla y respuestas]

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