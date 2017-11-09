#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;
using namespace CocosDenshion;


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

HelloWorld::~HelloWorld()
{

#if EXERCISE == 1
	_jumpAction->release();
#endif

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
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    addChild(rootNode);

#if EXAMPLES == 1
// 音效與音樂 --------------------------------------------------------------------------------
	//auto bkmusic = (cocostudio::ComAudio *)rootNode->getChildByName("bkmusic")->getComponent("bkmusic");
	//bkmusic->playBackgroundMusic();

	SimpleAudioEngine::getInstance()->playBackgroundMusic("./music/SR_bg.mp3", true);
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.2f);  //尚未實作
	//SimpleAudioEngine::getInstance()->stopBackgroundMusic();	// 停止背景音樂
	SimpleAudioEngine::getInstance()->preloadEffect("thinking cloud.mp3");	// 預先載入音效檔
	unsigned int eid = SimpleAudioEngine::getInstance()->playEffect("thinking cloud.mp3",true);  // 播放音效檔
	//SimpleAudioEngine::getInstance()->stopEffect(eid);  // 停止音效撥放，必須使用 PlayEffect 傳回的 id
	//SimpleAudioEngine::getInstance()->unloadEffect("thinking cloud.mp3");  // 釋放音效檔
//---------------------------------------------------------------------------------------------

#elif EXAMPLES == 2
// Sprite ------------------------------------------------------------------------------------- 
#if EXERCISE == 0
	auto runner = (cocos2d::Sprite *)rootNode->getChildByName("cuber01");
	runner->setColor(Color3B(75,155,77));
	Point pt = runner->getPosition();
	auto jumpAction = cocos2d::JumpTo::create(1.25f, Point(pt.x - 600, pt.y), 100, 3);
	auto tintTo = cocos2d::TintTo::create(1.25f, Color3B(50, 125, 250));
	runner->runAction(tintTo);
	runner->runAction(jumpAction);
#elif EXERCISE == 1
	//  ------ 課堂練習一  ------
	_runner = (cocos2d::Sprite *)rootNode->getChildByName("cuber01");
	_runner->setColor(Color3B(75, 155, 77));
	Point pt = _runner->getPosition();
	_jumpAction = cocos2d::JumpTo::create(1.25f, Point(pt.x - 600, pt.y), 100, 3);
	_jumpAction->retain();
#endif
//---------------------------------------------------------------------------------------------		

#elif EXAMPLES == 3
// Button -------------------------------------------------------------------------------------
	Button *cuberbtn = dynamic_cast<Button*>(rootNode->getChildByName("CuberBtn"));
	//Button *cuberbtn = (cocos2d::ui::Button *)(rootNode->getChildByName("CuberBtn"));
	cuberbtn->addTouchEventListener(CC_CALLBACK_2(HelloWorld::CuberBtnTouchEvent, this));
//---------------------------------------------------------------------------------------------	

#elif EXAMPLES == 4
// 文本 TTF 字型-------------------------------------------------------------------------------
	auto text = (cocos2d::ui::Text *)rootNode->getChildByName("Text101");
	text->setColor(Color3B(200, 255, 50));

//---------------------------------------------------------------------------------------------	

#elif EXAMPLES == 5
// CheckBox-------------------------------------------------------------------------------
	CheckBox *checkBox = dynamic_cast<CheckBox*>(rootNode->getChildByName("CheckBox_1"));
////CheckBox *checkBox = (cocos2d::ui::CheckBox*)(rootNode->getChildByName("CheckBox_1"));
	checkBox->addEventListener(CC_CALLBACK_2(HelloWorld::checkBoxTouchEvent, this));
//---------------------------------------------------------------------------------------------	

#elif EXAMPLES == 6
// FNT 字體-------------------------------------------------------------------------------
	auto bmtlabel = (cocos2d::Label *)rootNode->getChildByName("BMFont");
	bmtlabel->setColor(Color3B(200, 255, 50));
//---------------------------------------------------------------------------------------------	

#elif EXAMPLES == 7
// loadingBar -------------------------------------------------------------------------------
#if EXERCISE != 2
	auto loadingBar = (cocos2d::ui::LoadingBar *)rootNode->getChildByName("LoadingBar_1");
	loadingBar->setDirection(LoadingBar::Direction::LEFT);
	loadingBar->setPercent(50);
#else 
	_loadingBar = (cocos2d::ui::LoadingBar *)rootNode->getChildByName("LoadingBar_1");
	_loadingBar->setDirection(LoadingBar::Direction::LEFT);
	_loadingBar->setPercent(100);
#endif
//---------------------------------------------------------------------------------------------	

#elif EXAMPLES == 8
// Slider 滑動條 -------------------------------------------------------------------------------------
	auto *slider = (cocos2d::ui::Slider *)(rootNode->getChildByName("Slider_1"));
	slider->addEventListener(CC_CALLBACK_2(HelloWorld::sliderEvent, this));
	slider->setPercent(50);
	slider->setMaxPercent(100);		// 可以設定超過 100，但超過100會讓捲動鈕的顯示會有問題
	// 以下用於 slider 顯示用
	_sliderValue = (cocos2d::ui::Text *)rootNode->getChildByName("Text101");
//---------------------------------------------------------------------------------------------	

#elif EXAMPLES == 9
//// 序列幀動畫 -------------------------------------------------------------------------------------
	auto runner = (cocos2d::Sprite *)rootNode->getChildByName("Sprite_1");
	runner->setColor(Color3B(135, 250, 50));
	auto action = (ActionTimeline *)CSLoader::createTimeline("MainScene.csb");
	rootNode->runAction(action);
	action->gotoFrameAndPlay(0, 21, true);
//---------------------------------------------------------------------------------------------	

#elif EXAMPLES == 10
// 讀入與控制組合式的序列幀動畫
	auto triRoot1 = CSLoader::createNode("triangleNode.csb");
	triRoot1->setPosition(100, 360);
	this->addChild(triRoot1);

	auto triAction = (ActionTimeline *)CSLoader::createTimeline("triangleNode.csb");
	triRoot1->runAction(triAction);
	triAction->setDuration(3.0f);
	triAction->gotoFrameAndPlay(0, 35, false);

	// _triRoot2 的動畫撥放在按下螢幕後啟動
	_triRoot2 = CSLoader::createNode("triangleNode.csb");
	_triRoot2->setPosition(300, 360);
	this->addChild(_triRoot2);
	_triAction = (ActionTimeline *)CSLoader::createTimeline("triangleNode.csb");
	_triAction->setDuration(2.0f);
	_triRoot2->runAction(_triAction);
//---------------------------------------------------------------------------------------------	

// 以下加入場景的 TouchBegan 事件中
	//_triAction->gotoFrameAndPlay(0, 35, false);
//---------------------------------------------------------------------------------------------	

#endif

// 將 doStep 函式掛入 schedule list 中，每一個 frame 就都會被呼叫到
	this->schedule(CC_SCHEDULE_SELECTOR(HelloWorld::doStep));
	return true;
}


void HelloWorld::doStep(float dt)
{
#if EXERCISE == 2 //課堂練習二
	float t = _loadingBar->getPercent();
	if (t >= dt * 5 )  t = t - dt *5;
	else t = 0;
	_loadingBar->setPercent(t);
#else

#endif
}

void HelloWorld::CuberBtnTouchEvent(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
		case Widget::TouchEventType::BEGAN:
			log("Touch Down");
			break;
		case Widget::TouchEventType::MOVED:
			log("Touch Move");
			break;
		case Widget::TouchEventType::ENDED:
			log("Touch Up");

#if EXERCISE == 1
			_runner->runAction(_jumpAction);
#endif
			break;
		case Widget::TouchEventType::CANCELED:
			log("Touch Cancelled");
			break;
		default:
			break;
	}
}

void HelloWorld::checkBoxTouchEvent(Ref* object, CheckBox::EventType type) {
	switch (type)
	{
	case CheckBox::EventType::UNSELECTED:
		log("Unselected");
		break;

	case CheckBox::EventType::SELECTED:
		log("Selected");
		break;

	}
}


void HelloWorld::sliderEvent(cocos2d::Ref* sender, cocos2d::ui::Slider::EventType type)
{
	if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
	{
		Slider* slider = dynamic_cast<Slider*>(sender);
		int percent = slider->getPercent();
		int maxPercent = slider->getMaxPercent();
		_sliderValue->setString(StringUtils::format("Percent %5.2f", 100.0 * percent / maxPercent));
	}
}
