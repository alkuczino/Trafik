#include "Config.h"

Config::Config()
{
}

Config::Config(Map * map,Simulator * simulator){

	for (int i = -1; i < 1; ++i) {
		for (int j = 0; j < 10; ++j) {
			Road* tmpRoad = new Road(simulator->width()/2 + i*80, j*100);
			map->addNotMoving(*tmpRoad);
			simulator->getScene()->addItem(tmpRoad);
			
		}
	}
	
	Car* tmpCar = new Car(simulator->width() / 2 - 80,simulator->height(),0,-5);
	map->addMoving(*tmpCar);
	simulator->getScene()->addItem(tmpCar);
	
	Car* tmpCar2 = new Car(simulator->width() / 2, 0, 0, 5);
	map->addMoving(*tmpCar2);
	simulator->getScene()->addItem(tmpCar2);
	
	
	
}
