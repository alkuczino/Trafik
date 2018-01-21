#include "Car.h"


Car::Car():timer_(new QTimer)
{	
	point_index_ = 0;
	setPixmap(QPixmap("resources/car.png"));
	
	setPos(300, 0);
	setZValue(1);
		connect(timer_, SIGNAL(timeout()), this, SLOT(move()));
		timer_->start(25);
	}

Car::Car(int x, int y, int velX, int velY):point_index_(0),timer_(new QTimer),velX_(velX),velY_(velY) {
	setPixmap(QPixmap("resources/car.png"));
	setPos(x, y);
	points_ <<QPointF(1000, 200)<<QPointF(800, 700);
	dest_ = points_[0];
	
	rotateToPoint(dest_);
	setZValue(1);
	
	connect(timer_, SIGNAL(timeout()), this, SLOT(move()));
	timer_->start(25);
	

}

//void Car::move() {
//	setPos(x()+ velX_, y() + velY_);
//	const qreal angle = 90;
//	
//		//turnLeft();
//	
//	if (velY_<0&&pos().y() < 0-y()-this->pixmap().height()) {
//		velX_ = 0;
//		velY_ = 0;
//	}
//	else if (velY_>0&&pos().y()>700)
//	{
//		velX_ = 0;
//		velY_ = 0;
//	}
//	
//}

void Car::turnLeft() {
	setPos(x() - 2, y() - 2);
	qreal angle = 1;
	if(this->rotation() - static_cast<qreal>(90) != 0)
	setRotation(this->rotation() - angle);
	
	
}

void Car::turnRight() {

}

int Car::type() const {
	return Type;
}

void Car::rotateToPoint(QPointF p) {
	QLineF ln(pos(), p);
	setRotation(-1*ln.angle());
}

void Car::move() {
	// if close to est, rotate to next dest
	QLineF ln(pos(), dest_);
	if (ln.length() < 5) {
		point_index_++;
		if (point_index_ >= points_.size()) {
			return;
		}
		dest_ = points_[point_index_];
		rotateToPoint(dest_);
	}
	qreal theta = rotation(); // degrees

	double dy = velX_ * qSin(qDegreesToRadians(theta));
	double dx = velY_ * qCos(qDegreesToRadians(theta));

	setPos(x() + dx, y() + dy);

}