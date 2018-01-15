#pragma once
#include <QPushButton>
#include "Editor.h"


class Editor;

class Buttons: public QObject {
Q_OBJECT
public:
	Buttons();

	void addStartButton(Editor&);
	void addCarButton(Editor&);
	void addCameraButton(Editor&);
	void removeButton(Editor&);
	void addRoadButton(Editor&);

//public slots:
//	void startClicked();

private:
	QPushButton* startButton_;
	QPushButton* carButton_;
	QPushButton* cameraButton_;
	QPushButton* removeButton_;
	QPushButton* roadButton_;
};