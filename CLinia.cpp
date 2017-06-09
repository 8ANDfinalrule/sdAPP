#include "CLinia.h"
#include <QPen>
#include <iostream>

CLinia::CLinia(QPointF *pocz, QPointF *kon)
{
    wejscie=pocz;
    wyjscie=kon;
    /*std::cout<<"WEx: "<<wejscie->x()<<std::endl;
    std::cout<<"WEx: "<<wejscie->y()<<std::endl;
    std::cout<<"Wyx: "<<wyjscie->x()<<std::endl;
    std::cout<<"Wyx: "<<wyjscie->y()<<std::endl;*/
    QLineF *linia=new QLineF(*wejscie,*wyjscie);
    QPen *pen=new QPen(QColor("darkCyan"));
    pen->setWidth(1);
    this->setPen(*pen);
    this->setLine(*linia);
    this->setVisible(true);
    delete linia;
    delete pen;
}

void CLinia::updateLinia(bool czyPodaneWejscie,QPointF *punkt)
{
    QLineF *linia;
    if(czyPodaneWejscie){
        //std::cout<<"p1x"<<punkt->x()<<std::endl;
       // std::cout<<"p1y"<<punkt->y()<<std::endl;
        linia=new QLineF(*punkt,*wyjscie);
        wejscie=punkt;
    }
    else{
        linia=new QLineF(*wejscie,*punkt);
        wyjscie=punkt;
    }
    /*std::cout<<"linia1x"<<linia->x1()<<std::endl;
    std::cout<<"linia1x"<<linia->y1()<<std::endl;
    std::cout<<"linia2x"<<linia->x2()<<std::endl;
    std::cout<<"linia2x"<<linia->y2()<<std::endl;*/
    this->setLine(*linia);
    delete linia;
}



