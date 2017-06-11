
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
    treeItem->setText(0,nap);
    ui->LiczbaCzlonow->display(ileBlokow);
    std::string wartosc;
    wartosc=ui->wartosc->text().toStdString();

    CBlok *kolejny;
    CCzlonCzynny *blok;
    std::string napis=ui->typCzlonu->currentText().toStdString();
    if(ui->typCzlonu->currentText()=="Człon Różniczkujący"){
        blok=new CCzlonRozniczkujacy();
        kolejny=new CBlok(posX,posY,1,1);
    }
    else if(ui->typCzlonu->currentText()=="Człon Proporcjonalny"){
        blok=new CCzlonProporcjonalny();
        kolejny=new CBlok(posX,posY,1,1);
    }
    else if(ui->typCzlonu->currentText()=="Człon Całkujący"){
        blok=new CCzlonCalkujacy();
        kolejny=new CBlok(posX,posY,1,1);
    }
    else if(ui->typCzlonu->currentText()=="Człon Inercyjny"){
        blok=new CCzlonInercyjny();
        kolejny=new CBlok(posX,posY,1,1);
    }
    else if(ui->typCzlonu->currentText()=="Człon Opóźniający"){
        blok=new CCzlonOpozniajacy();
        kolejny=new CBlok(posX,posY,1,1);
    }
    else if(ui->typCzlonu->currentText()=="Konwerter"){
        blok=new CKonwerter();
        kolejny=new CBlok(posX,posY,1,1);
    }
    else if(ui->typCzlonu->currentText()=="Mux"){
        blok=new CMux(ileWejsc);
        std::cout<<"ILE WEJSCCZLON MUX"<<blok->getLiczbaWejsc()<<std::endl;
        kolejny=new CBlok(posX,posY,ileWejsc,1);
    }
    else if(ui->typCzlonu->currentText()=="Reversed Mux"){
        blok=new CReversedMux(ileWyjsc);
        kolejny=new CBlok(posX,posY,1,ileWyjsc);
    }
    else if(ui->typCzlonu->currentText()=="Węzeł"){
        blok=new CWezel(ileWejsc,'+');
        kolejny=new CBlok(posX,posY,ileWejsc,1);
    }
    else if(ui->typCzlonu->currentText()=="Stock"){
        blok=new CStock(ileWejsc,ileWyjsc,wartosc);
        kolejny=new CBlok(posX,posY,ileWejsc,ileWyjsc);
    }
    else if(ui->typCzlonu->currentText()=="Stała"){
        blok=new CStala(wartosc);
        kolejny=new CBlok(posX,posY,0,1);
    }
    else if(ui->typCzlonu->currentText()=="Źródło Sinusoidalne"){
        blok=new CZrodloSinusoidalne();
        kolejny=new CBlok(posX,posY,0,1);

    }
    blok->setWartoscCzlon(blok,wartosc);
    treeItem->setText(1,QString::fromStdString(napis));
    kolejny->setTitle(napis);
    kolejny->setWartoscDisp(wartosc);
    kolejny->setID(ileBlokow);
    czlony.push_back(blok);
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
    //std::cout<<"ETAP2"<<std::endl;
    czlony.at(idIn-1)->dodajPolaczenie(czlony.at(idOut-1),czlony.at(idIn-1),nrWe,nrWy);
    //std::cout<<"ETAP3"<<std::endl;
    pocz->dodajLinia(&*line,true,nrWy);
    kon->dodajLinia(&*line,false,nrWe);
    scene->addItem(line);
    //std::cout<<"ETAP4"<<std::endl;
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
    czlony.at(idCzlonu-1)->setTypPolaczenia(idWejscia,s);
}

void MainWindow::on_dodajPolaczenie_3_clicked()
{
    //EDYTUJ TYP WYJSCIA
    int idCzlonu=ui->idWyjsciaEdycja->text().toInt();
    std::string s=ui->typWyjscia->currentText().toStdString();
    czlony.at(idCzlonu-1)->setTypWyjscia(s);
}
