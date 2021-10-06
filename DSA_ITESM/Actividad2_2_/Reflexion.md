# Reflexión

- Create:
  - add(T data): Este método agrega un valor al inicio de la lista. La complejidad es O(1) ya que solo tiene que crear un nuevo nodo y ponerle el resto de la lista al apuntador next
  - add(int index, T data): esta función tiene una complejidad de Tiempo : O(N) y Espacio : O(1), ya que no crea memoria adicional, y le conlleva n cantidad de movimientos llegar al index. En este algoritmo, se recorre hasta el index y se le asigna un nuevo nodo a la variable next de ese nodo y se le asigna la variable next del anterior al nuevo nodo.
- Read:
  - get_node(int index): En este caso se va moviendo la cabeza de la lista index veces. Retorna la cabeza en ese momento
  - get(int index): Estor retorna get_node(index)->Data. El tiempo es O(N) ya que le toma N movimientos llegar al index, y O(1)
- Update:

  - update(int index, T value): Se obtiene el nodo a actualizar con get_node(index) y se le agrega el valor con curr->value = value. La complejidad es la misma que leer un dato de cierto index O(N) y O(1)

- Delete:
  - delete(int index) : Para eliminar este nodo, se usa la funcion curr = get_node(index-1), despues se asigna next = curr->next, y se apunta curr->next a next->next, después se elimina next. La complejidad de esto es O(N) y O(1), la misma que es leer un dato de cierto index
