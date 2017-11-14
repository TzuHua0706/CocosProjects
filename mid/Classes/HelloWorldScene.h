#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"

class HelloWorld : public cocos2d::Layer
{
private:

public:
	HelloWorld();
	~HelloWorld();

    cocostudio::ComAudio * bkmusic;
	cocos2d::Node * rootNode;
	cocos2d::Node * character;
	cocos2d::Sprite * eyes;
	cocos2d::Sprite * mouth;
	cocos2d::ui::Text * difficulty_text;
	cocos2d::ui::Button * btn_character_left;
	cocos2d::ui::Button * btn_character_right;
	cocos2d::ui::Button * btn_difficulty_left;
	cocos2d::ui::Button * btn_difficulty_right;
	cocos2d::ui::Button * btn_music;
	cocos2d::ui::Button * btn_play;

	cocos2d::Sprite * btn;

	bool scene_btn = true;
	bool music_open = true;
	bool left = true;
	unsigned int number = 0;
	unsigned int number_diff = 1;
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	void doStep(float dt);

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	//virtual void setVisible(bool visible);

	//button
	void bt_character_event_left(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void bt_character_event_right(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void bt_difficulty_event_left(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void bt_difficulty_event_right(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void bt_music_event(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void bt_play_event(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);

	//觸碰
	cocos2d::EventListenerTouchOneByOne *_listener1;
	bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰開始事件
	void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰移動事件
	void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent); //觸碰結束事件 

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
