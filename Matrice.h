#ifndef POO_TEMA_2_MATRICE_H
#define POO_TEMA_2_MATRICE_H

#include "Complex.h"
#include "Matrice_oarecare.h"

struct pozitie
{
    unsigned int linie;
    unsigned int coloana;
};
template <class T>
struct nod
{
    Complex<T> val;
    struct pozitie poz;
    struct nod *next;
};

template <class T>
class Matrice {
protected:
    unsigned int linii, coloane;

    struct nod<T> *head;

    int comparaPoz(struct pozitie p1, struct pozitie p2);

public:
    Matrice(unsigned int linii, unsigned int coloane);

    //void adauga(Complex<T> z, unsigned int linie, unsigned int coloana);

    virtual Complex<T> determinant() = 0;
    virtual Matrice_oarecare<T> inversa() = 0;
};

#endif //POO_TEMA_2_MATRICE_H
