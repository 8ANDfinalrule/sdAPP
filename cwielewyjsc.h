#ifndef CWIELEWYJSC_H
#define CWIELEWYJSC_H

#include "CStala.h"
#include "head.hpp"

class CWieleWyjsc:public virtual CCzlonCzynny
{
protected:
    CStala **wyjsciaPojedyncze;
    int liczbaWyjsc;
    std::vector <double> wyjscia;
public:
    CWieleWyjsc(int ileWyjsc){
        this->liczbaWyjsc=ileWyjsc;
        this->wyjsciaPojedyncze=new CStala*[liczbaWyjsc];
        for(int i=0;i<liczbaWyjsc;i++){
            std::string s=std::to_string(0.0);
            this->wyjsciaPojedyncze[i]=new CStala(s);
        }
    };
    void setLiczbaWyjsc(int liczba);
    int getLiczbaWyjsc();
    void setTypWyjscia(std::string typ){};
    CCzlon *getWskaznikWyjscia(int ktory);
};

#endif // CWIELEWYJSC_H
