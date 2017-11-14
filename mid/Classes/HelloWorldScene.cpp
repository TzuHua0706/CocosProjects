#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "game_scene.h"
#include "select_character.h"
#include "difficulty.h"
#include "C3B.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
	auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
HelloWorld::HelloWorld()
{
}
HelloWorld::~HelloWorld()
{

}
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	rootNode = CSLoader::createNode("MainScene.csb");
	addChild(rootNode);

	//Music
	bkmusic = (cocostudio::ComAudio *)rootNode->getChildByName("music_bg")->getComponent("music_bg");
	bkmusic->playBackgroundMusic();

	//Music button
	btn_music = dynamic_cast<Button*>(rootNode->getChildByName("Button_music"));
	btn_music->addTouchEventListener(CC_CALLBACK_2(HelloWorld::bt_music_event, this));

	//play button
	btn_play = dynamic_cast<Button*>(rootNode->getChildByName("Button_play"));
	btn_play->addTouchEventListener(CC_CALLBACK_2(HelloWorld::bt_play_event, this));

	//animation
	auto dancer = (ActionTimeline *)CSLoader::createTimeline("MainScene.csb");
	rootNode->runAction(dancer);
	dancer->gotoFrameAndPlay(0, 72, true);

	//character button left
	btn_character_left = dynamic_cast<Button*>(rootNode->getChildByName("Button_left"));
	btn_character_left->addTouchEventListener(CC_CALLBACK_2(HelloWorld::bt_character_event_left, this));
	//character button right
	btn_character_right = dynamic_cast<Button*>(rootNode->getChildByName("Button_right"));
	btn_character_right->addTouchEventListener(CC_CALLBACK_2(HelloWorld::bt_character_event_right, this));

	//Difficulty botton
	btn_difficulty_left = dynamic_cast<Button*>(rootNode->getChildByName("Button_left_0"));
	btn_difficulty_left->addTouchEventListener(CC_CALLBACK_2(HelloWorld::bt_difficulty_event_left, this));
	btn_difficulty_right = dynamic_cast<Button*>(rootNode->getChildByName("Button_right_0"));
	btn_difficulty_right->addTouchEventListener(CC_CALLBACK_2(HelloWorld::bt_difficulty_event_right, this));

	//text
	difficulty_text = (cocos2d::ui::Text *)rootNode->getChildByName("difficulty");

	//run character
	character = CSLoader::createNode("runner_cuber.csb");
	character->setPosition(615, 340);
	rootNode->addChild(character);
	auto chAction = (ActionTimeline *)CSLoader::createTimeline("runner_cuber.csb");
	character->runAction(chAction);
	chAction->gotoFrameAndPlay(0, 24, true);
	eyes = Sprite::createWithSpriteFrameName("ceyes1.png");
	eyes->setPosition(Vec2(595, 386));
	rootNode->addChild(eyes, 1);
	mouth = Sprite::createWithSpriteFrameName("cmouth1.png");
	mouth->setPosition(Vec2(590, 354));
	rootNode->addChild(mouth, 1);

	//C3B
	/*C3B::C3B("cuber01.png", "circle01.png","trapezoid01.png",true, rootNode);
	btn->setPosition(Vec2(1110, 386));
	rootNode->addChild(btn, 1);*/

	_listener1 = EventListenerTouchOneByOne::create();	//創建一個一對一的事件聆聽器
	_listener1->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);		//加入觸碰開始事件
	_listener1->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);		//加入觸碰移動事件
	_listener1->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);		//加入觸碰離開事件

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener1, this);	//加入剛創建的事件聆聽器

	this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::doStep));
    return true;
}
void HelloWorld::doStep(float dt)
{
}
void HelloWorld::bt_play_event(Ref *pSender, Widget::TouchEventType type) {
	if (scene_btn) {
		removeChild(rootNode);
		CCScene * scene = CCScene::create();
		game_scene * layer = game_scene::create();
		layer->get_character(number);
		scene->addChild(layer);
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(3.0f, scene));
		scene_btn = false;
	}
}
void HelloWorld::bt_music_event(Ref *pSender, Widget::TouchEventType type) {
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		music_open = !music_open;
		break;
	case Widget::TouchEventType::MOVED:
		break;
	case Widget::TouchEventType::ENDED:
		btn_music->setBright(music_open);
		if (!music_open) { bkmusic->stopBackgroundMusic(); }
		else bkmusic->playBackgroundMusic();
		break;
	case Widget::TouchEventType::CANCELED:
		break;
	default: break;
	}
}
void HelloWorld::bt_character_event_left(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		number++;
		left = true;
		break;
	case Widget::TouchEventType::MOVED:
		break;
	case Widget::TouchEventType::ENDED:
		rootNode->removeChild(character);
		number = number%NUMBER;
		select_character::select_character(number, rootNode, left);
		break;
	case Widget::TouchEventType::CANCELED:
		break;
	default:break;
	}
}
void HelloWorld::bt_character_event_right(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		number--;
		left = false;
		break;
	case Widget::TouchEventType::MOVED:
		break;
	case Widget::TouchEventType::ENDED:
		rootNode->removeChild(character);
		number = number%NUMBER;
		select_character::select_character(number, rootNode, left);
		break;
	case Widget::TouchEventType::CANCELED:
		break;
	default: break;
	}
}
void HelloWorld::bt_difficulty_event_left(Ref *pSender, Widget::TouchEventType type)
{
	//if (number_diff >= 2) { C3B::C3B(btn_difficulty_left, false); }
	//else { C3B::C3B(btn_difficulty_left, true); }
	//if (number_diff <= 0) { C3B::C3B(btn_difficulty_right, false); }
	//else { C3B::C3B(btn_difficulty_right, true); }
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		number_diff++;
		break;
	case Widget::TouchEventType::MOVED:
		break;
	case Widget::TouchEventType::ENDED:
		difficulty::difficulty(difficulty_text, number_diff);
		break;
	case Widget::TouchEventType::CANCELED:
		break;
	default:
		break;
	}
}
void HelloWorld::bt_difficulty_event_right(Ref *pSender, Widget::TouchEventType type)
{
	//if (number_diff >= 2) { C3B::C3B(btn_difficulty_left, false); }
	//else { C3B::C3B(btn_difficulty_left, true); }
	//if (number_diff <= 0) { C3B::C3B(btn_difficulty_right, false); }
	//else { C3B::C3B(btn_difficulty_right, true); }
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		number_diff--;
		break;
	case Widget::TouchEventType::MOVED:
		break;
	case Widget::TouchEventType::ENDED:
		difficulty::difficulty(difficulty_text, number_diff);
		break;
	case Widget::TouchEventType::CANCELED:
		break;
	default:
		break;
	}
}
bool  HelloWorld::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)//觸碰開始事件
{
	Point touchLoc = pTouch->getLocation();
	return true;
}
void  HelloWorld::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰移動事件
{
	Point touchLoc = pTouch->getLocation();
}

void  HelloWorld::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰結束事件 
{
	Point touchLoc = pTouch->getLocation();
}