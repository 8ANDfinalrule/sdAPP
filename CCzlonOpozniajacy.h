#ifndef CCZLONOPOZNIAJACY_H
#define CCZLONOPOZNIAJACY_H

#include "head.hpp"
#include "CCzlonPamietajacy.h"

class CCzlonOpozniajacy : public CCzlonPamietajacy{
private:
    int czasOpoznienia;
public:
    CCzlonOpozniajacy(int czas=3):czasOpoznienia(czas),CCzlonPamietajacy(czas){};
    void setCzasOpoznienia(int czas);
    int getCzasOpoznienia();
    void wykonajKrokSymulacji();
};

#endif // CCZLONOPOZNIAJACY_H
