#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CBlok.h"
#include <QGraphicsView>
#include "CCzlonCzynny.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QGraphicsScene *scene;
    QGraphicsView *view;
    void jedenKrokSymulacji();
    explicit MainWindow(QWidget *parent = 0);
    QGraphicsLineItem *rysujLinia(QPointF *punkt1, QPointF *punkt2);
    ~MainWindow();

private slots:

    void on_dodajCzlon_clicked();

    void on_dodajPolaczenie_clicked();

    void on_wykonajKrok_clicked();

    void on_startSymulacji_clicked();

    void on_dodajPolaczenie_2_clicked();

    void on_dodajPolaczenie_3_clicked();

private:
    int ileBlokow;
    std::vector<CCzlonCzynny*> czlony;
    std::vector<CBlok*> bloki;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
