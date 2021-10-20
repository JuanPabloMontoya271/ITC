#include <iostream>
#include <queue>
#include <utility> 
//#include<bits/stdc++.h>
using namespace std;

//estructura básica de nodo, sus extremos o "patitas" izq. y der.
struct node {
  int key;
  struct node *left, *right;
};

// Creando nodo u "hojita"
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

//tiempo complejidad de órdenes O(n), donde 
//n es el número de nodos u "hojitas" 
void inorder(struct node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void preorder(struct node *root) {
    if (root == NULL)
        return;
    cout << root->key <<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}

//regresa la altura del árbol
int height(struct node *root) {
    int h = 0;
    if (root != NULL) {
        int l_height = height(root->left);
        int r_height = height(root->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

// Inserta un nodo al BST
struct node *insert(struct node *node, int key) {
  // regresa nodo nuevo si está vacío en el árbol
  if (node == NULL) return newNode(key);

  // Se posiciona a la derecha e inserta el nodo
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

//Encuentra el sucesor en inorden
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  //encuentra la hojita a la izquierda
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

/* Helper function for getLevel().
It returns level of the data if data is
present in tree, otherwise returns 0.*/
//fuente: https://www.geeksforgeeks.org/get-level-of-a-node-in-a-binary-tree/
int getLevelUtil(struct node *node,
				int key, int level)
{
	if (node == NULL)
		return 0;

	if (node -> key == key)
		return level;

	int downlevel = getLevelUtil(node -> left,
								key, level + 1);
	if (downlevel != 0)
		return downlevel;

	downlevel = getLevelUtil(node->right,
							key, level + 1);
	return downlevel;
}


//regresa nivel en que se encuentra el dato
int whatLevelAmI(struct node *node, int key)
{
	return getLevelUtil(node, key, 1);
}

//fuente: https://www.geeksforgeeks.org/print-ancestors-of-a-given-node-in-binary-tree/
/* If target is present in tree, then prints the ancestors
and returns true, otherwise returns false. */
bool showAnc(struct node *root, int obj)
{
/* base cases */
if (root == NULL)
	return false;

if (root->key == obj)
	return true;

//si el target se encuentra a la izq. o der. de la hojita
if ( showAnc(root->left, obj) ||
	showAnc(root->right, obj) )
{
	cout << root->key << " ";
	return true;
}
return false; //si no se encuentra
}

void showLevelbyLevel(struct node *root,int nivelAbuscar){
 // int altura=height(root); //altura total del árbol

  /*if (root == NULL)
        cout<<"ROCO FONFO";*/
    
  int aux=root->key;
  int aux2=whatLevelAmI(root,aux); //nivel del valor actual que se esta repasando del BST

  if(aux2==nivelAbuscar){
    cout<<aux<<" ";
    return;
  }
  
    //cout<<"JALA LA PRIMERA";
    showLevelbyLevel(root->left,nivelAbuscar);
    showLevelbyLevel(root->right,nivelAbuscar);
/*
    if (root == NULL)
        //cout<<"AHH "<<root<<endl;
        return;
    cout << root->key <<" ";
    preorder(root->left);
    preorder(root->right);*/
    
  
  /*
  void preorder(struct node *root) {
    if (root == NULL)
        return;
    cout << root->key <<" ";
    preorder(root->left);
    preorder(root->right);*/

}

void printLevelOrder(node* root,int nivel)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Create an empty queue for level order traversal
    queue<std::pair<node*, int>> q;

    // Enqueue Root and initialize height
    
    q.push(std::make_pair(root, 0));
    // cout << q.front().second << endl;
    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        auto pair = q.front();
        // cout << q.front().second << pair.second+1 <<endl;
        node* node =pair.first;
        // cout << node->key << " " <<"LEvel" <<pair.second <<endl;
      
        q.pop();
        // std::cout << "children level" << pair.second+1 <<endl;
        if (pair.second < nivel)
        {
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(std::make_pair(node->left, pair.second+1));
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(std::make_pair(node->right, pair.second+1));
    }
    else
    {
      cout << node->key << " " <<"LEvel" <<pair.second <<endl;
    }
    }
    
}

int main() {
  struct node *root = NULL;
  int opcionOrd,numEnNiveles,numenAnc,respEnNiveles=1,x=1;
  int nums[8]={9,3,1,6,4,7,14,10};

  //ciclo para insertar nums en BST
  for(int j=0;j<8;j++){
    root = insert(root, nums[j]);
  }

cout<<"I- Visitar datos del BST "<<endl;
cout<<"\nElija una opción del menú: "<<endl;
cout<<"1. Preorden transversal"<<endl;
cout<<"2. Inorden transversal"<<endl;
cout<<"3. Post-orden transversal"<<endl;
cout<<"4. Nivel por nivel"<<endl;
cin>>opcionOrd;

if(opcionOrd==1){ cout<<"\nPreorden transversal-> "; preorder(root);}
else if(opcionOrd==2){cout << "\nInorden transversal-> ";
  inorder(root); }
else if(opcionOrd==3){cout << "\nPost-orden transversal-> ";
  postorder(root); }
else if(opcionOrd==4){cout<<"VER EL NIVEL: 2-> "; printLevelOrder(root, 2); }
  //FALTA EL DE POR NIVELES

//muestra en pantalla altura del árbol
cout<<endl;
cout<<"_________________________________________"<<endl;
cout << "\nII- Altura del árbol-> "<<height(root)<<endl;
cout<<"_________________________________________"<<endl;

cout << "\nIII- Ancestro(s) de un dato "<<endl;
cout<<"Digite el número del que desea encontrar su ancestro(s): ";
cin>>numenAnc;
showAnc(root,numenAnc);

cout<<"\n_________________________________________"<<endl;
cout << "\nIV- Nivel en el que se encuentran los datos"<<endl;

while(respEnNiveles==1){
  cout<<"\nIngrese el número que desea buscar en los niveles del árbol: ";
  cin>>numEnNiveles;

  int level = whatLevelAmI(root, numEnNiveles);
	if (level)
			cout << "\nNivel de  "<< numEnNiveles << " es "
				<< whatLevelAmI(root, numEnNiveles) << endl;
  else
			cout << -1 <<", El número "<< numEnNiveles<<": no está en el árbol"<< endl;
  
 do{//este ciclo valida si se ingresa 0 o 1 en las opciones
  cout<<"\nDigite 0 si ya no desea buscar elementos, 1 si desea continuar: ";
  cin>>respEnNiveles;
  if(respEnNiveles != 0 && respEnNiveles != 1){cout<<"ERROR: sólo puede ingresar 0 o 1. Intente de nuevo."<<endl; }

 }while(respEnNiveles != 0 && respEnNiveles != 1);
  }

  
}
