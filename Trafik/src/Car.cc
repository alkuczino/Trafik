#include "Car.h"


Car::Car():timer_(new QTimer)
{	
	
	setPixmap(QPixmap("resources/car.png"));
	
	setPos(300, 0);
		
		connect(timer_, SIGNAL(timeout()), this, SLOT(move()));
		timer_->start(25);
	}

Car::Car(int x, int y, int velX, int velY):timer_(new QTimer),velX_(velX),velY_(velY) {
	setPixmap(QPixmap("resources/car.png"));
	setPos(x, y);
	
	connect(timer_, SIGNAL(timeout()), this, SLOT(move()));
	timer_->start(25);
	

}

void Car::move() {
	setPos(x()+ velX_, y() + velY_);
	const qreal angle = 90;
	
		turnLeft();
	
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

void Car::turnLeft() {
	setPos(x() - 2, y() - 2);
	qreal angle = 1;
	if(this->rotation() - static_cast<qreal>(90) != 0)
	setRotation(this->rotation() - angle);
	
	
}

void Car::turnRight() {

}
