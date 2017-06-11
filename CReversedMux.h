#ifndef CREVERSEDMUX_H
#define CREVERSEDMUX_H

#include "head.hpp"
#include "CCzlonCzynny.h"
#include "CStala.h"
#include "cwielewyjsc.h"

class CReversedMux : public CWieleWyjsc{
private:

public:
    CReversedMux(int IleOut=2): CWieleWyjsc(IleOut){
        std::cout<<"REVERSED MUX"<<std::endl;
        for(int i=0;i<this->maxIloscWejsc;i++){
            this->setTypPolaczenia(i+1,"vector");
        }
        std::cout<<"REVERSED MUX2"<<std::endl;

    };

    void wykonajKrokSymulacji();

    void setTypWyjscia(std::string typ){};

};

#endif // CREVERSEDMUX_H
