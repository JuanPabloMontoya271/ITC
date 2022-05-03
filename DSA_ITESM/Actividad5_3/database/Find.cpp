#include "Find.hpp"

Find::Find(std::vector<Element>array, int num)
{
    array_ = array;
    auto sorter = Sort(array_);

    array_ = sorter.mergeSort();
    num_ = num;
}
int Find::sequential()
{
    std::cout << "[Busqueda Secuencial] : " << std::endl;
    int i = 0;
    for (i; i < array_.size(); i++)
    {
        if (array_[i].numeric_ip() >= num_)
        {
            std::cout << "[Index] : " << i << "\n[Value] : " << num_ << std::endl << std::endl;
            return i;
        }
    }

    std::cout << "[Index] : " << -1 << "\n[Value] : " << num_ << std::endl << std::endl;

    return-1;
}


int Find::binary()
{

    std::cout << "[Busqueda Binaria] : " << std::endl;
    int i = 0;
    int j = array_.size() - 1;
    int mid;
    while (i <= j)
    {
        mid = (i + j) / 2;
        if (array_[mid].numeric_ip() == num_)
        {
            // std::cout << "[Index]: " << mid << "\n[Value] : " << num_ << std::endl << std::endl;
            return mid;
        }
        else if (array_[mid].numeric_ip() > num_)
            j = mid - 1;
        else
            i = mid + 1;
    }

    // std::cout << "[Index] : " << mid << "\n[Value] : " << num_ << std::endl << std::endl;
    return mid;
}