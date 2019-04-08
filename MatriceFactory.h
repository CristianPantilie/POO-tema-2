#ifndef POO_TEMA_2_MATRICECLIENT_H
#define POO_TEMA_2_MATRICECLIENT_H

#include "Matrice.h"
#include "Matrice_oarecare.h"

/*
 * Factory design pattern
 * decide la run-time ce fel de clasa sa creeze (oarecare sau patratica)
 * creeaza o noua matrice potrivita pentru numarul de linii si coloane date
*/
template <typename T>
class MatriceFactory{
private:
    Matrice_oarecare<T> *newMat;
public:
    MatriceFactory();
    ~MatriceFactory();
    void creeaza(unsigned int lin, unsigned int col);
    Matrice_oarecare<T> *getNewMat();
    void setNewMat(Complex<T> z, unsigned int linie, unsigned int coloana);

    template <class Y> friend std::istream &operator>> (std::istream &is, Matrice_oarecare<Y> &matrice);
};



#endif //POO_TEMA_2_MATRICECLIENT_H
