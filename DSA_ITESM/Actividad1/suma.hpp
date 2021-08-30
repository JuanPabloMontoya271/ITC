#pragma once

class Suma
{
public:
    Suma(int);
    int iterativa();
    int recursiva();
    int directa();

private:
    int limite_;
    int asistente_recursivo(int);
};