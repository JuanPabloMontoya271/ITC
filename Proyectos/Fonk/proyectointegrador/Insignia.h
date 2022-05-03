#ifndef INSIGNIA_H
#define INSIGNIA_H
#include <iostream>
using namespace std;
// José Pablo Fong Coronado - A01252402
class Insignia{
    public:
        Insignia();  // constructor por defecto
        Insignia(string, string, string, string); // constructor con parámetros

        string getFechaObtencion() const; // getter de fecha obtencion
        string getGimnasio() const; // getter de gimnasio
        string getLider() const; //getter de lider de gimnasio
        string getTipo() const; // getter de tipo

        void setFechaObtencion(string); //setter de numero
        void setGimnasio(string); //setter de fecha obtencion
        void setLider(string); //setter de gimnasio
        void setTipo(string); //setter de fecha de tipo

    private:
        string fechaObtencion;
        string gimnasio;
        string lider;
        string tipo;
};
#endif //INSIGNIA_H