#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Trafik.h"

class Trafik : public QMainWindow
{
	

public:
	Trafik(QWidget *parent = Q_NULLPTR);

private:
	Ui::TrafikClass ui;
};
