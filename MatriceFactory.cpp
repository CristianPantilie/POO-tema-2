
#include "MatriceFactory.h"
#include "Matrice_oarecare.h"
#include "Matrice_patratica.h"
#include <iostream>
using namespace std;

template<typename T>
MatriceFactory<T>::MatriceFactory()
{
    newMat = NULL;
}

template<typename T>
MatriceFactory<T>::~MatriceFactory() {
    if(newMat)
    {
        delete newMat;
        newMat = NULL;
    }
}

template<typename T>
Matrice_oarecare<T> *MatriceFactory<T>::getNewMat() {
    return newMat;
}

template<typename T>
void MatriceFactory<T>::creeaza(unsigned int lin, unsigned int col) {
    if(lin == col) {
        newMat = new Matrice_patratica<T>(lin);
        cout << "\nAm creat o matrice patratica\n";
    }
        else
    {
        newMat = new Matrice_oarecare<T>(lin, col);
        cout << "\nAm creat o matrice oarecare";
    }
}

template<typename T>
void MatriceFactory<T>::setNewMat(Complex<T> z, unsigned int linie, unsigned int coloana) {
    this->newMat->adauga(z, linie, coloana);
}


template<typename Y>
istream &operator>>(istream &is, MatriceFactory<Y> &matrice) {
    unsigned int linii, coloane;
    cout << "\nNr. de linii: ";
    is >> linii;
    cout << "\nNr. de coloane: ";
    is >> coloane;
    matrice.creeaza(linii, coloane);

    while(true) {
        cout << "\nApasati 1 pentru a introduce un numar complex si orice altceva pentru a va opri";
        int i;
        is >> i;
        if (i == 1) {
            Complex<Y> z;
            unsigned int lin, col;
            is >> z;
            cout << "\nLinia: ";
            is >> lin;
            cout << "\nColoana: ";
            is >> col;
            matrice.setNewMat(z, lin, col);
        } else
            break;
    }

    return is;
}