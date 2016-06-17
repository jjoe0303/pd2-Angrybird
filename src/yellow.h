#ifndef YELLOW_H
#define YELLOW_H

#include "bird.h"

class Yellow:public Bird
{
public:
    Yellow(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // YELLOW_H
