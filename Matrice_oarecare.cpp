
#include "Matrice_oarecare.h"

#include <iostream>
using namespace std;

//constructor
template <typename T>
Matrice_oarecare<T>::Matrice_oarecare(unsigned int lin, unsigned int col) : Matrice<T>(lin, col) {}


//copy constructor
template<typename T>
Matrice_oarecare<T>::Matrice_oarecare(const Matrice_oarecare<T> &z) : Matrice<T>(z) {
    auto *iter1 = z.head;
    while(iter1)
    {
        this->adauga(iter1->val, iter1->poz.linie, iter1->poz.coloana);
        iter1 = iter1->next;
    }
}

//destructor
template<typename T>
Matrice_oarecare<T>::~Matrice_oarecare() {
    auto *iter = this->head;

    while(iter)
    {
        auto *temp = iter;
        iter = iter->next;
        delete temp;
    }
    this->head = NULL;
}

template<typename T>
void Matrice_oarecare<T>::operator=(const Matrice_oarecare<T> &z){

    this->linii = z.linii;
    this->coloane = z.coloane;
    this->head = NULL;

    auto *iter1 = z.head;
    while(iter1)
    {
        this->adauga(iter1->val, iter1->poz.linie, iter1->poz.coloana);
        iter1 = iter1->next;
    }
}


template <typename T>
Matrice_oarecare<T> Matrice_oarecare<T>::transpusa() {

    Matrice_oarecare<T> rez(this->coloane, this->linii);
    auto *iter = this->head;

    while(iter)
    {
        rez.adauga(iter->val, iter->poz.coloana, iter->poz.linie);
        iter = iter->next;
    }

    return rez;
}

template <typename T>
void Matrice_oarecare<T>::adauga(Complex<T> z, unsigned int linie, unsigned int coloana)
{
    auto *nou = new struct nod<T>;//new struct nod;
    nou->val =  z;
    nou->poz.linie = linie;
    nou->poz.coloana = coloana;
    nou->next = nullptr;

    if(!this->head || Matrice<T>::comparaPoz(this->head->poz, nou->poz) >= 0)
    {
        nou->next = this->head;
        this->head = nou;
    }
    else
    {
        auto *iter = this->head;
        while(iter->next && Matrice<T>::comparaPoz(iter->next->poz, nou->poz) < 0)
            iter = iter->next;

        nou->next = iter->next;
        iter->next = nou;
    }
}

template <typename T>
Matrice_oarecare<T> Matrice_oarecare<T>::operator+(const Matrice_oarecare<T> &z) {
    if(this->linii == z.linii && this->coloane == z.coloane)
    {
        Matrice_oarecare<T> rez(z.linii, z.coloane);

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
        return Matrice_oarecare<T>(0, 0);
    }
}


template <typename T>
Matrice_oarecare<T> Matrice_oarecare<T>::operator*(Matrice_oarecare<T> &z) {
    if(this->coloane == z.linii)
    {
        Matrice_oarecare<T> rez(this->linii, z.coloane);
        Matrice_oarecare<T> zt = z.transpusa();
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
        return Matrice_oarecare<T>(0, 0);
    }
}

template <typename Y>
ostream &operator<<(ostream &os, const Matrice_oarecare<Y> &matrice) {
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

template<typename Y>
istream &operator>>(istream &is, Matrice_oarecare<Y> &matrice) {
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

template<typename T>
Complex<T> Matrice_oarecare<T>::determinant() {
    cout << "Matricea nu este patratica, nu se poate calcula determinantul";
    return Complex<T>();
}

//}


template<typename T>
bool Matrice_oarecare<T>::esteDiagonala() {
    auto *iter = this->head;
    while(iter)
    {
        if(iter->poz.linie != iter->poz.coloana)
            return false;
        iter = iter->next;
    }
    return true;
}





