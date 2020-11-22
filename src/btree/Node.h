#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <typename T>
class Node
{
  public:
    int *keys;
    int key_numbers;
    bool leaf;
    int degree;
    Node **child;
    Node(int degree1, bool leaf1);
    ~Node() {};
    Node *search(int key);
    void insertNotFull(int key);
    void split(Node *node, int index);
    void walk();
    int searchKey(int key);
    void removeLeaf (int i);
    void removeNotLeaf(int i);
    int getPredecessor(int i);
    int getSuccessor(int i);
    void fillChild(int i);
    void borrowKeyBefore(int i);
    void borrowKeyAfter(int i);
    void merge(int i);
    void remove(int key);
};
#endif // NODE_H_INCLUDED