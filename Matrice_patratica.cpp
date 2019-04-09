
#include "Matrice_patratica.h"
#include <iostream>
using namespace std;

template <typename T>
Matrice_patratica<T>::Matrice_patratica(unsigned int dim) : Matrice_oarecare<T>(dim, dim) {}

template <typename T>
Complex<T> Matrice_patratica<T>::determinant()
{
    if(this->linii == this->coloane)
    {
        Complex<T> mat[this->linii][this->coloane];
        auto *iter = this->head;
        for (int i = 0; i < this->linii ; ++i) {
            for (int j = 0; j < this->coloane; ++j) {
                if(iter && iter->poz.linie == i + 1 && iter->poz.coloana == j + 1)
                {
                    mat[i][j] = iter->val;
                    iter = iter->next;
                }
                else
                    mat[i][j] = 0;
            }
        }

        Complex<T> *b[this->linii];
        for (int i = 0; i < this->linii ; ++i) {
            b[i] = mat[i];
        }

        return det(b, this->linii);

    }
    else
    {
        cout << "Matricea nu este patratica";
        return Complex<T>();
    }
}

template <typename T>
void Matrice_patratica<T>::cofactor(Complex<T> **mat, Complex<T> **cof, int i, int j, int n) {
    int l = 0, k = 0;
    for (int lin = 0; lin < n; ++lin) {
        for (int col = 0; col < n; ++col) {
            if(lin != i && col != j)
            {
                cof[l][k++] = mat[lin][col];
                if(k == n - 1)
                {
                    k = 0;
                    l++;
                }
            }
        }
    }
}

template <typename T>
Complex<T> Matrice_patratica<T>::det(Complex<T> **mat, int n) {

    Complex<T> D;

    if(n == 2) {
        Complex<T> c1 = mat[0][0] * mat[1][1];
        Complex<T> c2 = mat[0][1] * mat[1][0];
        return c1 + Complex<T>(-1) * c2;
    }

    Complex<T> **cof = new Complex<T> *[n];
    for (int i = 0; i < n; ++i) {
        cof[i] = new Complex<T>[n];
    }
    Complex<T> semn(1);

    for (int i = 0; i < n; ++i) {
        cofactor(mat, cof, 0, i, n);
        D =  D + semn * mat[0][i] * det(cof, n - 1);
        semn.setRe(-1);
    }

    return D;
}

template <typename T>
void Matrice_patratica<T>::adjuncta(Complex<T> **mat, Complex<T> **adj, int n) {

    if(n == 1){
        adj[0][0] = 1;
        return;
    }

    Complex<T> semn(1);
    Complex<T> **temp = new Complex<T>*[n];
    for (int i = 0; i < n; ++i) {
        temp[i] = new Complex<T>[n];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cofactor(mat, temp, i, j, n);

            if((i + j) % 2 == 0) {
                semn = 1;
            }
            else {
                semn = -1;
            }

            adj[j][i] = semn * det(temp, n - 1);
        }
    }
}

template <typename T>
Matrice_patratica<T> Matrice_patratica<T>::inversa() {

    Complex<T> det = this->determinant();
    if(det.getIm() == 0 && det.getRe() == 0)
    {
        cout << "Nu se poate calcula inversa";
        return Matrice_patratica<T>(0);
    }

    Complex<T> **mat = new Complex<T>*[this->linii];
    for (int i = 0; i < this->linii; ++i) {
        mat[i] = new Complex<T>[this->linii];
    }
    auto *iter = this->head;
    for (int i = 0; i < this->linii ; ++i) {
        for (int j = 0; j < this->coloane; ++j) {
            if(iter && iter->poz.linie == i + 1 && iter->poz.coloana == j + 1)
            {
                mat[i][j] = iter->val;
                iter = iter->next;
            }
            else
                mat[i][j] = 0;
        }
    }

    Complex<T> inversa[this->linii][this->linii];
    Complex<T> **adj = new Complex<T> *[this->linii];
    for (int i = 0; i < this->linii; ++i) {
        adj[i] = new Complex<T>[this->linii];
    }

    adjuncta(mat, adj, this->linii);

    for (int i = 0; i < this->linii; ++i) {
        for (int j = 0; j < this->linii; ++j) {
            inversa[i][j] = adj[i][j] / det;
        }
    }



    Matrice_patratica<T> inv(this->linii);

    for (int i = 0; i < this->linii; ++i) {
        for (int j = 0; j < this->linii; ++j) {
            inv.adauga(inversa[i][j], i + 1, j + 1);
        }
    }

    return inv;
}

template <typename Y>
ostream &operator<<(ostream &os, Matrice_patratica<Y> &patratica)
{
    if(!patratica.head)
        os << "Matricea este goala";
    else
    {
        auto *iter = patratica.head;

        for (int i = 1; i <= patratica.linii; ++i) {
            for (int j = 1; j <= patratica.coloane; ++j) {
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
    os << "\nDeterminantul: " << patratica.determinant();

    return os;
}
