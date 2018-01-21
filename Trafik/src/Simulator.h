#pragma once
#include <QGraphicsScene>
#include "Map.h"
#include <QGraphicsView>
#include <memory>
#include <QGraphicsSceneMouseEvent>
#include "Car.h"
#include "Road.h"
#include "Pavement.h"
#include "Junction.h"
#include "Config.h"
#include "Grass.h"
#include "RoadVertical.h"

const int RES_X = 1280;
const int RES_Y = 960;
enum {GRASS, PAVEMENT, ROAD_LEFT, ROAD_RIGHT, JUNCTION};
class Config;

class Simulator : public QGraphicsView {
public:
	Simulator();

	void loadConfig();
	
	void setCarClicked(bool);
	void setRemoveClicked(bool);
	void setCameraClicked(bool);
	void setRoadClicked(bool);
	void setStartClicked(bool);
	bool getIsStartClicked();
	void setJunctionClicked(bool);
	void setRoadVerticalClicked(bool);
	void addJunctionToMap(int x,int y);
	void addRoadToMap(int x, int y);
	void addPavementToMap(int x, int y);
	void addGrassToMap(int x, int y);
	void addRoadVerticalToMap(int x, int y);
	QGraphicsScene* getScene();

	void mouseReleaseEvent(QMouseEvent* event);
private:
	QGraphicsScene * scene_;
	Map* map_;
	Config* config_;
	bool isCarClicked_;
	bool isRemoveClicked_;
	bool isCameraClicked_;
	bool isRoadClicked_;
	bool isJunctionClicked_;
	bool isRoadVerticalClicked_;
	QGraphicsItem* item_;
	Road* tmpRoad_;
	Pavement* tmpPavement_;
	Car* tmpCar_;
	Junction* tmpJunction_;
	Grass* tmpGrass_;
	RoadVertical* tmpRoadVertical_;
};