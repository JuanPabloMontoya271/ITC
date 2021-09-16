#pragma once

#include <iostream>
#include <vector>
#include <memory>

class Sort
{
    public:
        Sort(std::shared_ptr<std::vector<float>>);

        // O(N^2) y O(1)
        void intercambio();

        // O(N^2) y O(1)
        void burbuja();

        // O(nlogn) y O(N)
        void mergeSort();

        
        void show();
        void reset();
        
    private:
        std::vector<float> array_;
        std::vector<float> backup_array_;
        void merge(int, int, int);
        void mergeSortHelper(int const, int const);

};
