#pragma once
#include "Moving.h"
#include "Map.h"
#include <QGraphicsScene>

class Car :public QObject, public Moving {
Q_OBJECT
public:
	Car();
	Car(int x, int y, int velX,int velY);
	//void keyPressEvent(QKeyEvent *event);
public slots:
	void move();
private:
	QTimer * timer_;
	int velX_, velY_;
};