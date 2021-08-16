#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map> 
using namespace std;

class Clientes{
    private:
        //Se declaran las variables privadas
        string claveDeCliente;
        string nombreDelCliente;
        string direccion;
        string telefono;



    public:
        void putDatos(vector<string> argumentos)
        {

            claveDeCliente=argumentos[0];
            nombreDelCliente=argumentos[1];
            direccion=argumentos[2];
            telefono=argumentos[3];

        };
        string get_Direccion(){return direccion;        }
        
        string get_claveDeCliente(){return claveDeCliente ;       }
        
        string get_telefono(){return telefono;        }
        
        string get_NombreDelCliente(){return nombreDelCliente;        }


};
class Vendedores{
    private: 
        string ClaveDelVendedor, Nombre, Comision;

    public:
        void putDatos(vector<string> argumentos){

                ClaveDelVendedor=argumentos[0];
                Nombre= argumentos[1];
                Comision =argumentos[1];

        }
        string get_ClaveDelVendedor(){

            return ClaveDelVendedor;
        }
        
        string get_Nombre(){

            return Nombre;
        }
        
        string get_Comision(){

            return Comision;
        }
};
class Facturas{
    private:
        string NoDeFactura, ClaveDelCliente, ClaveDelVendedor,ClaveDelArticulo, Cantidad, Total;
    public:
        void putDatos(vector<string> argumentos){
                NoDeFactura = argumentos[0];
                ClaveDelCliente =argumentos[1];
                ClaveDelVendedor = argumentos[2];
                ClaveDelArticulo =argumentos[3];
                Cantidad =argumentos[4];
                Total = argumentos[5];

            
        }
        string get_NoDeFactura (){return NoDeFactura;}
        
        string get_ClaveDelCliente (){return ClaveDelCliente;}
        
        string get_ClaveDelVendedor(){return ClaveDelVendedor;}
        
        string get_ClaveDelArticulo (){return ClaveDelArticulo;}
        
        string get_Cantidad (){return Cantidad;}
        
        string get_Total (){return Total;}

};
class Inventario{
    private:
        string ClaveDelArticulo,Album, Artista,Precio,Existencia;
    public:
        void putDatos(vector<string> argumentos){
                ClaveDelArticulo = argumentos[0];
                Album =argumentos[1];
                Artista = argumentos[2];
                Precio=argumentos[3];
                Existencia =argumentos[4];
                

            
        }
        string get_ClaveDelArticulo (){return ClaveDelArticulo;}
        
        string get_Album (){return Album;}
        
        string get_Artista(){return Artista;}
        
        string get_Precio (){return Precio;}
        
        string get_Existencia (){return Existencia;}
        
    
};

vector<Clientes> readAndTokenizeClientes(string nombre, int num_cols, bool headers){
        vector<Clientes> resultado;
        
        string lineaFile;
        stringstream ss;
        string valor;
        ifstream inf(nombre);
      
       

        

        if (!inf) {
            cerr << "Uh oh, Students.csv could not be opened for reading!" <<endl;
            exit(1);
        }
        if (headers){
        getline (inf, lineaFile); //skip first line
        }
        while (getline (inf, lineaFile)){
            ss.clear();
            ss << lineaFile;
            vector<string> argumentos;
            for (int i = 0; i< num_cols; i++){

                getline(ss, valor, ',');
                argumentos.push_back(valor);
                
            }
            Clientes temp;
            temp.putDatos(argumentos);
               resultado.push_back(temp);
            
           
        }
        
        
    return resultado;
}
vector<Vendedores> readAndTokenizeVendedores(string nombre, int num_cols, bool headers){
        vector<Vendedores> resultado;
       
        string lineaFile;
        stringstream ss;
        string valor;
        ifstream inf(nombre);
   
        if (!inf) {
            cerr << "Uh oh, Students.csv could not be opened for reading!" <<endl;
            exit(1);
        }
        if (headers){
        getline (inf, lineaFile); //skip first line
        }
        while (getline (inf, lineaFile)){
            ss.clear();
            ss << lineaFile;
            vector<string> argumentos;
            for (int i = 0; i< num_cols; i++){

                getline(ss, valor, ',');
                argumentos.push_back(valor);
                
            }
            Vendedores temp;
            temp.putDatos(argumentos);
               resultado.push_back(temp);
            
           
        }
        
        
    return resultado;
}
vector<Inventario> readAndTokenizeInventarios(string nombre, int num_cols, bool headers){
        vector<Inventario> resultado;
        
        string lineaFile;
        stringstream ss;
        string valor;
        ifstream inf(nombre);
     
        if (!inf) {
            cerr << "Uh oh, Students.csv could not be opened for reading!" <<endl;
            exit(1);
        }
        if (headers){
        getline (inf, lineaFile); //skip first line
        }
        while (getline (inf, lineaFile)){
            ss.clear();
            ss << lineaFile;
            vector<string> argumentos;
            for (int i = 0; i< num_cols; i++){

                getline(ss, valor, ',');
                // cout<<valor;
                argumentos.push_back(valor);
                
            }
            Inventario temp;
            temp.putDatos(argumentos);
           
            resultado.push_back(temp);
            
        }
        
    
    return resultado;
}
vector<Facturas> readAndTokenizeFacturas(string nombre, int num_cols, bool headers){
        vector<Facturas> resultado;
        
        string lineaFile;
        stringstream ss;
        string valor;
        ifstream inf(nombre);
        if (!inf) {
            cerr << "Uh oh, Students.csv could not be opened for reading!" <<endl;
            exit(1);
        }
        if (headers){
        getline (inf, lineaFile); //skip first line
        }
        while (getline (inf, lineaFile)){
            ss.clear();
            ss << lineaFile;
            vector<string> argumentos;
            for (int i = 0; i< num_cols; i++){

                getline(ss, valor, ',');
                argumentos.push_back(valor);
                
            }
            Facturas temp;
            temp.putDatos(argumentos);
            resultado.push_back(temp);
            
           
        }
        
        
    return resultado;
}
vector<string> MejorPeorVendedores(vector<Facturas> Facturas){ 
    
    unordered_map <string, int> counter;
    int MAXIMO = 0;
    int MIN=100000;
    string nombreMin;
    string nombreMax;

    for (int i=0; i<Facturas.size(); i++){
        
        string vendedor = Facturas[i].get_ClaveDelVendedor();
        if (counter.find(vendedor) == counter.end()){ 
        counter[vendedor] =1;
        if (counter[vendedor]>MAXIMO)
                {MAXIMO =counter[vendedor];
                nombreMax =vendedor;}
                
                }
  
    // If key found then iterator to that key is returned 
        else{
        counter[vendedor]= counter[vendedor]+1;
            if (counter[vendedor]>MAXIMO)
                {MAXIMO =counter[vendedor];
                nombreMax =vendedor;}


        }
            
    }
    for(auto x:counter){
        if (x.second<MIN){

            MIN = x.second;
            nombreMin=x.first;
        }
        
        

    }
    vector<string> results = {nombreMax, nombreMin};
    return results ;

 }

 vector<string> MejorPeorArticulo(vector<Facturas> Facturas){ 

    unordered_map <string, int> counter;
    int MAXIMO = 0;
    int MIN=100000;
    string nombreMin;
    string nombreMax;

    for (int i=0; i<Facturas.size(); i++){
        
        string articulo = Facturas[i].get_ClaveDelArticulo();
        if (counter.find(articulo) == counter.end()){ 
        counter[articulo] =stoi(Facturas[i].get_Cantidad());
        if (counter[articulo]>MAXIMO)
                {MAXIMO =counter[articulo];
                nombreMax =articulo;}
                
                }
  
    // If key found then iterator to that key is returned 
        else{
        counter[articulo]= counter[articulo]+stoi(Facturas[i].get_Cantidad());
            if (counter[articulo]>MAXIMO)
                {MAXIMO =counter[articulo];
                nombreMax =articulo;}


        }
            
    }
    for(auto x:counter){
        if (x.second<MIN){

            MIN = x.second;
            nombreMin=x.first;
        }
        
        

    }
    vector<string> results = {nombreMax, nombreMin};
    return results ;

 }
/* vector<string>
*/
vector<string> MejorPeorCliente(vector<Facturas> Facturas){ 

    unordered_map <string, int> counter;
    int MAXIMO = 0;
    int MIN=100000;
    string nombreMin;
    string nombreMax;

    for (int i=0; i<Facturas.size(); i++){
        
        string cliente = Facturas[i].get_ClaveDelCliente();
        if (counter.find(cliente) == counter.end()){ 
        counter[cliente] =stoi(Facturas[i].get_Total());
        if (counter[cliente]>MAXIMO)
                {MAXIMO =counter[cliente];
                nombreMax =cliente;}
                
                }
  
    // If key found then iterator to that key is returned 
        else{
        counter[cliente]= counter[cliente]+stoi(Facturas[i].get_Total());
            if (counter[cliente]>MAXIMO)
                {MAXIMO =counter[cliente];
                nombreMax =cliente;}


        }
            
    }
    for(auto x:counter){
        if (x.second<MIN){

            MIN = x.second;
            nombreMin=x.first;
        }
        
        

    }
    vector<string> results = {nombreMax, nombreMin};
    return results ;

 }


void mostrarArticulos(vector<Inventario> inventario__){
    for (int i = 0; i<inventario__.size();i++){

        cout<<"Producto "<< i<<" : "<<inventario__[i].get_ClaveDelArticulo()<<"\tDescripcion/Album : "<<inventario__[i].get_Album()<<"\tTipo/Artista : "<<inventario__[i].get_Artista()<< endl;
    }


}
Vendedores Matricula2Nombre(vector<Vendedores> vendy, string mat){

    for (int i=0; i< vendy.size(); i++){


        if (vendy[i].get_ClaveDelVendedor()== mat)
            return vendy[i];
    }
    return vendy[0];
}
Clientes ClaveCliente2Nombre(vector<Clientes> clienty, string mat){

    for (int i=0; i< clienty.size(); i++){
       
        if (clienty[i].get_claveDeCliente()== mat)
            return clienty[i];
    }
    return clienty[0];
}
Inventario ClaveArticulo2Nombre(vector<Inventario> arty, string mat){

    for (int i=0; i< arty.size(); i++){


        if (arty[i].get_ClaveDelArticulo()== mat)
            return arty[i];
    }
    return arty[0];
}
Inventario Factura2Articulo(vector<Facturas>facty, vector<Inventario> inventario,string mat){
    for (int i=0; i< facty.size(); i++){


        if (facty[i].get_ClaveDelArticulo()== mat)
            for (int j = 0; j< inventario.size();j++){

                if (inventario[j].get_ClaveDelArticulo()==mat){
                    return  inventario[j];
                    
                }
            }
           break;
    }
    return inventario[0];
}

vector<Facturas> filtro(vector<Facturas> original,int fecha_inicio, int fecha_final){

    vector<Facturas> filtradas;
    for (int i=0; i<original.size();i++){
        int f =stoi(original[i].get_NoDeFactura().substr(1));
        
        if (f>=fecha_inicio && f<=fecha_final ){
            cout<<"Factura: "<<original[i].get_NoDeFactura()<<"\tClave del Articulo: "<<original[i].get_ClaveDelArticulo()<<"\tTotal: "<<(original[i].get_Total())<<endl;
            filtradas.push_back(original[i]);
        }


    }
    return filtradas;


}

    

void vender(vector<Inventario> inventario, vector<Vendedores> vendedores, vector<Clientes> clientes){
    string ClaveDelArticulo, Cliente;
    int numeroAVender;
    cout<<"Cuantos articulos quiere vender? "<<endl;
    cin>>numeroAVender;
    for (int i=0; i<numeroAVender; i++){
    
        cout<<"Ingrese la clave del articulo que quiere vender: "<<endl;
        cin>>ClaveDelArticulo;
        cout<<"Ingrese el codigo del Cliente: "<<endl;
        cin>>Cliente;
        cout<<"Ingrese el codigo del vendedor: "<<endl;
        string vendedorM;
        cin>>vendedorM;
        cout<<"Cantidad de articulos"<<endl;
        int cantidad;
        cin>>cantidad;
        bool disponible;
        int precio;
        for (int j = 0; j< inventario.size();j++){


            if(inventario[j].get_ClaveDelArticulo()==ClaveDelArticulo && stoi(inventario[j].get_Existencia())-cantidad>=0){
                cout<<"Disponible";
                    disponible=1;
                    precio = cantidad*stoi(inventario[j].get_Precio());
                    break;

            }
           
        }
        bool cliente_existe;
        bool vendedor_existe;
        for (int j= 0; j< clientes.size();j++){


            if(clientes[j].get_claveDeCliente() == Cliente){
                   cliente_existe=1;
                    break;

            }
        }
        for (int j= 0; j< vendedores.size();j++){


            if(vendedores[j].get_ClaveDelVendedor() == Cliente){
                   vendedor_existe=1;
                    break;

            }
        }
        if (cliente_existe&&vendedor_existe&&disponible){
            string dia, mes, ano;
            cout<<"Ingrese el dia"<<endl;
            cin>>dia;
            cout<<"Ingrese el mes"<<endl;
            cin>>mes;
            cout<<"Ingrese el ano"<<endl;
            cin>>ano;
            string nFactura ="F"+ano+mes+dia;
            ofstream oft("static/facturas.csv", std::ofstream::out | std::ofstream::app);
            oft<<nFactura<<", "<<Cliente<<", "<< vendedorM<<", "<<ClaveDelArticulo<<", "<<cantidad<<", "<<precio<<endl;
            oft.close();
            cout<<nFactura<<", "<<Cliente<<", "<< vendedorM<<", "<<ClaveDelArticulo<<", "<<cantidad<<", "<<precio<<endl;
        }
       
   
    }


    
}

string ConsultasReportes (){
    string letra;
    cout << "------------------------Consultas y reportes------------------------" << 
    "\n Ingresa la letra correspondiente para conocer información de ventas e inventario"<< 
    "\n H para:  hacer venta" <<
    "\n I para:  mostrar inventario" <<
    "\n F para:  factura en particular mostrando el detalle de los artículos" <<
    "\n L para:  generar una lista de facturas dentro de un rango de fechas con sus totales" <<
    "\n V para:  mejor vendedor, el peor vendedor basado en las facturas registradas" <<
    "\n C para:  mejor cliente y el peor cliente basado en las facturas" <<
    "\n A para:  artículo más vendido y el artículo menos vendido"<<"\n ";
    
    cin >> letra;
    cout << endl;
    return letra;
}
int main(){
   
    string letra;
    string nfactura;

    vector <Clientes> client_ = readAndTokenizeClientes("static/cliente.csv",4, 1);
    vector <Vendedores> vend_ = readAndTokenizeVendedores("static/vendedores.csv",3,1);
    vector<Inventario> inv = readAndTokenizeInventarios("static/inventario.csv", 5,1);
    vector <Facturas> fact_ = readAndTokenizeFacturas("static/facturas.csv", 6, 1);
    
    letra = ConsultasReportes();
    
    if (letra == "F") {
        cout << "Ingresa Numero de Factura";
        cin >> nfactura;
        cout << endl;
        Inventario art = Factura2Articulo(fact_, inv, nfactura);
        cout<<art.get_Album()<<art.get_Artista()<<endl;
    }
    if (letra == "L") {
        int inicio, final_;
    cout<<"Ingrese una fecha de inicio en el siguiente formato aaaammdd : ";
    cin >>inicio;
    cout<<"Ingrese una fecha de final en el siguiente formato aaaammdd : ";
    cin >>final_;
       vector<Facturas> filtradas= filtro(fact_, inicio, final_);
       cout<<filtradas[0].get_NoDeFactura();
       }
    if (letra == "V") {// Mejor y peor vendedor
        vector<string> max_min = MejorPeorVendedores(fact_) ;
        Vendedores MejorV  = Matricula2Nombre(vend_,max_min[1]);
        cout<<MejorV.get_Nombre()<<endl;    
    }
    if (letra == "C") {// Mejor y peor cliente
        vector<string> max_minC= MejorPeorCliente(fact_) ;
        Clientes MejorC  = ClaveCliente2Nombre(client_,max_minC[1]);
        cout<<max_minC[1];
        cout<<MejorC.get_NombreDelCliente()<<endl;   
    }
    if (letra == "A") {// Mejor y peor articulo
        vector<string> max_minA= MejorPeorArticulo(fact_) ;
        Inventario MejorA  = ClaveArticulo2Nombre(inv,max_minA[1]);
        cout<<max_minA[1];
        cout<<MejorA.get_Album()<<endl;
    }
    if (letra == "A") {// Mejor y peor articulo
        vector<string> max_minA= MejorPeorArticulo(fact_) ;
        Inventario MejorA  = ClaveArticulo2Nombre(inv,max_minA[1]);
        cout<<max_minA[1];
        cout<<MejorA.get_Album()<<endl;
    }
    if (letra == "I") {// fx inventario
        mostrarArticulos(inv);
    } 
    if (letra == "H") {// fx inventario
        vender(inv, vend_, client_);
    } 
    
  

    
    
    
    
    
    
    return 0;
}