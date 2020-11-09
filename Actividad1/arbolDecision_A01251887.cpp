/*

Juan Pablo Montoya Estevez 
A01251887
10 de Noviembre del 2020
TC1033 Pensamiento computacional rientado a objetos

*/

#include <iostream>
#include <algorithm>
using namespace std;

int validar_ingreso(int ingresos){
    int resultado;
    if (ingresos <= 500){
        resultado = -1;


    }
    else if (ingresos>500 && ingresos <3000){

        resultado =0;

    }
    else{

        resultado = 1;
    }
return resultado;
}

int main(){
    bool continuar = 1;
    while (continuar){
        int ingreso;
        int trabajo;
        cout<<"Ingrese un valor entero para ingreso : ", cin>> ingreso;
        cout<<"Ingrese un valor boleano para trabajo : ", cin>>trabajo;
        int res = validar_ingreso(ingreso)+trabajo;
        
        bool r =  min(max(res,0),1);
        string response = (r? "es": "no es") ;  
        
        cout<<"El usuario "<<response<<" sujeto a credito." <<endl;
        cout<<"Desea continuar? ";
        cin>>continuar;
        

    }
}