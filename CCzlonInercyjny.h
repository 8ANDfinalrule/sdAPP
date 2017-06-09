#ifndef CCZLONINERCYJNY_H
#define CCZLONINERCYJNY_H

#include "head.hpp"
#include "CCzlonPamietajacy.h"

class CCzlonInercyjny : public CCzlonPamietajacy{
private:
    int stalaInercji;
public:
    CCzlonInercyjny(int ilePamietanych=1, int stala=1)
        : stalaInercji(stala),CCzlonPamietajacy(ilePamietanych){};
    void setStalaInercji(int stala);
    int getStalaInercji();
    void wykonajKrokSymulacji();
};

#endif // CCZLONINERCYJNY_H
