#ifndef CPOLACZENIE_H
#define CPOLACZENIE_H

#include "head.hpp"
#include "CCzlon.h"

class CPolaczenie{
private:
    CCzlon *wskaznikPoczatku;
    CCzlon *wskaznikKonca;
    int numerWyjsciaPoczatku;
    std::string typWejscia;
    void zapiszTypWejscia(std::string typ);
    void dodajPoczatek(CCzlon *poczatek, bool czyWieleWyjsc=0);
    void dodajKoniec(CCzlon *koniec);
public:
    CPolaczenie(CCzlon *poczatek=NULL, CCzlon *koniec=NULL,bool czyWieleWyjsc=0, int ktory=1);
    CCzlon *getWskaznikPoczatku();
    std::string getSygnal();
    void wypiszSygnal();
};

#endif // CPOLACZENIE_H
