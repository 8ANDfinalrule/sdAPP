#ifndef CCZLONROZNICZKUJACY_H
#define CCZLONROZNICZKUJACY_H

#include "head.hpp"
#include "CCzlonPamietajacy.h"


class CCzlonRozniczkujacy : public CCzlonPamietajacy{
private:
    int czasRozniczkowania;
public:
    CCzlonRozniczkujacy(int ilePamietanych=1, int czas=1)
        : czasRozniczkowania(czas),CCzlonPamietajacy(ilePamietanych){};
    void setCzasRozniczkowania(int czas);
    int getCzasRozniczkowania();
    void wykonajKrokSymulacji();
};

#endif // CCZLONROZNICZKUJACY_H
