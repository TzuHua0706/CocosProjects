#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "set_Obstacle.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

set_Obstacle::set_Obstacle(cocos2d::Node * ob_node) {
	//Obstacle animatiom
	auto ani_Obstacle = CSLoader::createNode("triangleNode.csb");
	ani_Obstacle->setPosition(200, 340);
	ob_node->addChild(ani_Obstacle);
	Point pt_Obstacle = ani_Obstacle->getPosition();
	auto act_obstacle = (ActionTimeline *)CSLoader::createTimeline("triangleNode.csb");
	ani_Obstacle->runAction(act_obstacle);
	act_obstacle->gotoFrameAndPlay(0, 35, false);

	//fire animatiom
	auto ani_fire = CSLoader::createNode("fire.csb");
	ani_fire->setPosition(200, 340);
	ob_node->addChild(ani_fire);
	Point pt_fire = ani_fire->getPosition();
	auto act_fire = (ActionTimeline *)CSLoader::createTimeline("fire.csb");
	ani_fire->runAction(act_fire);
	act_fire->gotoFrameAndPlay(0, 35, false);
}
set_Obstacle::~set_Obstacle() {}