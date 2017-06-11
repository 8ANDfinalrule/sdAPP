#ifndef CCZLON_H
#define CCZLON_H

#include "head.hpp"

class CCzlon: public ICCzlon{
protected:
    std::string typWyjscia;
    ICWartosc *wartosc;
    int liczbaWyjsc;
public:
    CCzlon(std::string typ="double");
    std::string getTypWyjscia();

    virtual CCzlon *getWskaznikWyjscia(int ktory){};
    void setWartoscCzlon(CCzlon *c,std::string s);

};

#endif // CCZLON_H
