#pragma once
#include "NotMoving.h"
#include <QList>
const int ROAD_WIDTH = 40, ROAD_HEIGHT = 50;

class Road : public NotMoving {
public:
	Road();
	Road(int x, int y);
	void mouseReleaseEvent(QMouseEvent* event);
private:
	
	
};