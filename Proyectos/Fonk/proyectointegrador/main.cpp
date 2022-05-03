#include "Pokemon.h"
#include "Entrenador.h"
#include <sstream>
using namespace std;

void llenaPokedex(Pokemon poke[], int max){
    string n,r,t;
    int l;
    for(int i=0; i< max; i++){
        cout << "------ Pokemon " << i + 1 << " ------"<<endl;
        cout << "Nivel: " << endl;
        cin >> l;
        cout << "Nombre: " << endl;
        cin >> n;
        cout << "Region: " << endl;
        cin >> r;
        cout << "Tipo: " << endl;
        cin >> t;
        cout << "------------------" << endl;
        poke[i].setNivel(l);
        poke[i].setNombre(n);
        poke[i].setRegion(r);
        poke[i].setTipo(t);
    }
}
// IMPRIME EL POKEMON
void imprimePokemon(Pokemon arr[], int max, string tipo, string valor){
    cout << "Pokemon que encaja " << endl;
    for(int i=0; i< max; i++){
        if (tipo == "Nivel")
        {
            stringstream geek(valor);
            int x = 0;
            geek >> x;
            if (arr[i].getNivel() == x)
                arr[i].imprimePokemon();
        }
        else if (tipo == "Nombre")
        {
            if (arr[i].getNombre() == valor)
                arr[i].imprimePokemon();
        }
        else if (tipo == "Region")
        {
            
            if (arr[i].getRegion() == valor)
                arr[i].imprimePokemon();
        }
        else if (tipo == "Tipo")
        {
        
            if (arr[i].getTipo() == valor)
                arr[i].imprimePokemon();
        }
        else
        {
            
        }
       
        
    }
}

int main(){
    // POKEMON
    int registro;
    cout << "¿Cuantos pokemones quieres registrar?" << endl;
    cin >> registro;
    Pokemon pokes[registro];
    llenaPokedex(pokes,registro);
    
    
    //ENTRENADOR
    string no,po,fi;
    int ni;
    cout << "Ingresa los datos del entrenador" << endl;
    cout << "Nivel: " << endl;
    cin >> ni;
    cout << "Nombre: " << endl;
    cin >> no;
    cout << "Pueblo Origen: " << endl;
    cin >> po;
    cout << "Fecha inicio (DD/MM/AAAA): " << endl;
    cin >> fi;
    Entrenador entrenador1(ni,no,po,fi);
    entrenador1.imprimeEntrenador();
    string tipo;
    string valor;
    cout << "Atributo : " <<endl;
    cin >> tipo;
    cout << "Valor : " << endl;
    cin >> valor;
    imprimePokemon(pokes, registro, tipo, valor);
    return 0;
}