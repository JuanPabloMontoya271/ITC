#include "Entrenador.h"
#include <iostream>
using namespace std;
// José Pablo Fong Coronado - A01252402
Entrenador::Entrenador(){
    nivel = 0;
    nombre = "";
    puebloOrigen = "";
    fechaInicio = "";
}

Entrenador::Entrenador(int _nivel, string _nombre,string _puebloOrigen,string _fechaInicio){
    nivel = _nivel;
    nombre = _nombre;
    puebloOrigen = _puebloOrigen;
    fechaInicio = _fechaInicio;
}

int Entrenador::getNivel()const{
    return nivel;
}

string Entrenador::getNombre()const{
    return nombre;
}

string Entrenador::getPuebloOrigen()const{
    return puebloOrigen;
}

string Entrenador::getFechaInicio()const{
    return fechaInicio;
}

void Entrenador::setNivel(int _nivel){
    nivel = _nivel;
}

void Entrenador::setNombre(string _nombre){
    nombre = _nombre;
}

void Entrenador::setPuebloOrigen(string _puebloOrigen){
    puebloOrigen = _puebloOrigen;
}

void Entrenador::setFechaInicio(string _fechaInicio){
    fechaInicio = _fechaInicio;
}

void Entrenador::imprimeEntrenador(){
    cout << "---------------------------------" << endl;
    cout << "Nivel: " << nivel << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Pueblo Origen: " << puebloOrigen << endl;
    cout << "Fecha Inicio: " << fechaInicio << endl;
    cout << "---------------------------------" << endl;
}

void Entrenador::consultarInsignias(){

}