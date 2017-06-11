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
        //std::cout<<"ROZPOCZYNANIE SETOWANIE"<<std::endl;
        int i=0;
        do{
            found=wartosc.find_first_of(';');
            std::cout<<"ROZPOCZYNANIE SETOWANIE found:"<<found<<std::endl;
            std::string s;

            s=wartosc.substr(0,found-1);
            std::cout<<"ROZPOCZYNANIE SETOWANIE sdone:"<<s<<std::endl;
            wartosc.erase(0,found+1);
            if(s.empty()){
                return;
            }
            std::cout<<"ROZPOCZYNANIE SETOWANIEstod"<<std::endl;
            if(this->wartoscVector.size()<i+1){
                this->wartoscVector.push_back(std::stod(s));
            }else{
            this->wartoscVector.at(i)=std::stod(s);
            }
            i++;
        }while(found!=std::string::npos);
    }
}

std::vector<double> CVector::wczytajStringDoWektor(std::string str)
{
    std::size_t found=str.find_first_of(';');
    std::vector<double> vec;
    std::cout<<"WCZYTAJ STRING DO vecTOR found"<<found<<std::endl;
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
        std::cout<<"WCZYTAJ STRINGdoV2"<<found<<std::endl;
        do{
        found=str.find_first_of(';');
        std::cout<<"WCZYTAJ STRINGdoV2"<<found<<std::endl;
        std::string s;
        s=str.substr(0,found);
        str.erase(0,found+1);
        std::cout<<"WCZYTAJ STRINGdoV3 :s: "<<s<<std::endl;
        if(s.empty()){
            std::cout<<"Zwracam wektor bo pusty s, o rozmiarze "<<vec.size()<<std::endl;
            return vec;
        }
        std::cout<<"WCZYTAJ STRINGdoV4 :s: "<<s<<std::endl;
        vec.push_back(std::stod(s));
        }while(found!=std::string::npos);

    }
    return vec;
}

std::string CVector::wczytajWektorDoString(std::vector<double> vec)
{
    std::string string;
    std::cout<<"WCZYTAJWEKTORDOSTRINGVECTOR"<<std::endl;
    for(int i=0;i<vec.size();i++){
        std::cout<<"cos do wczytania: "<<i<<" = "<<vec.at(i)<<'.'<<std::endl;
        string.append(std::to_string(vec.at(i)));
        string.append(";");
    }
    if(string.empty()){
        string.append("0");
    }
    std::cout<<"WCZYTAJWEKTOr: string: "<<string<<std::endl;
    return string;
}

int CVector::getRozmiarWektora(){
    return wartoscVector.size();
}


std::string CDouble::getWartosc()
{
    std::ostringstream sstream;
    sstream << std::to_string(this->wartoscDouble);
    std::cout<<"MAMWARTOSC"<<sstream.str()<<std::endl;
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
    s=str.substr(0,found);
    if(s.empty()){
        return vec;
    }
    std::cout<<"DO WEKTORA cdoublE: "<<s<<std::endl;
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
    std::cout<<"WCZYTAJ STRING DO vecTOR found"<<found<<std::endl;
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
    s=str.substr(0,found-1);
    if(s.empty()){
        return vec;
    }
    vec.push_back((int)std::stod(s));
    return vec;
}

std::string CInt::wczytajWektorDoString(std::vector<double> vec)
{
    std::cout<<"WCZYTAJWEKTORDOSTRING INT"<<vec.size()<<" : vec size"<<std::endl;
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
    s=str.substr(0,found-1);
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
