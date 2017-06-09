#ifndef CCZLONPROPORCJONALNY_H
#define CCZLONPROPORCJONALNY_H

#include "head.hpp"
#include "CCzlonCzynny.h"

class CCzlonProporcjonalny : public CCzlonCzynny{
private:
    double wspProp;
public:
    CCzlonProporcjonalny(double wsp=5):wspProp(wsp){};
    void setWspProp(double wsp);
    double getWspProp();
    void wykonajKrokSymulacji();
};

#endif // CCZLONPROPORCJONALNY_H
