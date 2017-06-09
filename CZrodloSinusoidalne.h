#ifndef CZRODLOSINUSOIDALNE_H
#define CZRODLOSINUSOIDALNE_H
#include "CCzlonCzynny.h"
#include <cmath>

class CZrodloSinusoidalne:public CCzlonCzynny{
private:
    double dlugoscKroku;
    double aktualnyArgument;
public:
    CZrodloSinusoidalne(double dlugoscK=1):dlugoscKroku(dlugoscK){this->aktualnyArgument=0;};
    void wykonajKrokSymulacji();
};

#endif // CZRODLOSINUSOIDALNE_H
