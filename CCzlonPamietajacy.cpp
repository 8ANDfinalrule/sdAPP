#include "head.hpp"
#include "CCzlonPamietajacy.h"


    CCzlonPamietajacy::CCzlonPamietajacy(int ile){
        std::list <std::vector<double> > (this->listaPamietanych);
    };

    void CCzlonPamietajacy::zapiszWartoscWejscia(){
        std::vector<double> wektor;
        std::string s;
        s=this->wektorWejsc[0].getSygnal();
        wektor=this->wartosc->wczytajStringDoWektor(s);
        listaPamietanych.push_back(wektor);
    }
