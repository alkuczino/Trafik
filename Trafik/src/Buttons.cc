#include "Buttons.h"

Buttons::Buttons()
{
}

void Buttons::addStartButton(Editor& editor)
{
	startButton_ = new QPushButton("START", &editor);
	connect(startButton_, SIGNAL(clicked()), &editor, SLOT(startClicked()));
}

void Buttons::addCarButton(Editor& editor)
{
	addCar_ = new QPushButton("CAR", &editor);
}

void Buttons::addCameraButton(Editor& editor)
{
}

void Buttons::removeButton(Editor& editor)
{
}

/*void Buttons::startClicked() {
	Simulator* simulator = new Simulator;
	simulator->loadConfig();
	simulator->show();
}*/