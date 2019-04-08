#include <iostream>
#include "Complex.h"

template<class T>
Complex<T>::Complex(T re, T im): re(re), im(im) {}

template<class T>
Complex<T>::Complex(const Complex<T> &z) {
    this->re = z.re;
    this->im = z.im;
}

template<class T>
Complex<T>::~Complex() {

}

template<class T>
void Complex<T>::setRe(T re) {
    Complex::re = re;
}

template<class T>
void Complex<T>::setIm(T im) {
    Complex::im = im;
}

template<class T>
void Complex<T>::operator=(const Complex<T> &z) {
    this->re = z.re;
    this->im = z.im;
}

template<class T>
Complex<T> Complex<T>::operator+(const Complex<T> &z) {
    Complex res(this->re + z.re, this->im + z.im);
    return res;
}


template<class T>
Complex<T> Complex<T>::operator*(const Complex<T> &z) {
    T re = this->re * z.re - this->im * z.im;
    T im = this->re * z.im + this->im * z.re;
    Complex res(re, im);
    return res;
}

template<class T>
Complex<T> Complex<T>::operator/(Complex<T> &z) {
    Complex conj(z.re, -z.im);
    Complex numitor = *this * conj;
    Complex numarator = z * conj;
    Complex res(numitor.re / numarator.re, numitor.im / numarator.re);
    return res;
}

template <class Y>
std::ostream &operator<<(std::ostream &os, const Complex<Y> &z) {
    os << z.re;
    if(z.im > 0) {
        os << "+";
        if(z.im != 1)
            os << z.im;
        os << "i";
    }
    return os;
}

template<class Y>
std::istream &operator>>(std::istream &is, Complex<Y> &z) {
    std::cout << "Partea reala: ";
    is >>  z.re;
    std::cout << "Partea imaginara: ";
    is >> z.im;
    return is;
}

template<class T>
T Complex<T>::getRe() {
    return this->re;
}

template<class T>
T Complex<T>::getIm() {
    return this->im;
}
