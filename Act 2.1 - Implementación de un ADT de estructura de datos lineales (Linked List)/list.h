/*
 * Archivo: list.h
 *  Creado el: 25/09/2020
 *  Autor: Jesùs Ugalde Reséndiz
 *  Matería: TC1031
 *
 */
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <string>
#include <sstream>
#include "exception.h"

template <class T> class List;

template <class T>
class Link {
	private:
		Link(T);
		Link(T, Link<T>*);
		T value;
		Link<T> * next;
		friend class List<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0)
{

}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt)
{

}



template <class T>
class List
{
	private:
		Link<T> *head;
		int size;
	public:
		List();
		~List();
		void add(T) throw (OutOfMemory);
		int find(T);
		void update(T,T);
		T remove(int) throw (IndexOutOfBounds);
		void clear();
		std::string toString() const;
};

template <class T>
List<T>::List() : head(0), size(0)
{
}

template <class T>
List<T>::~List()
{
	clear();
}


/*Implementacion del metodo add*/
template <class T>
void List<T>::add(T val) throw (OutOfMemory)
{
	Link<T> *new_Link, *puntero;

	new_Link = new Link<T>(val);
	if (new_Link==0)
	{
		throw OutOfMemory();
	}
	if (size==0)
	{
		new_Link->next = head;
		head = new_Link;
		size ++;
		return;
	}
	puntero = head;
	while (puntero->next != 0)
	{
		puntero = puntero -> next;
	}

	new_Link->next = 0;
	puntero->next = new_Link;
	size++;
}

/*Implementacion del metodo find*/
template <class T>
int List<T>::find(T val)
{
	Link<T> *puntero;

	int indice = 0;
	puntero = head;
	while (puntero != 0)
	{
		if (puntero->value==val)
		{
			return indice ;
		}
		indice++;
		puntero = puntero->next;
	}
	return -1;
}

/*Implementacion del metodo update*/
template <class T>
void List<T>::update(T position,T val)
{
	Link<T> *puntero;
	int indice = 0;

	puntero = head;
	while (puntero != 0)
	{
		if (indice == position)
		{
			puntero->value = val;
		}
		puntero = puntero->next;
		indice++;
	}
}

/*Implementacion del metodo remove*/
template <class T>
T List<T>::remove(int indice) throw (IndexOutOfBounds)
{
	T aux;
	Link<T> *puntero, *q;

	if (indice > size)
	{
		throw IndexOutOfBounds();
	}

	puntero = head;

	if (indice==0)
	{
		aux = puntero->value;
		head = puntero->next;
		delete puntero;
	}
	for (int i = 1;i <= indice;i++)
	{
		if (indice == i)
		{
			q = puntero -> next;
			aux = q->value;
			puntero->next = q->next;
			delete q;
		}else
		{
			puntero = puntero->next;
		}
	}
	size--;
	return aux;
}

/*Destructor del objeto implmentado*/
template <class T>
void List<T>::clear()
{
	Link<T> *puntero, *q;

	puntero = head;
	while (puntero != 0) {
		q = puntero->next;
		delete puntero;
		puntero = q;
	}
	head = 0;
	size = 0;
}

/*Agregar un metodo toString a su clase.h*/
template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;
	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

#endif /* LINKEDLIST_H_INCLUDED */
