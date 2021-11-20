#pragma once

#include <iostream>
#include <vector>
#include <memory>

class SortFreq
{
public:
    SortFreq(std::vector<std::pair<int, int>>);

    // O(N^2) y O(1)
    void intercambio();

    // O(N^2) y O(1)
    void burbuja();

    // O(nlogn) y O(N)
    std::vector<std::pair<int, int>> mergeSort();


    void show();
    void reset();

private:
    std::vector<std::pair<int, int>> array_;
    std::vector<std::pair<int, int>> backup_array_;
    void merge(int, int, int);
    void mergeSortHelper(int const, int const);

};
