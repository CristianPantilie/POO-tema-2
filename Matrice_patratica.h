#ifndef POO_TEMA_2_MATRICE_PATRATICA_H
#define POO_TEMA_2_MATRICE_PATRATICA_H
#include "Matrice.h"
#include "Complex.h"
#include "Matrice_oarecare.h"

template <class T>
class Matrice_patratica: public Matrice_oarecare<T> {
private:


    void cofactor(Complex<T> **mat, Complex<T> **cof, int i, int j, int n);
    Complex<T> det(Complex<T> **mat, int n);
    void adjuncta(Complex<T> **mat, Complex<T> **adj, int n);

public:
    Matrice_patratica(unsigned int dim);

    Complex<T> determinant();
    Matrice_patratica<T> inversa();

};


#endif //POO_TEMA_2_MATRICE_PATRATICA_H
