#include <iostream>
#include <cassert>

using namespace std;

template <class T>
BSTNode<T>::BSTNode(T d, BSTNode<T> *l, BSTNode<T> *r) : left(l), right(r)
{
  data = d;
} //con

template <class T>
BinarySearchTree<T>::BinarySearchTree() : root(NULL)
{

} //con

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{

} //decon

//public versions
template <class T>
void BinarySearchTree<T>::insert(const T &value)
{
  if(root)
    insert(root, value);
  else //null
    root = new BSTNode<T>(value, NULL, NULL);
} //insert

template <class T>
void BinarySearchTree<T>::remove(const T &value)
{
  assert(root);
  remove(root, value);
} //remove

template <class T>
void BinarySearchTree<T>::find(const T &value) const
{
  assert(root != NULL);
  find(root, value);
} //find

template <class T>
void BinarySearchTree<T>::inOrder()
{
  inOrder(root);
  cout << endl;
} //inorder

template <class T>
void BinarySearchTree<T>::postOrder()
{
  postOrder(root);
  cout << endl;
} //postorder
//end public versions

//private versions
template <class T>
void BinarySearchTree<T>::insert(BSTNode<T> *t, const T &value)
{
  assert(value < t->data || t->data < value);

  if(t->data < value)
  {
    if(t->right == NULL)
      t->right = new BSTNode<T>(value, NULL, NULL);
    else //not null
      insert(t->right, value);
  } //if
  else //else
  {
    if(t->data > value)
    {
      if(t->left == NULL)
        t->left = new BSTNode<T>(value, NULL, NULL);
      else //not null
        insert(t->left, value);
    } //if
    else //dupe
      cout << "Found duplicate." << endl;
  } //else
} //insert

template <class T>
void BinarySearchTree<T>::remove(BSTNode<T> * &t, const T &value)
{
  assert(t != NULL);

  if(t != NULL)
  {
    if(t->data < value)
      remove(t->right, value);
    else //else
      if(value < t->data)
        remove(t->left, value);
      else //found
      {
        if(!(t->right) && !(t->left))
        {
          delete t;
          t = NULL;
        } //if
        else
          if((t->left && !(t->right)) || (t->right && !(t->left)))
          {
            BSTNode<T>* temp = NULL;

            if(t->left)
              temp = t->left;
            else
              temp = t->right;
            delete t;
            t = temp;
          } //if
          else //children
          {
            BSTNode<T>* min = findMin(t->right);
            t->data = min->data;
            remove(t->right, t->data);
          } //else
        } //else
  } //if
  else //no match
    cout << "Not found." << endl;
} //remove

template <class T>
void BinarySearchTree<T>::find(BSTNode<T> *t, const T &value) const
{
  if(t != NULL)
  {
    if(t->data < value)
      find(t->right, value);
    else //else
      if(value < t->data)
        find(t->left, value);
      else //found
        cout << "Found." << endl;
  } //if
  else //no match
    cout << "Not found." << endl;
} //find

template <class T>
void BinarySearchTree<T>::inOrder(BSTNode<T> *t)
{
  if(t != NULL)
  {
    inOrder(t->left);
    cout << t->data << ", ";
    inOrder(t->right);
  } //if
} //inorder

template <class T>
void BinarySearchTree<T>::postOrder(BSTNode<T> *t)
{
  if(t != NULL)
  {
    postOrder(t->left);
    postOrder(t->right);
    cout << t->data << ", ";
  } //if
} //postorder

template <class T>
void BinarySearchTree<T>::makeEmpty()
{

} //makeEmpty

template <class T>
BSTNode<T>* BinarySearchTree<T>::findMin(BSTNode<T> *t)
{
  if(t != NULL)
  {
    BSTNode<T>* temp = findMin(t->left);
    if(!temp)
      return t;
    else //else
      return temp;
  } //if
  else //none
    return NULL;
} //findMin
//end private versions
