#ifndef _SINGLEDICESCENE_H_
#define _SINGLEDICESCENE_H_

#include "cocos2d.h"
USING_NS_CC;

class SingleDiceScene : public Scene
{
public:

	static cocos2d::Scene* createScene();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(SingleDiceScene);
	virtual bool init();


	// dice instance
	cocos2d::Sprite *diceSprite;
	cocos2d::MenuItemImage *extendButton1;
	cocos2d::MenuItemImage *extendButton2;


	// touch function
	void shake(cocos2d::Ref* pSender);
	void extend(cocos2d::Ref* pSender);
	void changeMode1(cocos2d::Ref* pSender);
	void changeMode2(cocos2d::Ref* pSender);

private:
	int randomDice();
	bool extended;
};

#endif 