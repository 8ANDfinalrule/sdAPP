
#include "head.hpp"
#include "CCzlonProporcjonalny.h"


    void CCzlonProporcjonalny::setWspProp(double wsp){
        wspProp=wsp;
    };

    double CCzlonProporcjonalny::getWspProp(){
        return wspProp;
    };

    void CCzlonProporcjonalny::wykonajKrokSymulacji(){
        std::vector<double> wejscie;
        if(this->wektorFlagWejsc[0]==0){
            return;
        }
        std::string w=this->wektorWejsc[0].getSygnal();
        std::cout<<"wartoscPoZWejscia"<<w<<std::endl;
        wejscie=this->wartosc->wczytajStringDoWektor(w);
        for(int i=0;i<wejscie.size();i++){
            wejscie.at(i)=wejscie.at(i)*this->wspProp;
        }
        std::cout<<"wartoscPoZWejsciaPOOBLICZENIU WEEK"<<wejscie.at(0)<<std::endl;
        w=this->wartosc->wczytajWektorDoString(wejscie);
        std::cout<<"wartoscPoZWejsciaPOOBLICZENIU"<<w<<std::endl;
        this->wartosc->setWartosc(w);
        std::cout<<"wartoscPoObliczeniu"<<this->wartosc->getWartosc()<<std::endl;
    }
