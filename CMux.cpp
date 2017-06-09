
#include "head.hpp"
#include "CMux.h"
#include "CZmienne.h"



    void CMux::wykonajKrokSymulacji(){
        std::vector<double> nowy,p;
        double kolejny;
        std::string w;
       // std::cout<<"mux: "<<this->getIloscWejscCzlonu()<<std::endl;
        for(int i=0;i<this->getIloscWejscCzlonu();i++){
            CVector *v=dynamic_cast<CVector*>(this->wartosc);
            if(v==NULL){
                //std::cout<<"sssssss"<<std::endl;
                break;
            }
            else{
                std::cout<<"TY: "<<this->wartosc<<std::endl;
            }
            if(wektorFlagWejsc[i]==1){
            w=this->wektorWejsc[i].getSygnal();
            std::cout<<"mux2: sygnalwziety*(********) "<<w<<std::endl;
            ICWartosc *n=new CDouble;
            p=n->wczytajStringDoWektor(w);
            std::cout<<"sygnalWKEOTR^$%$&$) "<<p.at(0)<<std::endl;
            kolejny=p.at(0);
            }else{
                kolejny=0.0;
            }
            nowy.push_back(kolejny);
            //std::cout<<"mux3: "<<std::endl;
            std::cout<<"W od "<<i<<"= "<<nowy.at(i)<<' '<<std::endl;
        }
        //std::cout<<"mux2"<<this->wartosc->wczytajWektorDoString(nowy)<<std::endl;
        this->wartosc->setWartosc(this->wartosc->wczytajWektorDoString(nowy));
    }
