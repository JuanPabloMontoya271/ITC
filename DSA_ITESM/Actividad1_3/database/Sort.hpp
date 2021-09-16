#pragma once

#include <iostream>
#include <vector>
#include <memory>

class Sort
{
public:
    Sort(std::vector<Element>);

    // O(N^2) y O(1)
    void intercambio();

    // O(N^2) y O(1)
    void burbuja();

    // O(nlogn) y O(N)
    std::vector<Element> mergeSort();


    void show();
    void reset();

private:
    std::vector<Element> array_;
    std::vector<Element> backup_array_;
    void merge(int, int, int);
    void mergeSortHelper(int const, int const);

};
