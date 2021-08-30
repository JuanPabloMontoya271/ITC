#include <iostream>
#include "suma.hpp"

Suma::Suma(int limite)
{
    limite_ = limite;
}

int Suma::iterativa()
{
    int suma = 0;
    for (int i = 1; i <= limite_; i++)
        suma += i;
    return suma;
}

int Suma::recursiva()
{
    return asistente_recursivo(limite_);
}

int Suma::asistente_recursivo(int limite)
{

    if (limite == 1)
        return limite;
    else
        return limite + this->asistente_recursivo(limite - 1);
}

int Suma::directa()
{
    return limite_ * (limite_ + 1) / 2;
}