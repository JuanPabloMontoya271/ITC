#include "Find.hpp"
Find::Find(std::shared_ptr<std::vector<float>>array, float num )
{
    array_ = *array;
    sort(array_.begin(), array_.end());
    num_ = num;
}
int Find::sequential()
{
    std::cout << "[Busqueda Secuencial] : " << std::endl;
    int i = 0;
    for (i;  i< array_.size(); i++)
    {
        if (array_[i] == num_)
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
    int j = array_.size()-1;
    while (i<=j)
    {
        int mid = (i+j)/2;
        if (array_[mid] == num_)
        {
            std::cout << "[Index]: " << mid << "\n[Value] : " << num_ << std::endl << std::endl;
            return mid;
        }
        else if (array_[mid] > num_)
            j = mid-1;
        else
            i = mid+1;
    }

    std::cout << "[Index] : " << -1 << "\n[Value] : " << num_ << std::endl << std::endl;
    return -1;
}