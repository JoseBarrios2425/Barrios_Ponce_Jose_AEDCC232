## Actividad 3-CC232

### Estudiante

- Nombre: Jose Carlos Barrios Ponce

#### Bloque 1

1. Pasa de ser un bloque fijo donde la posicion del elemento es un valor importante a otra donde no existen posiciones solo existe la relacion entre nodos.

2. El acceso por rango te permite acceder directamente a cualquier elemento usando su posición(índice) mientras que el acceso por enlace debe utilizar punteros para recorrer desde el inicio a la posición deseada.

3. Mejora las inserciones y eliminaciones locales porque no necesita mover datos, solo cambiar conexiones entre los nodos. Empeora el acceso por indice porque los nodos no estan juntos en memoria y debe recorrer desde el inicio hasta el elemento que busca.

4. Las implementa bien por el uso de los punteros head (incio de la lista) y tail (final de la lista) lo que permite operar en ambos exxtremos de la lista.

5. 

6. El dummy es un nodo especial que no guarda datos, pero actúa como punto fijo que conecta el inicio y el final de la lista.

7. Se da porque para realizar estas operaciones primero se debe llegar al nodo i donde se aplicaran, ese recorrido hacia i siempre es de la misma forma, si i esta cerca del inicio avanza desde head y si esta cerca del final retrocede desde tail, entonces se recorre min(i,n-i). Luego el costo = recorrido + operacion(es constante) obteniendo O(1 + min(i,n-i)).

8. La idea espacial central de SEList es agrupar elementos en bloques (mini-arreglos) dentro de una lista enlazada, en lugar de guardar un elemento por nodo.

9. SEList usa BDeque (basada en ArrayDeque) para implementar cada bloque como un arreglo dinámico eficiente que permite inserciones y eliminaciones en tiempo constante amortizado, facilitando el manejo interno de los bloques.

10. DengList actúa como una capa de adaptación sobre CleanList para usar una interfaz más limpia o consistente.

#### Bloque 2
## Tables
| Archivo       | Salida u observable importante | Idea estructural| Argumento de costo, espacio o diseño|
| ------------- |:-------------:|:--------------------: |:------------------:|
| left foo ds     | right foo     |                   |                    |
| left bar      | right bar     |                  |                     
| left baz      | right baz     |           |                                

#### Bloque 3

(respuestas)

#### Bloque 4

(respuestas)

#### Bloque 5

(respuestas)

#### Bloque 6

(respuestas)

#### Bloque 7

(respuestas)

#### Bloque 8

(respuesta final)

#### Autoevaluación breve

- Qué puedo defender con seguridad:
- Qué todavía confundo:
- Qué evidencia usaría en una sustentación:
## Tables

| Left columns  | Right columns |
| ------------- |:-------------:|
| left foo      | right foo     |
| left bar      | right bar     |
| left baz      | right baz     |

## Blocks of code

```
let message = 'Hello world';
alert(message);
```

