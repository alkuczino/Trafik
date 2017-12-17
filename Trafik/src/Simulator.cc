#include "Simulator.h"

Simulator::Simulator()
{
	scene_ = new QGraphicsScene;
	map_ = new Map;
	Road* tmp3 = new Road(0, 0, 100, 100);
	map_->addNotMoving(*tmp3);
	//std::unique_ptr<Car> rect = std::make_unique<Car>();
	Car* tmpCar = new Car();
	map_->addMoving(*tmpCar);
	Car* tmp2 = new Car(100, 100);

	map_->addMoving(*tmp2);



	map_->getMoving().front()->setFlag(QGraphicsItem::ItemIsFocusable);
	map_->getMoving().front()->setFocus();
	scene_->addItem(map_->getNotMoving().front());
	scene_->addItem(map_->getMoving().front());
	scene_->addItem(map_->getMoving()[1]);


	//QGraphicsView* view = new QGraphicsView(scene_);
	//view->show();
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(800, 600);
	setScene(scene_);
	scene_->setSceneRect(0, 0, 800, 600);
	//map->getMoving().front()->setPos(view->width() / 2, view->height() - map->getMoving().front()->rect().height());
}
