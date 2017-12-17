#pragma once
#include "Moving.h"
#include "Map.h"
#include <QGraphicsScene>

class Car :public QObject, public Moving {
Q_OBJECT
public:
	Car();
	Car(int x, int y);
	//void keyPressEvent(QKeyEvent *event);
public slots:
	void move();
private:
	QTimer * timer_;
};