#ifndef CMUX_H
#define CMUX_H

#include "head.hpp"
#include "CWiele.h"

class CMux : public CWieleWejsc{
public:
    CMux(int ileIn=2): CWieleWejsc(ileIn){
        this->setTypWyjscia("vector");
        std::cout<<"Cczyli dziuala"<<std::endl;
    };
    void wykonajKrokSymulacji();
};

#endif // CMUX_H
