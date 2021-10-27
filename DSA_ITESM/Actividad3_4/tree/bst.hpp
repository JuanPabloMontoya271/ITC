#pragma once
#include <iostream>
#include <queue>
class BST
{
    int data;
	BST *left, *right;
    public:
        BST();
        
        

	
	    BST(int);


	    BST* Insert(BST*, int);

	
	    void Inorder(BST*);
        void preorder(BST*);
        void postorder(BST*);
        void levelorder(BST*);
        int height(BST*);
        bool ancestors(BST*, int);
        int whatlevelami(BST*, int, int);
};
