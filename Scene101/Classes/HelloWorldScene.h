#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"
#include "SimpleAudioEngine.h"
#include "cocostudio/CocoStudio.h"
#include "typedefs.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
private:
	// 課堂練習一
#if EXERCISE == 1
	cocos2d::Sprite *_runner;
	cocos2d::JumpTo *_jumpAction;
#elif EXERCISE == 2
// loadingBar 
	cocos2d::ui::LoadingBar *_loadingBar;
#endif

	cocos2d::ui::Text *_sliderValue;

// 讀入與控制組合式的序列幀動畫
	cocos2d::Node *_triRoot2;
	cocostudio::timeline::ActionTimeline *_triAction;

public:
	~HelloWorld();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	void doStep(float dt);

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	void checkBoxTouchEvent(cocos2d::Ref* object, cocos2d::ui::CheckBox::EventType type);
	void CuberBtnTouchEvent(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
	void sliderEvent(cocos2d::Ref* sender, cocos2d::ui::Slider::EventType type);

	// implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
