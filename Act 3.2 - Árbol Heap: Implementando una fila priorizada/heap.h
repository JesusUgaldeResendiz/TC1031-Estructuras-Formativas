/*
 *  Archivo: heap.h
 *  Creado el: 14/11/2020
 *  Autor: JesÃºs Ugalde ResÃ©ndiz
 *  Materia: TC1031
 */

#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
unsigned int typedef uint;

template <class T>
class Heap{
private:
  T *data;
  uint tam;
  uint sze;
  uint parent(uint) const;
  uint left(uint) const;
  uint right(uint) const;
  void heapify(uint);
  void swap(uint,uint);
public:
  Heap(uint);
  ~Heap();
  bool empty() const;
  void push(T);
  void pop();
  uint size() const;
  T top();
  std::string toString() const;
};

template <class T>
Heap<T>::Heap(uint t){
  tam = t;
  data = new T[tam];
  sze = 0;
}

template <class T>
Heap<T>::~Heap(){
  delete [] data;
  data = 0; 
  tam = 0; 
  sze = 0;
}

template <class T>
bool Heap<T>::empty() const {
  return (sze == 0);
}

template <class T>
T Heap<T>::top(){
  return data[0];
}

template <class T>
uint Heap<T>::size() const{
	return sze;
}

template <class T>
uint Heap<T>::parent(uint position) const {
	return((position - 1)/2);
}

template <class T>
uint Heap<T>::left(uint position) const { 
	return (1 + (2*position));
}

template <class T>
uint Heap<T>::right(uint position) const {
	return (2 + (2*position));
}

template <class T>
void Heap<T>::swap(uint i, uint j){
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
void Heap<T>::heapify(uint position){
	uint le = left(position);
	uint ri = right(position);
	uint min = position;
	if(ri <= sze && data[ri] < data[min]){
		min = ri;
	}
	if(le <= sze && data[le] < data[min]){
		min = le;
	}
	if(min != position){
		swap(position,min);
		heapify(min);
	}
}

template <class T>
void Heap<T>::push(T val){
	uint position;
	position = sze;
	sze ++;
	while(position > 0 && val < data[parent(position)]){
		data[position] = data[parent(position)];
		position = parent(position);
	}
	data[position] = val;
}

template <class T>
void Heap<T>::pop(){
	data[0] = data[--sze];
	heapify(0);
}

 // Agregue en tu heap.h el metodo to string
template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;
	aux << "[";	for (unsigned int i = 0; i < sze; i++) {
		if (i != 0) {
			aux << " ";
		} aux << data[i];
	} aux << "]";
	return aux.str();
}
#endif /*HEAP_H_INCLUDED*/
