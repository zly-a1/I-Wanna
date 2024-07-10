#include "Player.h"
USING_NS_CC;

bool Player::Init() {
    Size visibleSize = Director::getInstance()->getWinSize();

    Vec2 bp = Vec2(visibleSize.width / 2 - this->getContentSize().width * 0.4f * this->MapSize.width / 2 + this->getContentSize().width * 0.4f * this->BirthPlace.x,
        visibleSize.height / 2 + this->getContentSize().height * 0.4f * this->MapSize.height / 2 - this->getContentSize().height * 0.4f * this->BirthPlace.y
    );

    this->setName("kid");
    this->setOpacity(0);
    this->setPosition(bp);
    this->setScale(0.5f);

    Vec2* point = new Vec2[8];
    point[0] = Vec2(16.0f - 25, 0.0f - 25);
    point[1] = Vec2(34.0f - 25, 0.0f - 25);
    point[2] = Vec2(50.0f - 25, 16.0f - 25);
    point[3] = Vec2(50.0f - 25, 34.0f - 25);
    point[4] = Vec2(34.0f - 25, 50.0f - 25);
    point[5] = Vec2(16.0f - 25, 50.0f - 25);
    point[6] = Vec2(0.0f - 25, 34.0f - 25);
    point[7] = Vec2(0.0f - 25, 16.0f - 25);


    auto ballphy = PhysicsBody::createPolygon(point, 8);

    ballphy->setRotationEnable(false);
    ballphy->setEnabled(false);
    ballphy->setDynamic(true);
    ballphy->setContactTestBitmask(1);
    ballphy->setCollisionBitmask(1);
    ballphy->setCategoryBitmask(1);
    
    ballphy->setGroup(3);
    this->addComponent(ballphy);
    return true;
}

Player* Player::CreatePlayer(const std::string img,Size mapsize,Vec2 birthplace) {
    auto pl = new (std::nothrow)Player();
    if (pl&&pl->initWithFile(img))
    {
        pl->MapSize = mapsize;
        pl->BirthPlace = birthplace;
        pl->Init();
        pl->autorelease();
        return pl;
    }
    CC_SAFE_DELETE(pl);
    return NULL;
    

}

void Player::load() {
    this->runAction(FadeIn::create(0.5f));
    this->getPhysicsBody()->setEnabled(true);
}

void Player::setcanjump(bool canjump) {
    this->canjump = canjump;
}

bool Player::getcanjump() {
    return this->canjump;
}

void Player::setcanmove(bool canmove) {
    this->canmove = canmove;
}

bool Player::getcanmove() {
    return this->canmove;
}

Player::~Player()
{

}

Player::Player()
{

}