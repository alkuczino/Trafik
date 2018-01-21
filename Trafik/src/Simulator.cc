#include "Simulator.h"

Simulator::Simulator()
{
	isCarClicked_ = false;
	isCameraClicked_ = false;
	isRemoveClicked_ = false;
	isRoadClicked_ = false;
	isJunctionClicked_ = false;
	isRoadVerticalClicked_ = false;
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

void Simulator::setRoadVerticalClicked(bool boolean)
{
	isRoadVerticalClicked_ = boolean;
}

void Simulator::addJunctionToMap(int x, int y)
{

	map_->addArrayItem(x / 40 - 1, y / 40, PAVEMENT);
	map_->addArrayItem(x / 40, y / 40, ROAD_LEFT);
	map_->addArrayItem(x / 40 + 1, y / 40, ROAD_RIGHT);
	map_->addArrayItem(x / 40 + 2, y / 40, PAVEMENT);

	map_->addArrayItem(x / 40 - 1, y / 40 + 1, ROAD_LEFT);
	map_->addArrayItem(x / 40, y / 40 + 1, ROAD_LEFT);
	map_->addArrayItem(x / 40 + 1, y / 40 + 1, ROAD_RIGHT);
	map_->addArrayItem(x / 40 + 2, y / 40 + 1, ROAD_LEFT);

	map_->addArrayItem(x / 40 - 1, y / 40 + 2, ROAD_RIGHT);
	map_->addArrayItem(x / 40, y / 40 + 2, ROAD_LEFT);
	map_->addArrayItem(x / 40 + 1, y / 40 + 2, ROAD_RIGHT);
	map_->addArrayItem(x / 40 + 2, y / 40 + 2, ROAD_RIGHT);

	map_->addArrayItem(x / 40 - 1, y / 40 + 3, PAVEMENT);
	map_->addArrayItem(x / 40, y / 40 + 3, ROAD_LEFT);
	map_->addArrayItem(x / 40 + 1, y / 40 + 3, ROAD_RIGHT);
	map_->addArrayItem(x / 40 + 2, y / 40 + 3, PAVEMENT);





}

void Simulator::addRoadToMap(int x, int y)
{
	map_->addArrayItem(x / 40 - 2, y / 40, PAVEMENT);
	map_->addArrayItem(x / 40 - 1, y / 40, ROAD_LEFT);
	map_->addArrayItem(x / 40, y / 40, ROAD_RIGHT);
	map_->addArrayItem(x / 40 + 1, y / 40, PAVEMENT);
}

void Simulator::addPavementToMap(int x, int y)
{
}

void Simulator::addGrassToMap(int x, int y)
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			map_->addArrayItem(x / 40 + i, y / 40 + j, GRASS);
		}
	}
	
}

void Simulator::addRoadVerticalToMap(int x, int y)
{
	map_->addArrayItem(x / 40 - 1, y / 40 - 1, PAVEMENT);
	map_->addArrayItem(x / 40 - 1, y / 40, ROAD_LEFT);
	map_->addArrayItem(x / 40 - 1, y / 40 + 1, ROAD_RIGHT);
	map_->addArrayItem(x / 40 - 1, y / 40 + 2, PAVEMENT);
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
	if (event->button()==Qt::LeftButton) {
		if (isCarClicked_) {
			setCarClicked(false);
			item_ = scene_->itemAt(event->pos(), this->transform());


			if (tmpRoad_ = qgraphicsitem_cast<Road *>(item_))
			{
				if (event->x() - tmpRoad_->x() > ROAD_WIDTH / 2) {
					tmpCar_ = new Car(tmpRoad_->x() + ROAD_WIDTH / 2, tmpRoad_->y(), 2, 2);
					getScene()->addItem(tmpCar_);
				}
				else
				{
					tmpCar_ = new Car(tmpRoad_->x(), tmpRoad_->y(), 2, 2);
					getScene()->addItem(tmpCar_);
				}
			}
		}

		else if (isRoadVerticalClicked_) {
			setRoadVerticalClicked(false);
			item_ = scene_->itemAt(mapFromScene(event->pos()), this->transform());

			if (tmpGrass_ = qgraphicsitem_cast<Grass *>(item_)) {
				for (int i = 0; i < 4; i++) {
					tmpRoadVertical_ = new RoadVertical(mapFromScene(tmpGrass_->pos()).x() + i * ROAD_VERTICAL_WIDTH, mapFromScene(tmpGrass_->pos()).y() + GRASS_WIDTH / 4);
					getScene()->addItem(tmpRoadVertical_);
					tmpPavement_ = new Pavement(tmpRoadVertical_->x(), tmpRoadVertical_->y() - ROAD_VERTICAL_HEIGHT / 2);
					getScene()->addItem(tmpPavement_);
					tmpPavement_ = new Pavement(tmpRoadVertical_->x(), tmpRoadVertical_->y() + ROAD_VERTICAL_HEIGHT);
					getScene()->addItem(tmpPavement_);
					addRoadVerticalToMap(mapFromScene(tmpGrass_->pos()).x() + i * ROAD_VERTICAL_WIDTH, mapFromScene(tmpGrass_->pos()).y() + GRASS_WIDTH / 4);
				}
			}
		}

		else if (isRoadClicked_) {
			setRoadClicked(false);
			item_ = scene_->itemAt(mapFromScene(event->pos()), this->transform());

			if (tmpGrass_ = qgraphicsitem_cast<Grass *>(item_)) {
				for (int i = 0; i < 4; i++) {
					tmpRoad_ = new Road(mapFromScene(tmpGrass_->pos()).x() + GRASS_WIDTH / 4, mapFromScene(tmpGrass_->pos()).y() + i * ROAD_HEIGHT);
					getScene()->addItem(tmpRoad_);
					tmpPavement_ = new Pavement(tmpRoad_->x() - ROAD_WIDTH / 2, tmpRoad_->y());
					getScene()->addItem(tmpPavement_);
					tmpPavement_ = new Pavement(tmpRoad_->x() + ROAD_WIDTH, tmpRoad_->y());
					getScene()->addItem(tmpPavement_);
					addRoadToMap(mapFromScene(tmpGrass_->pos()).x() + GRASS_WIDTH / 4, mapFromScene(tmpGrass_->pos()).y() + i * ROAD_HEIGHT);
				}
			}
		}


		else if (isJunctionClicked_) {
			setJunctionClicked(false);
			item_ = scene_->itemAt(event->pos(), this->transform());

			if (tmpGrass_ = qgraphicsitem_cast<Grass *>(item_)) {
				tmpJunction_ = new Junction(tmpGrass_->x(), tmpGrass_->y());
				addJunctionToMap(mapFromScene(tmpJunction_->pos()).x(), mapFromScene(tmpJunction_->pos()).y());
				getScene()->addItem(tmpJunction_);
			}
		}
	}
	else if (event->button() == Qt::RightButton) {
		item_ = scene_->itemAt(event->pos(), this->transform());

		if (tmpRoad_ = qgraphicsitem_cast<Road *>(item_))
		{
			scene_->removeItem(tmpRoad_);

			delete tmpRoad_;
		}
		else if (tmpRoadVertical_ = qgraphicsitem_cast<RoadVertical *>(item_))
		{
			scene_->removeItem(tmpRoadVertical_);

			delete tmpRoadVertical_;
		}

		else if (tmpCar_ = qgraphicsitem_cast<Car *>(item_)) {
			scene_->removeItem(tmpCar_);
			delete tmpCar_;
		}

		else if (tmpJunction_ = qgraphicsitem_cast<Junction *>(item_)) {
			scene_->removeItem(tmpJunction_);
			delete tmpJunction_;
		}
		else if (tmpPavement_ = qgraphicsitem_cast<Pavement *>(item_)) {
			scene_->removeItem(tmpPavement_);
			delete tmpPavement_;
		}
	}
}
