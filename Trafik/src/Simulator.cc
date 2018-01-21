#include "Simulator.h"

Simulator::Simulator()
{
	isCarClicked_ = false;
	isCameraClicked_ = false;
	isRemoveClicked_ = false;
	isRoadClicked_ = false;
	isJunctionClicked_ = false;
	scene_ = new QGraphicsScene;
	map_ = new Map;
	tmpCar_ = new Car;
	tmpRoad_ = new Road;
	tmpPavement_ = new Pavement;

	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(RES_X, RES_Y);
	
	setFixedSize(RES_X, RES_Y);
	setScene(scene_);
	scene_->setSceneRect(0, 0, RES_X*4, RES_Y*4);
	
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


void Simulator::setJunctionClicked(bool boolean)
{
	isJunctionClicked_ = boolean;
}

QGraphicsScene * Simulator::getScene()
{
	return scene_;
}

void Simulator::mouseReleaseEvent(QMouseEvent * event)
{
	if (isCarClicked_) {
		setCarClicked(false);
		item_ = scene_->itemAt(event->pos(), this->transform());
		

		if (tmpRoad_ = qgraphicsitem_cast<Road *>(item_))
		{
			if (event->x() - tmpRoad_->x() > ROAD_WIDTH / 2) {
				tmpCar_ = new Car(tmpRoad_->x() + ROAD_WIDTH/2, tmpRoad_->y(), 2, 2);
				getScene()->addItem(tmpCar_);
			}
			else
			{
				tmpCar_ = new Car(tmpRoad_->x(), tmpRoad_->y(), 2, 2);
				getScene()->addItem(tmpCar_);
			}
		}
	}
	else if (isRoadClicked_) {
		setRoadClicked(false);
		item_ = scene_->itemAt(mapFromScene(event->pos()), this->transform());

		if (tmpGrass_ = qgraphicsitem_cast<Grass *>(item_)) {
			for (int i = 0; i < 4; i++) {
				tmpRoad_ = new Road(mapFromScene(tmpGrass_->pos()).x() + GRASS_WIDTH / 4, mapFromScene(tmpGrass_->pos()).y() +i*ROAD_HEIGHT);
				getScene()->addItem(tmpRoad_);
				tmpPavement_ = new Pavement(tmpRoad_->x() - ROAD_WIDTH / 2, tmpRoad_->y());
				getScene()->addItem(tmpPavement_);
				tmpPavement_ = new Pavement(tmpRoad_->x() + ROAD_WIDTH, tmpRoad_->y());
				getScene()->addItem(tmpPavement_);
			}
		}
	}
	else if (isJunctionClicked_) {
		setJunctionClicked(false);
		item_ = scene_->itemAt(event->pos(), this->transform());

		if (tmpGrass_ = qgraphicsitem_cast<Grass *>(item_)) {
			tmpJunction_ = new Junction(tmpGrass_->x(),tmpGrass_->y());
			getScene()->addItem(tmpJunction_);
		}
	}
}

