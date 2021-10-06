#include <iostream>
#include "LinkedList/linked_list.hpp"
int main()
{
    LinkedList<int> list;
    // list.add_mid(10);
    // Cuando no tengo nada : 
    list.push(1);
    // Cuando tengo 1
    list.push(2);
    list.update(1, 3);
    // Cuando tengo muchos
    list.push(4);
    list.push(5);
    list.push(6);
    list.push(7);
    list.push(8);
    list.del(0);
    LinkedList<int> list2;
    // Cuando no tengo nada : 
    list2.insert_mid(100);
    // Cuando tengo 1 : 
    list2.push(101);
    list2.insert_mid(100);
    // Cuando tengo muchos
    list2.push(101);
    list2.push(102);
    list2.push(103);
    list2.insert_mid(100);
    list2.update(1, 20);
    list2.del(1);
    list2.add(10, 10);


    return 0;

}