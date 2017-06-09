

#include "head.hpp"
#include "CCzlonInercyjny.h"
#include "CCzlonPamietajacy.h"


    void CCzlonInercyjny::setStalaInercji(int stala){
        stalaInercji=stala;
    };

    int CCzlonInercyjny::getStalaInercji(){
        return stalaInercji;
    };

    void CCzlonInercyjny::wykonajKrokSymulacji(){
        /////////////////////////
        std::vector<double> wejscie;
        if(this->wektorFlagWejsc[0]==0){
            return;
        }

        std::string w=this->wektorWejsc[0].getSygnal();

        wejscie=this->wartosc->wczytajStringDoWektor(w);
        for(int i=0;i<wejscie.size();i++){
            if(listaPamietanych.size()<1){
                break;
            }
            wejscie.at(i)=wejscie.at(i)-listaPamietanych.back().at(i);

        }
        w=this->wartosc->wczytajWektorDoString(wejscie);
        this->wartosc->setWartosc(w);
        this->zapiszWartoscWejscia();
        if(listaPamietanych.size()>this->stalaInercji){
        listaPamietanych.pop_front();
        }

    }
