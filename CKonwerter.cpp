
#include "head.hpp"
#include "CKonwerter.h"


    void CKonwerter::setRodzajSygnaluWyjscia(std::string wyjscie){
        this->setTypWyjscia(wyjscie);
    };
    void CKonwerter::setRodzajSygnaluWejscia(std::string wejscie){
        this->setTypPolaczenia(1,wejscie);
    };
    std::string CKonwerter::getSygnalWejscia(){
        return this->getTypPolaczenia();
    };
    std::string CKonwerter::getSygnalWyjscia(){
        return this->getTypWyjscia();
    };
    void CKonwerter::wykonajKrokSymulacji(){
        if(this->wektorFlagWejsc[0]==0){
            return;
        }
        std::string w;
        w=this->wektorWejsc[0].getSygnal();
        std::vector<double> wek;
        wek=this->wartosc->wczytajStringDoWektor(w);
        this->wartosc->setWartosc(this->wartosc->wczytajWektorDoString(wek));
    };
