#ifndef CLINIA_H
#define CLINIA_H


#include <QGraphicsLineItem>



class CLinia:public QGraphicsLineItem{
private:
    QPointF *wejscie;
    QPointF *wyjscie;
    int nrWejscia;
    int nrWyjscia;
public:
    CLinia(QPointF *pocz, QPointF *kon);
    void updateLinia(bool czyPodaneWejscie,QPointF *punkt);
};

#endif // CLINIA_H
