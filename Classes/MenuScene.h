#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_
#include "cocos2d.h"

class MenuScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	// a selector callback
	void leftMenuItem(cocos2d::Ref* pSender);
	void rightMenuItem(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(MenuScene);
};

#endif