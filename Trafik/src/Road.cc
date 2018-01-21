#include "Road.h"

Road::Road()
{
	setPixmap(QPixmap("resources/road.png"));	
}

Road::Road(int x, int y)
{
	setPixmap(QPixmap("resources/road.png"));
	setPos(x, y);

}


void Road::mouseReleaseEvent(QMouseEvent * event)
{

}

int Road::type() const
{
	return Type;
}
