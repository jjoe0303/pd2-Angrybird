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
    itemList.push_back(new Land(16,20,32,2.2,QPixmap("").scaled(width(),height()/6.0),world,scene));
 //   itemList.push_back(new Land(16,1.6,32,3.3,QPixmap(":/land.jpg").scaled(960,101),world,scene));

    // Create bird (You can edit here)
 /*   birdie = new Bird(4.5f,7.0f,0.7f,&timer,QPixmap(":/bird.png").scaled(46,46),world,scene);
    // Setting the Velocity
    birdie->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(birdie);
*/

    // Create pig (You can edit here)
    piggy = new Pig(20.5f,6.0f,0.7f,&timer,QPixmap(":/pig.png").scaled(46,46),world,scene);
    // Setting the Velocity
    piggy->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(piggy);

 /*   piggy2 = new Pig(12.5f,6.0f,0.7f,&timer,QPixmap(":/pig.png").scaled(46,46),world,scene);
    // Setting the Velocity
    piggy2->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(piggy2);
*/
    // Create pig (You can edit here)
   /* Pig *piggy2 = new Pig(12.0f,6.0f,0.25f,&timer,QPixmap(":/pig.png").scaled(46,46),world,scene);
    // Setting the Velocity
    piggy2->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(piggy2);
*/


    // Create wood (You can edit here)
    Wood *woody = new Wood(18.4f,6.0f,0.7f,2.8f,&timer,QPixmap(":/wood").scaled(21,83),world,scene);
    // Setting the Velocity
    woody->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(woody);

    // Create wood (You can edit here)
    Wood *woody2 = new Wood(22.4f,6.0f,0.7f,2.8f,&timer,QPixmap(":/wood").scaled(21,83),world,scene);
    // Setting the Velocity
    woody2->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(woody2);

    Wood *woody3 = new Wood(20.5f,8.0f,5.6f,0.6f,&timer,QPixmap(":/wood2").scaled(170,22),world,scene);
    // Setting the Velocity
    woody3->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(woody3);

  /*  Wood *woody4 = new Wood(10.4f,6.0f,0.7f,2.8f,&timer,QPixmap(":/wood").scaled(21,83),world,scene);
    // Setting the Velocity
    woody4->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(woody4);

    // Create wood (You can edit here)
    Wood *woody5 = new Wood(14.4f,6.0f,0.7f,2.8f,&timer,QPixmap(":/wood").scaled(21,83),world,scene);
    // Setting the Velocity
    woody5->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(woody5);

    Wood *woody6 = new Wood(12.5f,8.0f,5.6f,0.6f,&timer,QPixmap(":/wood2").scaled(170,22),world,scene);
    // Setting the Velocity
    woody6->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(woody6);
*/
    Land *hall = new Land(32.0,3.4,0.05,36.0,QPixmap().scaled(5,540),world,scene);
    // Setting the Velocity
   // sling2->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(hall);

    Land *hall2 = new Land(0.0,3.4,0.05,36.0,QPixmap().scaled(5,540),world,scene);
    // Setting the Velocity
   // sling2->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(hall2);

    QGraphicsPixmapItem * sling= new QGraphicsPixmapItem();
    sling->setPixmap(QPixmap(":/sling"));
    sling->setPos(50,290);
    scene->addItem(sling);
    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(&timer2,SIGNAL(timeout()),this,SLOT(vanish()));
    connect(&timer3,SIGNAL(timeout()),this,SLOT(bye()));
   // connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
    timer2.start(1000);
    timer3.start(15);

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

   // connect(birdie,SIGNAL(clicked()),this,SLOT(haha()));
 //   std::cout<<birdie->getLinearVelocity().x<<std::endl;
/*if(tmp==1){
      if(birdie->getLinearVelocity()==b2Vec2(0.0,0.0)){
     //     delete birdie;
          std::cout<<"haha"<<std::endl;
          tmp=0;
      }
    }*/

}
bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    QMouseEvent *e = static_cast<QMouseEvent *>(event);
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        // TODO : add your code here
      //  std::cout << "Press !" << std::endl ;
    /*    if(e->pos().x()>200){
            return true;
        }
*/
        if(tmp==1){
           //    std::cout<<"haha"<<std::endl;
           // std::cout<<"pig x"<<piggy->getpos().x<<std::endl;
           // std::cout<<"pig y"<<piggy->getpos().y<<std::endl;
           // std::cout<<"bird x"<<birdie->getpos().x<<std::endl;
           // std::cout<<"bird y"<<birdie->getpos().y<<std::endl;
               birdie->special();
             //  std::cout<<birdie->sp<<std::endl;
                if(birdie->sp==1){
                    // std::cout<<"haha"<<std::endl;
                     blackk=new Black(birdie->getpos().x,birdie->getpos().y,1.4f,&timer,QPixmap(":/black2").scaled(92,92),world,scene);
                     blackk->setLinearVelocity(b2Vec2(birdie->getLinearVelocity().x,birdie->getLinearVelocity().y));
                     itemList.push_back(blackk);
                     delete birdie;
                     insp=1;
                }
                if(birdie->sp==2){
                    blue2=new Blue(birdie->getpos().x,birdie->getpos().y,0.7f,&timer,QPixmap(":/blue").scaled(46,46),world,scene);
                    blue3=new Blue(birdie->getpos().x,birdie->getpos().y,0.7f,&timer,QPixmap(":/blue").scaled(46,46),world,scene);
                    blue2->setLinearVelocity(b2Vec2(birdie->getLinearVelocity().x,birdie->getLinearVelocity().y-0.1));
                    blue3->setLinearVelocity(b2Vec2(birdie->getLinearVelocity().x,birdie->getLinearVelocity().y+0.1));
                    insp=2;
                }

        }

        if(tmp==0){
        world->SetGravity(b2Vec2(0.0f, 0.0f));
       }
        if(count%4==0 && tmp==0){
        birdie = new Bird(4.5f,7.0f,0.7f,&timer,QPixmap(":/bird.png").scaled(46,46),world,scene);
        // Setting the Velocity
        birdie->setLinearVelocity(b2Vec2(0,0));
        itemList.push_back(birdie);
        count++;
        return true;
       }
       if(count%4==1 &&tmp==0){
        birdie = new Yellow(4.5f,7.0f,0.7f,&timer,QPixmap(":/yellow").scaled(46,46),world,scene);
        // Setting the Velocity
        birdie->setLinearVelocity(b2Vec2(0,0));
        itemList.push_back(birdie);
        count++;
        return true;
        }
        if(count%4==2 && tmp==0){
        birdie = new Black(4.5f,7.0f,0.7f,&timer,QPixmap(":/black").scaled(46,46),world,scene);
        // Setting the Velocity
        birdie->setLinearVelocity(b2Vec2(0,0));
        itemList.push_back(birdie);
        count++;
        return true;
        }
        if(count%4==3 &&tmp==0){
         birdie = new Blue(4.5f,7.0f,0.7f,&timer,QPixmap(":/blue").scaled(46,46),world,scene);
         // Setting the Velocity
         birdie->setLinearVelocity(b2Vec2(0,0));
         itemList.push_back(birdie);
         count++;
         return true;
         }
     return true;
    }
    if(event->type() == QEvent::MouseMove)
    {
        // TODO : add your code here
       // std::cout << "Move !" << std::endl ;
      //  QMouseEvent *e = static_cast<QMouseEvent *>(event);
        //x origin is 148
        //y origin is 338
        //std::cout << e->x() << std::endl ;
        // std::cout << e->y() << std::endl ;
       // birdie->
     /* if(tmp==1){
        if(birdie->getLinearVelocity()==b2Vec2(0,0)){
            delete birdie;
            tmp=0;
        }
      }*/
//prototype
 /*     if(tmp==1 && insp==0){
        if(birdie->getLinearVelocity()==b2Vec2(0,0)&& e->x()<200){
              delete birdie;
              tmp=0;
              return true;
          }
       }

      if(tmp==1 && insp==1){
          if(blackk->getLinearVelocity()==b2Vec2(0,0)&& e->x()<200){
                delete blackk;
                insp=0;
                tmp=0;
            }
      }

      if(tmp==1 && insp==2){
          if(blue2->getLinearVelocity()==b2Vec2(0,0)&&blue3->getLinearVelocity()==b2Vec2(0,0)&&birdie->getLinearVelocity()==b2Vec2(0,0)&& e->x()<200){
              delete birdie;
              delete blue2;
              delete blue3;
              insp=0;
              tmp=0;
          }
      }*/
        return true;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        // TODO : add your code here
       // std::cout << "Release !" << std::endl ;
        world->SetGravity(b2Vec2(0.0f, -9.8f));
        if(tmp==0){
             birdie->setLinearVelocity(b2Vec2(-(e->x()-148)/6,(e->y()-338)/6));
             tmp++;
        }
        return true;
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
    close();
}

void MainWindow::reslot()
{
    hide();
    MainWindow::show();
}


void MainWindow::vanish()
{
   // std::cout<<piggy->getLinearVelocity().x<<std::endl;
    if(piggy->getLinearVelocity().x>0.2 || piggy->getLinearVelocity().x<(-0.2)){
        piggy->health--;
       // std::cout<<piggy->health<<std::endl;
        if(piggy->health==0){
            delete piggy;
            timer2.stop();
        }
    }
}

void MainWindow::bye()
{

    if(tmp==1 && insp==0){
      if(birdie->getLinearVelocity()==b2Vec2(0,0)){
            delete birdie;
            tmp=0;
            return;
        }
     }

    if(tmp==1 && insp==1){
        if(blackk->getLinearVelocity()==b2Vec2(0,0)){
              delete blackk;
              insp=0;
              tmp=0;
              return;
          }
    }

    if(tmp==1 && insp==2){
        if(blue2->getLinearVelocity()==b2Vec2(0,0)&&blue3->getLinearVelocity()==b2Vec2(0,0)&&birdie->getLinearVelocity()==b2Vec2(0,0)){
            delete birdie;
            delete blue2;
            delete blue3;
            insp=0;
            tmp=0;
            return;
        }
    }
}


void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}

