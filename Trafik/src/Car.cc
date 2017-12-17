#include "Car.h"


Car::Car():timer_(new QTimer)
{
		setRect(0, 0, 100, 100);
		
		connect(timer_, SIGNAL(timeout()), this, SLOT(move()));
		timer_->start(50);
	}

Car::Car(int x, int y):timer_(new QTimer) {
	setRect(x, y, 100, 100);
	connect(timer_, SIGNAL(timeout()), this, SLOT(move()));
	timer_->start(50);
	

}

/*void Car::keyPressEvent(QKeyEvent* event) {
	if (event->key() == Qt::Key_Left) {
		setPos(x()-10, y());
	}
	else if (event->key() == Qt::Key_Right) {
		setPos(x()+10, y());
	}
	else if (event->key() == Qt::Key_Up) {
		setPos(x(), y()-10);
	}
	else if (event->key() == Qt::Key_Down) {
		setPos(x(), y()+10);
	}
}*/

void Car::move() {
	setPos(x(), y() + 10);
	if (pos().y() < 0-y()-this->rect().height()) {
		scene()->removeItem(this);	
		delete this;
	}

}