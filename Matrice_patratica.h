#ifndef POO_TEMA_2_MATRICE_PATRATICA_H
#define POO_TEMA_2_MATRICE_PATRATICA_H

#include <ostream>
#include "Matrice_oarecare.h"

template <typename T>
class Matrice_patratica: public Matrice_oarecare<T> {
private:


    void cofactor(Complex<T> **mat, Complex<T> **cof, int i, int j, int n);
    Complex<T> det(Complex<T> **mat, int n);
    void adjuncta(Complex<T> **mat, Complex<T> **adj, int n);

public:
    Matrice_patratica(unsigned int dim);

    Complex<T> determinant();
    Matrice_patratica<T> inversa();

    template <class Y> friend std::ostream &operator<<(std::ostream &os, Matrice_patratica<Y> &patratica);

};


#endif //POO_TEMA_2_MATRICE_PATRATICA_H
