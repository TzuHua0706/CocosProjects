#include "game_scene.h"
#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "set_Obstacle.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

Scene* game_scene::createScene()
{
	auto scene = Scene::create();

	auto layer = game_scene::create();

	scene->addChild(layer);

	return scene;
}
game_scene::game_scene()
{
}
game_scene::~game_scene()
{
}
void game_scene::get_character(unsigned int get) {
	game_character = get;
	//run character
	char animation_character[NUMBER][25] = { RUN_1, RUN_2, RUN_3, RUN_4 };
	g_character = CSLoader::createNode(animation_character[game_character]);
	g_character->setPosition(1105, 340);
	rootNode_game->addChild(g_character);
	auto chAction = (ActionTimeline *)CSLoader::createTimeline(animation_character[game_character]);
	g_character->runAction(chAction);
	chAction->gotoFrameAndPlay(0, 24, true);
}
bool game_scene::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	rootNode_game = CSLoader::createNode("gameScene.csb");
	addChild(rootNode_game);

	//Music
	bkmusic = (cocostudio::ComAudio *)rootNode_game->getChildByName("music_bg")->getComponent("music_bg");
	bkmusic->playBackgroundMusic();

	//Music button
	btn_music = dynamic_cast<Button*>(rootNode_game->getChildByName("Button_music"));
	btn_music->addTouchEventListener(CC_CALLBACK_2(game_scene::bt_music_event, this));

	//animation
	auto dancer = (ActionTimeline *)CSLoader::createTimeline("gameScene.csb");
	rootNode_game->runAction(dancer);
	dancer->gotoFrameAndPlay(0, 72, true);

	//background line
	bg_line = CSLoader::createNode("bg_line.csb");
	bg_line->setPosition(640, 353);
	rootNode_game->addChild(bg_line);
	auto line_Action = (ActionTimeline *)CSLoader::createTimeline("bg_line.csb");
	bg_line->runAction(line_Action);
	line_Action->gotoFrameAndPlay(0, 10, true);

	//home button
	btn_home = dynamic_cast<Button*>(rootNode_game->getChildByName("Button_home"));
	btn_home->addTouchEventListener(CC_CALLBACK_2(game_scene::bt_home_event, this));

	//character eyes&mouth
	eyes = Sprite::createWithSpriteFrameName("ceyes1.png");
	eyes->setPosition(Vec2(1085, 386));
	rootNode_game->addChild(eyes, 1);
	mouth = Sprite::createWithSpriteFrameName("cmouth1.png");
	mouth->setPosition(Vec2(1080, 354));
	rootNode_game->addChild(mouth, 1);

	//jump
	this->jump = Rect(origin.x + 50, origin.y + 50, visibleSize.width - 100, visibleSize.height - 100);

	set_Obstacle::set_Obstacle(rootNode_game);

	_listener1 = EventListenerTouchOneByOne::create();	//創建一個一對一的事件聆聽器
	_listener1->onTouchBegan = CC_CALLBACK_2(game_scene::onTouchBegan, this);		//加入觸碰開始事件
	_listener1->onTouchMoved = CC_CALLBACK_2(game_scene::onTouchMoved, this);		//加入觸碰移動事件
	_listener1->onTouchEnded = CC_CALLBACK_2(game_scene::onTouchEnded, this);		//加入觸碰離開事件

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener1, this);	//加入剛創建的事件聆聽器

	this->schedule(CC_SCHEDULE_SELECTOR(game_scene::doStep));
	return true;
}
void game_scene::doStep(float dt)
{
}
void game_scene::bt_home_event(Ref *pSender, Widget::TouchEventType type) {
	if (scene_btn) {
		removeChild(rootNode_game);
		CCScene * scene = CCScene::create();
		HelloWorld * layer = HelloWorld::create();
		scene->addChild(layer);
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.5f, scene));
		scene_btn = false;
	}
}
void game_scene::bt_music_event(Ref *pSender, Widget::TouchEventType type) {
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		music_open_game = !music_open_game;
		break;
	case Widget::TouchEventType::MOVED:
		break;
	case Widget::TouchEventType::ENDED:
		btn_music->setBright(music_open_game);
		if (!music_open_game) { bkmusic->stopBackgroundMusic(); }
		else bkmusic->playBackgroundMusic();
		break;
	case Widget::TouchEventType::CANCELED:
		break;
	default: break;
	}
}
bool  game_scene::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)//觸碰開始事件
{
	Point touchLoc = pTouch->getLocation();
	if (jump.containsPoint(touchLoc)) {
		Point seat_e = eyes->getPosition();
		Point seat_m = mouth->getPosition();
		Point seat = g_character->getPosition();
		auto jumpAction_e = cocos2d::JumpTo::create(0.5f, seat_e, 250, 1);
		auto jumpAction_m = cocos2d::JumpTo::create(0.5f, seat_m, 250, 1);
		auto jumpAction = cocos2d::JumpTo::create(0.5f, seat, 250, 1);
		eyes->runAction(jumpAction_e);
		mouth->runAction(jumpAction_m);
		g_character->runAction(jumpAction);
	}
	return true;
}
void  game_scene::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰移動事件
{
	Point touchLoc = pTouch->getLocation();
}

void  game_scene::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //觸碰結束事件 
{
	Point touchLoc = pTouch->getLocation();
}