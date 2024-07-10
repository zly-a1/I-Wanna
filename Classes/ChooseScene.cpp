
#include "ChooseScene.h"
#include "HelloWorldScene.h"

#include <string>
#include <iostream>
#include <fstream>


USING_NS_CC;


Scene* Choose::createScene()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto scene = Scene::create();
    auto sc = Choose::create();
    
   
    
    
    scene->addChild(sc);
    
    return scene;
}






// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(float filename)
{
    printf("Error while loading: %f\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}


Sprite* Choose::addSpriteatPosition(Vec2 pos, std::string img,int tag)
{
    auto Spr = Sprite::create(img);
    Spr->setPosition(pos.x, pos.y);
    Spr->setTag(tag);
    return Spr;
}

// on "init" you need to initialize your instance
bool Choose::init()
{
    //////////////////////////////
    // 1. super init first
    int guoguan = UserDefault::getInstance()->getIntegerForKey("guoguan");
    

    if (!Scene::init())
    {

        return false;


    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    

    

    auto candrag = false;

    std::string pngname[10] = {"one.png","two.png","three.png","four.png","five.png","six.png","seven.png","eight.png","nine.png","ten.png"};
    int sptag[10] = {1,2,3,4,5,6,7,8,9,10};

    for (int i = 0; i < 10; i++)
    {
        auto s = Sprite::create(pngname[i]);
        s->setOpacity(0);
        s->setTag(sptag[i]);
        if (i < 5)
        {
            s->setPosition(Vec2(visibleSize.width/6+i*visibleSize.width/6,visibleSize.height/3*2));
        }
        if (i >= 5)
        {
            s->setPosition(Vec2(visibleSize.width / 6 + (i-5) * visibleSize.width / 6, visibleSize.height / 3 * 1));
        }
        
        this->addChild(s);
        
    }
    candrag = true;
    auto chooselis = EventListenerTouchOneByOne::create();
    chooselis->onTouchBegan = [=](Touch* t, Event* e)
    {
        if (candrag)
        {
            if (e->getCurrentTarget()->getBoundingBox().containsPoint(t->getLocation())) {
                if (guoguan>= e->getCurrentTarget()->getTag())
                {
                    guan = e->getCurrentTarget()->getTag();
                }
                if (e->getCurrentTarget()->getTag()==7)
                {

                }
            
            }

            
            if (guan!=0)
            {
                this->getChildByTag(guan)->runAction(FadeTo::create(0.0f,127));
                
            }

            
        }
        return true;
    };
    chooselis->onTouchEnded = [=](Touch* t, Event* e)
    {
        if (candrag)
        {
            
            
            


            if (guan!=0&&guan<8)
            {
                for (auto child:this->getChildren())
                {
                    child->runAction(FadeOut::create(0.2f));
                }
                    
                this->runAction(Sequence::create(DelayTime::create(0.2f), CallFunc::create([=]() {
                    auto scene = HelloWorld::createScene(guan);
                    Director::getInstance()->pushScene(scene);
                    }), nullptr)
                );

                
            }
        }
    };
    for (int o = 1; o < 11; o++)
    {
        _eventDispatcher->addEventListenerWithSceneGraphPriority(chooselis->clone(), this->getChildByTag(o));
    }
    
    return true;
}

void Choose::onEnter() {
    Node::onEnter();
    int guoguan = UserDefault::getInstance()->getIntegerForKey("guoguan");
    for (auto child:this->getChildren())
    {
        if (child->getTag() <= guoguan)
        {
            child->runAction(FadeIn::create(0.2f));
        }
        else {
            child->runAction(FadeTo::create(0.2f,127));
        }
    }
}

void Choose::onExit() {
    Node::onExit();
}