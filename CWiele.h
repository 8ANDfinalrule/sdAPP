#ifndef CWIELE_H
#define CWIELE_H

#include "head.hpp"
#include "CCzlonCzynny.h"


class CWieleWejsc : public virtual CCzlonCzynny{
protected:

    bool sprawdzZgodnoscTypowPolaczenia(CCzlon *poczatek, CCzlonCzynny *koniec, int numerWejscia, int numerWyjscia=1);
public:
    CWieleWejsc(int ilosc=2);
    void setIloscWejscCzlonu(int ilosc);
    int getIloscWejscCzlonu();
    //void dodajPolaczenie(CCzlon *poczatek, CCzlon *koniec,int numerWejscia,bool czyWieleWyjsc=0, int numerWyjscia=1);
    void usunPolaczenie(int numerPolaczenia);
    std::string getTypPolaczenia(int numerPolaczenia);
};

#endif // CWIELE_H
