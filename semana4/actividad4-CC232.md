## Actividad 4-CC232

### Estudiante
- Jose Carlos Barrios Ponce

#### Bloque 1

1) LIFO (Last In, First Out): El último en entrar es el primero en salir. Como una pila de platos.

FIFO (First In, First Out): El primero en entrar es el primero en salir. Como una fila del banco.

2) Stack resuelve naturalmente esos problemas porque su comportamiento LIFO recuerda siempre lo último que hiciste o encontraste

3) Queue modela naturalmente procesos de espera y atención porque su comportamiento FIFO respeta el orden de llegada: el primero en entrar es el primero en ser atendido, igual que en una fila real del banco o supermercado.

4) Reemplazar recursión implícita por una estructura explícita significa usar una pila (Stack) que tú mismo manejas en lugar de dejar que el programa use la pila de llamadas de las funciones.

5) La información mínima que debe guardarse es el estado del punto de decisión que permita volver atrás y seguir explorando otras opciones.

6)  Ambas usan una Stack<char> y el mismo algoritmo de dividir entre la base, apilando los residuos. La version recursiva utiliza una pila de llamadas implicitamente para controlar cuando apilar mientras que la version iterativa usa un bucle while sin depender de llamadas recursivas.

7) La verificación iterativa necesita almacenar las aperturas pendientes porque cuando encuentras un paréntesis de cierre ), ] o }, debes comprobar que coincida con la última apertura que aún no se ha cerrado.

8) Necesita dos pilas porque separa dos tipos de información que se manejan de forma distinta: una Stack guarda los operandos, y otra Stack guarda los operadores (+, -, *, /, ^, !).

9) Son ejemplos naturales de backtracking porque ambos requieren explorar opciones y volver atrás cuando te quedas sin caminos válidos. 

10) La simulación bancaria no se modela bien con pila (LIFO) porque sería injusto: el último cliente llegaría a ser atendido primero, y los que llevan esperando mucho tiempo nunca saldrían.

11) La estructura auxiliar (como Stack o Queue) guarda el estado parcial del proceso en un momento dado. La correctitud depende de que esa estructura almacene exactamente la información necesaria y la maneje con las reglas adecuadas (LIFO o FIFO).

12) Resolver un problema significa encontrar una solución única o contar todas las soluciones posibles mientras que Simular un proceso significa modelar cómo evoluciona un sistema a través del tiempo, paso a paso, respetando reglas de llegada, atención y aleatoriedad.

#### Bloque 2 

| Archivo | Salida observable | Estructura central | Concepto |
|---------|-------------------|--------------------|----------|
| `demo_bank.cpp` | llegadas vs atendidos, colas por tiempo | `Queue` | FIFO para espera real |
| `demo_base_conversion.cpp` | `"30071"` (12345 en base 8) | `Stack` | pila invierte residuos |
| `demo_maze.cpp` | `(1,1) (2,1) (3,1) (3,2) (3,3)` | `Stack` + backtracking | LIFO permite retroceder |
| `demo_nqueens.cpp` | soluciones=2, `[1,3,0,2]` y `[2,0,3,1]` | `Stack` + backtracking | estado parcial con pila |
| `demo_paren_rpn.cpp` | RPN y valor numérico | dos `Stack` | operandos y operadores separados |
| `demo_stack_queue.cpp` | tope=9, frente=10 | `Stack` y `Queue` | LIFO vs FIFO básico |

1) La línea que imprime "Tope de la pila = 9" y "Frente de la cola = 10" deja clara la diferencia porque el 9 fue el último en entrar a la pila (después del 5 y 7) pero es el primero que se puede sacar, mientras que el 10 fue el primero en entrar a la cola (antes del 20 y 30) y es el primero que sale, mostrando así LIFO vs FIFO.

2) Imprimen exactamente "30071" para el número 12345 en base 8, sin ninguna diferencia entre la salida de toBaseRecursive y toBaseIterative.

3) La relación es que los paréntesis balanceados permiten que el evaluador convierta correctamente la expresión a RPN respetando la precedencia, y el RPN generado permite calcular el valor final sin ambigüedades.

4) solutions es la cantidad de tableros válidos encontrados (para N=4 son 2 soluciones), mientras que checks es el número total de veces que se comparó una reina candidata con las ya colocadas para ver si había conflicto. No miden lo mismo porque checks cuenta todos los intentos (incluyendo los que fallaron y llevaron a retroceder), mientras que solutions solo cuenta los intentos exitosos.

5) La secuencia de coordenadas muestra el orden exacto en que se recorrieron las celdas desde el inicio (1,1) hasta la meta (3,3), pasando por (2,1), (3,1) y (3,2). Eso demuestra que el algoritmo encontró un camino válido evitando las paredes (#).

6) Cada lista impresa en un instante t representa el estado de una ventanilla, mostrando los tiempos de atención restante de los clientes que están esperando en esa cola.

7) 

#### Bloque 3 (respuestas)

1) La prueba pública valida que `empty()` funciona antes y después de usar la pila, que `push()` agrega elementos, que `top()` devuelve el último elemento sin sacarlo, y que `pop()` saca los elementos en orden LIFO (el 9 antes que el 5), dejando la pila vacía al final.

2) La prueba pública valida que empty() funciona al inicio y al final, que enqueue() agrega elementos al final, que front() devuelve el primero sin sacarlo, y que dequeue() saca los elementos en orden FIFO (1, luego 2, luego 3), dejando la cola vacía.

3) Valida que las versiones recursiva e iterativa producen la misma representación correcta.

4) Valida que `parenRecursive` e `parenIterative` detectan correctamente expresiones balanceadas con distintos tipos de paréntesis `() [] {}`, y que fallan cuando el orden es incorrecto como en `"([)]"`. Además, prueba que ambas funciones manejan bien letras y operadores sin paréntesis.

5) Valida que `evaluateExpression` genera el RPN correcto (`"0 ! 1 + 2 3 ! 4 + ^ * 5 ! 67 - 8 9 + - -"`) y calcula el valor numérico exacto (2012) para la expresión `"(0!+1)*2^(3!+4)-(5!-67-(8+9))"`, comprobando que maneja factorial, potencias, paréntesis anidados y operadores binarios.

6) Valida que para N=4 se encuentran exactamente 2 soluciones, y que el vector `placements` contiene esas 2 soluciones, comprobando que el algoritmo de backtracking con pila funciona correctamente para un caso conocido.

7) Valida que findPath encuentra un camino desde (1,1) hasta (3,3) en un laberinto de 5x5 con paredes, comprobando que el camino no está vacío, que empieza en el origen y que termina en el destino, demostrando que el backtracking con pila funciona.

8) Valida que bestWindow devuelve el índice de la ventanilla con menos clientes esperando. En la prueba, la ventanilla 0 tiene 2 clientes, la 1 tiene 1 cliente y la 2 está vacía, por lo tanto elige correctamente el índice 2.

9) La prueba interna cubre casos borde que no están en la pública: conversión del número 0 (da "0") y de 255 a base 16 (da "FF"), expresiones sin paréntesis y con órdenes incorrectos como `")()("` y `"{[(])}"`, evaluaciones simples como `"3+4*2"` y factorial con potencia, N=1 reina (1 solución), laberinto sin solución (camino vacío), validación de que `toBaseIterative` lanza excepción con base inválida (1), y verificación de que en simulación `totalArrivals >= totalServed`.

10) Pasar pruebas solo confirma que el código funciona para ciertos casos de entrada, pero no explica por qué funciona.

11) Usar una Queue en lugar de un Stack para el backtracking del laberinto. Las pruebas mínimas (como encontrar un camino simple) podrían pasar porque la cola también encuentra un camino, pero no sería el correcto por LIFO vs FIFO. El error conceptual (no entender que el backtracking necesita LIFO para retroceder) sobreviviría, pero fallaría en laberintos más complejos donde importa el orden de exploración.

#### Bloque 4

1) El residuo (n % base) es el dígito que se va a guardar, el cociente (n / base) es lo que sigue dividiéndose hasta llegar a cero, y la pila guarda los residuos en orden inverso al que se generan. Al final, desapilar invierte el orden y da la representación correcta en la base deseada.

2) Porque el algoritmo genera el primer residuo (el dígito menos significativo) primero, pero en la representación final ese dígito debe ir al final. Apilarlos los guarda en orden inverso, y al desapilarlos se obtienen en el orden correcto.

3) En la versión recursiva, el call stack guarda automáticamente los estados pendientes (el cociente y el punto de retorno) en cada llamada. En la versión iterativa con pila explícita, tú mismo apilas los residuos en un Stack y controlas el bucle while.

4) divideParentheses busca el punto donde se cierra el primer bloque de paréntesis principal, es decir, encuentra la posición mi donde el contador de paréntesis abiertos vuelve a cero por primera vez.

5) La versión recursiva parenRecursive solo maneja paréntesis redondos (), por lo que no puede verificar [] ni {}. En cambio, la versión iterativa parenIterative usa una pila y verifica los tres tipos de pares: (), [], {}.

6) Porque al encontrar un cierre (como ) o ] o }), la función inmediatamente verifica si la pila está vacía (no hay apertura pendiente) o si el tope de la pila no coincide con el cierre esperado (por ejemplo, tope ( con cierre ]). En cualquiera de esos casos, retorna false en ese mismo instante, sin seguir procesando el resto de la cadena.

7) La versión iterativa es más natural para verificar paréntesis con `parenIterative`, porque recorrer la cadena con un bucle y usar una pila explícita refleja directamente cómo una persona revisaría el balance. La versión recursiva es más expresiva para la conversión de bases con `toBaseRecursive`, porque la definición matemática de conversión (n = base * cociente + residuo) es inherentemente recursiva y se lee de forma muy clara y elegante.


#### Bloque 5 (respuestas y experimento 3)

1) EvaluationResult guarda dos cosas: value (el resultado numérico de evaluar la expresión) y rpn (la expresión convertida a notación polaca inversa como string).

2) Porque los espacios no tienen significado matemático y solo entorpecerían el análisis. Al quitarlos, el evaluador puede leer la expresión carácter por carácter sin saltarse espacios, facilitando la detección de números, operadores y paréntesis.

3) La función isUnaryMinus detecta que un '-' es unario cuando está al inicio de la expresión o va después de un '(' u otro operador ('+', '-', '*', '/', '^'), y además va seguido de un dígito o punto.

4) El factorial se trata como operador unario porque actúa sobre un solo operando (el número que lo precede), a diferencia de +, -, *, / que necesitan dos operandos. El código impone que el operando debe ser un entero: usa std::round(b) y verifica que la diferencia con el original sea menor a 1e-9, lanzando error si no es entero. Además, solo acepta números no negativos porque factorialInt lanza excepción con negativos.

5) La RPN se construye paso a paso durante la evaluación porque cada vez que se lee un número se agrega inmediatamente a la RPN, y cada vez que se va a evaluar un operador (cuando orderBetween devuelve >), ese operador también se agrega a la RPN justo antes de aplicarlo a los operandos.

6) Determina qué hacer: si '<' el nuevo operador tiene menor prioridad y se apila, si '>' el de tope tiene mayor prioridad y se evalúa primero, y si '=' es un paréntesis que cierra o el final de expresión y se descarta el tope.

7) Una expresión mal formada debe terminar en error porque producir un valor arbitrario sería engañoso: el usuario creería que el cálculo es correcto cuando en realidad la entrada tenía errores como operadores faltantes, paréntesis desbalanceados o división por cero.

8) La ventaja es que puedes verificar el proceso de evaluación: la RPN muestra el orden en que se aplicaron los operadores, y el valor es el resultado final. Si algo anda mal, comparar la RPN esperada con la generada ayuda a depurar.

#### Bloque 6 (respuestas y experimentos 4-5)

1) Dos reinas entran en conflicto si están en la misma fila (x igual), misma columna (y igual) o misma diagonal (x+y igual o x-y igual). El operador == devuelve true si hay conflicto.

2) La pila solution representa las reinas ya colocadas en el tablero. Cada Queen guarda su fila (x) y columna (y). La pila crece al avanzar a la siguiente fila y se reduce al retroceder cuando no hay columnas válidas.

3) Avanzar en columna significa probar la siguiente columna dentro de la misma fila cuando la actual no funciona. Se retrocede cuando se agotan todas las columnas de la fila actual, entonces se saca la reina anterior de la pila y se aumenta su columna para probar otra opción.

4) checks cuenta cuántas veces se comparó una reina candidata con las ya colocadas. Es útil porque muestra el esfuerzo real del algoritmo: más checks significa más intentos fallidos y más backtracking.

5) Cuando collectPlacements vale false, el algoritmo no guarda las soluciones en el vector placements.

6) 

AVAILABLE: celda libre no visitada.

ROUTE: celda que forma parte del camino actual.

BACKTRACKED: celda que ya se exploró y resultó en callejón sin salida.

WALL: pared que no se puede atravesar.

7) incoming guarda por dónde se llegó a la celda (dirección de entrada). outgoing guarda la próxima dirección a probar para salir de la celda.

8) Porque necesita recordar qué celdas ya exploró sin éxito (BACKTRACKED) para no volver a probarlas.

9) Ambos exploran un espacio de opciones, usan backtracking con pila para retroceder cuando fallan, y prueban candidatos en orden. En N-Reinas el estado es una lista de reinas colocadas (fila y columna). En laberinto el estado es una celda con coordenadas y sus direcciones de entrada/salida.

#### Bloque 7 (respuestas y experimento 6)
#### Bloque 8 (respuesta final)

#### Autoevaluación breve
- Qué puedo defender con seguridad:
- Qué todavía confundo:
- Qué experimento me dio mejor evidencia:
- Qué evidencia usaría en una sustentación:

