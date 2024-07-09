#ifndef _FILLBLOCK_NODE_H__
#define __FILLBLOCK_NODE_H__

#include "cocos2d.h"


class FillBlock : public cocos2d::Sprite
{
public:

	FillBlock();
	~FillBlock();

	static FillBlock* CreateBlock();
	

	int BlockType;


	CREATE_FUNC(FillBlock);
	bool Init();

};


#endif // __FILLBLOCK_NODE_H__
