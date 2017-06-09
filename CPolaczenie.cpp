
#include "head.hpp"
#include "CCzlon.h"
#include "CPolaczenie.h"
#include "CStala.h"


    void CPolaczenie::dodajPoczatek(CCzlon *poczatek, bool czyWieleWyjsc){
        if(czyWieleWyjsc){
            CCzlonCzynny *nowy=new CCzlonCzynny;
            std::cout<<"zwracam "<<numerWyjsciaPoczatku<<" wskaznik na polaczenie"<<std::endl;
            nowy=(CCzlonCzynny*)poczatek->getWskaznikWyjscia(numerWyjsciaPoczatku);
            this->wskaznikPoczatku=nowy;
        }
        else{
        wskaznikPoczatku=poczatek;
        }
    };

    void CPolaczenie::dodajKoniec(CCzlon *koniec){
        wskaznikKonca=koniec;
    };

    void CPolaczenie::zapiszTypWejscia(std::string typ){
        typWejscia=typ;
    };

    CPolaczenie::CPolaczenie(CCzlon *poczatek, CCzlon *koniec,bool czyWieleWyjsc, int ktory){
        numerWyjsciaPoczatku=ktory-1;
        //std::cout<<"TWORZENIE POLACENIA"<<std::endl;
        dodajPoczatek(poczatek,czyWieleWyjsc);
        dodajKoniec(koniec);
        if(poczatek==NULL){
            zapiszTypWejscia("double");
        }else{
        zapiszTypWejscia(this->wskaznikPoczatku->getTypWyjscia());
        }
        //std::cout<<"TWORZENIE POLACENIA2"<<std::endl;
    };

    CCzlon *CPolaczenie::getWskaznikPoczatku(){
        CCzlon *wskaznik=wskaznikPoczatku;
        std::cout<<"getwskaznik"<<std::endl;
        if(wskaznikPoczatku==NULL){
            wskaznik->setTypWyjscia("NULL");
            return wskaznik;
        }
        return wskaznik;
    };

    std::string CPolaczenie::getSygnal(){
        std::string s;
        //std::cout<<"BIORESYGNAL: "<<std::endl;
        CCzlonCzynny *c=(CCzlonCzynny*)this->wskaznikPoczatku;
        //std::cout<<"BIORESYGNAL: "<<std::endl;
        s=c->getWartoscCzlonu();
        std::cout<<"BIORESYGNAL: "<<s<<std::endl;

        return s;
    }

    void CPolaczenie::wypiszSygnal()
    {
        std::cout<<this->getSygnal()<<std::endl;
    };

