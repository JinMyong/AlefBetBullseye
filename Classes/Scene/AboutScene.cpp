//
//  AboutScene.cpp
//  AlephBet
//
//  Created by Fredric on 1/12/16.
//
//

#include "AboutScene.hpp"
#include "MainMenuScene.hpp"
#include "Const.h"
#include "Global.hpp"
#include "SoundEffects.hpp"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    #include "SocialGame.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    #include "platform/android/jni/JniHelper.h"
#endif

CCScene* AboutScene::scene()
{
    CCScene* scene = CCScene::create();
    AboutScene* layer = AboutScene::create();
    scene->addChild(layer);
    return scene;
}

bool AboutScene::init()
{
    if (!CCLayer::create()) {
        return false;
    }
    
    winSize = CCDirector::sharedDirector()->getWinSize();
    createUI();
    
    return true;
}

void AboutScene::createUI()
{
    // Add Backgrouond image
    CCSprite* bg = CCSprite::create(getResPath(ABOUT_BG_IMG));
    bg->setScaleX(SCALEX);
    bg->setScaleY(SCALEY);
    bg->setPosition(ccp(winSize.width * 0.5, winSize.height * 0.5));
    this->addChild(bg);
    
    // Add Scene title
    CCSprite* title_scene = CCSprite::create(getResPath(ABOUT_TITLE_SCENE_IMG));
    title_scene->setScale(SCALE);
    title_scene->setPosition(ccp(winSize.width * 0.5, winSize.height - 45 * SCALEY));
    this->addChild(title_scene);
    
    // Add Text Background
    CCSprite* txt_bg = CCSprite::create(getResPath(ABOUT_TEXT_BG_IMG));
    txt_bg->setScaleX(SCALEX);
    txt_bg->setScaleY(SCALEY);
    txt_bg->setPosition(ccp(winSize.width * 0.5, winSize.height * 0.5 + 20 * SCALEY));
    this->addChild(txt_bg);
    
    // Add Text
    CCSprite* txt_title = CCSprite::create(getResPath(ABOUT_TITLE_GAME_IMG));
    txt_title->setPosition(ccp(winSize.width * 0.5, winSize.height - 165 * SCALEY));
    txt_title->setScale(SCALE);
    this->addChild(txt_title);
    
    CCSprite* txt_game = CCSprite::create(getResPath(ABOUT_TEXT_GAME));
    txt_game->setScale(SCALE);
    txt_game->setPosition(ccp(winSize.width * 0.5, 750 * SCALEY));
    this->addChild(txt_game);
    
    // Add "Tell a Friend" button
    CCMenuItemImage* btn_email = CCMenuItemImage::create(getResPath(ABOUT_BTN_EMAIL_IMG_NOR), getResPath(ABOUT_BTN_EMAIL_IMG_PRS), this, menu_selector(AboutScene::emailHandler));
    btn_email->setScale(SCALE * 0.8);
    btn_email->setPosition(ccp(415 * SCALEX, 407 * SCALEY));
    
    // Add Link Button
    CCMenuItemImage* btn_link = CCMenuItemImage::create(getResPath(ABOUT_BTN_LINK_IMG_NOR), getResPath(ABOUT_BTN_LINK_IMG_PRS), this, menu_selector(AboutScene::linkHandler));
    btn_link->setScale(SCALE * 0.8);
    btn_link->setPosition(ccp(415 * SCALEX, 312 * SCALEY));
    
    // Add mainmenu button
    CCMenuItem* btn_menu = CCMenuItemImage::create(getResPath(ABOUT_BTN_MAINMENU_IMG_NOR), getResPath(ABOUT_BTN_MAINMENU_IMG_PRS), this, menu_selector(AboutScene::mainmenuHandler));
    btn_menu->setScale(SCALE * 0.8);
    btn_menu->setPosition(ccp(415 * SCALEX, 217 * SCALEY));
    
    CCMenu* menu = CCMenu::create(btn_menu, btn_email, btn_link, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu);
    
    // Add Character
    CCSprite* character = CCSprite::create(getResPath(ABOUT_CHARACTER_IMG));
    character->setScale(SCALE);
    character->setAnchorPoint(ccp(0, 0));
    character->setPosition(ccp(10 * SCALEX, 10 * SCALEY));
    this->addChild(character);
}

void AboutScene::mainmenuHandler(cocos2d::CCObject *sender)
{
    SoundEffects::getInstance()->playButtonEffect();
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.0, MainMenuScene::scene()));
}

void AboutScene::emailHandler(cocos2d::CCObject *sender)
{
    SoundEffects::getInstance()->playButtonEffect();
    CCString* emailtext = CCString::createWithFormat("%s\n%s", EMAIL_TEXT_FRIEND, ANDROID_URL);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    SocialGame::sendemail(EMAIL_TEXT_FRIEND);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t
                    , "com/bullseye/alefbet/AlefBetBullseye"
                    , "sendemail"
                    , "(Ljava/lang/String;)V"))
    {
        jstring StringArg1 = t.env->NewStringUTF(emailtext->getCString());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, StringArg1);
    }
#endif
}

void AboutScene::linkHandler(cocos2d::CCObject *sender)
{
    SoundEffects::getInstance()->playButtonEffect();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    SocialGame::openWebSite();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t
                                       , "com/bullseye/alefbet/AlefBetBullseye"
                                       , "openWebsite"
                                       , "(Ljava/lang/String;)V"))
    {
        jstring StringArg1 = t.env->NewStringUTF(WEBSITE_URL);
        t.env->CallStaticVoidMethod(t.classID, t.methodID, StringArg1);
    }
#endif
}