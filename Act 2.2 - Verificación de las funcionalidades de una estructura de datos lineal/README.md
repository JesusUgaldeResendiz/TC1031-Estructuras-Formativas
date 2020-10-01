Analisis de complejidad - Jesús Ugalde Reséndiz

Actividad: Act 2.2 - Verificación de las funcionalidades de una estructura de datos lineal

Función add: Es de orden O(n), lineal, esto debido a que solo sigue una serie de instrucciones que pasa a tomar acciónes por medio de condicionales dependiendo de la condición de la lista existente.

Función find: De igual manera es de orden O(n), es decir lineal, debido esto a que si bien es ciclada, solo lo es una vez por un ciclo while, el cual definiria su orden de complejidad.

Función update: Se mantiene también como un algoritmo de orden lineal, es decir O(n), debido a que obedece la misma estructura que el find, solo que con distintas instrucciones en su contenido.

Función remove: Como las ya mencionadas anteriormente es O(n), esto por que pese a que en el algoritmo find encontramos ciclos if anidados, el que realmente nos define su orden de complejidad es el while, y al existir solo uno este es de orden lineal.

