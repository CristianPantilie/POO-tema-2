#ifndef POO_TEMA_2_MATRICE_OARECARE_H
#define POO_TEMA_2_MATRICE_OARECARE_H

#include "Matrice.h"

template <class T>
class Matrice_oarecare: public Matrice<T> {
private:

public:

    Matrice_oarecare(unsigned int lin, unsigned int col);

    void adauga(Complex<T> z, unsigned int linie, unsigned int coloana);
    Matrice_oarecare<T> transpusa();
    Matrice_oarecare<T> operator+(const Matrice_oarecare<T> &z);
    Matrice_oarecare<T> operator*(Matrice_oarecare<T> &z);
    template <class Y> friend std::ostream &operator<< (std::ostream &os, const Matrice_oarecare<Y> &matrice);
    template <class Y> friend std::istream &operator>> (std::istream &is, Matrice_oarecare<Y> &matrice);

    Complex<T> determinant();
    Matrice_oarecare<T> inversa();

};


#endif //POO_TEMA_2_MATRICE_OARECARE_H
