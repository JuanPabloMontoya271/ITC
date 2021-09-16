#include "Sort.cpp"
#include "Find.cpp"
int main()
{   
    std::vector<float> array = {2,2,4,5,1};
    auto array_ptr = std::make_shared<std::vector<float>>(array);
    auto orden = Sort(array_ptr);
    
    

    bool continuar = 1;
    while (continuar)
    {
        float num;
        std::cout << "Qué número desea buscar ? " << std::endl;
        std::cin >> num;
        auto buscador = Find(array_ptr, num);
        auto seq = buscador.sequential();
        auto bin = buscador.binary();
        std::cout << "Desea Continuar ? " << std::endl;
        std::cin >> continuar;
    }
    
    orden.intercambio();
    orden.show();
    orden.reset();
    orden.show();
    orden.burbuja();
    orden.show();
    orden.reset();
    orden.show();
    orden.mergeSort();
    orden.show();
    orden.reset();
    orden.show();
    

}