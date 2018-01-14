#include "Simulator.h"

Simulator::Simulator()
{
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

QGraphicsScene * Simulator::getScene()
{
	return scene_;
}
