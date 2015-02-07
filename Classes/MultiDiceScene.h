#ifndef _MULTIDICESCENE_H_
#define _MULTIDICESCENE_H_
#include "cocos2d.h"
USING_NS_CC;
class MultiDiceScene : public Scene{
public:
	virtual bool init();
	CREATE_FUNC(MultiDiceScene);
	// dice instance
	cocos2d::Sprite *diceSprite1;
	cocos2d::Sprite *diceSprite2;
	cocos2d::Sprite *diceSprite3;
	cocos2d::Sprite *diceSprite4;
	cocos2d::Sprite *diceSprite5;
	cocos2d::Sprite *diceSprite6;


	// touch function
	void shake(cocos2d::Ref* pSender);
	//    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	//    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	//    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);

private:
	void randomDice(cocos2d::Sprite * sprite);
};

#endif 