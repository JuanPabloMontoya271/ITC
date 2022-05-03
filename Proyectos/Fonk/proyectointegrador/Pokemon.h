#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
using namespace std;
// José Pablo Fong Coronado - A01252402
class Pokemon{
    public:
        Pokemon();  // constructor por defecto
        Pokemon(int, string, string, string); // constructor con parámetros

        int getNivel() const; //getter de nivel
        string getNombre() const; // getter de nombre
        string getRegion() const; // getter de region
        string getTipo() const; // getter de tipo

        void setNivel(int); //setter de nivel
        void setNombre(string); //setter de nombre
        void setRegion(string); //setter de region
        void setTipo(string); //setter de tipo

        void imprimePokemon();

    private:
        int nivel;
        string nombre;
        string region;
        string tipo;
};
#endif //POKEMON_H