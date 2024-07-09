/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "AppDelegate.h"
#include "StartScene.h"



// #define USE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

#include <Windows.h>
#include <Uxtheme.h>
#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")
#endif

USING_NS_CC;




static cocos2d::Size designResolutionSize = cocos2d::Size(1280,720);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#endif
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil,multisamplesCount
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8, 0};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {




    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();


    if(!glview) {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("I Wanna", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
        
#else
        glview = GLViewImpl::create("park");


#endif
        director->setOpenGLView(glview);
    }
#if(CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
    HICON icon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
    HICON icon1 = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON2));
    ::SendMessage(glview->getWin32Window(), WM_SETICON, ICON_BIG, (LPARAM)icon1);
    ::SendMessage(glview->getWin32Window(), WM_SETICON, ICON_SMALL, (LPARAM)icon);
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    HWND hWnd = Director::getInstance()->getOpenGLView()->getWin32Window();
    
    
#endif
   



    // turn on display FPS
    director->setDisplayStats(false);

    

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 120);

    auto screenSize = glview->getFrameSize();
    auto designSize = designResolutionSize;



    if(CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)
    {
        Director::getInstance()->getOpenGLView()->setDesignResolutionSize(designSize.width*screenSize.height/designSize.height,designSize.height,ResolutionPolicy::SHOW_ALL);
    }
    else{
        Director::getInstance()->getOpenGLView()->setDesignResolutionSize(designSize.width,designSize.height,ResolutionPolicy::NO_BORDER);
    }






    //register_all_packages();

    // create a scene. it's an autorelease object
    auto scene = Start::createScene();

    scene->setName("start");
    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#endif
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#endif
}