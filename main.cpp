#include "mainwindow.h"
#include <QApplication>
#include <head.hpp>
#include <CCzlon.h>
#include <CCzlonCzynny.h>
#include <CCzlonCalkujacy.h>
#include <CCzlonInercyjny.h>
#include <CCzlonPamietajacy.h>
#include <CCzlonRozniczkujacy.h>
#include <CCzlonProporcjonalny.h>
#include <CCzlonOpozniajacy.h>
#include <CKonwerter.h>
#include <CMux.h>
#include <CReversedMux.h>
#include <CStala.h>
#include <CPolaczenie.h>
#include <CWezel.h>
#include <CWiele.h>
#include <CZmienne.h>
#include <cstockend.h>



using namespace std;

int CCzlonCzynny::indeksCzlonu;

void wypiszWynikDouble(CCzlonCzynny *czlon){

    cout<<czlon->getWartoscCzlonu()<<endl;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    /*
    cout << "Witaj" << endl;
    CCzlonProporcjonalny **czlon=new CCzlonProporcjonalny*[5];
    const int ILECZLONOW=3;
    int powtorzenia=4;
    for(int i=0;i<ILECZLONOW;i++){
    czlon[i]=new CCzlonProporcjonalny;
    };
    CStala *stala=new CStala(3.0);

    CStock *pocz=new CStock(2,2,5.0);
    pocz->dodajPolaczenie(stala,pocz,1);
    pocz->setIleNaWyjscie(0.2);
    cout<<"POCZ: "<<pocz->getTypWyjscia()<<endl;

    double war;
    pocz->getWartosc(war);
        cout << "Stock"<<war<<endl;
    czlon[0]->dodajPolaczenie(pocz,czlon[0],1,1);

    for(int i=0;i<ILECZLONOW-1;i++){
        czlon[i+1]->dodajPolaczenie(czlon[i],czlon[i+1]);
    }


    CCzlonOpozniajacy *czlonO=new CCzlonOpozniajacy(2);
    cout<<"ty stara kurwo niemyta"<<endl;
    CMux *mux=new CMux(4);
    mux->dodajPolaczenie(czlon[0],mux,1);
    cout<<"MUX L : "<<mux->getIloscWejscCzlonu()<<endl;
    mux->dodajPolaczenie(czlon[2],mux,2);
    mux->dodajPolaczenie(czlonO,mux,3);
    cout<<"kupsko"<<endl;
    mux->dodajPolaczenie(pocz,mux,4,true,2);
    pocz->dodajPolaczenie(czlon[1],pocz,2);
    char *tab=new char[3];
    tab[0]='+';tab[1]='-';tab[2]='*';

    CWezel *wezel=new CWezel(3,tab);
    czlonO->dodajPolaczenie(czlon[1],czlonO);

    CCzlonProporcjonalny *czlonZWek=new CCzlonProporcjonalny(2.43);
    czlonZWek->setTypWyjscia("vector");
    CReversedMux *rmux=new CReversedMux(3);
    //rmux->setTypPolaczenia("")
    czlonZWek->setTypPolaczenia("double");
    czlonZWek->dodajPolaczenie(wezel,czlonZWek);

    rmux->dodajPolaczenie(czlonZWek,rmux);

    CCzlonProporcjonalny **odbior=new CCzlonProporcjonalny*[3];
    for(int i=0;i<3;i++){

        odbior[i]=new CCzlonProporcjonalny(21);
        odbior[i]->dodajPolaczenie(rmux,odbior[i],true,i+1);
    }

    wezel->dodajPolaczenie(czlon[0],wezel,1);
    wezel->dodajPolaczenie(czlonO,wezel,2);
    wezel->setTypPolaczenia("vector",3);
    wezel->dodajPolaczenie(mux,wezel,3);
    for(int i=0;i<ILECZLONOW;i++){
    czlon[i]->setWspProp(i+(double)2);
    };
        CCzlonProporcjonalny *ostatni=new CCzlonProporcjonalny(1.32);
        ostatni->dodajPolaczenie(odbior[0],ostatni);
        //ITERACJE OBLICZEN
    for(int j=0;j<powtorzenia;j++){
        pocz->wykonajKrokSymulacji();
        cout<<endl<<"POCZ"<<endl;
        wypiszWynikDouble(pocz);
        for(int i=0;i<ILECZLONOW;i++){
        czlon[i]->wykonajKrokSymulacji();
        cout<<endl<<"czlon proprcjonalny "<<i<<endl;
        wypiszWynikDouble(czlon[i]);
        }
        czlonO->wykonajKrokSymulacji();

        mux->wykonajKrokSymulacji();

        wezel->wykonajKrokSymulacji();
        czlonZWek->wykonajKrokSymulacji();
        rmux->wykonajKrokSymulacji();
        odbior[0]->wykonajKrokSymulacji();
        odbior[1]->wykonajKrokSymulacji();
        odbior[2]->wykonajKrokSymulacji();
        ostatni->wykonajKrokSymulacji();
        cout<<endl<<"CzlonoZWEK"<<endl;
        wypiszWynikDouble(czlonZWek);
        cout<<endl<<"Rmux"<<endl;
        wypiszWynikDouble(rmux);

        cout<<endl<<"odbior1"<<endl;
        wypiszWynikDouble(odbior[0]);
        cout<<endl<<"odbior2"<<endl;
        wypiszWynikDouble(odbior[1]);

        cout<<endl<<"CzlonoOPOZ"<<endl;
        wypiszWynikDouble(czlonO);
        cout<<endl<<"MUX"<<endl;
        wypiszWynikDouble(mux);
        cout<<endl<<"CWezel"<<endl;
        wypiszWynikDouble(wezel);
        cout<<endl<<"Ostatni"<<endl;
        wypiszWynikDouble(ostatni);


    }
    */

    w.createPopupMenu();

    return a.exec();
}
