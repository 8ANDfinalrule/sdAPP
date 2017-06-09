
#include "head.hpp"
#include "CCzlonOpozniajacy.h"


    void CCzlonOpozniajacy::setCzasOpoznienia(int czas){
        czasOpoznienia=czas;
    };
    int CCzlonOpozniajacy::getCzasOpoznienia(){
        return czasOpoznienia;
    };
    void CCzlonOpozniajacy::wykonajKrokSymulacji(){
        std::vector<double> wejscie;
        if(this->wektorFlagWejsc[0]==0){
            return;
        }
        std::string w;

        if(!(this->listaPamietanych.size()<this->czasOpoznienia)){
            w=this->wartosc->wczytajWektorDoString(this->listaPamietanych.front());
            this->wartosc->setWartosc(w);
        }
        this->zapiszWartoscWejscia();
        if(listaPamietanych.size()>this->czasOpoznienia){
        listaPamietanych.pop_front();
        }
    }
