#include "ActorController.h"
USING_NS_CC;


bool ActorController::Init() {
    auto visibleSize = Director::getInstance()->getVisibleSize();

    if (CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)
    {
        this->left = ui::Button::create("control.png","control.png");
        left->setOpacity(0);
        left->setRotation(-90.0f);
        left->setPosition(Vec2(visibleSize.width / 5, visibleSize.height / 8));
        left->setName("l");
        left->setScale(1.5f);
        

        right = ui::Button::create("control.png","control.png");
        right->setOpacity(0);
        right->setPosition(Vec2(visibleSize.width / 5 * 2, visibleSize.height / 8));
        right->setRotation(90.0f);
        right->setScale(1.5f);
        right->setName("r");
        

        jump = ui::Button::create("control.png","control.png");
        jump->setOpacity(0);
        jump->setRotation(0.0f);
        jump->setPosition(Vec2(visibleSize.width / 5 * 4, visibleSize.height / 8));
        jump->setScale(1.5f);
        jump->setName("j");
        

        this->addChild(left);
        this->addChild(right);
        this->addChild(jump);


        jump->addTouchEventListener([=](Ref* r, ui::Widget::TouchEventType t) {
            if (t == ui::Widget::TouchEventType::BEGAN)
                if (target->getcanjump())
                {
                    jump->setOpacity(127);
                    auto v = target->getPhysicsBody()->getVelocity();
                    v.y = 200.0f;
                    target->getPhysicsBody()->setVelocity(v);
                }
            if (t == ui::Widget::TouchEventType::ENDED)
                if (target->getcanjump())
                {
                    jump->setOpacity(255);
                    
                }
            });

        left->addTouchEventListener([=](Ref* r, ui::Widget::TouchEventType t) {
            if (t == ui::Widget::TouchEventType::BEGAN)
            {
                left->setOpacity(127);
                auto v = target->getPhysicsBody()->getVelocity();
                v.x = -200.0f;
                target->getPhysicsBody()->setVelocity(v);
            }
            if (t == ui::Widget::TouchEventType::ENDED)
            {
                left->setOpacity(255);
                auto v = target->getPhysicsBody()->getVelocity();
                v.x = 0.0f;
                target->getPhysicsBody()->setVelocity(v);
            }
            });
        right->addTouchEventListener([=](Ref* r, ui::Widget::TouchEventType t) {
            if (t == ui::Widget::TouchEventType::BEGAN)
            {
                right->setOpacity(127);
                auto v = target->getPhysicsBody()->getVelocity();
                v.x = 200.0f;
                target->getPhysicsBody()->setVelocity(v);
            }
            if (t == ui::Widget::TouchEventType::ENDED)
            {
                right->setOpacity(255);
                auto v = target->getPhysicsBody()->getVelocity();
                v.x = 0.0f;
                target->getPhysicsBody()->setVelocity(v);
            }
            });
    }
    else {
        this->PClistener = EventListenerKeyboard::create();
        PClistener->onKeyPressed = [=](EventKeyboard::KeyCode c, Event* e) {
            auto v = Vec2(0, 0);
            switch (c)
            {
            case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
                v = this->target->getPhysicsBody()->getVelocity();
                v.x = -200.0f;
                target->getPhysicsBody()->setVelocity(v);
                break;
            case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
                v = this->target->getPhysicsBody()->getVelocity();
                v.x = 200.0f;
                target->getPhysicsBody()->setVelocity(v);
                break;
            case EventKeyboard::KeyCode::KEY_SPACE:
                if (target->getcanjump())
                {
                    v = this->target->getPhysicsBody()->getVelocity();
                    v.y = 200.0f;
                    target->getPhysicsBody()->setVelocity(v);
                    break;
                }
            
            }
            };
        PClistener->onKeyReleased = [=](EventKeyboard::KeyCode c, Event* e) {
            auto v = Vec2(0, 0);
            switch (c)
            {
            case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
                v = target->getPhysicsBody()->getVelocity();
                v.x = 0.0f;
                target->getPhysicsBody()->setVelocity(v);
                break;
            case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
                v = target->getPhysicsBody()->getVelocity();
                v.x = 0.0f;
                target->getPhysicsBody()->setVelocity(v);
                break;
            
            
            }
            };
        _eventDispatcher->addEventListenerWithSceneGraphPriority(PClistener, target);
    }
    return true;
}

ActorController* ActorController::CreateController(Player* tg) {
    auto cl = new (std::nothrow)ActorController();
    if (cl && cl->init())
    {
        cl->target = tg;
        cl->Init();
        cl->autorelease();
        return cl;
    }
    CC_SAFE_DELETE(cl);
    return NULL;
}

void ActorController::load() {
    if (CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)
    {
        for (auto child : this->getChildren()) {
            child->runAction(FadeIn::create(0.2f));
        }
    }
    
}
