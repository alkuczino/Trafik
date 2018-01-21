#pragma once
#include "Moving.h"
#include "Map.h"
#include <QGraphicsScene>
const int CAR_WIDTH = 40, CAR_HEIGHT = 40;

class Car :public QObject, public Moving {
Q_OBJECT
public:
	enum { Type = UserType + 2 };
	Car();
	Car(int x, int y, int velX,int velY);
	void rotateToPoint(QPointF p);

public slots:
	void move();
	void turnLeft();
	void turnRight();

private:
	QTimer * timer_;
	int velX_, velY_;
	int type() const;
	QList<QPointF> points_;
	QPointF dest_;
	int point_index_;
};