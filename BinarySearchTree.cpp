#include <iostream>
#include <cassert>

using namespace std;

template <class T>
BSTNode<T>::BSTNode(T d, BSTNode<T> *l, BSTNode<T> *r) : left(l), right(r)
{
  data = d;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{

}

//public versions
template <class T>
void BinarySearchTree<T>::insert(const T &value)
{
  insert(root, value);
}

template <class T>
void BinarySearchTree<T>::remove(const T &value)
{
  assert(root);
  remove(root, value);
}

template <class T>
void BinarySearchTree<T>::find(const T &value)
{
  assert(root != NULL);
}

template <class T>
void BinarySearchTree<T>::inOrder()
{

}

template <class T>
void BinarySearchTree<T>::postOrder()
{

}
//end public versions

//private versions
template <class T>
void BinarySearchTree<T>::insert(BSTNode<T> *t, const T &value)
{
  if(t == NULL)
    t = new BSTNode<T>(value, NULL, NULL);
  else
  {
    assert(value < t->data || t->data < value);
    if(value < t->data)
      insert(t->left, value);
    else
      insert(t->right, value);
  }
}

template <class T>
void BinarySearchTree<T>::remove(BSTNode<T> * &t, const T &value)
{
  assert(t != NULL);
}

template <class T>
void BinarySearchTree<T>::find(BSTNode<T> *t, const T &value)
{

}

template <class T>
void BinarySearchTree<T>::inOrder(BSTNode<T> *t)
{
  if(t)
  {
    inOrder(t->left);
    cout << t->data << ", ";
    inOrder(t->right);
  }
}

template <class T>
void BinarySearchTree<T>::postOrder(BSTNode<T> *t)
{

}

template <class T>
void BinarySearchTree<T>::makeEmpty()
{

}
//end private versions
