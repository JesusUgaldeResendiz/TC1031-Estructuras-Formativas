ANALISIS DE COMPLEJIDAD - Jesús Ugalde Reséndiz

Act 3.3 - Árbol Desplegado: Implementando un Splay Tree

Función add: El algortimo add se realiza en cierto numero de iteraciones debido a que toma como auxiliar la función add de la clase Node ademas de que igualmente debe de revisar si el arbol se encuentra o no vacio para agregar datos al splay, posteriormente el arbol es ordenado con el nuevo valor como root, entonces es quelos demas valores se comparan con este teniendo así que su complejidad es de orden O(log(n))

Función remove: Para este metodo la complejidad es igualmente O(log(n)) pues igualmente se comporta de tal manera que utiliza un n numero de pasos en el que determina el como se eliminara el valor del splay, pero se divide en dos diferentes etapas, primero buscando en todo el arbol el valor a eliminar para despues realizar un splay en el parent, hasta ahí tenemos que es O(n) pero gracias a los splays se va balanceando el arbol y resulta en una complejidad O(log(n)). 

Función find: Este metodo funciona de tal manera que lo que hace inicialmente recorriendo el arbol para así encontrar un valor que seria el predesecor, funcionando de manera muy parecida a el arbol de busqueda binaria, no obstante gracias a la acción constante de la función splay, este acorta pasos y se transforma en una complejidad de O(log(n).

Función inorder: Inorder a diferencia de las anteriores funciones recorre todos los objetos que tiene el arbl, y posteriormente los imprime, a lo que si recorre el arbol, tenemos que sigue una iteración de n pasos que lo transforma automaticamente en un algortimo de orden lineal, es decir O(n).

Función size: Como size unicamente nos retorna el valor de uno de los atributos de nuestro arbol mantiene una instrucción constante, siendo de una orden de O(1) constante.
