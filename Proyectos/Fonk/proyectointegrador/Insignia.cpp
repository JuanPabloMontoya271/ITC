#include "Entrenador.h"
#include "Insignia.h"
#include <iostream>
using namespace std;
using namespace std;
// José Pablo Fong Coronado - A01252402
Insignia::Insignia(){
    fechaObtencion = "";
    gimnasio = "";
    lider = "";
    tipo = "";
}

Insignia::Insignia(string _fechaObtencion,string _gimnasio,string _lider, string _tipo){
    fechaObtencion = _fechaObtencion;
    gimnasio = _gimnasio;
    lider = _lider;
    tipo = _tipo;
}

string Insignia::getFechaObtencion()const{
    return fechaObtencion;
}

string Insignia::getGimnasio()const{
    return gimnasio;
}

string Insignia::getLider()const{
    return lider;
}

string Insignia::getTipo()const{
    return tipo;
}

void Insignia::setFechaObtencion(string _fechaObtencion){
    fechaObtencion = _fechaObtencion;
}

void Insignia::setGimnasio(string _gimnasio){
    gimnasio = _gimnasio;
}

void Insignia::setLider(string _lider){
    lider = _lider;
}

void Insignia::setTipo(string _tipo){
    tipo = _tipo;
}