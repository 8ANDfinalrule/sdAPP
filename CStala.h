#ifndef CSTALA_H
#define CSTALA_H

#include "head.hpp"
#include "CCzlonCzynny.h"

class CStala : public CCzlonCzynny{
private:
public:
    CStala(std::string wartosc="0"): CCzlonCzynny(){
        this->wartosc->setWartosc(wartosc);
    };
    void setStala(std::string wartosc);
};

#endif // CSTALA_H
