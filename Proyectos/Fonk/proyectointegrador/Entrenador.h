#ifndef ENTRENADOR_H
#define ENTRENADOR_H
#include <iostream>
using namespace std;
// José Pablo Fong Coronado - A01252402
class Entrenador{
    public:
        Entrenador();  // constructor por defecto
        Entrenador(int, string, string, string); // constructor con parámetros

        int getNivel() const; //getter de nivel
        string getNombre() const; // getter de nombre
        string getPuebloOrigen() const; // getter de pueblo origen
        string getFechaInicio() const; // getter de fecha de inicio

        void setNivel(int); //setter de nivel
        void setNombre(string); //setter de nombre
        void setPuebloOrigen(string); //setter de pueblo origen
        void setFechaInicio(string); //setter de fecha de inicio

        void imprimeEntrenador();
        void consultarInsignias();

    private:
        int nivel;
        string nombre;
        string puebloOrigen;
        string fechaInicio;
};
#endif //ENTRENADOR_H