Analisis de complejidad, actividad: 
Act 2.1 - Implementación de un ADT de estructura de datos lineales (Linked List)

Función add: Esta viene a ser de orden O(n), debido a que solamente es una serie de instrucciones en donde el unico iterador es un while, por tanto al no tener màs que este y ser un solo recorrido del mismo es de la orden antes mencionada.

Función find: Igualmente es O(n), esto por que justo como la funciòn add, esta siguiendo el ciclo solo una vez mientras que la direcciòn no sea nula, por ende es lineal y de orden O(n).

Función update: Nuevamente O(n), siguiendo la misma estructura en un ciclo while y recorriendo una sola vez nuestra estructura, siguiendo la complejidad ya mencionada como en las anteriores funciones.

Función remove: La complejidad es de orden O(n) nuevamente, por que pese a que el ciclo que se utilizo cambía, no cambia que igualmente solo esta haciendo un recorrido en nuestra estructura y si llega a ver que lo que queremos eliminar es igual es igual a dicho indice lo borra, teniendo nuevamente una funciòn de complejidad lineal.
