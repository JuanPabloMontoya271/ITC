#include <list>
#include <iostream>
#include <vector>
#include "HashNode.cpp"
using namespace std;
template <typename K, typename V>
class Linear
{
	int BUCKET; 

	
	vector<HashNode<K,V>*> table;
public:
	Linear(int);  

	
	void insertItem(K x, V value);

	
	
	int getIndex(K key);
	void remove(K key_);
	
	int hashFunction(K x) {
		return (x % BUCKET);
	}
    void insert(K key, V value);
	void displayHash();
};
