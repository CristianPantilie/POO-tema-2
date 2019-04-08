#ifndef POO_TEMA_2_MATRICE_H
#define POO_TEMA_2_MATRICE_H

#include "Complex.h"

struct pozitie
{
    unsigned int linie;
    unsigned int coloana;
};
template <typename T>
struct nod
{
    Complex<T> val;
    struct pozitie poz;
    struct nod *next;
};

template <typename T>
class Matrice {
protected:
    unsigned int linii, coloane;

    struct nod<T> *head;

    int comparaPoz(struct pozitie p1, struct pozitie p2);

public:
    Matrice(unsigned int linii, unsigned int coloane);
    Matrice(const Matrice<T> &z);
    virtual ~Matrice();

    virtual Complex<T> determinant() = 0;

};

#endif //POO_TEMA_2_MATRICE_H
