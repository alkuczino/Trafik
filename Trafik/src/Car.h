#pragma once
#include "Moving.h"
#include "Map.h"
#include <QGraphicsScene>
const int CAR_WIDTH = 40, CAR_HEIGHT = 50;

class Car :public QObject, public Moving {
Q_OBJECT
public:
	Car();
	Car(int x, int y, int velX,int velY);
public slots:
	void move();
	void turnLeft();
	void turnRight();
private:
	QTimer * timer_;
	int velX_, velY_;
};