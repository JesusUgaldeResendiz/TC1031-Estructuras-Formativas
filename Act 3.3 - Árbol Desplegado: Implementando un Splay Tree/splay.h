/*
 *  Archivo: splay.h
 *  Creado el: 21/10/2020
 *  Autor: Jesùs Ugalde Reséndiz
 *  Matería: TC1031
 *
 */

#ifndef SPLAY_H
#define SPLAY_H

#include <sstream>
#include <iostream>
using namespace std;

template <class T> class SplayTree;


template <class T> class Nodo {


public:

  Nodo (T);
  Nodo (T, Nodo<T>*, Nodo<T>*, Nodo<T>*); 
  Nodo<T>* find(T);
  Nodo<T>* add(T);
  Nodo<T>* remove(T);
  
  
  void preorder(stringstream&) const;
  void inorder(stringstream&) const;
  void removeChilds();
  void print_tree(stringstream&) const;
  

  Nodo<T>* splay(Nodo<T>*, Nodo<T>*);

private:
    T value;
  Node *left, *right, *parent;

  Node<T>* succesor();
  Node<T>* rot_right(Node<T>*);
  Node<T>* rot_left(Node<T>*);

  friend class SplayTree<T>;
};

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri, Node<T> *p) : value(val), left(le), right(ri), parent(p) {}

template <class T>
Node<T>* Node<T>::add(T val) 
{

if (val < value) 
{
  if (left != 0)
  {
    return left->add(val);
  }
  else 
  {
    left = new Node<T>(val);
    left->parent = this;
    return left;
  }
  } else 
  {
    if (right != 0) 
	{
      return right->add(val);
    } else 
	{
      right = new Node<T>(val);
      right->parent = this;
      return right;
    }
  }
}

template <class T>
Node<T>* Node<T>::succesor()
{
	Node<T> *le, *ri;
	
	le = left;
	ri = right;
	
	if (right == 0)
	{
		if (left != 0)
		{
			left = 0;
		}
	if(le)
		le->parent = 0;
	return le;
	}
	
	if (right->left == 0)
	{
		right = right->right;
		if(right)
			right->parent = parent;
		if(ri)
		{
			ri->right = 0;
			ri->parent = 0;
		}
		return ri;
	}
	
	Node<T> *p, *c;
	p = right;
	c = right->left;
	while(c->left != 0)
	{
		p = c;
		c = c->left;
	}
	p->left = c->right;
	if(p->left != 0)
		p->left->parent = p;
	c->right = 0;
	return c;
}


template <class T>
Node<T>* Node<T>::remove(T val) 
{
Node<T> *succ, *old;
if (val < value) 
{
  if (left != 0) 
  {
    if (left->value == val) 
	{
      old = left;
      succ = left->succesor();
      if (succ != 0) 
	  {
        succ->left = old->left;
        succ->right = old->right;
        succ->parent = old->parent;
        if (succ->left)
          succ->left->parent = succ;
        if (succ->right)
          succ->right->parent = succ;
      }
      left = succ;
      delete old;
      return this;
    } else 
	{
      return left->remove(val);
    }
  }
} else if (val > value) 
{
  if (right != 0) 
  {
    if (right->value == val) 
	{
      old = right;
      succ = right->succesor();
      if (succ != 0) 
	  {
        succ->left = old->left;
        succ->right = old->right;
        succ->parent = old->parent;
        if (succ->left)
          succ->left->parent = succ;
        if (succ->right)
          succ->right->parent = succ;
      }
      right = succ;
      delete old;
      return this;
  } else 
  {
    return right->remove(val);
      }
    }
  }
  return 0;
}

template <class T>
Node<T>* Node<T>::rot_right(Node<T>* x)
{
  Node<T> *y = x->left;
  x->left = y->right;
  if(y->right)
    y->right->parent = x;
  y->right = x;

  y->parent = x->parent;
  x->parent = y;
 
  if (y->parent)
  {
    if (y->parent->left && y->parent->left->value == x->value)
      y->parent->left = y;
    else
      y->parent->right = y;  
  }
  return y;
}

template <class T>
Node<T>* Node<T>::rot_left(Node<T>* x)
{
  Node<T> *y = x->right;
  x->right = y->left;
  if(y->left)
    y->left->parent = x;
  y->left = x;
  y->parent = x->parent;
  x->parent = y;
  if (y->parent) 
  {
    if (y->parent->left && y->parent->left->value == x->value)
      y->parent->left = y;
    else
      y->parent->right = y;  
  }
  return y;
}

template <class T>
void Node<T>::inorder(stringstream &aux) 
{
  if (left != 0) 
  {
    left->inorder(aux);
  }
  if (aux.tellp() != 1) 
  {
    aux << " ";
  }
  aux << value;
  if (right != 0) 
  {
    right->inorder(aux);
  }
}

template <class T>
void Node<T>::preorder(stringstream &aux)
{
	aux << value;
	if (left != 0) 
	{
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) 
	{
		aux << " ";
		right->preorder(aux);
	}
}

template <class T>
Node<T>* Node<T>::find(T val) 
{
  if (val == value)
  {
    return this;
  } else if (val < value) 
  {
    if (left != 0)
    return left->find(val);
  else
    return this;
  } else if (val > value) 
  {
    if (right != 0)
      return right->find(val);
    else
      return this;
  }
  return 0;
}


template <class T>
Node<T>* Node<T>::splay(Node<T>* root,Node<T>* x) 
{ 
  while (x->parent != 0)
  {
	
    if(x->parent->value == root->value)
	{
      if(x->parent->left && x->parent->left->value == x->value)
	  {
        rot_right(x->parent);
      } else 
	  {
        rot_left(x->parent);
      }
	} else
	{
        Node<T>*p = x->parent; 
        Node<T>*g = p->parent; 
		
        if(p->left && g->left && 
		x->value == p->left->value && p->value == g->left->value)
		{
		  rot_right(g);
          rot_right(p);
        } else if (p->right && g->right && 
		x->value == p->right->value && p->value == g->right->value)
		{
		  rot_left(g);
          rot_left(p);
        } else if (p->left && g-> right && 
		x->value == p->left->value && p->value == g->right->value)
		{
		  rot_right(p);
          rot_left(g);
        } else 
		{
		  rot_left(p);
          rot_right(g);
        }
      }
    }
    return x;
}




template <class T> class SplayTree {


public:
  SplayTree();
  
  string inorder();
  string print_tree();
  string preorder();
  
  bool find (T);
  bool empty();
  void add(T);
  int size();
  void remove (T);

private:
  Nodo<T> *root;

};

template <class T> SplayTree<T>::SplayTree()  {

  root = 0;
}

template <class T> bool SplayTree<T>::empty() const {
  
  if (root == 0 ) return true ;
  else return false;
}
 
template <class T> void SplayTree<T>::add(T val) {
  if ( root != 0) {
    Nodo<T>* added = root->add(val);
    root = root->splay(root,added);
  } 
  else     root = new Nodo<T>(val);
  
}
template <class T> string SplayTree<T>::preorder() const {
  stringstream aux;

  aux << "[";
  if (!empty()) {
    root->preorder(aux);
  }
  aux << "]";
  return aux.str();
}

template <class T>
int SplayTree<T>::size(){
	return 0;
}

template <class T>
void SplayTree<T>::remove(T val) 
{
  if (root != 0) 
  {
    if (val == root->value) 
	{
      Node<T> *succ = root->succesor();
      if (succ != 0) 
	  {
        succ->left = root->left;
        succ->right = root->right;
        succ->parent = 0;
        if (succ->left)
          succ->left->parent = succ;
        if (succ->right)
          succ->right->parent = succ;
      }
      delete root;
      root = succ;
    } else 
	{
      Node<T>* p = root->remove(val);
      root = root->splay(root,p);
    }
  }
}

template <class T> bool SplayTree<T>::find(T val) {
  if (root != 0) {
    Nodo<T>* found = root->find(val);
    root = root->splay(root,found);
    return (root->value == val);
  } else {
    return false;
  }
}

template <class T> string SplayTree<T>::inorder() const {
  stringstream aux;

  aux << "[";
  if (!empty()) {
    root->inorder(aux);
  }
  aux << "]";
  return aux.str();
}

#endif /*SPLAY__H_INCLUDED*/
