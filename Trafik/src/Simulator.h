#pragma once
#include <QGraphicsScene>
#include "Map.h"
#include <QGraphicsView>
#include <memory>
#include "Car.h"
#include "Road.h"
#include "Config.h"
#define RES_X 1024
#define RES_Y 768

class Simulator : public QGraphicsView {
public:
	Simulator();
	void loadConfig();
private:
	QGraphicsScene * scene_;
	Map* map_;
	class Config* config_;

};