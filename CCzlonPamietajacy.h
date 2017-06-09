#ifndef CCZLONPAMIETAJACY_H
#define CCZLONPAMIETAJACY_H

#include "head.hpp"
#include "CCzlonCzynny.h"
#include <list>


class CCzlonPamietajacy : public CCzlonCzynny, ICPamietajacy{
protected:
    std::list <std::vector<double> > listaPamietanych;
public:
    CCzlonPamietajacy(int ile=1);
    void zapiszWartoscWejscia();
};

#endif // CCZLONPAMIETAJACY_H
