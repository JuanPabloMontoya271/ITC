#include "Hash/Chain.cpp"
#include "Hash/linear.cpp"
#include "Hash/Quadratic.cpp"
using namespace std;
int main()
{

int a[] = {1, 199, 24, 2, 128};
float v[] = {1.5, 1.6, 1.7, 1.8, 1.32};
int n = sizeof(a)/sizeof(a[0]);


Chain<int, float> h(7); 
			
for (int i = 0; i < n; i++)
	h.insertItem(a[i], v[i]);

h.displayHash();




return 0;
}
