#include "Road.h"

Road::Road()
{
	setPixmap(QPixmap("resources/road.png"));
}

Road::Road(int x, int y, int w, int h)
{
	setPixmap(QPixmap("resources/road.png"));
	setPos(0, 500);
}