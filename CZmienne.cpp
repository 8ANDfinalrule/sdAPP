#include "head.hpp"
#include "CZmienne.h"


void CVector::setRozmiarWektora(int rozmiar){
    wartoscVector.resize(rozmiar,0);
}

std::string CVector::getWartosc()
{

    std::ostringstream sstream;
    for(int i=0;i<this->wartoscVector.size();i++){
        sstream<<this->wartoscVector.at(i);
        sstream<<";";
    }
    return sstream.str();
}

void CVector::setWartosc(std::string wartosc)
{
    std::size_t found=wartosc.find_first_of(';');
    if(found==std::string::npos){
        std::cout<<"ZLY TYP DANYCH; NIE WEKTOR"<<std::endl;
    }
    else{
        int i=0;
        do{
            found=wartosc.find_first_of(';');
            std::string s;
            s.append(0,found-1);
            wartosc.erase(0,found+1);
            if(s.empty()){
                return;
            }
            this->wartoscVector.at(i)=std::stod(s);
            i++;
        }while(found!=std::string::npos);
    }
}

std::vector<double> CVector::wczytajStringDoWektor(std::string str)
{
    std::size_t found=str.find_first_of(';');
    std::vector<double> vec;
    if(found==std::string::npos){
        if(str.empty()){
            vec.push_back(0.0);
            return vec;
        }else{
        vec.push_back(std::stod(str));
        return vec;
        }
    }
    else{
        do{
        found=str.find_first_of(';');
        std::string s;
        s.append(0,found-1);
        str.erase(0,found+1);
        if(s.empty()){
            return vec;
        }
        vec.push_back(std::stod(s));
        }while(found==std::string::npos);

    }
    return vec;
}

std::string CVector::wczytajWektorDoString(std::vector<double> vec)
{
    std::string string;
    for(int i=0;i<vec.size();i++){
        string.append(std::to_string(vec.at(i)));
        string.append(";");
    }
    return string;
}

int CVector::getRozmiarWektora(){
    return wartoscVector.size();
}


std::string CDouble::getWartosc()
{
    std::ostringstream sstream;
    sstream << this->wartoscDouble;
    return sstream.str();
}

void CDouble::setWartosc(std::string wartosc)
{
    std::size_t found=wartosc.find_first_of('.');
    std::size_t found2=wartosc.find_last_of('.');
    if(found==found2){
        this->wartoscDouble=std::stod(wartosc);
    }else{
        std::cout<<"ZLY TYP DANYCH; NIE DOUBLE"<<std::endl;
    }
}

std::vector<double> CDouble::wczytajStringDoWektor(std::string str)
{
    std::size_t found=str.find_first_of(';');
    std::vector<double> vec;
    if(found==std::string::npos){
        if(str.empty()){
            vec.push_back(0.0);
            return vec;
        }else{
        vec.push_back(stod(str));
        return vec;
        }
    }
    std::string s;
    s.append(0,found-1);
    if(s.empty()){
        return vec;
    }
    vec.push_back(std::stod(s));
    return vec;
}

std::string CDouble::wczytajWektorDoString(std::vector<double> vec)
{
    std::string string;
    string.append(std::to_string(vec.at(0)));
    return string;
}


std::string CInt::getWartosc()
{
    std::ostringstream sstream;
    sstream << this->wartoscInt;
    return sstream.str();
}

void CInt::setWartosc(std::string wartosc)
{
    std::size_t found=wartosc.find_first_of('.');
    std::size_t found2=wartosc.find_first_of(';');
    if(found==std::string::npos&&found2==std::string::npos){
        this->wartoscInt=std::stod(wartosc);
    }else{
        std::cout<<"ZLY TYP DANYCH; NIE INT"<<std::endl;
    }
}

std::vector<double> CInt::wczytajStringDoWektor(std::string str)
{
    std::size_t found=str.find_first_of(';');
    std::vector<double> vec;
    if(found==std::string::npos){
        if(str.empty()){
            vec.push_back(0.0);
            return vec;
        }else{
        vec.push_back(std::stod(str));
        return vec;
        }
    }
    std::string s;
    s.append(0,found-1);
    if(s.empty()){
        return vec;
    }
    vec.push_back((int)std::stod(s));
    return vec;
}

std::string CInt::wczytajWektorDoString(std::vector<double> vec)
{
    std::string string;
    string.append(std::to_string((int)vec.at(0)));
    return string;
}


std::string CBool::getWartosc()
{
    std::ostringstream sstream;
    sstream << this->wartoscBool;
    return sstream.str();
}

void CBool::setWartosc(std::string wartosc)
{
    std::size_t found=wartosc.find("true");
    std::size_t found2=wartosc.find("false");
    if(found==std::string::npos&&found2==std::string::npos){
        std::cout<<"ZLY TYP DANYCH; NIE BOOL"<<std::endl;
    }
    else if(found==std::string::npos){
        this->wartoscBool=false;
    }
    else {
        this->wartoscBool=true;
    }
}

std::vector<double> CBool::wczytajStringDoWektor(std::string str)
{
    std::size_t found=str.find_first_of(';');
    std::vector<double> vec;
    if(found==std::string::npos){
        if(str.empty()){
            vec.push_back(0.0);
            return vec;
        }else{
        vec.push_back(std::stod(str));
        return vec;
        }
    }
    std::string s;
    s.append(0,found-1);
    if(s.empty()){
        return vec;
    }
    vec.push_back((bool)std::stod(s));
    return vec;
}

std::string CBool::wczytajWektorDoString(std::vector<double> vec)
{
    std::string string;
    string.append(std::to_string((bool)vec.at(0)));
    return string;
}
