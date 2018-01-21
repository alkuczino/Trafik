#include "RoadVertical.h"

RoadVertical::RoadVertical()
{
	setPixmap(QPixmap("resources/roadVertical.png"));
}

RoadVertical::RoadVertical(int x, int y)
{
	setPixmap(QPixmap("resources/roadVertical.png"));
	setPos(x, y);
}

void RoadVertical::mouseReleaseEvent(QMouseEvent * event)
{

}

int RoadVertical::type() const
{
	return Type;
}

