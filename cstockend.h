#ifndef CSTOCKEND_H
#define CSTOCKEND_H

#include "head.hpp"
#include "CWiele.h"
#include "CStala.h"

class CStock : public CWiele{
private:
    double ileNaWyjscie;
    CStala **wyjsciaPojedyncze;
    std::vector <double> wyjscia;
public:
    CStock(int ileIn=2, int IleOut=2, std::string wartosc="0"):CWiele(ileIn){
        //std::cout<<"konstruktor CStock"<<std::endl;
        this->liczbaWyjsc=IleOut;
        wyjsciaPojedyncze=new CStala*[liczbaWyjsc];
        for(int i=0;i<liczbaWyjsc;i++){
            std::string w;
            w.append(std::to_string(0.0));
            wyjsciaPojedyncze[i]=new CStala(w);
            wyjsciaPojedyncze[i]->setTypWyjscia("double");

        }
        ileNaWyjscie=0.01;
        ////////////////////////////
        //std::cout<<"konstruktor CStock2"<<std::endl;
        this->wartosc->setWartosc(wartosc);
        //std::cout<<"konstruktor CStock3"<<std::endl;
    };
    void wykonajKrokSymulacji();
    void setLiczbaWyjsc(int liczba);
    int getLiczbaWyjsc();
    CCzlon *getWskaznikWyjscia(int ktory);
    void setIleNaWyjscie(double ile);
    double getIleNaWyjscie();
};

#endif // CSTOCKEND_H
