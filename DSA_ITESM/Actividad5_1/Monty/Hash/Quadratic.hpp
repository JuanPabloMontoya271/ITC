
#include <list>
#include <iostream>
#include <vector>
#include "HashNode.cpp"
using namespace std;
template <typename K, typename V>
class Quadratic
{
	int BUCKET;

	
	vector<HashNode<K,V>*> table;
public:
	Quadratic(int); 

	
	void insertItem(K x, V value);

	int hashFunction(K x) {
		return (x % BUCKET);
	}
    void insert(K key, V value);
	void displayHash();
};
