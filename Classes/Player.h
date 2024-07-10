#ifndef __PLAYER_NODE_H__
#define __PLAYER_NODE_H__

#include "cocos2d.h"


class Player : public cocos2d::Sprite
{
public:
	
	Player();
	~Player();

	static Player* CreatePlayer(const std::string img, cocos2d::Size mapsize, cocos2d::Vec2 birthplace);
	void setcanjump(bool canjump);
	bool getcanjump();
	void setcanmove(bool canmove);
	bool getcanmove();

	cocos2d::Vec2 BirthPlace=cocos2d::Vec2::ZERO;
	cocos2d::Size MapSize = cocos2d::Size::ZERO;
	bool canjump=true;
	bool canmove = true;

	void load();

	CREATE_FUNC(Player);
	bool Init();

};


#endif // __PLAYER_NODE_H__
