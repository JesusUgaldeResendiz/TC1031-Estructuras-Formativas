/*
 * Archivo: dlist.h
 * Created on: 28/09/2020
 * Autor: Jesùs Ugalde Reséndiz
 * Matería: TC1031
*/

#ifndef DLIST_H_INCLUDED
#define DLIST_H_INCLUDED

#include <string>
#include <sstream>
#include "exception.h"

template <class T> class DList;

template <class T>
class DLink
{
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

	T value;
	DLink<T> *previous;
	DLink<T> *next;

	friend class DList<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {}



template <class T>
class DList
{
private:
	DLink<T> *head;
	DLink<T> *tail;
	int size;

public:
	DList();
	DList(const DList<T>&) throw (OutOfMemory);
	~DList();
	void add(T) throw (OutOfMemory);
	T find(T);
	void update(T,T);
	T remove(int) throw (IndexOutOfBounds);
	void clear();
	std::string toStringForward() const;
	std::string toStringBackward() const;
};

template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

template <class T>
DList<T>::~DList()
{
	clear();
}

/*Implementacion del algoritmo add*/
template <class T>
void DList<T>::add(T valor) throw (OutOfMemory)
{
	DLink<T> *new_DLink, *p, *q;
	new_DLink = new DLink<T>(valor);

	if(new_DLink == 0)
	{
		throw OutOfMemory();
	}
	if(head==0 && tail==0)
	{
	head = new_DLink;
	tail = new_DLink;
  }
	else
	{
		tail->next = new_DLink;
		new_DLink->previous = tail;
		tail = new_DLink;
	}
	size++;
}

/*Implementacion del algoritmo find*/
template <class T>
T DList<T>::find(T valor)
{
	int pos = 0;
	DLink<T> *p;

	p = head;
	while(p != 0)
	{
		if(p->value==valor)
		{
			return pos;
		}
		p = p->next;
		pos++;
	}
	return -1;
}

/*Implementacion del algoritmo update*/
template <class T>
void DList<T>::update(T position,T val)
{
	DLink<T> *puntero;
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

/*Implementacion del algoritmo remove*/
template <class T>
T DList<T>::remove(int indice) throw (IndexOutOfBounds)
{
	int position;
	T valor;
	DLink<T> *p;

	if (indice < 0 || indice >= size)
	{
		throw IndexOutOfBounds();
	}

	if(indice == 0)
	{
		if(head == 0 && tail == 0)
		{
			throw NoSuchElement();
		}
		p = head;
		valor = p->value;
		if(head==tail)
		{
			head = 0;
			tail = 0;
		}
		else
		{
			head = p->next;
			p->next->previous = 0;
		}
		delete p;
		size --;
		return valor;

	}

	p = head;
	position = 0;
	while(position != indice)
	{
		p = p->next;
		position++;
	}

	valor = p->value;
	p->previous->next = p->next;
	if(p->next != 0)
	{
		p->next->previous = p->previous;
	}

	size--;
	delete p;

	return valor;
}

template <class T>
void DList<T>::clear() {
	DLink<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
	size = 0;
}

// Incluye estos funciones en tu dlist.h para poder imprimir tus respuestas
// en formatos compatibles con el main
template <class T>
std::string DList<T>::toStringForward() const {
	std::stringstream aux;
	DLink<T> *p;
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

template <class T>
std::string DList<T>::toStringBackward() const {
	std::stringstream aux;
	DLink<T> *p;
	p = tail;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->previous != 0) {
			aux << ", ";
		}
		p = p->previous;
	}
	aux << "]";
	return aux.str();
}


#endif /*DLIST_H_INCLUDED*/
