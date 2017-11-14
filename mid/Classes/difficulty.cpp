#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "difficulty.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

difficulty::difficulty(cocos2d::ui::Text * difficulty_text, int number) {
	char diff[NUMBER_DIFF][10] = {"Difficult","Normal","Easy"};
	for (int i = 0; i < NUMBER_DIFF; i++) {
		if(i == number)
			difficulty_text->setText(diff[i]);
	}
}
difficulty::~difficulty() {}