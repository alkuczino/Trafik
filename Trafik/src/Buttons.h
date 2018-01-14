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

//public slots:
//	void startClicked();

private:
	QPushButton* startButton_;
	QPushButton* addCar_;
	QPushButton* addCamera_;
	QPushButton* remove_;
};