
#include "HelloWorldScene.h"
#include "StartScene.h"
//#include "StartScene.cpp"



#include "ui/CocosGUI.h"


#include <string>
#include <iostream>


USING_NS_CC;

int Guanqia;



namespace birth {
    Vec2* BirthPlaces = new Vec2(0,0);

}

Scene* HelloWorld::createScene(int guanqia)
{
   
    auto Hello = Scene::createWithPhysics();
    
    Hello->getPhysicsWorld()->setGravity(Vec2(0.0f, -240.0f));
    auto phy = HelloWorld::create();
    Hello->addChild(phy);
    
    //Hello->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto visibleSize = Director::getInstance()->getWinSize();
    
    auto fmes = Director::getInstance()->getOpenGLView()->getFrameSize();

    Guanqia = guanqia;
    if (Guanqia==1)
    {
        birth::BirthPlaces->x = 0;
        birth::BirthPlaces->y = 12;
    }
    if (Guanqia == 2)
    {
        birth::BirthPlaces->x = 0;
        birth::BirthPlaces->y = 0;
    }
    if (Guanqia == 3)
    {
        birth::BirthPlaces->x = 0;
        birth::BirthPlaces->y = 0;
    }
    if (Guanqia == 4)
    {
        birth::BirthPlaces->x = 11;
        birth::BirthPlaces->y = 1;
    }
    if (Guanqia == 5)
    {
        birth::BirthPlaces->x = 4;
        birth::BirthPlaces->y = 4;
    }
    if (Guanqia == 6)
    {
        birth::BirthPlaces->x = 1;
        birth::BirthPlaces->y = 1;
    }
    if (Guanqia == 7)
    {
        birth::BirthPlaces->x = 4;
        birth::BirthPlaces->y = 4;
    }
    return Hello;

}



// Print useful error message instead of segfaulting when files are not there.

Sprite* HelloWorld::addSpriteatPosition(Vec2 pos,std::string img)
{
    auto Spr = Sprite::create(img);
    Spr->setPosition(pos.x,pos.y);
    return Spr;
}


// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    
    
    if (!Scene::init())
    {

        return false;


    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    MapSize=Size(25,16);

    this->scheduleUpdate();
    
    
    
    

    ball = Player::CreatePlayer("kid.png", this->MapSize, *birth::BirthPlaces);
    ball->setName("kid");
    this->addChild(ball);


    std::vector<std::vector<float>>gamemap(static_cast<unsigned int>(MapSize.height), vector<float>(static_cast<unsigned int>(MapSize.width)));

    int row = MapSize.width, col = MapSize.height;



    if (Guanqia == 1)
    {
        gamemap[col - 16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 14] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 12] = { 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 11] = { 1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,4 };
        gamemap[col - 10] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,4 };
        gamemap[col - 9] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 8] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 7] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 };
        gamemap[col - 6] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,4 };
        gamemap[col - 5] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 4] = { 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 3] = { 0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 2] = { 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 1] = { 1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 };
    }
    if (Guanqia == 2)
    {
        gamemap[col - 16] = { 0,0,0,0,0,0,0,0,0,0,4,1,5,5,5,5,5,5,5,5,5,5,5,5,5 };
        gamemap[col - 15] = { 0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 14] = { 0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 13] = { 0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 12] = { 1,1,1,1,1,1,1,0,0,0,4,1,0,0,1,1,1,1,1,1,1,1,0,0,4 };
        gamemap[col - 11] = { 6,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,1,0,0,0,5,0,0,0,4 };
        gamemap[col - 10] = { 6,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,1,6,0,0,0,0,0,0,4 };
        gamemap[col - 9] = { 6,0,0,0,0,0,0,0,0,0,4,1,1,1,0,0,1,0,0,0,0,2,0,0,4 };
        gamemap[col - 8] = { 6,0,0,0,0,0,0,2,2,2,2,1,0,0,0,0,1,0,0,1,1,1,1,1,4 };
        gamemap[col - 7] = { 6,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,4 };
        gamemap[col - 6] = { 6,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,6,0,0,0,0,0,0,4 };
        gamemap[col - 5] = { 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,4 };
        gamemap[col - 4] = { 6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,4 };
        gamemap[col - 3] = { 6,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,3,0,0,0,0,0,0,4 };
        gamemap[col - 2] = { 6,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,4 };
        gamemap[col - 1] = { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 };
    }
    if (Guanqia == 3)
    {
        gamemap[col - 16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        gamemap[col - 15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 14] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 12] = { 1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,4 };
        gamemap[col - 11] = { 6,5,5,5,5,5,5,5,5,1,2,2,2,2,2,2,2,2,2,0,4,1,6,0,4 };
        gamemap[col - 10] = { 6,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,4,1,6,0,4 };
        gamemap[col - 9] = { 6,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,5,0,0,0,0,0,0,0,4 };
        gamemap[col - 8] = { 6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4 };
        gamemap[col - 7] = { 6,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,0,0,4 };
        gamemap[col - 6] = { 6,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
        gamemap[col - 5] = { 6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 4] = { 6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 3] = { 6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 2] = { 6,2,2,2,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,3,1 };
        gamemap[col - 1] = { 1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1 };
    }
    if (Guanqia == 4)
    {
        gamemap[col - 16] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
        gamemap[col - 15] = { 1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,5,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 14] = { 1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 13] = { 1,0,0,4,1,1,1,1,0,0,1,0,0,0,0,0,0,0,2,0,0,0,0,0,1 };
        gamemap[col - 12] = { 1,0,0,0,0,1,6,0,0,0,1,1,1,1,1,1,1,1,1,1,6,0,0,0,1 };
        gamemap[col - 11] = { 1,1,6,0,0,1,6,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 10] = { 1,0,0,0,0,1,6,0,0,0,1,0,0,0,0,2,0,0,2,0,0,0,0,0,1 };
        gamemap[col - 9] = { 1,0,0,4,1,1,0,0,0,0,1,0,0,0,4,1,1,1,1,1,1,1,1,1,1 };
        gamemap[col - 8] = { 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 7] = { 1,1,6,0,0,1,3,0,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 6] = { 1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,6,0,0,1 };
        gamemap[col - 5] = { 1,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 4] = { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 3] = { 1,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 2] = { 1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1 };
        gamemap[col - 1] = { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 };
    }

    if (Guanqia == 5)
    {
        gamemap[col - 16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        gamemap[col - 15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        gamemap[col - 14] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        gamemap[col - 13] = { 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0 };
        gamemap[col - 12] = { 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0 };
        gamemap[col - 11] = { 0,0,0,1,1,1,2,1,1,1,2,1,1,1,2,1,1,1,2,1,0,1,0,0,0 };
        gamemap[col - 10] = { 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0 };
        gamemap[col - 9] = { 0,0,0,1,0,1,1,1,2,1,1,1,2,1,1,1,2,1,1,1,1,1,0,0,0 };
        gamemap[col - 8] = { 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0 };
        gamemap[col - 7] = { 0,0,0,1,1,1,2,1,1,1,2,1,1,1,2,1,1,1,2,1,0,1,0,0,0 };
        gamemap[col - 6] = { 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0 };
        gamemap[col - 5] = { 0,0,0,1,3,0,0,0,2,0,0,0,2,0,0,0,2,0,0,2,0,1,0,0,0 };
        gamemap[col - 4] = { 0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0 };
        gamemap[col - 3] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        gamemap[col - 2] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        gamemap[col - 1] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

    }

    if (Guanqia == 6)
    {
        gamemap[col - 16] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
        gamemap[col - 15] = { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 14] = { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,0,0,0,0,1 };
        gamemap[col - 13] = { 1,0,0,2,2,2,2,0,0,0,0,0,0,0,5,0,5,0,2,0,0,2,0,0,1 };
        gamemap[col - 12] = { 1,1,1,1,1,1,1,0,0,2,2,0,0,0,0,0,0,0,5,0,0,5,0,0,1 };
        gamemap[col - 11] = { 1,3,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 10] = { 1,0,0,0,0,0,1,0,0,1,5,0,0,0,1,2,0,1,0,0,0,0,0,0,1 };
        gamemap[col - 9] = { 1,0,0,0,0,0,1,0,1,1,0,0,0,0,1,1,1,1,0,4,1,6,0,4,1 };
        gamemap[col - 8] = { 1,0,0,0,0,5,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1 };
        gamemap[col - 7] = { 1,0,0,1,0,0,0,0,2,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1 };
        gamemap[col - 6] = { 1,0,0,2,2,0,2,0,0,0,2,0,0,0,2,0,0,5,0,2,2,0,0,0,1 };
        gamemap[col - 5] = { 1,0,0,1,1,1,1,1,1,1,1,6,0,0,1,1,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 4] = { 1,0,0,0,5,0,5,0,5,0,1,0,0,0,1,6,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 3] = { 1,6,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1 };
        gamemap[col - 2] = { 1,0,0,0,0,2,0,2,0,0,0,0,2,2,1,0,0,0,0,0,0,2,2,2,1 };
        gamemap[col - 1] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };



    }
    if (Guanqia == 7)
    {
        gamemap[col - 16] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
        gamemap[col - 15] = { 1,5,5,5,5,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 14] = { 1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 13] = { 1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 12] = { 1,1,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 11] = { 1,5,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 10] = { 1,0,0,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 9] =  { 1,0,1,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1 };
        gamemap[col - 8] =  { 1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 7] =  { 1,1,0,1,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 6] =  { 1,6,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 5] =  { 1,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 4] =  { 1,0,1,5,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 3] =  { 1,0,5,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1 };
        gamemap[col - 2] =  { 1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,3,1 };
        gamemap[col - 1] =  { 1,2,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };



    }


    auto gmp = GameMap::CreateMap(gamemap, MapSize,this->getChildByName("kid")->getContentSize());
    gmp->setName("GameMap");
    this->addChild(gmp);
 

    auto control = ActorController::CreateController(ball);
    control->setName("Controller");
    this->addChild(control);


    EventListenerPhysicsContact* contact = EventListenerPhysicsContact::create();
    contact->onContactPreSolve = [=](PhysicsContact& contact,PhysicsContactPreSolve& slove)
    {
        auto NodeA = contact.getShapeA()->getBody();
        auto NodeB = contact.getShapeB()->getBody();
        if (NodeA&&NodeB)
        {
            if ((NodeA->getGroup() == 1 && NodeB->getGroup() == 3)||(NodeB->getGroup() == 1 && NodeA->getGroup() == 3  )) {
                ball->setcanjump(true);
                
            }
            
            if ((NodeA->getGroup() == 2 && NodeB->getGroup() == 3) || (NodeB->getGroup() == 2 && NodeA->getGroup() == 3)) {
                this->kill();
            }
            if ((NodeA->getGroup() == 4 && NodeB->getGroup() == 3) || (NodeA->getGroup() == 3 && NodeB->getGroup() == 4))
            {
                ball->setcanmove(false);
                ball->getPhysicsBody()->setEnabled(false);
                int shuju = UserDefault::getInstance()->getIntegerForKey("guoguan");
                if (shuju == Guanqia)
                {
                    if (shuju < 8)
                    {
                        shuju++;
                    }
                    UserDefault::getInstance()->setIntegerForKey("guoguan", shuju);
                }
                auto spa = Spawn::create(FadeOut::create(0.2f), nullptr);
                auto children = this->getChildren();
                for (Node* child : children)
                {


                    auto seq = Sequence::create( spa, CallFunc::create([=]() {
                            child->removeAllChildrenWithCleanup(true);
                    }), nullptr);

                    child->runAction(seq->clone());

                    
                }

                this->runAction(Sequence::create(DelayTime::create(3.0f), CallFunc::create([=]() {
                    
                    //Director::getInstance()->replaceScene(TransitionFade::create(0.2f, Start::createScene()));
                    Director::getInstance()->popToRootScene();
                }),nullptr));
            }
        }
        return true;
    };
    
    contact->onContactSeparate = [=](PhysicsContact& contact)
    {
        auto NodeA = contact.getShapeA()->getBody();
        auto NodeB = contact.getShapeB()->getBody();
        if (NodeA && NodeB)
        {
            if ((NodeA->getGroup() == 1 && NodeB->getGroup() == 3) || (NodeB->getGroup() == 1 && NodeA->getGroup() == 3)) {
                ball->setcanjump(false);
                
                
            }
            

        }
        return true;
    };

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contact, this);

    
    

    return true;
}



void HelloWorld::update(float dt)
{
    
    auto visi = Director::getInstance()->getVisibleSize();
    if (!this->getBoundingBox().intersectsRect(ball->getBoundingBox()))
    {
        this->kill();
    }
    
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}

void HelloWorld::kill()
{
    ball->setcanjump(false);
    ball->setcanmove(false);
    ball->getPhysicsBody()->setEnabled(false);
    
    auto fade = Spawn::create(FadeOut::create(0.5f),ScaleTo::create(0.5f,0.4f),nullptr);
    auto out = Spawn::create(FadeIn::create(0.5f), ScaleTo::create(0.5f, 0.5f), nullptr);

    auto visibleSize = Director::getInstance()->getWinSize();

    


    Vec2 bp=Vec2(visibleSize.width/2-ball->getContentSize().width*0.4f*MapSize.width/2+ball->getContentSize().width*0.4f*birth::BirthPlaces->x,
                 visibleSize.height/2+ball->getContentSize().height*0.4f*MapSize.height/2-ball->getContentSize().height*0.4f*birth::BirthPlaces->y
    );

    this->getChildByName("kid")->runAction(Sequence::create(fade,Place::create(static_cast<const Vec2>(bp)),out, CallFunc::create([=]() {
        this->getChildByName("kid")->getPhysicsBody()->setEnabled(true);
        this->getChildByName("kid")->getPhysicsBody()->setVelocity(Vec2(0.0f,0.0f));
        this->canmove = true;
        }), nullptr));
    
}

void HelloWorld::onEnter() {
    Node::onEnter();
    dynamic_cast<GameMap*>(this->getChildByName("GameMap"))->load();
    dynamic_cast<ActorController*>(this->getChildByName("Controller"))->load();
    ball->load();
}