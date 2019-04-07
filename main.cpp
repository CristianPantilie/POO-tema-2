#include <iostream>
#include "Complex.cpp"
#include "Matrice.cpp"
#include "Matrice_patratica.cpp"
#include "Matrice_oarecare.cpp"
#include "MatriceClient.cpp"

using namespace std;

int main() {

    Complex<int> z(4, 3);

//    m.adauga(z, 1, 1);
//
//    Matrice_patratica<int> A(2);
//    Matrice_oarecare<int> B(2, 3);
//
//    A.adauga(z, 1, 1);
//    A.adauga(z, 2, 2);
//    cout << A << endl;
//
//    B.adauga(z, 1, 1);
//    B.adauga(z, 2, 2);
//    B.adauga(z, 2, 3);
//
//    cout << B << endl;
//
//    cout << A * B;

    MatriceClient<int> factory;
    factory.creeaza(2, 2);
    Matrice<int> A = *factory.getMatrice();
    factory.creeaza(2, 3);
    Matrice<int> B = *factory.getMatrice();

    A.adauga(z, 1, 1);
    A.adauga(z, 2, 2);

    B.adauga(z, 1, 1);
    B.adauga(z, 2, 2);
    B.adauga(z, 2, 3);

    cout << A << endl << B << endl << A * B;

//    Complex<double> *s = new Complex<double>(3, 4);
//    delete s;



    return 0;
}