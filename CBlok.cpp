#include "CBlok.h"
#include <iostream>


CBlok::CBlok(double startX,double startY,int ileIn, int ileOut)
{
    ileP=0;
    this->setRect(startX,startY,sizeX,sizeY);
    ileWejsc=ileIn;
    ileWyjsc=ileOut;
    punktyWejsc=new QPointF*[ileIn];
    for(int i=0;i<ileIn;i++){
        punktyWejsc[i]=new QPointF;
    }
    punktyWyjsc=new QPointF*[ileOut];
        for(int i=0;i<ileOut;i++){
            punktyWyjsc[i]=new QPointF;
        }


    // IN/OUT
    int suma=ileIn+ileOut;
    QGraphicsEllipseItem **punkt=new QGraphicsEllipseItem*[suma];
    for(int i=0;i<suma;i++){
        punkt[i]=new QGraphicsEllipseItem(this);
    }
    for(int i=0;i<ileIn;i++){
        int podzialH=sizeY/(ileIn+1);
        //std::cout<<"Lwejsc"<<ileIn<<std::endl;
        punkt[i]->setRect(QRectF(-promienSlotu/2,-promienSlotu/2,promienSlotu,promienSlotu));
        punkt[i]->setPos(mapToScene(QPointF(startX-promienSlotu/2,startY+(i+1)*podzialH)));
        punktyWejsc[i]->setX(punkt[i]->pos().x());
        punktyWejsc[i]->setY(punkt[i]->pos().y());
        punkt[i]->show();
    }
    for(int i=0;i<ileOut;i++){
        int podzialH=sizeY/(ileOut+1);
        punkt[ileIn+i]->setRect(QRectF(-promienSlotu/2,-promienSlotu/2,promienSlotu,promienSlotu));
        punkt[ileIn+i]->setPos(mapToScene(QPointF(startX+promienSlotu/2+sizeX,startY+(i+1)*podzialH)));
        punktyWyjsc[i]->setX(punkt[ileIn+i]->pos().x());
        punktyWyjsc[i]->setY(punkt[ileIn+i]->pos().y());
        punkt[ileIn+i]->show();
    }


    // TYTUL
    text=new QGraphicsTextItem(this);
    QFont *font=new QFont;
    font->setBold(true);
    font->setPixelSize(8);
    text->setFont(*font);
    text->setPlainText(QString("blok2"));
    text->setPos(mapToScene(startX,startY));

    // WYNIK
    disp=new QGraphicsTextItem(this);
    font->setPixelSize(10);
    disp->setFont(*font);
    disp->setTextWidth(20);
    disp->setPlainText(QString("wynik"));
    disp->setPos(mapToScene(startX+sizeX/3,startY+sizeY/3));

    // ID
    ID=new QGraphicsTextItem(this);
    font->setBold(true);
    font->setPixelSize(9);
    ID->setFont(*font);
    ID->setPos(mapToScene(startX+3,startY+sizeY-20));
    ID->setPlainText("1");

    startPX=startX;
    startPY=startY;

    this->setFlag(ItemIsMovable,true);
    this->setFlag(ItemIsFocusable,true);
    text->show();
    delete font;
}

void CBlok::setTitle(std::string title)
{
    text->setPlainText(QString::fromStdString(title));
}

std::string CBlok::getTitle()
{
    return text->toPlainText().toStdString();
}

QPointF *CBlok::getPunktWejscia(int numerWejscia)
{

    QPointF *punktZw=new QPointF(*this->punktyWejsc[numerWejscia-1]);
    QPointF *dod=new QPointF(mapToScene(0,0));
    *punktZw+=*dod;
    return punktZw;
}

QPointF *CBlok::getPunktWyjscia(int numerWejscia)
{
    QPointF *punktZw=new QPointF(*this->punktyWyjsc[numerWejscia-1]);
    QPointF *dod=new QPointF(mapToScene(0,0));
    *punktZw+=*dod;
    return punktZw;
}

QPointF *CBlok::getStartPoint()
{
    QPointF *punkt=new QPointF;
    punkt->setX(startPX);
    punkt->setY(startPY);
    return punkt;
}

void CBlok::setWartoscDisp(std::vector<double> wartosc)
{
    QString napis;
    QFont *font=new QFont;
    font->setPixelSize(7);
    disp->setFont(*font);
    for(int i=0;i<wartosc.size();i++){
        napis.push_back(QString::number(wartosc.at(i)));
        if(i>0){
            napis.push_back(";\n ");
        }
    }
    disp->setPlainText(QString(napis));
    disp->adjustSize();
}
void CBlok::setWartoscDisp(std::string wartosc)
{
    QString napis=QString::fromStdString(wartosc);
    QFont *font=new QFont;
    font->setPixelSize(7);
    disp->setFont(*font);
    disp->setPlainText(QString(napis));
    disp->adjustSize();
}

void CBlok::setID(int id)
{
    ID->setPlainText(QString::number(id));
}

int CBlok::getIleWejsc()
{
   return ileWejsc;
}

int CBlok::getIleWyjsc()
{
    return ileWyjsc;
}

void CBlok::dodajLinia(CLinia *linia,bool czyPoczatek,int numerSlotu)
{
    linie.push_back(linia);
    jakieLinie.push_back(czyPoczatek);
    nrSlotu.push_back(numerSlotu);
}

void CBlok::updateWszystkieLinie()
{
    for(int i=0;i<linie.size();i++){
        if(jakieLinie.at(i)==1){
            linie.at(i)->updateLinia(true,getPunktWyjscia(nrSlotu.at(i)));
        }
        else{
            linie.at(i)->updateLinia(false,getPunktWejscia(nrSlotu.at(i)));
        }
    }
}



void CBlok::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        this->setFocus();
        this->setFlag(ItemIsMovable,true);
        event->accept();
        startDrag.setX(event->pos().x()-startPX);
        startDrag.setY(event->pos().y()-startPY);
    }
    Q_UNUSED(event);
}

void CBlok::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    this->setPos(QPointF(mapToItem(this,event->scenePos()-QPointF(startPX,startPY)-startDrag)));
    update();
    ileP++;
    updateWszystkieLinie();
}
void CBlok::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    this->setVisible(true);
    this->clearFocus();
    this->setFlag(ItemIsMovable,false);
    Q_UNUSED(event);
}
