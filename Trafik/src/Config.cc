#include "Config.h"

Config::Config()
{
}

Config::Config(Map * map, Simulator * simulator)
{
	Road* tmp = new Road(0, 0);
	map->addNotMoving(*tmp);
	simulator->scene()->addItem(map->getNotMoving()[1]);
	
}
