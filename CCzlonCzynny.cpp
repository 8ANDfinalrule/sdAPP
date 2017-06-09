#include "head.hpp"
#include "CCzlonCzynny.h"
#include "CCzlon.h"
#include <iostream>
#include <CReversedMux.h>
#include <cstockend.h>

    int CCzlonCzynny::getIndeksCzlonu(){
        return indeksCzlonu;
    };


    void CCzlonCzynny::dodajPolaczenie(ICCzlon *wejscie,ICCzlon *wyjscie,int nrWejscia,int nrWyjscia){

        if(wektorFlagWejsc[nrWejscia-1]==1){
            std::cout<<"DO TEGO WEJSCIA JEST PODLACZONE INNE POLACZENIE"<<std::endl;
            return;
        }
        else{

            if(this->sprawdzZgodnoscTypowPolaczenia((CCzlon*)wejscie,(CCzlonCzynny*) wyjscie)) {
                //std::cout<<"ZEPSUTE POLACZENIE"<<std::endl;
                wektorFlagWejsc[nrWejscia-1]=1;
                bool czyWieleWyjsc=0;
                CReversedMux *n=dynamic_cast<CReversedMux*>(wejscie);
                CStock *s=dynamic_cast<CStock*>(wejscie);
                if(n!=NULL||s!=NULL){
                   czyWieleWyjsc=1;
                }else{
                    czyWieleWyjsc=0;
                }
                //std::cout<<"czywielewyjsc: "<<czyWieleWyjsc<<std::endl;
                //std::cout<<"ZEPSUTE POLACZENIE3"<<std::endl;
                wektorWejsc[nrWejscia-1]=CPolaczenie((CCzlon*)wejscie,(CCzlon*)wyjscie,czyWieleWyjsc,nrWyjscia);
                //std::cout<<"ZEPSUTE POLACZENIE4"<<std::endl;
            }
            else{
                std::cout<<"NIEZGODNOSC TYPOW POLACZENIA"<<std::endl;
            }
        }
    };

    bool CCzlonCzynny::sprawdzZgodnoscTypowPolaczenia(CCzlon *poczatek, CCzlon *koniec){
        CCzlonCzynny *c=dynamic_cast<CCzlonCzynny*>(koniec);

        if(poczatek->getTypWyjscia()==c->getTypPolaczenia()){
            return true;
        }
        else{
            if(koniec->getTypWyjscia()=="double"){
                CReversedMux *czlon1=dynamic_cast<CReversedMux*>(poczatek);
                if(czlon1!=NULL){
                    return true;
                }
            }
            return false;
        }
    }


    void CCzlonCzynny::setTypWyjscia(std::string typ){
        typWyjscia=typ;
        if(typWyjscia=="double"){
            delete this->wartosc;
            this->wartosc=new CDouble;
            //std::cout<<"KONWERSJAdouble"<<std::endl;
        }
        else if(typWyjscia=="int"){
            delete this->wartosc;
            this->wartosc=new CInt;
            //std::cout<<"KONWERSJAINT"<<std::endl;
        }
        else if(typWyjscia=="bool"){
            delete this->wartosc;
            this->wartosc=new CBool;
            std::cout<<"KONWERSJABOOL"<<std::endl;
        }
        else if(typWyjscia=="vector"){
            delete this->wartosc;
            std::cout<<"KONWERSJAVECTOR"<<std::endl;
            this->wartosc= new CVector;
            std::cout<<"KONWERSJAVECTOR2"<<std::endl;
            CVector *v=dynamic_cast<CVector*>(this->wartosc);
            if(v!=NULL){

                std::cout<<"KONWERSJAVECTORDZIALA:"<<this->wartosc->getWartosc()<<std::endl;
            }
        }
    }

    void CCzlonCzynny::usunPolaczenie(int zKtoregoWejscia){
        wektorFlagWejsc[zKtoregoWejscia-1]=0;
        wektorWejsc[zKtoregoWejscia-1]=NULL;
    };

    void CCzlonCzynny::setTypPolaczenia(int ktory, std::string typ){
        wektorTypowWejsc[ktory-1]=typ;
    };

    std::string CCzlonCzynny::getTypPolaczenia(){
        return wektorTypowWejsc[0];
    };

    CCzlonCzynny::~CCzlonCzynny(){
        delete this->wektorFlagWejsc;
        delete this->wektorWejsc;
        delete this->wektorTypowWejsc;
        indeksCzlonu--;
    };

    void CCzlonCzynny::wypiszSygnalZWejscia(){
        this->wektorWejsc[0].wypiszSygnal();
    }

    int CCzlonCzynny::getLiczbaWejsc()
    {
        return this->maxIloscWejsc;
    }

    int CCzlonCzynny::getLiczbaWyjsc()
    {
        return 1;
    }

    std::string CCzlonCzynny::getWartoscCzlonu()
    {
        //std::cout<<"BEZPOSREDNIO WARTOSC"<<std::endl;
        std::string s;
        //std::cout<<"BEZPOSREDNIO WARTOSCgggg"<<std::endl;
       // CVector *v=dynamic_cast<CVector*>(this->wartosc);
        //if(v==NULL){std::cout<<"SLABO"<<std::endl;s="0.0";}
        //else{
        //    //std::cout<<"BEZPOSREDNIO WARTOSC2.3:"<<std::endl;
        s=this->wartosc->getWartosc();
        //std::cout<<"BEZPOSREDNIO WARTOSC2:"<<s<<std::endl;
        //}
        return this->wartosc->getWartosc();

    }

    std::string CCzlonCzynny::getStringFromWektorCzlon(std::vector<double> w)
    {
        std::string s;
        s=this->wartosc->wczytajWektorDoString(w);
        return s;
    }
