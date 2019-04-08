
#include "Matrice.h"
#include <iostream>
using namespace std;

template <class T>
Matrice<T>::Matrice(unsigned int linii, unsigned int coloane) : linii(linii), coloane(coloane)
{
    this->head = nullptr;
}


template <class T>
int Matrice<T>::comparaPoz(struct pozitie  p1, struct pozitie p2)
{
    if( (p1.linie < p2.linie) || (p1.linie == p2.linie && p1.coloana < p2.coloana) )
        return -1;    //mai mica
    else if(p1.linie == p2.linie && p1.coloana == p2.coloana)
        return 0;     //egale
    else
        return 1;     //mai mare

}




