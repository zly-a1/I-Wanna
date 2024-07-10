#include "GameMap.h"

USING_NS_CC;

bool GameMap::Init()
{
    int i = 0;
    int k = 0;



    auto VisibleSize = Director::getInstance()->getWinSize();

    Vec2 blockpos = Vec2(VisibleSize.width / 2 - MapSize.width * BlockSize.width * 0.4f / 2, VisibleSize.height / 2 + MapSize.height * BlockSize.height * 0.4f / 2);

    for (i = 0; i < MapSize.height; i++)
    {

        for (k = 0; k < MapSize.width; k++)
        {
            if (Map[i][k] == 1)
            {

                auto s = Sprite::create("Block.png");
                s->setPosition(blockpos);
                s->setScale(0.4f);
                s->setOpacity(0);
                s->setTag((i + 1) * (k + 1));
                auto phy1 = PhysicsBody::createBox(s->getContentSize(), PhysicsMaterial(0.2f, 0.0f, 0.0f));
                phy1->setContactTestBitmask(1);
                phy1->setCollisionBitmask(1);
                s->addComponent(phy1);
                s->getPhysicsBody()->setDynamic(false);
                s->getPhysicsBody()->setGroup(1);
                this->addChild(s);


            }
            if (Map[i][k] == 2 || Map[i][k] == 4 || Map[i][k] == 5 || Map[i][k] == 6)
            {
                auto s = Sprite::create("Spike.png");
                s->setPosition(blockpos);
                s->setScale(0.4f);
                s->setOpacity(0);
                s->setTag((i + 1) * (k + 1));
                auto poly = AutoPolygon::generatePolygon("Spike.png");
                auto count = poly.triangles.indexCount;
                auto indc = poly.triangles.indices;
                auto verts = poly.triangles.verts;

                Vec2* ps = new Vec2[count];
                for (int t = 0; t < count - 1; t++)
                {
                    ps[t].x = verts[indc[t]].vertices.x - s->getContentSize().width / 2;
                    ps[t].y = verts[indc[t]].vertices.y - s->getContentSize().height / 2;
                }

                auto phy1 = PhysicsBody::createPolygon(ps, count);
                phy1->setContactTestBitmask(1);
                phy1->setCollisionBitmask(1);
                s->addComponent(phy1);
                s->getPhysicsBody()->setDynamic(false);
                s->getPhysicsBody()->setGroup(2);
                this->addChild(s);
                if (Map[i][k] == 6)
                {
                    s->setRotation(90.0f);
                }

                if (Map[i][k] == 4)
                {
                    s->setRotation(-90.0f);
                }
                if (Map[i][k] == 5)
                {
                    s->setRotation(180.0f);
                }
                if (Map[i][k] == 2)
                {
                    s->setRotation(0.0f);
                }

                delete[]ps;
            }



            if (Map[i][k] == 3)
            {
                auto s = Sprite::create("Warp.png");
                s->setPosition(blockpos);
                s->setScale(0.4f);
                s->setOpacity(0);
                s->setTag((i + 1) * (k + 1));
                auto poly = AutoPolygon::generatePolygon("Warp.png");
                auto count = poly.triangles.indexCount;
                auto indc = poly.triangles.indices;
                auto verts = poly.triangles.verts;

                Vec2* ps = new Vec2[count];
                for (int t = 0; t < count - 1; t++)
                {
                    ps[t].x = verts[indc[t]].vertices.x - s->getContentSize().width / 2;
                    ps[t].y = verts[indc[t]].vertices.y - s->getContentSize().height / 2;
                }

                auto phy1 = PhysicsBody::createPolygon(ps, count);
                phy1->setContactTestBitmask(1);
                phy1->setCollisionBitmask(1);
                s->addComponent(phy1);
                s->getPhysicsBody()->setDynamic(false);
                s->getPhysicsBody()->setGroup(4);
                this->addChild(s);



                delete[]ps;
            }
            blockpos.x += BlockSize.width * 0.4f;
        }
        blockpos.y -= BlockSize.height * 0.4f;
        blockpos.x = VisibleSize.width / 2 - MapSize.width * BlockSize.height * 0.4f / 2;


    }
    return true;
}

GameMap* GameMap::CreateMap(std::vector<std::vector<float>> gamemap,Size mapsize,Size blocksize)
{
	auto node = new (std::nothrow) GameMap();
	if (node&&node->init())
	{
		node->Map = gamemap;
        node->MapSize = mapsize;
        node->BlockSize = blocksize;
		node->Init();
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
}

void GameMap::load() {
    for (auto child : this->getChildren()) {
        child->runAction(FadeIn::create(0.2f));
    }
}