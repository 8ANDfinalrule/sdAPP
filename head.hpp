#ifndef HEAD_HPP
#define HEAD_HPP

#include <string>
//#include <sstream>
#include <vector>
//#include <list>
#include <iostream>
//#include <cstdlib>
//#include <typeinfo>


class ICPamietajacy{
public:
    virtual void zapiszWartoscWejscia()=0;
};

class ICWartosc{
public:
    virtual std::string getWartosc()=0;
    virtual void setWartosc(std::string wartosc)=0;
    virtual std::vector<double> wczytajStringDoWektor(std::string str)=0;
    virtual std::string wczytajWektorDoString(std::vector<double> vec)=0;
};

class ICCzlon{
public:
    virtual void setTypWyjscia(std::string typ)=0;
    virtual std::string getTypWyjscia()=0;
    virtual void wykonajKrokSymulacji()=0;
    virtual void dodajPolaczenie(ICCzlon *wejscie,ICCzlon *wyjscie,int nrWyjscia,int nrWejscia)=0;
    virtual void usunPolaczenie(int zKtoregoWejscia)=0;
    virtual void setTypPolaczenia(int ktory,std::string typ)=0;
    virtual int getLiczbaWejsc()=0;
    virtual int getLiczbaWyjsc()=0;
};

#endif // HEAD_HPP
