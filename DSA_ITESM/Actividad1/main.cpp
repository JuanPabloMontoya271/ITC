#include "suma.cpp"
int main()
{
    Suma suma{10};
    std::cout << "[Suma iterativa] : " << suma.iterativa() << std::endl;
    std::cout << "[Suma recursiva] : " << suma.recursiva() << std::endl;
    std::cout << "[Suma directa]   : " << suma.directa() << std::endl;
}