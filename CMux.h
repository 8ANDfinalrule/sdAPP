#ifndef CMUX_H
#define CMUX_H

#include "head.hpp"
#include "CWiele.h"

class CMux : public CWiele{
public:
    CMux(int ileIn=2): CWiele(ileIn){
        this->setTypWyjscia("vector");
        std::cout<<"Cczyli dziuala"<<std::endl;
    };
    void wykonajKrokSymulacji();
};

#endif // CMUX_H
