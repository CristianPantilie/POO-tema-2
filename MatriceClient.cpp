
#include "MatriceClient.h"
#include "Matrice_oarecare.h"
#include "Matrice_patratica.h"

template<class T>
MatriceClient<T>::MatriceClient()
{
    newMat = NULL;
}

template<class T>
MatriceClient<T>::~MatriceClient() {
    if(newMat)
    {
        delete[] newMat;
        newMat = NULL;
    }
}

template<class T>
Matrice_oarecare<T> *MatriceClient<T>::getMatrice() {
    return newMat;
}

template<class T>
void MatriceClient<T>::creeaza(unsigned int lin, unsigned int col) {
    if(lin == col)
        newMat = new Matrice_patratica<T>(lin);
    else
        newMat = new Matrice_oarecare<T>(lin, col);
}
