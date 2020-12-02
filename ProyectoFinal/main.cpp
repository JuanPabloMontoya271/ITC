#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Clientes{
    private:
        //Se declaran las variables privadas
        string claveDeCliente;
        string nombreDelCliente;
        string direccion;
        string telefono;



    public:
        Clientes(string clave_del_cliente, string nombre_del_cliente, string dir, string tel)
        {

            claveDeCliente=clave_del_cliente;
            nombreDelCliente=nombre_del_cliente;
            direccion=dir;
            telefono=tel;

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
        Vendedores(string clave_del_vendedor, string nombre, string comision){

                ClaveDelVendedor=clave_del_vendedor;
                Nombre= nombre;
                Comision = comision;

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
        Facturas(string noDeFactura, string claveDelCliente, string claveDelVendedor, string claveDelArticulo, string cantidad, string total){
                NoDeFactura = noDeFactura;
                ClaveDelCliente =claveDelCliente;
                ClaveDelVendedor = claveDelVendedor;
                ClaveDelArticulo =claveDelArticulo;
                Cantidad =cantidad;
                total = Total;

            
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
        string ClaveDelArticulo, Descripcion, Precio,Tipo, Existencia;
    public:
        Inventario(string claveDelArticulo, string descripcion, string precio, string tipo, string existencia){
                ClaveDelArticulo = claveDelArticulo;
                Descripcion =descripcion;
                Precio = precio;
                Tipo=tipo;
                Existencia =existencia;
                

            
        }
        string get_ClaveDelArticulo (){return ClaveDelArticulo;}
        
        string get_Descripcion (){return Descripcion;}
        
        string get_Precio(){return Precio;}
        
        string get_Tipo (){return Tipo;}
        
        string get_Existencia (){return Existencia;}
        
    

};

int main(){



    return 0;
}