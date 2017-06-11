#ifndef CREVERSEDMUX_H
#define CREVERSEDMUX_H

#include "head.hpp"
#include "CCzlonCzynny.h"
#include "CStala.h"

class CReversedMux : public CCzlonCzynny{
private:
    CStala **wyjsciaPojedyncze;
    std::vector <double> wyjscia;
public:
    CReversedMux(int IleOut=2): CCzlonCzynny(){
        this->liczbaWyjsc=IleOut;

        std::cout<<"REVERSED MUX"<<std::endl;
        for(int i=0;i<this->maxIloscWejsc;i++){
            this->setTypPolaczenia(i+1,"vector");
        }
        std::cout<<"REVERSED MUX2"<<std::endl;
        wyjsciaPojedyncze=new CStala*[liczbaWyjsc];
        for(int i=0;i<liczbaWyjsc;i++){
            std::string s=std::to_string(0.0);
            wyjsciaPojedyncze[i]=new CStala(s);
        }
        std::cout<<"REVERSED MUX3"<<std::endl;
    };

    void setLiczbaWyjsc(int liczba);
    int getLiczbaWyjsc();
    void wykonajKrokSymulacji();
    void setTypWyjscia(std::string typ){};
    CCzlon *getWskaznikWyjscia(int ktory);
};

#endif // CREVERSEDMUX_H
