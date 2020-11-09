/*
Media Aritmética
Juan Pablo Montoya Estevez 
A01251887
10 de Noviembre del 2020
TC1033 Pensamiento computacional rientado a objetos

*/
#include <iostream>
using namespace std;

int main (){

float numero;
cout<<"Ingrese un numero para comenzar: ";
cin>>numero;
int counter  = 1;
float acumulador= numero;

while (numero){

    cout<<"Ingrese un numero: ";
    cin>>numero;
    counter++;
    acumulador+=numero;
}
cout<<"El promedio es igual a: "<< acumulador/(counter-1)<<endl;

}