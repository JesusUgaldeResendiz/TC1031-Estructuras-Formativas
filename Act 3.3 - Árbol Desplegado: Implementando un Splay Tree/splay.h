/*
 *  Archivo: splay.h
 *  Creado el: 20/10/2020
 *  Autor: Jesùs Ugalde Reséndiz
 *  Matería: TC1031
 */
#ifndef SPLAY_H_INCLUDED
#define SPLAY_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T> class SplayTree;

template <class T>
class Node{
private:
	T value;
	Node *left, *right, *parent;

	Node<T>* succesor();
	Node<T>* rot_right(Node<T>*);
	Node<T>* rot_left(Node<T>*);

public:
	Node(T);
	Node(T,Node<T>*,Node<T>*,Node<T>*);
	Node<T>*add(T);
	Node<T>*find(T);
	Node<T>*remove(T);
	void removeChilds();
	void inorder(stringstream&) const;
	void print_tree(stringstream&) const;
	void preorder(stringstream&) const;
	Node<T>* splay(Node<T>*,Node<T>*);

	friend class SplayTree<T>;
};

template <class T>
Node<T>::Node(T val){
  value = val;
  left = 0;
  right = 0;
  parent = 0;
}

template <class T>
Node<T>::Node(T val,Node<T> *le,Node<T> *ri,Node<T> *p){
  value = val;
  left = le;
  right = ri;
  parent = p;
}

template <class T>
Node<T>* Node<T>::add(T val){
	if(val > value){
		if(right !=0){
			return right->add(val);
		}
		else{
			right=new Node<T>(val);
			right->parent=this;
			return right;
		}
	}
	else{
		if(val < value){
			if(left!=0){
				return left->add(val);
			}
			else{
				left=new Node<T>(val);
				left->parent =this;
				return left;
			}
		}
	}
}

template <class T>
Node<T>* Node<T>::find(T val){
	if(val == value){
		return this;
	}
	else if(val < value){
		if(left != 0){
			return left->find(val);
		}
		else{
			return this;
		}
	}
	else if (val > value){
		if(right!=0){
			return right->find(val);
		}
		else{
			return this;
		}
	}
	return 0;
}

template <class T>
Node<T>* Node<T>::succesor(){
	Node<T> *izq, *der;
	izq = left;
	der = right;

	if(right == 0){
		if(left != 0){
			left = 0;
		}
		if(izq)
			izq->parent = 0;
		return izq;
	}

	if(right->left == 0){
		right = right->right;
		if(right)
			right->parent = parent;
		if(der){
			der->right = 0;
			der->parent = 0;
		}
		return der;
	}

  Node<T> *p,*q;
  p = right;
  q = right->left;
  while(q->left != 0){
    p = q;
    q = q->left;
  }
  p->left = q->right;
  if(p->left != 0)
    p->left->parent = p;
  q->right = 0;
  return q;
}

template<class T>
Node<T>* Node<T>::remove(T val){
	Node<T> *succ,*old;
	if(val<value){
		if(left!=0){
			if(left->value==val){
				old=left;
				succ=left->succesor();
				if(succ !=0){
					succ->left=old->left;
					succ->right=old->right;
					succ->parent=old->parent;
					if(succ->left)
						succ->left->parent=succ;
					if(succ->right)
						succ->right->parent=succ;
				}
				left=succ;
				delete old;
				return this;
			}else{
				return left->remove(val);
			}
		}
	}else if (val >value){
		if(right!=0){
			if(right->value==val){
				old=right;
				succ=right->succesor();
				if(succ!=0){
					succ->left=old->left;
					succ->right=old->right;
					succ->parent=old->parent;
					if(succ->left)
						succ->left->parent=succ;
					if(succ->right)
						succ->right->parent=succ;
				}
				right=succ;
				delete old;
				return this;
			}else{
				return right->remove(val);
			}
		}
	}
	return 0;
}

template<class T>
void Node<T>::removeChilds(){
	if(right !=0){
		right->removeChilds();
		delete right;
		right=0;
	}
	if(left !=0){
		left->removeChilds();
		delete left;
		left=0;
	}
}

template <class T>
Node<T>* Node<T>::rot_right(Node<T>* q){
	Node<T> *p;
	p = q->left;
	q->left = p->right;

	if(p->right){
		p->right->parent = q;
	}
	p->right = q;

	p->parent= q->parent;
	q->parent = p;

	if(p->parent){
		if(p->parent->left && p->parent->left->value == q->value)
			p->parent->left = p;
		else
			p->parent->right = p;
	}
	return p;
}

template<class T>
Node<T>* Node<T>::rot_left(Node<T>*q){
	Node<T> *p;
	p = q->right;
	q->right = p->left;

	if(p->left){
		p->left->parent = q;
	}
	p->left = q;

	p->parent = q->parent;
	q->parent = p;

	if(p->parent){
		if(p->parent->left && p->parent->left->value==q->value)
			p->parent->left = p;
		else
			p->parent->right = p;
	}
	return p;
}

template<class T>
Node<T>* Node<T>::splay(Node<T>* root, Node<T>* q){
	while(q->parent!=0){

		if(q->parent->value == root->value){
			if(q->parent->left && q->parent->left->value == q->value){
				rot_right(q->parent);
			}
			else{
				rot_left(q->parent);
			}
		}
		else{
			Node<T>*p = q->parent;
			Node<T>*g = p->parent;
			if(p->left && g->left && q->value == p->left->value && p->value == g->left->value){
				rot_right(g);
				rot_right(p);
			}
			else if(p->right && g->right && q->value == p->right->value && p->value == g->right->value){
				rot_left(g);
				rot_left(p);
			}
			else if(p->left && g->right && q->value == p->left->value && p->value == g->right->value){
				rot_right(p);
				rot_left(g);
			}
			else{
				rot_left(p);
				rot_right(g);
			}
		}
	}
	return q;
}

template <class T>
void Node<T>::inorder(stringstream &aux) const {
	if(left != 0){
		left->inorder(aux);
	}
	if(aux.tellp() != 1){
		aux<<" ";
	}
	aux<<value;
	if(right != 0){
		right->inorder(aux);
	}
}

template <class T>
void Node<T>::print_tree(stringstream &aux) const {
	if (parent != 0){
		aux << "\n node " << value;
		aux << " parent " << parent->value;
	}
	else{
		aux << "\n root " << value;
	}
	if (left != 0){
		aux << " left " << left->value;
	}
	if (right != 0){
		aux << " right " << right->value;
	}
	aux << "\n";
	if (left != 0) {
		left->print_tree(aux);
	}
	if (right != 0) {
		right->print_tree(aux);
	}
}

template <class T>
void Node<T>::preorder(stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

template<class T>
class SplayTree{
private:
	Node<T> *root;
	int sze;

public:
	SplayTree();
	~SplayTree();
	bool empty() const;
	void add(T);
	bool find(T);
	void remove(T);
	string inorder() const;
	string print_tree() const;
	string preorder() const;
	int size();
};

template <class T>
SplayTree<T>::SplayTree(){
	root = 0;
}

template<class T>
SplayTree<T>::~SplayTree() {}

template<class T>
bool SplayTree<T>::empty() const{
	return (root==0);
}

template<class T>
void SplayTree<T>::add(T val){
	sze ++;
	if(root !=0){
		Node<T>* p = root->add(val);
		root=root->splay(root,p);
	}
	else{
		root=new Node<T>(val);
	}
}

template<class T>
void SplayTree<T>::remove(T val){
	if(root != 0){
		if(val == root->value){
			Node<T> *succ = root->succesor();
			if(succ != 0){
				succ->left = root->left;
				succ->right = root->right;
				succ->parent = 0;
				if(succ->left){
					succ->left->parent=succ;
				}
				if(succ->right){
					succ->right->parent=succ;
				}
			}
			delete root;
			root = succ;
		}
		else{
			Node<T>*p = root->remove(val);
			if (p != 0){
				root=root->splay(root,p);
			}
		}
	}
	sze --;
}

template<class T>
bool SplayTree<T>::find(T val){
	if(root != 0){
		Node<T>* found = root->find(val);
		root = root->splay(root,found);
		return (root->value == val);
		}
	else{
		return false;
	}
}

template <class T>
string SplayTree<T>::inorder() const {
  stringstream aux;

  aux << "[";
  if (!empty()) {
    root->inorder(aux);
  }
  aux << "]";
  return aux.str();
}


template <class T>
string SplayTree<T>::print_tree() const {
  stringstream aux;

  aux << "\n ================================ ";
  if (!empty()) {
    root->print_tree(aux);
  }
  aux << " ================================== \n";
  return aux.str();
}

template <class T>
string SplayTree<T>::preorder() const {
  stringstream aux;

  aux << "[";
  if (!empty()) {
    root->preorder(aux);
  }
  aux << "]";
  return aux.str();
}

template <class T>
int SplayTree<T>::size() {
  return sze;
}

#endif /*SPLAY_H_INCLUDED*/
