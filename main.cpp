#include <iostream>
#include "Complex.cpp"
#include "Matrice.cpp"
#include "Matrice_patratica.cpp"
#include "Matrice_oarecare.cpp"

using namespace std;

int main() {

    Complex<int> z(4, 3);
    Complex<double> d;

    Matrice<double> m(2, 2);

//    m.adauga(z, 1, 1);

    Matrice_patratica<int> A(2);
    Matrice_oarecare<int> B(2, 3);

    A.adauga(z, 1, 1);
    A.adauga(z, 2, 2);
    cout << A << endl;

    B.adauga(z, 1, 1);
    B.adauga(z, 2, 2);
    B.adauga(z, 2, 3);

    cout << B << endl;

    cout << A + B;


//    Complex<double> *s = new Complex<double>(3, 4);
//    delete s;



    return 0;
}