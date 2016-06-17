#ifndef YELLOW_H
#define YELLOW_H

#include "bird.h"
#include "gameitem.h"
#include <gameitem.h>

#define YELLOW_DENSITY 10.0f
#define YELLOW_FRICTION 0.2f
#define YELLOW_RESTITUTION 0.5f

class Yellow:public Bird
{
public:
    Yellow(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // YELLOW_H
