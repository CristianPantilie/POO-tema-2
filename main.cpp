#include <iostream>
#include <fstream>
#include "Complex.cpp"
#include "Matrice.cpp"
#include "Matrice_patratica.cpp"
#include "Matrice_oarecare.cpp"
#include "MatriceFactory.cpp"

using namespace std;



int main() {

    Complex<int> z(4, 3);

    MatriceFactory<int> factory;
    cin >> factory;
    Matrice_oarecare<int> *A = factory.getNewMat();

    cout << *A;
    cout << "Determinant : " << A->determinant() << "\n\n";




    ofstream f;
    ifstream g;
    f.open("writehere.txt");
    g.open("readhere.txt");

    unsigned int linii, coloane;
    g >> linii >> coloane;
    Matrice_oarecare<int> B(linii, coloane);
    int k = 0, nr;
    g >> nr;
    while(k < nr){
        double re, im;
        unsigned int linie, coloana;
        g >> re >> im;
        g >> linie >> coloana;
        Complex<int> z(re, im);
        B.adauga(z, linie, coloana);
        k++;
    }

    Matrice_oarecare<int> C(4, 1);
    Complex<int> z5(6, 2);
    C.adauga(z5, 1, 1);
    Complex<int> z6(-2, 3);
    C.adauga(z6, 4, 1);

    f << B << "\n*\n" << C << "\n=\n" << B * C << "\n\n";
    f << B << "\n+\n" << C << "\n=\n" << B + C << "\n\n";


    f.close();
    g.close();

    return 0;
}