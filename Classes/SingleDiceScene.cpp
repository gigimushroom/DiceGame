#include "SingleDiceScene.h"


Scene* SingleDiceScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	auto layer = SingleDiceScene::create();
	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}

bool SingleDiceScene::init()
{


	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	diceSprite = Sprite::create("dice1.png");
	diceSprite -> setPosition(Point((visibleSize.width/2) + origin.x + 200, visibleSize.height/2 + origin.y + 200));

	// init the shake action button
	auto shakeButton = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(SingleDiceScene::shake, this));
	shakeButton->setPosition(Point((visibleSize.width/2), visibleSize.height/2 + origin.y - 200));


	// init the extension menu
	auto modeBotton = MenuItemImage::create(
		"skill_kb.png",
		"skill_kb.png",
		CC_CALLBACK_1(SingleDiceScene::extend, this));
	modeBotton ->setVisible(true);
	modeBotton->setPosition(Point((visibleSize.width/2) - 250, visibleSize.height/2 + origin.y - 250));

	extendButton1 = MenuItemImage::create(
		"skill_ld.png",
		"skill_ld.png",
		CC_CALLBACK_1(SingleDiceScene::changeMode1, this));
	extendButton1 ->setVisible(false);
	extendButton1->setPosition(Point((visibleSize.width/2) - 250, visibleSize.height/2 + origin.y - 250));

	extendButton2 = MenuItemImage::create(
		"skill_zl.png",
		"skill_zl.png",
		CC_CALLBACK_1(SingleDiceScene::changeMode2, this));
	extendButton2 ->setVisible(false);
	extendButton2->setPosition(Point((visibleSize.width/2) - 250, visibleSize.height/2 + origin.y - 250));


	auto menu = Menu::create(modeBotton, extendButton1, extendButton2, NULL);
	menu->setPosition(Vec2::ZERO);



	auto shakeAction = Menu::create(shakeButton, NULL);
	shakeAction->setPosition(Vec2::ZERO);



	this->addChild(menu,1);
	this->addChild(shakeAction, 1);
	this->addChild(diceSprite);
	extended = false;
	return true;
}

void SingleDiceScene::shake(Ref* pSender)
{
	int number = randomDice();
	std::string text = "dice";
	text += std::to_string(number);
	text += std::string(".png");
	diceSprite->setTexture(text);

}

void SingleDiceScene::extend(Ref* pSender)
{
	if (!extended)
	{
		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();
		auto action1 = Sequence::create(
			MoveTo::create(1, Point((visibleSize.width/2) - 150, visibleSize.height/2 + origin.y - 250)),
			NULL);

		auto action2 = Sequence::create(
			MoveTo::create(1, Point((visibleSize.width/2) - 250, visibleSize.height/2 + origin.y - 150)),
			NULL);

		extendButton1 -> setVisible(true);
		extendButton2 -> setVisible(true);
		extendButton1 ->runAction(action1);
		extendButton2 ->runAction(action2);
		extended = true;
	}
	else
	{
		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();
		auto action1 = Sequence::create(
			MoveTo::create(1, Point((visibleSize.width/2) - 250, visibleSize.height/2 + origin.y - 250)),
			NULL);

		auto action2 = Sequence::create(
			MoveTo::create(1, Point((visibleSize.width/2) - 250, visibleSize.height/2 + origin.y - 250)),
			NULL);

		extendButton1 ->runAction(action1);
		extendButton2 ->runAction(action2);
		extendButton1 -> setVisible(false);
		extendButton2 -> setVisible(false);

		extended = false;
	}

}

void SingleDiceScene::changeMode1(Ref* pSender)
{
	diceSprite->setTexture("skill_ld.png");
}

void SingleDiceScene::changeMode2(Ref* pSender)
{
	diceSprite->setTexture("skill_zl.png");
}


int SingleDiceScene::randomDice()
{
	int diceNumber;
	const int LOW = 1;
	const int HIGH = 6;

	time_t seconds;
	time(&seconds);
	srand((unsigned int) seconds);

	diceNumber = rand() % (HIGH - LOW + 1) + LOW;

	return diceNumber;
}