#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"

#define NUMBER_DIFF 3

class difficulty : public cocos2d::Layer
{
private:
public:
	difficulty(cocos2d::ui::Text * difficulty_text, int number);
	~difficulty();
	char diff[NUMBER_DIFF][10];
};