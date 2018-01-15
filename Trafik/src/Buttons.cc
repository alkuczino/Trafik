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
	carButton_ = new QPushButton("CAR", &editor);
	carButton_->move(80, 0);
	connect(carButton_, SIGNAL(clicked()), &editor, SLOT(carClicked()));
}

void Buttons::addCameraButton(Editor& editor)
{
}

void Buttons::removeButton(Editor& editor)
{

}

void Buttons::addRoadButton(Editor& editor) {
	roadButton_ = new QPushButton("ROAD", &editor);
	roadButton_->move(160, 0);
	connect(roadButton_, SIGNAL(clicked()), &editor, SLOT(roadClicked()));
}

/*void Buttons::startClicked() {
	Simulator* simulator = new Simulator;
	simulator->loadConfig();
	simulator->show();
}*/