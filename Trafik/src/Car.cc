#include "Car.h"


Car::Car():timer_(new QTimer)
{	
	
	setPixmap(QPixmap("resources/car.png"));
	
	setPos(300, 0);
		//setRect(0, 0, 100, 100);
		
		connect(timer_, SIGNAL(timeout()), this, SLOT(move()));
		timer_->start(25);
	}

Car::Car(int x, int y, int velX, int velY):timer_(new QTimer),velX_(velX),velY_(velY) {
	setPixmap(QPixmap("resources/car.png"));
	setPos(x, y);
	
	//setRect(x, y, 100, 100);
	connect(timer_, SIGNAL(timeout()), this, SLOT(move()));
	timer_->start(25);
	

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
	setPos(x()+ velX_, y() + velY_);
	if (velY_<0&&pos().y() < 0-y()-this->pixmap().height()) {
		velX_ = 0;
		velY_ = 0;
	}
	else if (velY_>0&&pos().y()>700)
	{
		velX_ = 0;
		velY_ = 0;
	}
	
}