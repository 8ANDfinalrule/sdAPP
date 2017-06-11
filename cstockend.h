#ifndef CSTOCKEND_H
#define CSTOCKEND_H

#include "head.hpp"
#include "CWiele.h"
#include "CStala.h"
#include "cwielewyjsc.h"

class CStock : public CWieleWejsc,public CWieleWyjsc{
private:
    double ileNaWyjscie;
public:
    CStock(int ileIn=2, int IleOut=2, std::string wartosc="0"):CWieleWejsc(ileIn),CWieleWyjsc(IleOut){
        for(int i=0;i<liczbaWyjsc;i++){
            std::string w;
            w.append(std::to_string(0.0));
            wyjsciaPojedyncze[i]->setTypWyjscia("double");
        }
        ileNaWyjscie=0.01;
        ////////////////////////////
        //std::cout<<"konstruktor CStock2"<<std::endl;
        this->wartosc->setWartosc(wartosc);
        //std::cout<<"konstruktor CStock3"<<std::endl;
    };
    void wykonajKrokSymulacji();
    void setIleNaWyjscie(double ile);
    double getIleNaWyjscie();
};

#endif // CSTOCKEND_H
