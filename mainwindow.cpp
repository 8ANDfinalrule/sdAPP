
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <CBlok.h>
//#include <QWidget>
#include <iostream>
#include "CLinia.h"
#include <string>
#include <sstream>
#include <CCzlonRozniczkujacy.h>
#include <CCzlonProporcjonalny.h>
#include <CCzlonCalkujacy.h>
#include <CCzlonOpozniajacy.h>
#include <CCzlonInercyjny.h>
#include <cstockend.h>
#include <CKonwerter.h>
#include <CMux.h>
#include <CReversedMux.h>
#include <CWezel.h>
#include <QTreeWidgetItem>
#include "CZrodloSinusoidalne.h"
#include "windows.h"
#include <QTimer>




void MainWindow::jedenKrokSymulacji()
{
    for(int i=0;i<czlony.size();i++){
        //std::cout<<"1symulacja"<<std::endl;
            czlony.at(i)->wykonajKrokSymulacji();
            std::string war;
            //std::cout<<"2symulacja"<<std::endl;
            war=czlony.at(i)->getWartoscCzlonu();
            //std::cout<<"3symulacja"<<std::endl;
            //std::cout<<"WPISUJE: "<<war<<std::endl;

            bloki.at(i)->setWartoscDisp(war);
            bloki.at(i)->update();
            //std::cout<<"WPISUJE2: "<<war<<std::endl;
        }

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ileBlokow=0;
    scene=new QGraphicsScene();

    scene->setSceneRect(ui->pole->rect());

    view = new QGraphicsView(scene,ui->pole);
    view->setRenderHints(QPainter::Antialiasing);
    view->show();

}

MainWindow::~MainWindow()
{
    delete scene;
    delete view;
    delete ui;
}

void MainWindow::on_dodajCzlon_clicked()
{
    // start pos

    int posX=180,posY=300;

    int ileWejsc=ui->lWejsc->text().toInt();
    int ileWyjsc=ui->lWyjsc->text().toInt();
    QTreeWidgetItem *treeItem=new QTreeWidgetItem;
    ileBlokow++;
    QString nap=QString::number(ileBlokow);
   // std::cout<<"nap"<<nap.toStdString()<<std::endl;
    treeItem->setText(0,nap);
    ui->LiczbaCzlonow->display(ileBlokow);
    std::vector<double> wartosc;
    wartosc.push_back(ui->wartosc->value());
    //std::cout<<"VALUE PUSHED"<<wartosc.at(0)<<std::endl;
    CBlok *kolejny;
    if(ui->typCzlonu->currentText()=="Człon Różniczkujący"){
        std::string napis=ui->typCzlonu->currentText().toStdString();
        CCzlonRozniczkujacy *blok=new CCzlonRozniczkujacy();
        blok->setWartoscCzlon(blok,blok->getStringFromWektorCzlon(wartosc));
        treeItem->setText(1,QString::fromStdString(napis));
        kolejny=new CBlok(posX,posY,1,1);
        kolejny->setTitle(napis);
        kolejny->setWartoscDisp(wartosc);
        kolejny->setID(ileBlokow);
        czlony.push_back(blok);
    }
    else if(ui->typCzlonu->currentText()=="Człon Proporcjonalny"){
        std::string napis=ui->typCzlonu->currentText().toStdString();
        CCzlonProporcjonalny *blok=new CCzlonProporcjonalny();
        blok->setWartoscCzlon(blok,blok->getStringFromWektorCzlon(wartosc));
        treeItem->setText(1,QString::fromStdString(napis));
        kolejny=new CBlok(posX,posY,1,1);
        kolejny->setTitle(napis);
        kolejny->setWartoscDisp(wartosc);
        kolejny->setID(ileBlokow);
        czlony.push_back(blok);
    }
    else if(ui->typCzlonu->currentText()=="Człon Całkujący"){
        std::string napis=ui->typCzlonu->currentText().toStdString();
        CCzlonCalkujacy *blok=new CCzlonCalkujacy();
        blok->setWartoscCzlon(blok,blok->getStringFromWektorCzlon(wartosc));
        treeItem->setText(1,QString::fromStdString(napis));
        kolejny=new CBlok(posX,posY,1,1);
        kolejny->setTitle(napis);
        kolejny->setWartoscDisp(wartosc);
        kolejny->setID(ileBlokow);
        czlony.push_back(blok);
    }
    else if(ui->typCzlonu->currentText()=="Człon Inercyjny"){
        std::string napis=ui->typCzlonu->currentText().toStdString();
        CCzlonInercyjny *blok=new CCzlonInercyjny();
        blok->setWartoscCzlon(blok,blok->getStringFromWektorCzlon(wartosc));
        treeItem->setText(1,QString::fromStdString(napis));
        kolejny=new CBlok(posX,posY,1,1);
        kolejny->setTitle(napis);
        kolejny->setWartoscDisp(wartosc);
        kolejny->setID(ileBlokow);
        czlony.push_back(blok);
    }
    else if(ui->typCzlonu->currentText()=="Człon Opóźniający"){
        std::string napis=ui->typCzlonu->currentText().toStdString();
        CCzlonOpozniajacy *blok=new CCzlonOpozniajacy();
        blok->setWartoscCzlon(blok,blok->getStringFromWektorCzlon(wartosc));
        treeItem->setText(1,QString::fromStdString(napis));
        kolejny=new CBlok(posX,posY,1,1);
        kolejny->setTitle(napis);
        kolejny->setWartoscDisp(wartosc);
        kolejny->setID(ileBlokow);
        czlony.push_back(blok);
    }
    else if(ui->typCzlonu->currentText()=="Konwerter"){
        std::string napis=ui->typCzlonu->currentText().toStdString();
        CKonwerter *blok=new CKonwerter();
        blok->setWartoscCzlon(blok,blok->getStringFromWektorCzlon(wartosc));
        treeItem->setText(1,QString::fromStdString(napis));
        kolejny=new CBlok(posX,posY,1,1);
        kolejny->setTitle(napis);
        kolejny->setWartoscDisp(wartosc);
        kolejny->setID(ileBlokow);
        czlony.push_back(blok);
    }
    else if(ui->typCzlonu->currentText()=="Mux"){
        std::string napis=ui->typCzlonu->currentText().toStdString();
        CMux *blok=new CMux(ileWejsc);
        //std::cout<<"MUX1"<<std::endl;
        blok->setWartoscCzlon(blok,blok->getStringFromWektorCzlon(wartosc));
        //std::cout<<"MUX2"<<std::endl;
        treeItem->setText(1,QString::fromStdString(napis));
        kolejny=new CBlok(posX,posY,ileWejsc,1);
        //std::cout<<"MUX3"<<std::endl;
        kolejny->setTitle(napis);
        kolejny->setWartoscDisp(wartosc);
        kolejny->setID(ileBlokow);
        czlony.push_back(blok);
    }
    else if(ui->typCzlonu->currentText()=="Reversed Mux"){
        std::string napis=ui->typCzlonu->currentText().toStdString();
        CReversedMux *blok=new CReversedMux(ileWyjsc);
        blok->setWartoscCzlon(blok,blok->getStringFromWektorCzlon(wartosc));
        treeItem->setText(1,QString::fromStdString(napis));
        kolejny=new CBlok(posX,posY,1,ileWyjsc);
        kolejny->setTitle(napis);
        kolejny->setWartoscDisp(wartosc);
        kolejny->setID(ileBlokow);
        czlony.push_back(blok);
    }
    else if(ui->typCzlonu->currentText()=="Węzeł"){
        std::string napis=ui->typCzlonu->currentText().toStdString();
        CWezel *blok=new CWezel(ileWejsc,'+');
        blok->setWartoscCzlon(blok,blok->getStringFromWektorCzlon(wartosc));
        treeItem->setText(1,QString::fromStdString(napis));
        kolejny=new CBlok(posX,posY,ileWejsc,1);
        kolejny->setTitle(napis);
        kolejny->setWartoscDisp(wartosc);
        kolejny->setID(ileBlokow);
        czlony.push_back(blok);
    }
    else if(ui->typCzlonu->currentText()=="Stock"){
        std::string napis=ui->typCzlonu->currentText().toStdString();
        //std::cout<<"ETAP2.1"<<std::endl;
        CStock *blok=new CStock();
        blok->setWartoscCzlon(blok,blok->getStringFromWektorCzlon(wartosc));
        //std::cout<<"ETAP2.2"<<std::endl;
        treeItem->setText(1,QString::fromStdString(napis));
        kolejny=new CBlok(posX,posY,ileWejsc,ileWyjsc);
        kolejny->setTitle(napis);
        kolejny->setWartoscDisp(wartosc);
        kolejny->setID(ileBlokow);
        //std::cout<<"ETA2.3"<<std::endl;
        czlony.push_back(blok);
    }
    else if(ui->typCzlonu->currentText()=="Stała"){
        std::string napis=ui->typCzlonu->currentText().toStdString();
        CStala *blok=new CStala();
        blok->setWartoscCzlon(blok,blok->getStringFromWektorCzlon(wartosc));
        treeItem->setText(1,QString::fromStdString(napis));
        kolejny=new CBlok(posX,posY,0,1);
        kolejny->setTitle(napis);
        kolejny->setWartoscDisp(wartosc);
        kolejny->setID(ileBlokow);
        czlony.push_back(blok);
    }
    else if(ui->typCzlonu->currentText()=="Źródło Sinusoidalne"){
        std::string napis=ui->typCzlonu->currentText().toStdString();
        CZrodloSinusoidalne *blok=new CZrodloSinusoidalne();
        blok->setWartoscCzlon(blok,blok->getStringFromWektorCzlon(wartosc));
        treeItem->setText(1,QString::fromStdString(napis));
        kolejny=new CBlok(posX,posY,0,1);
        kolejny->setTitle(napis);
        kolejny->setWartoscDisp(wartosc);
        kolejny->setID(ileBlokow);
        czlony.push_back(blok);
    }
    bloki.push_back(kolejny);
    scene->addItem(kolejny);
    kolejny->show();
    ui->listaCzlonow->addTopLevelItem(treeItem);

}

void MainWindow::on_dodajPolaczenie_clicked()
{

    int idOut,idIn;
    idOut=ui->idWyjscia->text().toInt();
    idIn=ui->idWejscia->text().toInt();
    //std::cout<<"POCZidWejscia"<<idIn<<std::endl;
    //std::cout<<"idWyjscia"<<idIn<<std::endl;
    //std::cout<<"ileblokow"<<ileBlokow<<std::endl;
    if(idOut<1||idOut>ileBlokow){
        return;
    }
    if(idIn<1||idIn>ileBlokow){
        return;
    }
    if(idIn==idOut){
        return;
    }
    CBlok *pocz=bloki.at(idOut-1);
    CBlok *kon=bloki.at(idIn-1);
    int nrWe,nrWy;
    nrWy=ui->nrWyjscia1->text().toInt();
    nrWe=ui->nrWejscia2->text().toInt();
    if(nrWy>pocz->getIleWyjsc()){
        std::cout<<"CASE1idout:"<<nrWy<<std::endl;
        std::cout<<"ilewyjsc: "<<pocz->getIleWyjsc()<<std::endl;
        return;
    }
    if(nrWe>kon->getIleWejsc()){
        std::cout<<"CASE2idin:"<<nrWe<<std::endl;
        std::cout<<"ilewejsc: "<<kon->getIleWejsc()<<std::endl;
        return;
    }
    CLinia *line=new CLinia(pocz->getPunktWyjscia(nrWy),kon->getPunktWejscia(nrWe));
    std::cout<<"ETAP2"<<std::endl;
    czlony.at(idIn-1)->dodajPolaczenie(czlony.at(idOut-1),czlony.at(idIn-1),nrWe,nrWy);
    std::cout<<"ETAP3"<<std::endl;
    pocz->dodajLinia(&*line,true,nrWy);
    kon->dodajLinia(&*line,false,nrWe);
    scene->addItem(line);
    std::cout<<"ETAP4"<<std::endl;
    //delete czlon,czlonP;

}

void MainWindow::on_wykonajKrok_clicked()
{
    jedenKrokSymulacji();
}

void MainWindow::on_startSymulacji_clicked()
{
    int i=ui->ileKrokow->text().toInt();
    int waitT;
    waitT=ui->waitTime->text().toInt();
    for(int j=0;j<i;j++){
        QTimer *timer = new QTimer(this);
        QEventLoop *event=new QEventLoop(this);
        connect(timer, SIGNAL(timeout()), event, SLOT(quit()));
        timer->start(waitT);
        event->exec();
        std::cout<<"CZEKAM"<<j<<std::endl;
        jedenKrokSymulacji();
    }
}

void MainWindow::on_dodajPolaczenie_2_clicked()
{
    //EDYTUJ TYP WEJSCIA
    int idCzlonu=ui->idWejsciaEdycja->text().toInt();
    int idWejscia=ui->nrWejsciaEdycja->text().toInt();
    std::string s=ui->typWejscia->currentText().toStdString();
    czlony.at(idCzlonu)->setTypPolaczenia(idWejscia,s);
}

void MainWindow::on_dodajPolaczenie_3_clicked()
{
    //EDYTUJ TYP WYJSCIA
    int idCzlonu=ui->idWyjsciaEdycja->text().toInt();
    std::string s=ui->typWyjscia->currentText().toStdString();
    czlony.at(idCzlonu)->setTypWyjscia(s);
}
