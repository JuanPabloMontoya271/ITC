#include <list>
#include <iostream>
#include <string>
#include "HashNode.cpp"
using namespace std;
template <typename K, typename V>
class Chain
{
	int BUCKET; 

	
	list<HashNode<K, V>*> *table;
public:
	Chain(int v); 

	
	void insertItem(K x, V value);

	
	void deleteItem(K key);

	
	int hashFunction(K x) {
		return (x % BUCKET);
	}

	void displayHash();
};

