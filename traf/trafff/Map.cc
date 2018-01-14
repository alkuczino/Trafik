#include "Map.h"

Map::Map()
{
}

void Map::addMoving(Moving& moving)
{
	Moving* tmp = &moving;
	moving_.push_back(tmp);
}

std::vector<Moving*> Map::getMoving()
{
	return moving_;
}

void Map::addNotMoving(NotMoving& notMoving){
	NotMoving* tmp = &notMoving;
	notMoving_.push_back(tmp);
}

std::vector<NotMoving*> Map::getNotMoving()
{
	return notMoving_;
}
