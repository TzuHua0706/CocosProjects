#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "select_character.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

select_character::select_character(int number, cocos2d::Node * rootNode, bool left) {
	char ch_img[NUMBER][25] = { CH_1, CH_2, CH_3, CH_4 };
	for (int i = 0; i < NUMBER; i++) {
		ch[i] = (cocos2d::Sprite *)rootNode->getChildByName(ch_img[i]);
		/*if (i > 4) {
			ch[i] = Sprite::createWithSpriteFrameName(ch_img[i]);
			ch[i]->setPosition(Vec2(615, 317));
			rootNode->addChild(ch[i], 0);
		}*/
		c_pt[i] = ch[i]->getPosition();
	}
	select_character::turn(number, rootNode, left);
}
select_character::~select_character(){
}
void select_character::turn(int number, cocos2d::Node * rootNode, bool left) {
	char run_character[NUMBER][25] = { RUN_1, RUN_2, RUN_3, RUN_4};
	character = CSLoader::createNode(run_character[number]);
	character->setPosition(615, 340);
	auto chAction = (ActionTimeline *)CSLoader::createTimeline(run_character[number]);
	character->runAction(chAction);
	chAction->gotoFrameAndPlay(0, 24, true);
	if (left) {
		for (int i = 0; i < NUMBER; i++) {
			goAction[i] = cocos2d::JumpTo::create(0.1f, c_pt[(i - 1 + NUMBER) % NUMBER], 0, 1);
			ch[i]->runAction(goAction[i]);
		}
	}
	else {
		for (int i = 0; i < NUMBER; i++) {
			goAction[i] = cocos2d::JumpTo::create(0.1f, c_pt[(i + 1) % NUMBER], 0, 1);
			ch[i]->runAction(goAction[i]);
		}
	}
	for (int i = 0; i < NUMBER; i++) {
		if (i == ((number - 1 + NUMBER) % NUMBER) || i == ((number + 1) % NUMBER))ch[i]->setVisible(true);
		else ch[i]->setVisible(false);
	}
	rootNode->addChild(character);
}