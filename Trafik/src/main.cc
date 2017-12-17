//#include "Trafik.h"
#include <QApplication>
#include <QGraphicsScene>
#include "Map.h"
#include <QGraphicsView>
#include <memory>
#include "Car.h"
#include "Road.h"



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	QGraphicsScene* scene = new QGraphicsScene;
	Map* map = new Map();
	//std::unique_ptr<Car> rect = std::make_unique<Car>();
	Car* tmpCar = new Car();
	map->addMoving(*tmpCar);
	Car* tmp2 = new Car(100,100);
	
	map->addMoving(*tmp2);

	Road* tmp3 = new Road(0, 0, 100, 100);
	map->addNotMoving(*tmp3);
	map->getMoving().front()->setFlag(QGraphicsItem::ItemIsFocusable);
	map->getMoving().front()->setFocus();
	scene->addItem(map->getMoving().front());
	scene->addItem(map->getMoving()[1]);
	scene->addItem(map->getNotMoving().front());

	QGraphicsView* view = new QGraphicsView(scene);
	view->show();
	//view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	//view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setFixedSize(800, 600);
	scene->setSceneRect(0, 0, 800, 600);
	//map->getMoving().front()->setPos(view->width() / 2, view->height() - map->getMoving().front()->rect().height());
	//Trafik w;
	//w.show();
	return a.exec();
}
