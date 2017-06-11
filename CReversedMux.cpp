#include "head.hpp"
#include "CReversedMux.h"



    void CReversedMux::wykonajKrokSymulacji(){

        this->setTypWyjscia("vector");
        if(this->wektorFlagWejsc[0]==0){
            return;
        }
        std::string s,zapisz;
        s=this->wektorWejsc[0].getSygnal();
        std::cout<<s<<"  - SYGNAL PRZYSZEDL Z WEJSCIA"<<std::endl;
        wyjscia=this->wartosc->wczytajStringDoWektor(s);
        wyjscia.resize(this->liczbaWyjsc,0);
        std::cout<<"LICZBA WYJSC R MUX = "<<this->liczbaWyjsc<<std::endl;
        for(int i=0;i<wyjscia.size();i++){
            std::cout<<wyjscia.at(i)<<"  to jest to ."<<std::endl;
        }

        for(int i=0;i<liczbaWyjsc;i++){
            zapisz.append(std::to_string(wyjscia.at(i)));
            zapisz.append(";");
            s.clear();
            s.append(std::to_string(wyjscia.at(i)));
            std::cout<<"WYJSCIE POJEDYNCZE DO rMUX"<<s<<std::endl;
            wyjsciaPojedyncze[i]->setTypWyjscia("double");
            wyjsciaPojedyncze[i]->setStala(s);

            std::cout<<"WYJSCIE POJEDYNCZE DO rMUXB STALA"<<wyjsciaPojedyncze[i]->getWartoscCzlonu()<<std::endl;
        }
        std::cout<<"WYJSCIE Z WEKTORA"<<zapisz<<std::endl;
        this->wartosc->setWartosc(zapisz);

    }

