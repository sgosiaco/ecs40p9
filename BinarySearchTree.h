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
    void insert(BSTNode<T> *t, const T &value) const;
    void remove(BSTNode<T> * &t, const T &value) const;
    void find(const BSTNode<T> *t, const T &value) const;
    void inOrder(const BSTNode<T> *t) const;
    void postOrder(const BSTNode<T> *t) const;
    void makeEmpty(BSTNode<T> *t) const;
    const BSTNode<T>* const findMin(const BSTNode<T> *t) const;
  protected:

  public:
    void insert(const T &value);
    void remove(const T &value);
    void find(const T &value) const;
    void inOrder() const;
    void postOrder() const;
    BinarySearchTree();
    ~BinarySearchTree();
} ;  // class BinarySearchTree
#include "BinarySearchTree.cpp"
#endif	// bst
