#ifndef CZMIENNE_H
#define CZMIENNE_H

#include "head.hpp"

class CVector:public ICWartosc{
protected:
    int rozmiarVector;
    std::vector <double> wartoscVector;
public:
    CVector(){
        this->rozmiarVector=2;
        wartoscVector.resize(rozmiarVector,0.0);
    }
    int getRozmiarWektora();
    void setRozmiarWektora(int rozmiar);
    std::string getWartosc();
    void setWartosc(std::string wartosc);
    std::vector<double> wczytajStringDoWektor(std::string str);
    std::string wczytajWektorDoString(std::vector<double> vec);
};

class CDouble:public ICWartosc{
protected:
    double wartoscDouble=0;
public:
    CDouble():wartoscDouble(0.0){};
    std::string getWartosc();
    void setWartosc(std::string wartosc);
    std::vector<double> wczytajStringDoWektor(std::string str);
    std::string wczytajWektorDoString(std::vector<double> vec);
};

class CInt: public ICWartosc{
protected:
    int wartoscInt;
public:
    CInt():wartoscInt(0){};
    std::string getWartosc();
    void setWartosc(std::string wartosc);
    std::vector<double> wczytajStringDoWektor(std::string str);
    std::string wczytajWektorDoString(std::vector<double> vec);
};

class CBool: public ICWartosc{
protected:
    bool wartoscBool;
public:
    CBool():wartoscBool(false){};
    std::string getWartosc();
    void setWartosc(std::string wartosc);
    std::vector<double> wczytajStringDoWektor(std::string str);
    std::string wczytajWektorDoString(std::vector<double> vec);
};

#endif // CZMIENNE_H
