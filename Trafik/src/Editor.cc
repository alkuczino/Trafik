#include "Editor.h"

void Editor::addButtons() {
	buttons_->addStartButton(*this);
}

Editor::Editor() {
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
	Simulator* simulator = new Simulator;
	simulator->loadConfig();
	simulator->show();
}