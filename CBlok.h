#ifndef CBLOK_H
#define CBLOK_H
#include <QGraphicsRectItem>
#include <QGraphicsSceneDragDropEvent>
#include <QFont>
#include <vector>
#include "CLinia.h"


class CBlok: public QGraphicsRectItem{
private:
   QGraphicsTextItem *text;
   QGraphicsTextItem *disp;
   QGraphicsTextItem *ID;
   double startPX;
   double startPY;
   double sizeX=100,sizeY=70;
   QPointF startDrag;
   int ileWejsc,ileWyjsc;
   QPointF **punktyWejsc;
   QPointF **punktyWyjsc;
   std::vector<CLinia*> linie;
   std::vector<bool> jakieLinie;
   std::vector<int> nrSlotu;
   int ileP;
   int promienSlotu=5;

public:
    CBlok(double startX,double startY,int ileIn, int IleOut);
    QPointF *getPunktWejscia(int numerWejscia);
    QPointF *getPunktWyjscia(int numerWejscia);
    QPointF *getStartPoint();
    void setWartoscDisp(std::string wartosc);
    void setWartoscDisp(std::vector<double> wartosc);
    void setTitle(std::string title);
    std::string getTitle();
    void setID(int id);
    int getIleWejsc();
    int getIleWyjsc();
    void dodajLinia(CLinia *linia,bool czyPoczatek,int numerSlotu);
    void updateWszystkieLinie();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CBLOK_H
