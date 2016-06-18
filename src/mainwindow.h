#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <pig.h>
#include <button.h>
#include <wood.h>
#include <yellow.h>
#include <black.h>
#include <blue.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
    void quitslot();
    void reslot();
    void haha();
    void vanish();
    void bye();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    QTimer timer2;
    QTimer timer3;
    Bird *birdie;
    Pig * piggy;
    Pig * piggy2;
    Bird *blackk;
    Bird *blue2;
    Bird *blue3;
    b2Vec2 * velocity;
    int count=0;
    int tmp=0;
    int insp=0;
    int inpig=0;
};

#endif // MAINWINDOW_H
