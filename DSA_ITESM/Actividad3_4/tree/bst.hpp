#pragma once
#include <iostream>
#include <queue>
class BST
{
    int data;
    std::string ip;
	BST *left, *right;
    public:
        BST();
        
        

	
	    BST(int, std::string);


	    BST* Insert(BST*, int, std::string);

        void First5(BST* root, std::vector <BST*>& array);
	    void Inorder(BST*);
        void preorder(BST*);
        void postorder(BST*);
        void levelorder(BST*);
        int  height(BST*);
        bool ancestors(BST*, int);
        int  whatlevelami(BST*, int, int);
};
