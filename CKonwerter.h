#ifndef CKONWERTER_H
#define CKONWERTER_H

#include "head.hpp"
#include "CCzlonCzynny.h"

class CKonwerter : public CCzlonCzynny{
private:
    std::string typSygnaluWyjscia;
public:
    CKonwerter(std::string wejscie="int", std::string wyjscie="double"){
        this->setRodzajSygnaluWejscia(wejscie);
        this->setRodzajSygnaluWyjscia(wyjscie);
    }
    std::string getSygnalWejscia();
    std::string getSygnalWyjscia();
    void setRodzajSygnaluWyjscia(std::string wejscie);
    void setRodzajSygnaluWejscia(std::string wejscie);
    void wykonajKrokSymulacji();
};

#endif // CKONWERTER_H
