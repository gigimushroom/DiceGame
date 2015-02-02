#include "MenuScene.h"
#include "SingleDiceScene.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MenuScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !Layer::init() )
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto LeftChoice = MenuItemImage::create(
		"dice.png",
		"skill_kb.png",
		CC_CALLBACK_1(MenuScene::leftMenuItem, this));

	LeftChoice->setPosition(Vec2(visibleSize.width/4 + origin.x, visibleSize.height/2 + origin.y));
	// create menu, it's an autorelease object
	auto lMenu = Menu::create(LeftChoice, NULL);
	lMenu->setPosition(Vec2::ZERO);
	this->addChild(lMenu, 1);

	auto rightChoice = MenuItemImage::create(
		"dice.png",
		"skill_kb.png",
		CC_CALLBACK_1(MenuScene::rightMenuItem, this));

	rightChoice->setPosition(Vec2(visibleSize.width/4*3 + origin.x, visibleSize.height/2 + origin.y));
	// create menu, it's an autorelease object
	auto rMenu = Menu::create(rightChoice, NULL);
	rMenu->setPosition(Vec2::ZERO);
	this->addChild(rMenu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = LabelTTF::create("Choose your life", "Arial", 24);

	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);


	return true;
}


void MenuScene::leftMenuItem(Ref* pSender)
{
	Director::getInstance()->replaceScene(SingleDiceScene::create()); // ¸Ä³ÉtonyµÄscene
}

void MenuScene::rightMenuItem(Ref* pSender)
{
    Director::getInstance()->replaceScene(SingleDiceScene::create()); 
}
