#include "Simulator.h"

Simulator::Simulator()
{
	isCarClicked_ = false;
	isCameraClicked_ = false;
	isRemoveClicked_ = false;
	isRoadClicked_ = false;
	scene_ = new QGraphicsScene;
	map_ = new Map;

	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(RES_X, RES_Y);
	setScene(scene_);
	scene_->setSceneRect(0, 0, RES_X, RES_Y);
	
	setWindowTitle("Symulator");
}

void Simulator::loadConfig()
{
	config_ = new Config(map_, this);
}

void Simulator::setCarClicked(bool boolean)
{
	isCarClicked_ = boolean;
}

void Simulator::setRemoveClicked(bool boolean)
{
	isRemoveClicked_ = boolean;
}

void Simulator::setCameraClicked(bool boolean)
{
	isCameraClicked_ = boolean;
}

void Simulator::setRoadClicked(bool boolean)
{
	isRoadClicked_ = boolean;
}


QGraphicsScene * Simulator::getScene()
{
	return scene_;
}

void Simulator::mouseReleaseEvent(QMouseEvent * event)
{
	if (isCarClicked_) {
		setCarClicked(false);
		Car* tmpCar = new Car(event->x() - CAR_WIDTH/2,event->y() - CAR_HEIGHT/2, 0, 0);
		getScene()->addItem(tmpCar);
	}
	else if (isRoadClicked_) {
		setRoadClicked(false);
		Road* tmpRoad = new Road(event->x() - ROAD_WIDTH/2, event->y() - ROAD_HEIGHT/2);
		getScene()->addItem(tmpRoad);
	}
}

