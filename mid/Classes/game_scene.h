#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"
#include "basic.h"

class game_scene : public cocos2d::Layer
{
private:

public:
	game_scene();
	~game_scene();

	cocostudio::ComAudio * bkmusic;
	cocos2d::Sprite * eyes;
	cocos2d::Sprite * mouth;
	cocos2d::ui::Button * btn_home;
	cocos2d::ui::Button * btn_music;
	cocos2d::Node * rootNode_game;
	cocos2d::Node * character;
	cocos2d::Node * bg_line;
	cocos2d::Rect jump;

	bool scene_btn = true;
	bool music_open_game = true;
	unsigned int game_character;

	virtual bool init();
	void doStep(float dt);

	void get_character(unsigned int get);
	void bt_music_event(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void bt_home_event(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);

	static cocos2d::Scene* createScene();

	//觸碰
	cocos2d::EventListenerTouchOneByOne *_listener1;
	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰開始事件
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰移動事件
	void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰結束事件 

	// implement the "static create()" method manually
	CREATE_FUNC(game_scene);
};
#endif // __GAME_SCENE_H__