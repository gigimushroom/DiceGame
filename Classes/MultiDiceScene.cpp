#include "MultiDiceScene.h"

bool MultiDiceScene::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	diceSprite1 = Sprite::create("dice1.png");
	diceSprite1 -> setPosition(Point((visibleSize.width/2) + origin.x, visibleSize.height/2 + origin.y + 200));

	diceSprite2 = Sprite::create("dice2.png");
	diceSprite2 -> setPosition(Point((visibleSize.width/4) + origin.x, visibleSize.height/2 + origin.y + 200));

	diceSprite3 = Sprite::create("dice3.png");
	diceSprite3 -> setPosition(Point((visibleSize.width/4*3) + origin.x, visibleSize.height/2 + origin.y + 200));

	diceSprite4 = Sprite::create("dice4.png");
	diceSprite4 -> setPosition(Point((visibleSize.width/2) + origin.x, visibleSize.height/4 + origin.y + 200));

	diceSprite5 = Sprite::create("dice5.png");
	diceSprite5 -> setPosition(Point((visibleSize.width/4) + origin.x, visibleSize.height/4 + origin.y + 200));

	diceSprite6 = Sprite::create("dice6.png");
	diceSprite6 -> setPosition(Point((visibleSize.width/4*3) + origin.x, visibleSize.height/4 + origin.y + 200));

	auto shakeButton = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(MultiDiceScene::shake, this));
	shakeButton->setPosition(Point((visibleSize.width/2) - 200, visibleSize.height/2 + origin.y - 200));

	auto lMenu = Menu::create(shakeButton, NULL);
	lMenu->setPosition(Vec2::ZERO);
	this->addChild(lMenu, 1);

	// on touch event
	//        auto listener = EventListenerTouchOneByOne::create();
	//        listener->setSwallowTouches(true);
	//        listener->onTouchBegan = CC_CALLBACK_2(SingleDiceScene::onTouchBegan, this);
	//        listener->onTouchMoved = CC_CALLBACK_2(SingleDiceScene::onTouchMoved,this);
	//        listener->onTouchEnded = CC_CALLBACK_2(SingleDiceScene::onTouchEnded,this);
	//    
	//    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	this->addChild(diceSprite1);
	this->addChild(diceSprite2);
	this->addChild(diceSprite3);
	this->addChild(diceSprite4);
	this->addChild(diceSprite5);
	this->addChild(diceSprite6);

	return true;
}

void MultiDiceScene::shake(Ref* pSender)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	cocos2d::Sprite *zhongSprite;
	zhongSprite = Sprite::create("zhong.png");
	zhongSprite -> setPosition(Point((visibleSize.width/6) + origin.x, visibleSize.height/2 + origin.y + 50));
	zhongSprite -> setVisible(true);
	//auto action2 = MoveTo::create(3, Point( 200, 150));

	auto moveBy1 = MoveBy::create(1, Vec2(300,0));
	auto delay = DelayTime::create(1);
	auto jump = JumpBy::create(0.5, Vec2(0, 0), 100, 3);
	auto moveBy2 = MoveBy::create(1, Vec2(700,0));

	auto fadeOut = FadeOut::create(2.0f);
	zhongSprite->runAction(Sequence::create(moveBy1, jump, jump, delay, moveBy2, fadeOut, nullptr));

	srand(time(NULL));
	randomDice(diceSprite1);
	randomDice(diceSprite2);
	randomDice(diceSprite3);
	randomDice(diceSprite4);
	randomDice(diceSprite5);
	randomDice(diceSprite6);

	this->addChild(zhongSprite);
}

void MultiDiceScene::randomDice(cocos2d::Sprite * sprite)
{
	auto delay = DelayTime::create(2);
	sprite->runAction(Sequence::create(delay, delay, nullptr));
	const int LOW = 1;
	const int HIGH = 6;
	int diceNumber = rand() % (HIGH - LOW + 1) + LOW;

	std::string text = "dice";
	text += std::to_string(diceNumber);
	text += std::string(".png");
	sprite->setTexture(text);
}