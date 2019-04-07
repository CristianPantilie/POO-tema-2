
#include "Matrice.h"
#include <iostream>
using namespace std;

template <class T>
Matrice<T>::Matrice(unsigned int linii, unsigned int coloane) : linii(linii), coloane(coloane)
{
    this->head = nullptr;
}

template <class T>
void Matrice<T>::adauga(Complex<T> z, unsigned int linie, unsigned int coloana)
{
    auto *nou = new struct nod;
    nou->val =  z;
    nou->poz.linie = linie;
    nou->poz.coloana = coloana;
    nou->next = nullptr;

    if(!this->head || comparaPoz(this->head->poz, nou->poz) >= 0)
    {
        nou->next = this->head;
        this->head = nou;
    }
    else
    {
        auto *iter = this->head;
        while(iter->next && comparaPoz(iter->next->poz, nou->poz) < 0)
            iter = iter->next;

        nou->next = iter->next;
        iter->next = nou;
    }
}

template <class T>
int Matrice<T>::comparaPoz(Matrice<T>::pozitie p1, Matrice<T>::pozitie p2)
{
    if( (p1.linie < p2.linie) || (p1.linie == p2.linie && p1.coloana < p2.coloana) )
        return -1;    //mai mica
    else if(p1.linie == p2.linie && p1.coloana == p2.coloana)
        return 0;     //egale
    else
        return 1;     //mai mare

}

template <class T>
Matrice<T> Matrice<T>::transpusa() {

    Matrice rez(this->coloane, this->linii);
    auto *iter = this->head;

    while(iter)
    {
        rez.adauga(iter->val, iter->poz.coloana, iter->poz.linie);
        iter = iter->next;
    }

    return rez;
}


template <class T>
Matrice<T> Matrice<T>::operator+(const Matrice<T> &z) {
    if(this->linii == z.linii && this->coloane == z.coloane)
    {
        Matrice rez(z.linii, z.coloane);

        auto *iter1 = this->head;
        auto *iter2 = z.head;

        while(iter1 || iter2)
        {
            int c;
            if(iter1 && iter2)
                c = comparaPoz(iter1->poz, iter2->poz);
            else if(!iter1)
                c = 1;
            else
                c = -1;

            if(c == 0)
            {
                rez.adauga(iter1->val + iter2->val, iter1->poz.linie, iter1->poz.coloana);
                iter1 = iter1->next;
                iter2 = iter2->next;
            }
            else if(c > 0)
            {
                rez.adauga(iter2->val, iter2->poz.linie, iter2->poz.coloana);
                iter2 = iter2->next;
            }
            else if(c < 0)
            {
                rez.adauga(iter1->val, iter1->poz.linie, iter1->poz.coloana);
                iter1 = iter1->next;

            }
        }
        return rez;
    }
    else
    {
        std::cout << "Matricile nu pot fi adunate";
        return Matrice(0, 0);
    }
}

template <class T>
Matrice<T> Matrice<T>::operator*(Matrice<T> &z) {
    if(this->coloane == z.linii)
    {
        Matrice rez(this->linii, z.coloane);
        Matrice zt = z.transpusa();
        auto *iter1 = this->head;
        auto *iter2 = zt.head;

        for (int i = 1; i <= this->linii; ++i)
        {
            bool found = false;
            Complex<T> r(0, 0);
            while(iter1 && iter1->poz.linie < i)
                iter1 = iter1->next;

            while(iter1 && iter1->poz.linie == i)
            {
                iter2 = zt.head;
                int col;
                for (int j = 1; j <= zt.linii; ++j) {

                    while (iter2 && iter2->poz.linie < j)
                        iter2 = iter2->next;

                    while (iter2 && iter2->poz.linie == j)
                    {
                        for (int k = 1; k <= zt.linii; ++k)
                        {
                            if (iter1->poz.coloana == k && iter2->poz.coloana == k) {
                                if (found)
                                    r = r + iter1->val * iter2->val;
                                else {
                                    r = iter1->val * iter2->val;
                                    found = true;
                                    col = j;
                                }
                            }
                        }
                        iter2 = iter2->next;
                    }
                }
                if (found)
                    rez.adauga(r, i, col);

                iter1 = iter1->next;
            }
        }
        return rez;
    }
    else
    {
        cout << "Matricile nu pot fi inmultite";
        return Matrice(0, 0);
    }
}


template <class Y>
ostream &operator<<(ostream &os, const Matrice<Y> &matrice) {
    if(!matrice.head)
        os << "Matricea este goala";
    else
    {
        auto *iter = matrice.head;

        for (int i = 1; i <= matrice.linii; ++i) {
            for (int j = 1; j <= matrice.coloane; ++j) {
                if(iter->poz.linie == i && iter->poz.coloana == j)
                {
                    os << iter->val << "       ";
                    if(iter->next)
                        iter = iter->next;
                }
                else
                    os << "   " << 0 << "       ";
            }
            os << endl;
        }
    }
    return os;
}

template<class Y>
istream &operator>>(istream &is, Matrice<Y> &matrice) {
    cout << "\nNr. de linii: ";
    is >> matrice.linii;
    cout << "\nNr. de coloane: ";
    is >> matrice.coloane;
    while(true) {
        cout << "\nApasati 1 pentru a introduce un numar complex si 0 pentru a va opri";
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
            matrice.adauga(z, lin, col);
        } else
            break;
    }

    return is;
}

template<class T>
Complex<T> Matrice<T>::determinant() {

    cout << "Eroare: matricea nu este patratica";

    return Complex<T>();
}

