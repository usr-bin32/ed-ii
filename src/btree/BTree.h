#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED
#include "Node.h"

template <typename T>
class BTree
{
  public:
    int degree;
    Node<T> *root;
    BTree(int degree1);
    ~BTree() {};
    Node<T> *search(int key) {return (root == NULL)? NULL : root->search(key);};
    void insert(int key);
    void walk();
    void remove(int key);
};
#endif // BTREE_H_INCLUDED