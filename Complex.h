#ifndef POO_TEMA_2_COMPLEX_H
#define POO_TEMA_2_COMPLEX_H

#include <ostream>

template <class T>
class Complex {
private:
    T re, im;
public:
    Complex(T re = 0, T im = 0);
    Complex(const Complex<T> &z);
    virtual ~Complex();

    void setRe(T re);
    void setIm(T im);
    T getRe();
    T getIm();

    void operator=(const Complex<T> &z);
    Complex<T> operator+(const Complex<T> &z);
    Complex<T> operator*(const Complex<T> &z);
    Complex<T> operator/(Complex<T> &z);
    template<class Y>
    friend std::ostream &operator<<(std::ostream &os, const Complex<Y> &z);
    template<class Y>
    friend std::istream &operator>>(std::istream &is, Complex<Y> &z);

};


#endif //POO_TEMA_2_COMPLEX_H
