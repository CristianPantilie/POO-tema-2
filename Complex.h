#ifndef POO_TEMA_2_COMPLEX_H
#define POO_TEMA_2_COMPLEX_H

template <class T>
class Complex {
private:
    T re, im;
public:
    Complex(T re, T im);

    virtual ~Complex();
};


#endif //POO_TEMA_2_COMPLEX_H
