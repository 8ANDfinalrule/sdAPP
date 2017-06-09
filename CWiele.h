#ifndef CWIELE_H
#define CWIELE_H

#include "head.hpp"
#include "CCzlonCzynny.h"


class CWiele : public CCzlonCzynny{
protected:

    bool sprawdzZgodnoscTypowPolaczenia(CCzlon *poczatek, CCzlonCzynny *koniec, int numerWejscia, int numerWyjscia=1);
public:
    CWiele(int ilosc=2);
    void setIloscWejscCzlonu(int ilosc);
    int getIloscWejscCzlonu();
    //void dodajPolaczenie(CCzlon *poczatek, CCzlon *koniec,int numerWejscia,bool czyWieleWyjsc=0, int numerWyjscia=1);
    void usunPolaczenie(int numerPolaczenia);
    std::string getTypPolaczenia(int numerPolaczenia);
    int getLiczbaWyjsc();
};

#endif // CWIELE_H
