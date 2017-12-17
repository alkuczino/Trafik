//#include "Trafik.h"
#include <QApplication>
#include "Simulator.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Simulator* simulator = new Simulator;
	simulator->show();
	return a.exec();
}
