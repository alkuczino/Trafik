#pragma once
#include <QGraphicsScene>
#include "Map.h"
#include <QGraphicsView>
#include <memory>
#include "Car.h"
#include "Road.h"
#include "Config.h"
const int RES_X = 1000;
const int RES_Y = 800;

class Simulator : public QGraphicsView {
public:
	Simulator();

	void loadConfig();

	QGraphicsScene* getScene();
private:
	QGraphicsScene * scene_;
	Map* map_;
	class Config* config_;

};