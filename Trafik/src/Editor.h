#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Buttons.h"
#include "Simulator.h"
#include <QObject>

class Buttons;

const int EDITOR_X = 300, EDITOR_Y = 100;

class Editor: public QGraphicsView {
	Q_OBJECT
public:
	Editor();
	void addButtons();
	//void deleteSimulator();
	public slots:
	void startClicked();
	void carClicked();
	void roadClicked();
	QGraphicsScene* getScene();

private:

	QGraphicsScene* scene_;
	Simulator* simulator_;
	Buttons* buttons_;
	bool running_;
	
};