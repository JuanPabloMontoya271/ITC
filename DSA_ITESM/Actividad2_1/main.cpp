#include <iostream>
#include "LinkedList/linked_list.hpp"
int main()
{
    LinkedList<int> list;
    list.add(1);
    list.add(23);
    list.add(3);
    list.display();
    list.update(1, 20);
    list.display();
    list.del(1);
    list.display();
    list.add(10, 10);
    list.display();
    std::cout << list[1] << std::endl;
    return 0;

}