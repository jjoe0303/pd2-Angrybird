#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(960,540);
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QPixmap(":/bgg")));
    scene->setSceneRect(0,0,960,540);
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.2,32,2.2,QPixmap(":/land.jpg").scaled(width(),height()/6.0),world,scene));
 //   itemList.push_back(new Land(16,1.6,32,3.3,QPixmap(":/land.jpg").scaled(960,101),world,scene));

    // Create bird (You can edit here)
    Bird *birdie = new Bird(0.0f,10.0f,0.7f,&timer,QPixmap(":/bird.png").scaled(46,46),world,scene);
    // Setting the Velocity
    birdie->setLinearVelocity(b2Vec2(10,0));
    itemList.push_back(birdie);


    // Create pig (You can edit here)
    Pig *piggy = new Pig(20.0f,6.0f,0.7f,&timer,QPixmap(":/pig.png").scaled(46,46),world,scene);
    // Setting the Velocity
    piggy->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(piggy);

    // Create pig (You can edit here)
   /* Pig *piggy2 = new Pig(12.0f,6.0f,0.25f,&timer,QPixmap(":/pig.png").scaled(46,46),world,scene);
    // Setting the Velocity
    piggy2->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(piggy2);
*/


    // Create wood (You can edit here)
    Wood *woody = new Wood(18.0f,6.0f,0.7f,2.8f,&timer,QPixmap(":/wood").scaled(21,83),world,scene);
    // Setting the Velocity
    woody->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(woody);

    // Create wood (You can edit here)
    Wood *woody2 = new Wood(22.4f,6.0f,0.7f,2.8f,&timer,QPixmap(":/wood").scaled(21,83),world,scene);
    // Setting the Velocity
    woody2->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(woody2);

    Wood *woody3 = new Wood(20.5f,8.0f,5.6f,0.7f,&timer,QPixmap(":/wood2").scaled(170,22),world,scene);
    // Setting the Velocity
    woody3->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(woody3);

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);

    Button *quitbutton = new Button();
    quitbutton->setPos(880,10);
    quitbutton->setPixmap(QPixmap(":/quitbutton"));
    connect(quitbutton,SIGNAL(clicked()),this,SLOT(quitslot()));
    scene->addItem(quitbutton);

    Button *rebutton = new Button();
    rebutton->setPos(820,12);
    rebutton->setPixmap(QPixmap(":/rebutton"));
    connect(rebutton,SIGNAL(clicked()),this,SLOT(reslot()));
    scene->addItem(rebutton);
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        /* TODO : add your code here */
        std::cout << "Press !" << std::endl ;
    }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
        std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        /* TODO : add your code here */
        std::cout << "Release !" << std::endl ;
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::quitslot()
{
    delete ui;
    close();
}

void MainWindow::reslot()
{
    hide();
    MainWindow::show();
}


void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}

