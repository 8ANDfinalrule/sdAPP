

#include "head.hpp"
#include "CCzlonCalkujacy.h"



    void CCzlonCalkujacy::setCzasCalkowania(int czas){
        this->czasCalkowania=czas;
    };

    int CCzlonCalkujacy::getCzasCalkowania(){
        return czasCalkowania;
    };

    void CCzlonCalkujacy::wykonajKrokSymulacji(){
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
        if(listaPamietanych.size()>this->czasCalkowania){
        listaPamietanych.pop_front();
        }
    }
