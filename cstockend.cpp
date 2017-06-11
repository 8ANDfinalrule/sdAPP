#include "cstockend.h"

void CStock::wykonajKrokSymulacji(){
    std::vector<double> wartoscTego;
    std::vector<double> pom;
    std::string s;
    std::cout<<this->wartosc->getWartosc()<<"towartosc***PPPPPP"<<std::endl;
    s=this->getWartoscCzlonu();
    pom=this->wartosc->wczytajStringDoWektor(s);
    wartoscTego=pom;
    wartoscTego.resize(maxIloscWejsc,0);
    for(int i=0;i<this->maxIloscWejsc;i++){
        if(this->wektorFlagWejsc[i]==1){
            s=this->wektorWejsc[i].getSygnal();
            pom=this->wartosc->wczytajStringDoWektor(s);
        pom.resize(wartoscTego.size(),0);
        std::cout<<"POMSize: "<<pom.size()<<std::endl;
        for(int j=0;j<pom.size();j++){
            std::cout<<"POM: "<<pom.at(j)<<std::endl;
            wartoscTego.at(j)+=pom.at(j);
        }
        }
        std::cout<<"suma "<<0<<"="<<wartoscTego.at(0)<<std::endl;
    }
        for(int k=0;k<wartoscTego.size();k++){
           for(int j=0;j<this->liczbaWyjsc;j++){
            this->wyjsciaPojedyncze[j]->setTypWyjscia("double");
            s.clear();
            s.append(std::to_string(this->ileNaWyjscie));
            this->wyjsciaPojedyncze[j]->setStala(s);
            wartoscTego.at(k)-=ileNaWyjscie;
        }  
    }

        this->wartosc->setWartosc(this->wartosc->wczytajWektorDoString(wartoscTego));
        std::cout<<this->wartosc->getWartosc()<<"towartosc***"<<std::endl;
}


void CStock::setIleNaWyjscie(double ile){
    this->ileNaWyjscie=ile;
}

double CStock::getIleNaWyjscie(){

    return this->ileNaWyjscie;
}

