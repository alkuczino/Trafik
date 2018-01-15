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

};