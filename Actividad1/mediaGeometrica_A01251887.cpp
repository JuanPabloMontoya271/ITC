/*
Media Geométrica
Juan Pablo Montoya Estevez 
A01251887
10 de Noviembre del 2020
TC1033 Pensamiento computacional rientado a objetos

*/
#include <iostream>
#include <math.h>
using namespace std;

int main (){

double numero;
cout<<"Ingrese un numero para comenzar: ";
cin>>numero;
int counter  = 1;
double acumulador= numero;

while (numero){

    cout<<"Ingrese un numero: ";
    cin>>numero;
    
    if (numero !=0){
    counter++;
    acumulador*=numero;}
}

cout<<"El promedio es igual a: "<< pow(acumulador,((double)1/(counter)))<<endl;

}