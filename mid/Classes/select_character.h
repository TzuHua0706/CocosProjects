#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"
#include "basic.h"

//#define CH_1 "cuber01.png"
//#define CH_2 "circle01.png"
//#define CH_3 "trapezoid01.png"
//#define CH_4 "trangle01.png"

class select_character : public cocos2d::Layer
{
private:
public:
	select_character(int number, cocos2d::Node * rootNode, bool left);
	~select_character();

	/*cocos2d::Sprite * ch_1;
	cocos2d::Sprite * ch_2;
	cocos2d::Sprite * ch_3;
	cocos2d::Sprite * ch_4;*/
	//cocos2d::Sprite * mouth;

	cocos2d::Sprite * ch[NUMBER];
	cocos2d::Point c_pt[NUMBER];
	cocos2d::JumpTo * goAction[NUMBER];
	cocos2d::Node * character;

	void turn(int number, cocos2d::Node * rootNode, bool left);

	//char ch_img[NUMBER][25];
	//char run_character[NUMBER][25];
};
