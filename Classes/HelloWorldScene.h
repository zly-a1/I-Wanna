
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Player.h"
#include "ActorController.h"
#include "GameMap.h"
using namespace std;

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene(int guanqia);

    

    virtual bool init();

    cocos2d::Sprite* addSpriteatPosition(cocos2d::Vec2 pos, std::string img);

    virtual void onEnter()override;
   
    cocos2d::Size MapSize=cocos2d::Size(0,0);
    

    void update(float dt);

    void kill();

    bool canmove = true;

    Player* ball;

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__

