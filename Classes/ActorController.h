#ifndef  __ACTORCONTROLLER_NODE_H__
#define  __ACTORCONTROLLER_NODE_H__


#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Player.h"

class ActorController : public cocos2d::Node
{
public:

	static ActorController* CreateController(Player* tg);

	//��׿�˵Ŀ��ư���
	cocos2d::ui::Button* left;
	cocos2d::ui::Button* right;
	cocos2d::ui::Button* jump;

	void load();
	
	//PC�˵ļ�����
	cocos2d::EventListenerKeyboard* PClistener;
	//�󶨵�Player
	Player* target;

	CREATE_FUNC(ActorController);
	bool Init();

};


#endif // __ACTORCONTROLLER_NODE_H__

