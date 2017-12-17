#pragma once
#include <QGraphicsScene>
#include "Map.h"
#include <QGraphicsView>
#include <memory>
#include "Car.h"
#include "Road.h"


class Simulator : public QGraphicsView {
public:
	Simulator();
private:
	QGraphicsScene * scene_;
	Map* map_;


};