#include "Pokemon.h"
#include <iostream>
using namespace std;
// José Pablo Fong Coronado - A01252402
Pokemon::Pokemon(){
    nivel = 0;
    nombre = "";
    region = "";
    tipo = "";
}

Pokemon::Pokemon(int _nivel, string _nombre,string _region,string _tipo){
    nivel = _nivel;
    nombre = _nombre;
    region = _region;
    tipo = _tipo;
}

int Pokemon::getNivel()const{
    return nivel;
}

string Pokemon::getNombre()const{
    return nombre;
}

string Pokemon::getRegion()const{
    return region;
}

string Pokemon::getTipo()const{
    return tipo;
}

void Pokemon::setNivel(int _nivel){
    nivel = _nivel;
}

void Pokemon::setNombre(string _nombre){
    nombre = _nombre;
}

void Pokemon::setRegion(string _region){
    region = _region;
}

void Pokemon::setTipo(string _tipo){
    tipo = _tipo;
}

void Pokemon::imprimePokemon(){
    cout << "---------------------------------" << endl;
    cout << "Nivel: " << nivel << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Region: " << region << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "---------------------------------" << endl;
}