#include "Quadratic.hpp"
template <typename K, typename V>
Quadratic<K,V>::Quadratic(int b)
{
	this->BUCKET = b;
    vector<HashNode<K,V>*> temp(10, NULL);
    this->table = temp;
}
template <typename K, typename V>
void Quadratic<K,V>::insert(K key, V value )
{
	
        int tsize = (table).size();
        cout << "size" << tsize <<endl;
	
		int hv = key % tsize;

		
		
		if (table[hv] ==NULL)
			(table[hv]) = new HashNode<K,V>(key, value);
		else
		{
		
			for (int j = 0; j < tsize; j++)
			{
		
				int t = (hv + j*j ) % tsize;
				if (table[t] == NULL)
				{
	
					table[t] = new HashNode<K,V>(key, value);
					break;
				}
			}
		}
	
	
}

template <typename K, typename V>

void Quadratic<K,V>::displayHash() {
	for (int j = 0 ; j < table.size(); j++)
    {
        if (table[j] !=NULL)
        {
            cout << "KEY : " << table[j]->key <<endl << "Value : "  << table[j]->value <<endl;
        }
    }
        
}
