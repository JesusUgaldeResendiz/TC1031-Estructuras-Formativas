Analisis de complejidad - Jesús Ugalde Reséndiz A01706340

Act 3.2 - Árbol Heap: Implementando una fila priorizada


Función push: Esta función es de orden O(log(n)) debido a que esta recorre la lista por medio de un while con ayuda de parent el cual es su auxiliar para poder revisar en la posicion donde va a insertarse un nuevo elemento, no obstate tomando eso como punto de partida y que parent divide la posición para agilizar la inserción podemos entonces ahora si decir que gracias a la manera en que parent agiliza el metodo para hacerlo en menos pasos tiende a ser O(log(n))

Función pop: Así como push, este metodo pop funciona también gracias a un auxiliar el cual es en este caso el heapify, quien se encarga de revisar y arreglar las anomalias al momento de incluir nuevos elementos o eliminarlos, dependiendo del caso esta toma una rama de desiciones y termina simplificando los n pasos en el que se realiza la acción sinedo así de orden O(log(n)).

Función top: Para top a diferencia de las antes mencionadas tenemos que su complejidad es constante, esto debido a que unicamente toma el valor que recibe y ese mismo es el que te regresa, por lo tanto tiende a ser O(1).

Función empty: Así como en top solamente nos regresa un valor, o mejor dicho en este caso el estado de una condición en la estructura, por lo cual hace un trabajo director y tiende a ser de orden O(1).

Funcion size: Nos encontramos en la misma situación que top y que empty pues unicamente nos regresa un valor establecido en nuestro array de punteros, por lo cual esta funcion se mantiene como O(1).
