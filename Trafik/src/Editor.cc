#include "Editor.h"

void Editor::addButtons() {
	buttons_->addStartButton(*this);
	buttons_->addCarButton(*this);
	buttons_->addRoadButton(*this);
}

Editor::Editor() {
	running_ = false;
	scene_ = new QGraphicsScene;
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(EDITOR_X, EDITOR_Y);
	setScene(scene_);
	scene_->setSceneRect(300, 0, EDITOR_X, EDITOR_Y);
	buttons_ = new Buttons();
	addButtons();

	

	setWindowTitle("Edytor");
}

void Editor::startClicked() {
	if (!running_) {
		running_ = true;
		simulator_ = new Simulator;
		simulator_->loadConfig();
		simulator_->show();
	}
}

void Editor::carClicked(){
	simulator_->setCarClicked(true);

	}

void Editor::roadClicked() {
	simulator_->setRoadClicked(true);
}

QGraphicsScene* Editor::getScene()
{
	return scene_;
}
