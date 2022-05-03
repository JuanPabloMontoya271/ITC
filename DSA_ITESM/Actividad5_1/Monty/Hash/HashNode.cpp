
#pragma once
#include <iostream>
#include <string>

using namespace std;
template<typename K, typename V>
class HashNode
{
    public:
        K key; 
        V value;
        HashNode(K, V);
};
template<typename K, typename V>
HashNode<K,V>::HashNode(K key_, V value_)
        {
            key = key_;
            value = value_;
        }