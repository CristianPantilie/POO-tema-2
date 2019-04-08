#ifndef POO_TEMA_2_MATRICECLIENT_H
#define POO_TEMA_2_MATRICECLIENT_H

#include "Matrice.h"
#include "Matrice_oarecare.h"

/*
 * Factory design pattern
 * creeaza o noua matrice potrivita pentru numarul de linii si coloane date
 *
*/
template <class T>
class MatriceClient{
private:
    Matrice_oarecare<T> *newMat;
public:
    MatriceClient();
    ~MatriceClient();
    void creeaza(unsigned int lin, unsigned int col);
    Matrice_oarecare<T> *getMatrice();
};



#endif //POO_TEMA_2_MATRICECLIENT_H
