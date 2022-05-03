#include "linear.hpp"
template <typename K, typename V>
Linear<K,V>::Linear(int b)
{
	this->BUCKET = b;
    vector<HashNode<K,V>*> temp(10, NULL);
    this->table = temp;
}


template <typename K, typename V>
int Linear<K,V>::getIndex(K key)
{
        int tsize = table.size();
	
		int hv = key % tsize;

		if (table[hv] ==NULL)
			return hv;
		else
		{
			
			for (int j = 0; j < tsize; j++)
			{
				int t = (hv + j ) % tsize;
				if (table[t] == NULL)
				{
					
					return t;
				}
			}
		}
	return -1;
}
template <typename K, typename V>
void Linear<K,V>::insert(K key, V value )
{

	auto idx = getIndex(key);
	if (idx != -1)
		table[idx] = new HashNode<K,V>(key, value);
				
	
	
}

template <typename K, typename V>

void Linear<K,V>::displayHash() {
	for (int j = 0 ; j < table.size(); j++)
    {
        if (table[j] !=NULL)
        {
            cout << "KEY : " << table[j]->key <<"\t" << "Value : "  << table[j]->value <<endl;
        }
    }
        
}

