#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "C3B.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

C3B::C3B(char * normal,char * touched, char * disable, bool methob , cocos2d::Node * rootNode) {
	if (methob) {
		btn = Sprite::createWithSpriteFrameName(normal);
		btn->setPosition(Vec2(1110, 386));
		rootNode->addChild(btn, 1);
	}
	else
	    btn = Sprite::createWithSpriteFrameName(disable);
}
C3B::~C3B() {}