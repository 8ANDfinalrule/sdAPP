#include "CZrodloSinusoidalne.h"


void CZrodloSinusoidalne::wykonajKrokSymulacji()
{
    this->aktualnyArgument+=this->dlugoscKroku;
    double w=sin(this->aktualnyArgument*3.141593/180);
    std::string s;
    s=std::to_string(w);
    this->wartosc->setWartosc(s);
}
