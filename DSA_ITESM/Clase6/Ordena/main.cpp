#include <iostream>
#include "Orden.cpp"
#include "search.cpp"

int main()
{

    int array[10] = { 2,4,5,6,7,3,2,4,5,6 };

    int array2[7] = { 29,3,42,17,30,15,8 };

    //Orden::ordSeleccion(array2, 7);

    //Orden::ordIntercambio(array, 10);
    //Orden::burbuja(array, 10);

    Orden::ordInsercion(array2, 7);

    for (int i = 0; i < 7; i++)
        std::cout << array2[i] << " ";

    int a = search::busquedaBin(array2, 7, 29);

    std::cout << std::endl;

    if (a == 0)
        std::cout << "nel";
    else
        std::cout << "si" << a;




}

