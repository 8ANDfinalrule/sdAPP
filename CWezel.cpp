#include "head.hpp"
#include "CWezel.h"

    std::vector<char> CWezel::getListaDzialan(){
        std::vector<char> zwroc;
        zwroc=wektorDzialan;
        return zwroc;
    };

    void CWezel::setNoweDzialanie(int gdzie, char znak){
        wektorDzialan.at(gdzie)=znak;
    };

    void CWezel::wykonajKrokSymulacji(){
        std::vector<double> wejscie;
        std::vector<double> wynik;
        std::string w;
        w=this->wektorWejsc[0].getSygnal();
        wejscie=this->wartosc->wczytajStringDoWektor(w);
        int rozmiarWektoraWejscia=wejscie.size();
        wynik.resize(rozmiarWektoraWejscia);

        if(wektorDzialan.at(0)=='+'||wektorDzialan.at(0)=='-'){
            for(int i=0;i<rozmiarWektoraWejscia;i++){
                wynik.at(i)=0;
            }
        }
        else{
            for(int i=0;i<rozmiarWektoraWejscia;i++){
                wynik.at(i)=1;
            }
        }

        for(int i=0;i<this->maxIloscWejsc;i++){
            if(this->wektorFlagWejsc[i]==0){
                continue;
            }
            w=this->wektorWejsc[i].getSygnal();
            wejscie=this->wartosc->wczytajStringDoWektor(w);
            wejscie.resize(rozmiarWektoraWejscia,0.0);
            switch (wektorDzialan.at(i)){
            case '+':
                for(int i=0;i<rozmiarWektoraWejscia;i++){
                wynik.at(i)+=wejscie.at(i);
                }
                break;
            case '-':
                for(int i=0;i<rozmiarWektoraWejscia;i++){
                wynik.at(i)-=wejscie.at(i);
                }
                break;
            case '*':
                for(int i=0;i<rozmiarWektoraWejscia;i++){
                wynik.at(i)=wynik.at(i)*wejscie.at(i);
                }
                break;
            case '/':
                for(int i=0;i<rozmiarWektoraWejscia;i++){
                wynik.at(i)=wynik.at(i)/wejscie.at(i);
                }
                break;
            }
        }
        this->wartosc->setWartosc(this->wartosc->wczytajWektorDoString(wynik));
    }
