#include <iostream>
#include "BTree.h"
#include "Node.h"

using namespace std;

template <typename T>
BTree<T>::BTree(int degree1)
{
    degree = degree1;
    root = NULL;
}

template <typename T>
void BTree<T>::insert(int key)
{
   if(root == NULL)
   {
      root = new Node(degree,true);
      root->keys[0] = key;
      root->key_numbers = 1;
   }
   else
   {
     if(root->key_numbers == 2*degree-1)
     {
       Node<T> *node = new Node(degree,false);
       node->child[0] = root;
       node->split(root, 0);

       int i=0;
       if(node->keys[0] < key)
          i++;
       node->child[0]->insertNotFull(key);

       root = node;
     }
     else 
        root->insertNotFull(key);
   }
}

template <typename T>
void BTree<T>::walk()
{
   if (root != NULL) 
    root->walk();
}

template <typename T>
void BTree<T>::remove(int key)
{
   if(!root)
   {
      cout<< "Arvore vazia" <<endl; 
   }

   root->remove(key);

   if(root->key_numbers == 0)
   {
      Node<T> *aux = root;
      if(root->leaf)
        root = NULL;
      else
        root = root->child[0];

      delete aux;
   }
}