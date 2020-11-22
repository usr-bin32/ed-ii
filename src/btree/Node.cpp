#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
Node<T>::Node(int degree1, bool leaf1)
{
   degree = degree1;
   leaf = leaf1;

   keys = new int[2*degree-1];
   child = new Node<T> *[2*degree];

   key_numbers=0;
}

template <typename T>
void Node<T>::walk()
{
   int i;
   for(i=0;i<key_numbers;i++)
   {
      if(leaf == false)
        child[i]->walk();
      cout<<keys[i]<<endl;
   }
   if(leaf == false)
      child[i]->walk();
}

template <typename T>
Node<T>* Node<T>::search(int key)
{
    int i = 0; 
    while (i < key_numbers && key > keys[i]) 
        i++; 
  
    if (keys[i] == key) 
        return this; 
  
    if (leaf == true) 
        return NULL; 

    return child[i]->search(key);
}

template <typename T>
void Node<T>::insertNotFull(int key)
{
   int i = key_numbers-1;

   if(leaf == true)
   {
      while (i >= 0 && keys[i] > key) 
        { 
          keys[i+1] = keys[i]; 
          i--; 
        } 
        keys[i+1] = key; 
        key_numbers = key_numbers+1; 
   }

   else
   { 
      while (i >= 0 && keys[i] > key) 
        i--; 
      if (child[i+1]->key_numbers == 2*degree-1) 
      { 
        split(child[i+1],i+1); 
        if (keys[i+1] < key) 
          i++; 
      } 
      child[i+1]->insertNotFull(key); 
   } 
}

template <typename T>
void Node<T>::split(Node *node, int index)
{
   Node<T> *node1 = new Node(node->degree, node->leaf); 
   node1->key_numbers = degree - 1; 

   for (int j = 0; j < degree-1; j++) 
     node1->keys[j] = node->keys[j+degree];

   if (node->leaf == false) 
   { 
      for (int j = 0; j < degree; j++) 
         node1->child[j] = node->child[j+degree]; 
   } 

   node->key_numbers = degree - 1; 
  
   for (int j = key_numbers; j >= index+1; j--) 
      child[j+1] = child[j]; 
  
   child[index+1] = node1; 
  
    for (int j = key_numbers-1; j >= index; j--) 
        keys[j+1] = keys[j]; 

    keys[index] = node->keys[degree-1]; 
    key_numbers = key_numbers + 1; 
}

template <typename T>
int Node<T>::searchKey(int key)
{
    int i=0;
    for(i=0; i<key_numbers && keys[i]<key ; ++i);
    return i;

}

template <typename T>
int Node<T>::getPredecessor(int i)
{
  Node<T> *node = child[i];
  while(!node->leaf)
    node = node->child[node->key_numbers];
  
  return node->keys[node->key_numbers-1];
}

template <typename T>
int Node<T>::getSuccessor(int i)
{
   Node<T> *node = child[i+1];
   while(!node->leaf)
    node = node->child[0];
  
   return node->keys[0];
}

template <typename T>
void Node<T>::fillChild(int i)
{
   if(i!=key_numbers && child[i+1]->key_numbers >= degree)
      borrowKeyBefore(i);
   
   else if(i!=0 && child[i-1]->key_numbers >= degree)
      borrowKeyAfter(i);
   
   else
   {
      if(i != key_numbers)
        merge(i);
      else
        merge(i-1);
   }
}

template <typename T>
void Node<T>::borrowKeyBefore(int i)
{
   Node<T> *c = child[i];
   Node<T> *sib = child[i-1];

   for (int j = c->key_numbers-1; j>=0; --j) 
        c->keys[j+1] = c->keys[j]; 
   
   if (!c->leaf) 
   { 
      for(int j=c->key_numbers; j>=0; --j) 
        c->child[j+1] = c->child[j]; 
   } 

   c->keys[0] = keys[i-1];

   if (!c->leaf) 
      c->child[0] = sib->child[sib->key_numbers];

   keys[i-1] = sib->keys[sib->key_numbers-1];

   sib->key_numbers = sib->key_numbers -1;
   c->key_numbers = c->key_numbers + 1; 
}

template <typename T>
void Node<T>::borrowKeyAfter(int i)
{
   Node<T> *c = child[i];
   Node<T> *sib = child[i+1];

   c->keys[(c->key_numbers)] = keys[i];
   
   if (!c->leaf) 
   { 
      c->child[(c->key_numbers) + 1] = sib->child[0]; 
   } 

   keys[i] = sib->keys[0];

   for(int j=1; j<sib->key_numbers; ++j)
      sib->keys[j-1] = sib->keys[j];

   if(!sib->leaf)
   {
      for(int j=1; j<=sib->key_numbers; ++j)
        sib->child[j-1] = sib->child[j];
   }

   sib->key_numbers = sib->key_numbers - 1;
   c->key_numbers = c->key_numbers + 1;
}

template <typename T>
void Node<T>::merge(int i)
{
   Node<T> *c = child[i];
   Node<T> *sib = child[i+1];

   c->keys[degree - 1] = keys[i];

   for(int j=0; j<sib->key_numbers; ++j)
      c->keys[j+degree] = sib->keys[j];

   if(!c->leaf)
   {
      for(int j=0; j<sib->key_numbers; ++j)
        c->child[degree+j] = sib->child[j];
   }

   for(int k= i+1; k<key_numbers; ++k)
      keys[k-1] = keys[k];

   for(int z= i+2; z<=key_numbers; ++z)
      child[z-1] = child[z];

  c->key_numbers = c->key_numbers + sib->key_numbers+1;
  key_numbers--;

  delete(sib);  
}

template <typename T>
void Node<T>::remove(int key)
{
  int i = searchKey(key);
  if(i<key_numbers && keys[i] == key)
  {
    if(!leaf)
      removeNotLeaf(i);
    else 
      removeLeaf(i);
  }
  else 
  {
     if(leaf)
        return;

     bool isPresent = ((i == key_numbers)? true:false);
     
     if(child[i]->key_numbers < degree)
        fillChild(i);
     

     if(isPresent && i > key_numbers)
        child[i-1]->remove(key);
     
     else
        child[i]->remove(key);

  }
}

template <typename T>
void Node<T>::removeLeaf(int i)
{
   for(int j=i+1;j<key_numbers; ++j)
      keys[j-1] = keys[j];
   
   key_numbers--;
}

template <typename T>
void Node<T>::removeNotLeaf(int i)
{
   int key = keys[i];

   if(child[i]->key_numbers >=degree)
   {
      int aux = getPredecessor(i);
      keys[i] = aux;
      child[i]->remove(aux);
   }
   else if(child[i+1]->key_numbers >=degree)
   {
      int aux = getSuccessor(i);
      keys[i] = aux;
      child[i+1]->remove(aux);
   }
   else
   {
      merge(i);
      child[i]->remove(key);
   }
}