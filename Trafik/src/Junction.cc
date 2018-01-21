#include "Junction.h"

Junction::Junction()
{
}

Junction::Junction(int x, int y)
{
	setPixmap(QPixmap("resources/junction.png"));
	setPos(x, y);
}
