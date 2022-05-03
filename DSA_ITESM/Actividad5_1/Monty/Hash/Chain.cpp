#include <list>
#include <iostream>
#include <string>
#include "Chain.hpp"


using namespace std;


template<typename K, typename V>
Chain<K,V>::Chain(int b)
{
	this->BUCKET = b;
	table = new list<HashNode<K, V>*>[BUCKET];
}
template<typename K, typename V>
void Chain<K, V>::insertItem(K key, V value)
{
	int index = hashFunction(key);

	table[index].push_back(new HashNode<K,V>{key,value});
    
}
template<typename K, typename V>
void Chain<K,V>::deleteItem(K key)
{

int index = hashFunction(key);


typename list <HashNode<K, V>*> :: iterator i;
for (i = table[index].begin();
		i != table[index].end(); i++) {
	if ((*i)->key == key)
	break;
}


if (i != table[index].end())
	table[index].erase(i);
}


template<typename K, typename V>
void Chain<K,V>::displayHash() {
for (int i = 0; i < BUCKET; i++) {
	cout << i;
	for (auto x : table[i])
	cout << " --> " << "Key" << x->key << " Value : " << x->value;
	cout << endl;
}
}

