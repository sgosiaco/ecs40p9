#include <iostream>
#include <cassert>

using namespace std;

template <class T>
BSTNode<T>::BSTNode(T d, BSTNode<T> *l, BSTNode<T> *r) : left(l), right(r)
{
  data = d;
}

template <class T>
BinarySearchTree<T>::BinarySearchTree() : root(NULL)
{

}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{

}

//public versions
template <class T>
void BinarySearchTree<T>::insert(const T &value)
{
  if(root)
    insert(root, value);
  else
    root = new BSTNode<T>(value, NULL, NULL);
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
  inOrder(root);
  cout << endl;
}

template <class T>
void BinarySearchTree<T>::postOrder()
{
  postOrder(root);
  cout << endl;
}
//end public versions

//private versions
template <class T>
void BinarySearchTree<T>::insert(BSTNode<T> *t, const T &value)
{
  /*
  if(t == NULL)
  {
  t = new BSTNode<T>(value, NULL, NULL);
}
else
{

if(value < t->data)
insert(t->left, value);
else
insert(t->right, value);
}
*/
  assert(value < t->data || t->data < value);
  if(t->data < value)
  {
    if(t->right == NULL)
      t->right = new BSTNode<T>(value, NULL, NULL);
    else
      insert(t->right, value);
  }
  else
  {
    if(t->data > value)
    {
      if(t->left == NULL)
        t->left =new BSTNode<T>(value, NULL, NULL);
      else
        insert(t->left, value);
    }
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
  if(t != NULL)
  {
    inOrder(t->left);
    cout << t->data << ", ";
    inOrder(t->right);
  }
}

template <class T>
void BinarySearchTree<T>::postOrder(BSTNode<T> *t)
{
  if(t != NULL)
  {
    inOrder(t->left);
    inOrder(t->right);
    cout << t->data << ", ";
  }
}

template <class T>
void BinarySearchTree<T>::makeEmpty()
{

}
//end private versions
