#include "bst.hpp"
using namespace std;
BST::BST()
	: data(0)
	, left(NULL)
	, right(NULL)
{
}

BST::BST(int value)
{
	data = value;
	left = right = NULL;
}


BST* BST::Insert(BST* root, int value)
{
	if (!root)
	{
		
		return new BST(value);
	}


	if (value > root->data)
	{
		
		root->right = Insert(root->right, value);
	}
	else
	{
		
		root->left = Insert(root->left, value);
	}

	
	return root;
}

void BST::Inorder(BST* root)
{
	if (!root) {
		return;
	}
	Inorder(root->left);
	cout << root->data << endl;
	Inorder(root->right);
}
void BST::preorder(BST* root)
{
	if (!root) {
		return;
	}
    cout << root->data << endl;
	preorder(root->left);
	
	preorder(root->right);
}
void BST::postorder(BST* root)
{
	if (!root) {
		return;
	}
    
	postorder(root->left);
	
	postorder(root->right);
    cout << root->data << endl;
}
void BST::levelorder(BST* root)
{
    
    if (root == NULL)
        return;
 
    
    queue<BST*> q;
 
    
    q.push(root);
 
    while (q.empty() == false) {
        
        BST* node = q.front();
        cout << node->data << " ";
        q.pop();
 
        
        if (node->left != NULL)
            q.push(node->left);
 
        
        if (node->right != NULL)
            q.push(node->right);
    }
}
int BST::height(BST* node)
{
    if (node == NULL)
        return 0;
    else
    {
        
        int left = height(node->left);
        int right = height(node->right);
     
        
        if (left > right)
            return(left + 1);
        else return(right + 1);
    }
}
bool BST::ancestors(BST* root, int target)
{
  
  if (root == NULL)
     return false;
 
  if (root->data == target)
     return true;
 
  
  if ( ancestors(root->left, target) ||
       ancestors(root->right, target) )
  {
    cout << root->data << " ";
    return true;
  }
 
 
  return false;
}
int BST::whatlevelami(BST* root, int target, int count)
{
    if (root == NULL)
    {
        return -1;
    }
    if (target == root->data)
    {
        cout << "found" <<endl;
        return count;
    }
    if (target > root->data )
    {
        return whatlevelami(root->right, target, count+1);

    }
    else
    {
        return whatlevelami(root->left, target, count+1);
    }
}