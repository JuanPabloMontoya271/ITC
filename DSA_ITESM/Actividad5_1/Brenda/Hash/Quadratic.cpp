// C++ implementation of
// the Linear Probing
#include <list>
#include <iostream>
#include <vector>
using namespace std;
class HashNode
{
    public:
        int key; 
        string value;
        HashNode(int key_, string value_)
        {
            key = key_;
            value = value_;
        }
};
class Hash
{
	int BUCKET; // No. of buckets

	// Pointer to an array containing buckets
	vector<HashNode*> table;
public:
	Hash(int V); // Constructor

	// inserts a key into hash table
	void insertItem(int x, string value);

	// deletes a key from hash table
	// void deleteItem(int key);

	// hash function to map values to key
	int hashFunction(int x) {
		return (x % BUCKET);
	}
    void insert(int key, string value);
	void displayHash();
};

Hash::Hash(int b)
{
	this->BUCKET = b;
    vector<HashNode*> temp(10, NULL);
    this->table = temp;
}

void Hash::insert(int key, string value )
{
	// Iterating through the array
        int tsize = (table).size();
		// Computing the hash value
		int hv = key % tsize;

		// Insert in the table if there
		// is no collision
		if (table[hv] ==NULL)
			(table[hv]) = new HashNode(key, value);
		else
		{
			// If there is a collision
			// iterating through all
			// possible quadratic values
			for (int j = 0; j < tsize; j++)
			{
				// Computing the new hash value
				int t = (hv + j*j) % tsize;
				if (table[t] == NULL)
				{
					// Break the loop after
					// inserting the value
					// in the table
					table[t] = new HashNode(key, value);
					break;
				}
			}
		}
	
	
}
// function to display hash table
void Hash::displayHash() {
	for (int j = 0 ; j < table.size(); j++)
    {
        if (table[j] !=NULL)
        {
            cout << "KEY : " << table[j]->key <<endl << "Value : "  << table[j]->value <<endl;
        }
    }
        
}
// Function to print an array

// Function to implement the
// quadratic probing


// Driver code
int main()
{
	int a[] = {15, 11, 27, 8, 12};
string v[] = {"Brenda", "Monty", "Brenda2", "Monty2", "Nada "};
int n = sizeof(a)/sizeof(a[0]);

// insert the keys into the hash table
Hash h(7); // 7 is count of buckets in
			// hash table
cout <<"inserting" << endl;
for (int i = 0; i < n; i++)
	h.insert(a[i], v[i]);

// delete 12 from hash table
// h.deleteItem(12);

// display the Hash table
cout <<"Display hash"<<endl;
h.displayHash();

return 0;
}

// This code is contributed by gauravrajput1
