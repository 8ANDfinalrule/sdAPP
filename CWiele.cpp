#include "CWiele.h"
#include "head.hpp"

    CWiele::CWiele(int ilosc){
        std::cout<<"pro"<<std::endl;
        maxIloscWejsc=ilosc;
        std::cout<<"KONSTRUKTOR cWIELE"<<std::endl;
        wektorTypowWejsc=new std::string[maxIloscWejsc];
        wektorWejsc=new CPolaczenie[maxIloscWejsc];
        wektorFlagWejsc=new bool[maxIloscWejsc];

        for (int i=0;i<maxIloscWejsc;i++){
            wektorFlagWejsc[i]=0;
            setTypPolaczenia(i+1,"double");
        }
        std::cout<<"KONSTRUKTOR cWIELE2"<<std::endl;
        indeksCzlonu++;

    };

    void CWiele::setIloscWejscCzlonu(int ilosc){
        maxIloscWejsc=ilosc;
        wektorTypowWejsc=new std::string[maxIloscWejsc];
        wektorWejsc=new CPolaczenie[maxIloscWejsc];
        wektorFlagWejsc=new bool[maxIloscWejsc];
        for (int i=0;i<maxIloscWejsc;i++){
            wektorFlagWejsc[i]=0;
        }
    };
    int CWiele::getIloscWejscCzlonu(){
        return maxIloscWejsc;
    };

    /*void CWiele::dodajPolaczenie(CCzlon *poczatek, CCzlon *koniec,int numerWejscia,bool czyWieleWyjsc, int numerWyjscia){
        if(wektorFlagWejsc[numerWejscia-1]==1){
            std::cout<<"DO TEGO WEJSCIA JEST PODLACZONE INNE POLACZENIE"<<std::endl;
            return;
        }
        else{
            if(wektorTypowWejsc[numerWejscia-1]==poczatek->getTypWyjscia()){
                std::cout<<"DODAWANIE1"<<std::endl;
                wektorFlagWejsc[numerWejscia-1]=1;
                std::cout<<"DODAWANIE2"<<std::endl;
                wektorWejsc[numerWejscia-1]=CPolaczenie(poczatek,koniec,czyWieleWyjsc,numerWyjscia);
                std::cout<<"DODAWANIE3"<<std::endl;
            }
            else{
                std::cout<<"TYPY: "<<poczatek->getTypWyjscia()<<','<<this->wektorTypowWejsc[numerWejscia-1]<<std::endl;
                std::cout<<"NIEZGODNOSC TYPOW POLACZENIA"<<std::endl;
            }
        }
    };*/
    void CWiele::usunPolaczenie(int numerPolaczenia){
        wektorFlagWejsc[numerPolaczenia-1]=0;
    };

    std::string CWiele::getTypPolaczenia(int numerPolaczenia){
        return wektorTypowWejsc[numerPolaczenia];
    }

    int CWiele::getLiczbaWyjsc()
    {
        return this->liczbaWyjsc;
    }
