#pragma once

#include <vector>
#include <memory>
#include "Moving.h"
#include "NotMoving.h"

class Map {
public:
	Map();
	void addMoving(Moving& moving);
	void addNotMoving(NotMoving& notMoving);
	std::vector<Moving*> getMoving();
	std::vector<NotMoving*> getNotMoving();
private:
	std::vector <Moving*> moving_;
	std::vector <NotMoving*> notMoving_;


};