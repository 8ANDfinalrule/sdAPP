#ifndef CWEZEL_H
#define CWEZEL_H

#include "head.hpp"
#include "CWiele.h"

class CWezel: public CWieleWejsc{
private:
    std::vector <char> wektorDzialan;
public:
    CWezel(int ileIn=2): CWieleWejsc(ileIn){
        wektorDzialan.resize(maxIloscWejsc);
            for(int i=0;i<maxIloscWejsc;i++){
                wektorDzialan.at(i)='+';
            };
    };
    CWezel(int ileIn=2, char dzialania='+'):CWieleWejsc(ileIn){
        wektorDzialan.resize(maxIloscWejsc);
        for(int i=0;i<maxIloscWejsc;i++){
            wektorDzialan.at(i)=dzialania;
        };
    };
    void setWektorDzialan(char *znaki);
    std::vector<char> getListaDzialan();
    void setNoweDzialanie(int gdzie, char znak);
    void wykonajKrokSymulacji();
};

#endif // CWEZEL_H
