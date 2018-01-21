#include "Config.h"

Config::Config()
{
}

Config::Config(Map * map,Simulator * simulator){


	for (int i = 0; i < simulator->getScene()->width() / GRASS_WIDTH; i++) {
		for (int k = 0; k < simulator->getScene()->height() / GRASS_HEIGHT; k++) {
			Grass * tmpGrass = new Grass(i*GRASS_WIDTH, k*GRASS_HEIGHT);
			simulator->getScene()->addItem(tmpGrass);
		}
		}
	
		for (int j = 0; j < 20; ++j) {
			Road* tmpRoad = new Road(simulator->width()/2-ROAD_WIDTH*1.5, j*ROAD_HEIGHT);
			simulator->getScene()->addItem(tmpRoad);
			Pavement* tmpPavement = new Pavement(tmpRoad->x() - ROAD_WIDTH / 2, tmpRoad->y());
			simulator->getScene()->addItem(tmpPavement);
			tmpPavement = new Pavement(tmpRoad->x() + ROAD_WIDTH, tmpRoad->y());
			simulator->getScene()->addItem(tmpPavement);
			//map->addNotMoving(*tmpRoad);
			
			
		}


		
		
	
	
	
	Car* tmpCar = new Car(simulator->width() / 2 - ROAD_WIDTH,simulator->height(),2,2);
	//map->addMoving(*tmpCar);
	simulator->getScene()->addItem(tmpCar);
	
	Car* tmpCar2 = new Car(simulator->width() / 2 - ROAD_WIDTH/2, 0, 2, 2);
	//map->addMoving(*tmpCar2);
	simulator->getScene()->addItem(tmpCar2);
	
	
	
}
