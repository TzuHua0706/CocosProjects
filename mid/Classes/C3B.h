#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"

class C3B : public cocos2d::Layer
{
private:
public:
	C3B(char * normal, char * touched, char * disable, bool methob, cocos2d::Node * rootNode);
	~C3B();
	cocos2d::Sprite * btn;
};