/*
 * Archivo: sorts.h
 *
 *  Fecha de creacion: 09/09/2020
 *      Autor: Jesus Ugalde Resendiz
 */
#ifndef SORTS_H_INCLUDED
#define SORTS_H_INCLUDED

#include <vector>
#include <list>

template <class T>
class Sorts 
{
private:
	// Las funciones/metodos para hacer talacha me las quedo yo.
	void swap(std::vector<T>&, int, int);
	void unirSplit(std::vector<T>&, std::vector<T>&, int, int);
	void unirArray(std::vector<T>&, std::vector<T>&, int, int, int);
	void copyArray(std::vector<T>&, std::vector<T>&, int, int);
	int bs_aux(const std::vector<T>&v,int low,int high,int val);	
public:
	// Los metodos publicos seran los que los usuarios podran usar libremente.
	void ordenaBurbuja(std::vector<T>&);
	void ordenaSeleccion(std::vector<T>&);
	void ordenaMerge(std::vector<T>&);
	
	int busqSecuencial(const std::vector<T>&,int); 
	int busqBinaria(const std::vector<T>&v,int valor);
};

/* Implementacion del algoritmo swap */
template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) 
{
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}


// Implementacion del algoritmo ordenaBurbuja
template <class T>
void Sorts<T>::ordenaBurbuja(std::vector<T> &v) 
{

	for (int i=v.size()-1;i>0;i--) {
		for (int j=0;j<i;j++) 
		{
			if (v[j]>v[j + 1]) 
			{
				swap(v, j, j + 1);
			}
		}
	}
}

// Implementacion del algoritmo ordenaSeleccion
template <class T>
void Sorts<T>::ordenaSeleccion(std::vector<T> &v) 
{
	int p;

	for (int i=v.size()-1;i>0;i--) 
	{
		p = 0;
		for (int j=1;j<=i;j++) 
		{
			if (v[j]>v[p]) 
			{
				p = j;
			}
		}

		if (p!=i) 
		{
			swap(v, i, p);
		}
	}
}

// Implementacion del auxiliar unirSplit (size y elementos de lista / 2)
template <class T>
void Sorts<T>::unirSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) 
{
	int mid;

	if ((high-low)<1) 
	{
		return;
	}
	mid = (high + low) / 2;
	unirSplit(A, B, low, mid);
	unirSplit(A, B, mid + 1, high);
	unirArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}

/* Implementacion del algoritmo del unirArray; las partes se ordenan y unen */
template <class T>
void Sorts<T>::unirArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high)
{
	int i, j, k;

	i = low;
	j = mid+1;
	k = low;

	while (i<=mid &&j <=high) 
	{
		if (A[i]<A[j]) 
		{
			B[k] = A[i];
			i++;
		} else 
		{
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i>mid) {
		for (;j<=high;j++) 
		{
			B[k++] = A[j];
		}
	} else {
		for (;i<=mid;i++) 
		{
			B[k++] = A[i];
		}
	}
}

/* Implementacion del algoritmo del copyArray; Se mezlan las subdiviciones */
template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) 
{
	for (int i=low;i<=high;i++) 
	{
		A[i] = B[i];
	}
}

/* Implementacion del algoritmo ordenaMerge */
template <class T>
void Sorts<T>::ordenaMerge(std::vector<T> &v) 
{
	std::vector<T> tmp(v.size());
	unirSplit(v, tmp, 0, v.size() - 1);
}

/* Implementacion del algoritmo busqSecuencial */
template <class T>
int Sorts<T>::busqSecuencial(const std::vector<T>&v,int valor)
{
	for (int i=0;i<v.size();i++) 
	{
		if (valor == v[i]) 
		{
			return i;
		}
	}
	
	return (-1);
}

/* Implementacion del algoritmo bs_aux */
template <class T>
int Sorts<T>::bs_aux(const std::vector<T>&v,int low,int high,int valor)
{ 
	int mid;

	if (low<=high) 
	{
		mid = (high+low)/2;
		if (valor==v[mid]) 
		{
			return mid;
		} else if (valor<v[mid]) 
		{
			return bs_aux(v, low, mid - 1, valor);
		} else if (valor>v[mid]) 
		{
			return bs_aux(v, mid + 1, high, valor);
		}
	}
	
	return low;
}

/* Implementacion del algoritmo busqBinaria */
template <class T>
int Sorts<T>::busqBinaria(const std::vector<T>&v,int valor) 
{
	return bs_aux(v, 0,v.size() - 1, valor);
}





#endif /* SORTS_H_INCLUDED */
