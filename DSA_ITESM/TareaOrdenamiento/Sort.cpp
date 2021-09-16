#include "Sort.hpp"

Sort::Sort(std::shared_ptr<std::vector<float>> array)
{
    array_ = *array;
    backup_array_ =*array;
};
void Sort::intercambio()
{
    std::cout << "[Ordenamiento de Intercambio]" << std::endl;
	int i, j, aux; 
    int n = array_.size();
	for (i = 0; i <= n - 2; i++)
		for (j = i + 1; j <= n - 1; j++)
			if (array_[i] > array_[j])
			{
				aux = array_[i];
				array_[i] = array_[j];
				array_[j] = aux;
			}
}
void Sort::burbuja()
{
    std::cout << "[Ordenamiento Burbuja]" << std::endl;
	bool interruptor = true;
	int tmp = 0;
    int n = array_.size();
	for (int pasada = 0; pasada < n - 1 && interruptor; pasada++)
    {
		interruptor = false; // no se han hecho intercambios
		for (int j = 0; j < n - 1 - pasada; j++) 
        {
			if (array_[j + 1] < array_[j])
            {
				tmp = array_[j];
				array_[j] = array_[j + 1];
				array_[j + 1] = tmp;
				interruptor = true;
			}
		}
	}
}
void Sort::mergeSort()
{
    std::cout << "[Merge Sort]" << std::endl;
    mergeSortHelper(0, array_.size()-1);
}
void Sort::mergeSortHelper(int const begin, int const end)
{
	if (begin >= end)
		return; // Returns recursivly

	auto mid = begin + (end - begin) / 2;
	mergeSortHelper(begin, mid);
	mergeSortHelper( mid + 1, end);
	merge(begin, mid, end);

}
void Sort::merge(int const left, int const mid, int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array_[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array_[mid + 1 + j];

	auto indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			array_[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array_[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array_[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array_[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}

}
void Sort::reset()
{
    std::cout << "[Arreglo Original]" << std::endl;
    array_ = backup_array_;
}
void Sort::show()
{
    for (auto value : array_)
        std::cout << value << "\t";
    std::cout << std::endl << std::endl;
}