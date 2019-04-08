#include <iostream>
#include "Complex.cpp"
#include "Matrice.cpp"
#include "Matrice_patratica.cpp"
#include "Matrice_oarecare.cpp"
#include "MatriceFactory.cpp"

using namespace std;

int main() {

    Complex<int> z(4, 3);
//
    MatriceFactory<int> factory;
    cin >> factory;
    Matrice_oarecare<int> *A = factory.getNewMat();



    cout << A->determinant();


    return 0;
}