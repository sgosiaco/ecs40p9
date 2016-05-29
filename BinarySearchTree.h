#ifndef BinarySearchTree_H
#define	BinarySearchTree_H

#include <iostream>

using namespace std;

template <class T>
class BinarySearchTree;

template <class T>
class BSTNode
{
  private:
    friend class BinarySearchTree<T>;
    BSTNode<T>* left;
    BSTNode<T>* right;
    T data;
  protected:

  public:
    BSTNode(T dat, BSTNode<T> *l, BSTNode<T> *r);
}; //BSTNode


template <class T>
class BinarySearchTree
{
  private:
    BSTNode<T>* root;
    void insert(BSTNode<T> *t, const T &value);
    void remove(BSTNode<T> * &t, const T &value);
    void find(BSTNode<T> *t, const T &value) const;
    void inOrder(BSTNode<T> *t);
    void postOrder(BSTNode<T> *t);
    void makeEmpty();
    BSTNode<T>* findMin(BSTNode<T> *t);
  protected:

  public:
    void insert(const T &value);
    void remove(const T &value);
    void find(const T &value) const;
    void inOrder();
    void postOrder();
    BinarySearchTree();
    ~BinarySearchTree();
} ;  // class BinarySearchTree
#include "BinarySearchTree.cpp"
#endif	// bst
