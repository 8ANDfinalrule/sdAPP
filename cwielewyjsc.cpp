#include "cwielewyjsc.h"


CCzlon *CWieleWyjsc::getWskaznikWyjscia(int ktory){

    if(ktory<liczbaWyjsc){

        CCzlonCzynny *zwracany=new CStala;
        zwracany=wyjsciaPojedyncze[ktory];
        //zwracany->setTypWyjscia("double");
        std::cout<<"zwracam "<<ktory<<" wskaznik"<<std::endl;
        return zwracany;
    }
    else{
        std::cout<<"POWAZNY BLAD"<<std::endl;
    }
}

void CWieleWyjsc::setLiczbaWyjsc(int liczba){
    liczbaWyjsc=liczba;
};

int CWieleWyjsc::getLiczbaWyjsc(){
    return liczbaWyjsc;
};
