#ifndef  __ACTORCONTROLLER_NODE_H__
#define  __ACTORCONTROLLER_NODE_H__


#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Player.h"

class ActorController : public cocos2d::Node
{
public:

	static ActorController* CreateController(Player* tg);

	//安卓端的控制按键
	cocos2d::ui::Button* left;
	cocos2d::ui::Button* right;
	cocos2d::ui::Button* jump;

	void load();
	
	//PC端的监听器
	cocos2d::EventListenerKeyboard* PClistener;
	//绑定的Player
	Player* target;

	CREATE_FUNC(ActorController);
	bool Init();

};


#endif // __ACTORCONTROLLER_NODE_H__

