#ifndef __GAMEMAP_NODE_H__
#define __GAMEMAP_NODE_H__

#include "cocos2d.h"
#include <vector>


class GameMap : public cocos2d::Node
{
public:

	static GameMap* CreateMap(std::vector<std::vector<float>> gamemap,cocos2d::Size mapsize,cocos2d::Size blocksize);

	std::vector<std::vector<float>> Map;

	cocos2d::Size BlockSize;

	cocos2d::Size MapSize;

	CREATE_FUNC(GameMap);

	void load();

	bool Init();

};


#endif // __PLAYER_NODE_H__
