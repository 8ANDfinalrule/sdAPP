#include "head.hpp"
#include "CCzlon.h"
#include "CZmienne.h"


CCzlon::CCzlon(std::string typ){
    typWyjscia=typ;
};

void CCzlon::setWartoscCzlon(CCzlon *c, std::string s)
{
    c->wartosc->setWartosc(s);
};

std::string CCzlon::getTypWyjscia(){
    return typWyjscia;
}
