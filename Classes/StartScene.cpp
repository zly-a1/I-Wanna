
#include "StartScene.h"



#include <string>
#include <iostream>
#include <external/win32-specific/icon/include/iconv.h>


USING_NS_CC;

 


Scene* Start::createScene()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto scene = Scene::create();
    auto st = Start::create();

    
    
    scene->addChild(st);
    return scene;
}



// Print useful error message instead of segfaulting when files are not there.


// on "init" you need to initialize your instance
bool Start::init()
{
    //////////////////////////////
    // 1. super init first


    if (!Scene::init())
    {

        return false;


    }
    
    if (!UserDefault::getInstance()->getIntegerForKey("guoguan"))
    {
        UserDefault::getInstance()->setIntegerForKey("guoguan",1);
        UserDefault::getInstance()->flush();
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    this->scheduleUpdate();

    
    
    

    button = ui::Button::create("play.png","play.png");
    button->setOpacity(0);
    button->setName("play");
    button->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 3*2));

 
    
    this->addChild(button);
    
    

    button->addTouchEventListener([=](Ref* r, ui::Widget::TouchEventType t) {
        if (t==ui::Widget::TouchEventType::BEGAN)
        {
            button->setScale(1.0f);
            button->runAction(FadeTo::create(0.0f, 127));
        }
        if (t == ui::Widget::TouchEventType::ENDED)
        {
            button->setScale(1.0f);
            
            button->runAction(Sequence::create(FadeTo::create(0.0f, 255), FadeOut::create(0.2f), nullptr));

            custom->runAction(FadeOut::create(0.2f));

            

            this->runAction(Sequence::create(DelayTime::create(0.2f), CallFunc::create([=]() {
                
                Director::getInstance()->replaceScene(Choose::createScene());
                }), nullptr));
        }
        });

    custom = ui::Button::create("custom.png","custom.png");
    custom->setOpacity(0);
    custom->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 3));
    this->addChild(custom);

    custom->addTouchEventListener([=](Ref* r, ui::Widget::TouchEventType t) {
        if (t == ui::Widget::TouchEventType::BEGAN)
        {
            custom->setScale(1.0f);
            custom->runAction(FadeTo::create(0.0f, 127));

            auto tip = Label::createWithSystemFont("it's nothing now","arial",15);
            tip->setColor(Color3B(255, 255, 255));
            tip->setPosition(Vec2(visibleSize.width / 2, custom->getPositionY() - 80));
            this->addChild(tip);
            tip->runAction(Sequence::create(FadeIn::create(0.2f), DelayTime::create(1.0f), FadeOut::create(0.2f), CallFunc::create(
                [=]() {
                    tip->removeAllChildrenWithCleanup(true);
                }
            ), nullptr)
            );
        }
        if (t == ui::Widget::TouchEventType::ENDED)
        {

            custom->runAction(FadeTo::create(0.0f, 255));


            //button->runAction(FadeOut::create(0.2f));
        }
        });

    

    auto creator = Label::createWithSystemFont(convertToUTF8("作者：郑霖懿"), "arial", 15);
    creator->setColor(Color3B(255, 255, 255));
    creator->setPosition(visibleSize.width - creator->getContentSize().width / 2,creator->getContentSize().height/ 2);
    this->addChild(creator);


    return true;

    
}

void Start::onEnter() {
    Node::onEnter();
    button->runAction(FadeIn::create(0.2f));
    custom->runAction(FadeIn::create(0.2f));
    
}

void Start::onExit() {
    Node::onExit();
}

void Start::update(float delta) {

}




std::string Start::convertToUTF8(const std::string& strGB)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> cvt;
    std::wstring strW = cvt.from_bytes(strGB);
    std::string strUTF8 = cvt.to_bytes(strW);

    return strUTF8;
}
