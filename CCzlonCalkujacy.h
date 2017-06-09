#ifndef CCZLONCALKUJACY_H
#define CCZLONCALKUJACY_H

#include "head.hpp"
#include "CCzlonPamietajacy.h"

class CCzlonCalkujacy : public CCzlonPamietajacy{
private:
    int czasCalkowania;
public:
    CCzlonCalkujacy(int ilePamietanych=2, int czas=2)
        : czasCalkowania(czas),CCzlonPamietajacy(ilePamietanych){};
    void setCzasCalkowania(int czas);
    int getCzasCalkowania();
    void wykonajKrokSymulacji();
};

#endif // CCZLONCALKUJACY_H
