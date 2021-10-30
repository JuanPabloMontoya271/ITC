// C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
#include "tree/bst.cpp"
using namespace std;


void test(BST b, BST* root, std::vector<int> array, std::vector<std::string> ips)
{
    root = b.Insert(root, array[0], ips[0]);
    for (int i = 1; i < array.size(); i++)
    {
        b.Insert(root, array[i], ips[i]);
       
    }
    
	

	b.Inorder(root);
    cout << "PREORDER : " << endl;
    b.preorder(root);
    cout << "POSTORDER : " << endl;
    b.postorder(root);
    cout << "INORDER : " << endl;
    b.Inorder(root);
    cout << "LEVELORDER : " << endl;
    b.levelorder(root);
    
	cout << endl << "HEIGHT : " <<b.height(root)<< endl;
    int n;
    cout << "input a number "<<endl;
    cin>>n;
    cout << "Ancestors of " << n << endl;
    b.ancestors(root, n) ;
    cout <<endl;
    cout <<b.whatlevelami(root, n, 0)<<endl;
}
int main()
{

	BST b, *root = NULL;
    std::vector<int> array={10,20,30,42,394,20};
    std::vector<std::string> ips = {"123", "1234", "12345", "123456", "1234567", "12345678"};
    test(b, root, array, ips);
	// root = b.Insert(root, 50);
	// b.Insert(root, 30);
	// b.Insert(root, 20);
	// b.Insert(root, 40);
	// b.Insert(root, 70);
	// b.Insert(root, 60);
	// b.Insert(root, 80);

	// b.Inorder(root);
    // cout << "PREORDER : " << endl;
    // b.preorder(root);
    // cout << "POSTORDER : " << endl;
    // b.postorder(root);
    // cout << "INORDER : " << endl;
    // b.Inorder(root);
    // cout << "LEVELORDER : " << endl;
    // b.levelorder(root);
	// cout << endl <<b.height(root)<< endl;
    // int n;
    // cout << "input a number "<<endl;
    // cin>>n;
    // cout << "Ancestors of " << n << endl;
    // b.ancestors(root, n) ;
    // cout <<endl;
    // cout <<b.whatlevelami(root, n, 0)<<endl;
    return 0;

}

