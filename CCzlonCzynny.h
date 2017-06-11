#ifndef CCZLONCZYNNY_H
#define CCZLONCZYNNY_H

#include "head.hpp"
#include "CCzlon.h"
#include "CPolaczenie.h"
#include "CZmienne.h"

class CCzlonCzynny : public CCzlon{
protected:
    static int indeksCzlonu;
    int liczbaWyjsc;
    int maxIloscWejsc=1;
    CPolaczenie *wektorWejsc;
    std::string *wektorTypowWejsc;
    bool *wektorFlagWejsc;
    virtual bool sprawdzZgodnoscTypowPolaczenia(CCzlon *poczatek, CCzlon *koniec);
public:
    CCzlonCzynny(std::string typWejscia="double",std::string typWyjscia="double"):CCzlon(typWyjscia){
        //std::cout<<"CCZLON CZYNNY KONS"<<std::endl;
        this->indeksCzlonu=0;
        this->liczbaWyjsc=1;
        wektorTypowWejsc=new std::string[maxIloscWejsc];
        for(int i=0;i<maxIloscWejsc;i++){
            wektorTypowWejsc[0]=typWejscia;
        }
        if(this->getTypWyjscia()=="double"){
            //std::cout<<"CZLON DOUBLE "<<std::endl;
            this->wartosc=new CDouble;
        }else if(this->getTypWyjscia()=="int"){
            this->wartosc=new CInt;
        }
        else if(this->getTypWyjscia()=="bool"){
                    this->wartosc=new CBool;
                }
        else if(this->getTypWyjscia()=="vector"){
            //std::cout<<"CZLON VECTOR "<<std::endl;
            this->wartosc=new CVector;
                }
        wektorWejsc=new CPolaczenie[maxIloscWejsc];
        wektorFlagWejsc=new bool[maxIloscWejsc];
        wektorFlagWejsc[0]=0;
        indeksCzlonu++;
    };
    static int getIndeksCzlonu();
    virtual void dodajPolaczenie(ICCzlon *wejscie, ICCzlon *wyjscie, int nrWejscia=1, int nrWyjscia=1);
    void usunPolaczenie(int zKtoregoWejscia);
    void setTypPolaczenia(int ktory=1,std::string typ="double");
    std::string getTypPolaczenia();
    void wypiszSygnalZWejscia();
    int getLiczbaWejsc();
    virtual int getLiczbaWyjsc();
    virtual void setTypWyjscia(std::string typ);
    virtual void wykonajKrokSymulacji(){};
    std::string getWartoscCzlonu();
    std::string getStringFromWektorCzlon(std::vector <double> w);
    ~CCzlonCzynny();
};

#endif // CCZLONCZYNNY_H
