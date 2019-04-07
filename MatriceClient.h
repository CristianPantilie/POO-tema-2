#ifndef POO_TEMA_2_MATRICECLIENT_H
#define POO_TEMA_2_MATRICECLIENT_H

#include "Matrice.h"

/*
 * Factory design pattern
 * creeaza o noua matrice potrivita pentru numarul de linii si coloane date
 *
*/
template <class T>
class MatriceClient{
private:
    Matrice<T> *newMat;
public:
    MatriceClient();
    ~MatriceClient();
    void creeaza(unsigned int lin, unsigned int col);
    Matrice<T> *getMatrice();
};



#endif //POO_TEMA_2_MATRICECLIENT_H
