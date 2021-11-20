# Juan Pablo Montoya

# A01251887

## Puntos Clave a considerar

- Para iniciar el programa debe correr el archivo main. Ahí se encuentra solamente la función principal, todo lo demás está escrito en header y implementation files.
  El programa hace:
- Ordenamiento con los siguientes algoritmos:
  - Bubble Sort
  - Selection Sort
  - Merge Sort
- Busqueda con los siguientes algoritmos:
  - Binary Search
  - Linear Search
- Se dividió el proyecto en tres submodulos:
  - Database: Contiene las clases de los algoritmos
  - DateParser: Contiene las clases de el manejo de archivos y fechas, así comoo el de las estructuras de almacenamiento utilizadas y las estructuras de datos implementadas
  - Interface: En esta parte se escribió el código que tiene que ver con la interacción del usuario con el programa. Esta parte pudo estar escrita de una manera más limpia, pero por cuestiones de tiempo, decidí dejarla así.
- Puntos de Mejora:
  - La memoria aún no está optimizada en este proyecto, traté de hacer una implementación de smart pointers para optimizar el uso de memoria y evitar copias innecesarias, sin embargo, esto complicaba arduamente la tarea, ya que iba a tener que reescribir los algoritmos de parsing para evitar ciertos problemas de manejo de memoria.

  - Implementar heapsort, un algoritmo aún más eficiente para ordenar los datos
  - La interfaz puede tener más manejo de edge cases
