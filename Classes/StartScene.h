
#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"
#include <iconv.h>
#include "ChooseScene.h"
#include "ui/CocosGUI.h"
#include <string>
#include <vector>
#include <codecvt>
#include <locale>



using namespace std;

class Start : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init()override;

    virtual void onEnter()override;
    virtual void onExit()override;

    virtual void update(float delta)override;

    std::string convertToUTF8(const std::string& strGB);

    cocos2d::ui::Button* button;
    cocos2d::ui::Button* custom;

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Start);
};

#endif 


