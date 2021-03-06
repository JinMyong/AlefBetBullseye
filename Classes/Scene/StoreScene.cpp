//
//  StoreScene.cpp
//  AlephBet
//
//  Created by Fredric on 1/25/16.
//
//

#include "StoreScene.hpp"
#include "Const.h"
#include "MainMenuScene.hpp"
#include "Global.hpp"
#include "SoundEffects.hpp"


#define ITEM_PENCIL_POS         ccp(192 * SCALEX, 470 * SCALEY)
#define ITEM_FISH_POS           ccp(182 * SCALEX, 460 * SCALEY)
#define ITEM_STAR_POS           ccp(192 * SCALEX, 470 * SCALEY)
#define ITEM_BULB_POS           ccp(188 * SCALEX, 471 * SCALEY)
#define ITEM_MATAZHBALL_POS     ccp(192 * SCALEX, 457 * SCALEY)
#define ITEM_MATAZH_POS         ccp(192 * SCALEX, 470 * SCALEY)


bool StoreScene::init()
{
    if (!CCLayer::init())
    {
        return false;
    }
    winSize = CCDirector::sharedDirector()->getWinSize();
    options = GameOptions::getInstance();
    CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache->addSpriteFramesWithFile(getResPath("images/storeScene/store_character.plist"));
    createUI();
    
    currentCoin = options->getCoins();
    
    return true;
}

CCScene* StoreScene::scene()
{
    CCScene* scene = CCScene::create();
    StoreScene *layer = StoreScene::create();
    scene->addChild(layer);
    return scene;
}

void StoreScene::createUI()
{
    // Add Background Image
    CCSprite* bg_spt = CCSprite::create(getResPath(STORE_BG_IMG));
    bg_spt->setScaleX(SCALEX);
    bg_spt->setScaleY(SCALEY);
    bg_spt->setPosition(ccp(winSize.width * 0.5, winSize.height * 0.5));
    this->addChild(bg_spt, ZORDER_BG);
    
    // Add Shuk title
    CCSprite* title_shuk = CCSprite::create(getResPath(STORE_TITLE_IMG));
    title_shuk->setScale(SCALE);
    title_shuk->setPosition(ccp(winSize.width * 0.5, winSize.height - 45 * SCALEY));
    this->addChild(title_shuk);
    
    // Add Character image
    int item = options->getItem();
    char frameName[50];
    sprintf(frameName, "character_shuk_%d.png", item);
    CCSprite* character = CCSprite::createWithSpriteFrameName(frameName);
    character->setTag(TAG_CHARACTER);
    character->setScale(SCALE);
    character->setPosition(ccp(232 * SCALEX, 378 * SCALEY));
    this->addChild(character, ZORDER_CHARACTER);
    
    // Add Coin Image
    CCSprite* spt_coin = CCSprite::create(getResPath(GAMERESULT_COIN_IMG));
    spt_coin->setScale(SCALE * 1.2);
    spt_coin->setPosition(ccp(450 * SCALEX, winSize.height - 135 * SCALEY));
    this->addChild(spt_coin);
    
    // Add coin count label
    int current_coin = options->getCoins();
    char coin_str[10];
    sprintf(coin_str, "%d", current_coin);
    CCLabelTTF* lbl_coin = CCLabelTTF::create(coin_str, STANDARD_FONT, 55 * SCALE);
    lbl_coin->setHorizontalAlignment(kCCTextAlignmentRight);
    lbl_coin->setAnchorPoint(ccp(1, 0.5));
    lbl_coin->setPosition(ccp(winSize.width - 20 * SCALEX, spt_coin->getPositionY()));
    lbl_coin->setTag(TAG_COIN);
    this->addChild(lbl_coin);
    
    // Add Table image
    CCSprite* table = CCSprite::create(getResPath(STORE_TABLE_IMG));
    table->setScaleX(SCALEX);
    table->setScaleY(SCALEY);
    table->setPosition(ccp(winSize.width * 0.5, 244 * SCALEY));
    this->addChild(table, ZORDER_TABLE);
    
//    CCMenuItemImage* pencil_on = CCMenuItemImage::create(getResPath(STORE_TABLE_PENCIL_ON), getResPath(STORE_TABLE_PENCIL_ON));
    CCMenuItemImage* pencil_off = CCMenuItemImage::create(getResPath(STORE_TABLE_PENCIL_OFF), getResPath(STORE_TABLE_PENCIL_OFF));
    table_pencil = CCMenuItemToggle::createWithTarget(this, menu_selector(StoreScene::tableHandler), pencil_off, pencil_off, NULL);
    table_pencil->setTag(TAG_PENCIL);
    table_pencil->setScale(SCALE);
    table_pencil->setPosition(ccp(50 * SCALEX, 306 * SCALEY));
    
//    CCMenuItemImage* fish_on = CCMenuItemImage::create(getResPath(STORE_TABLE_FISH_ON), getResPath(STORE_TABLE_FISH_ON));
    CCMenuItemImage* fish_off = CCMenuItemImage::create(getResPath(STORE_TABLE_FISH_OFF), getResPath(STORE_TABLE_FISH_OFF));
    table_fish = CCMenuItemToggle::createWithTarget(this, menu_selector(StoreScene::tableHandler), fish_off, fish_off, NULL);
    table_fish->setTag(TAG_FISH);
    table_fish->setScale(SCALE);
    table_fish->setPosition(ccp(130 * SCALEX, 306 * SCALEY));
    
//    CCMenuItemImage* star_on = CCMenuItemImage::create(getResPath(STORE_TABLE_STAR_ON), getResPath(STORE_TABLE_STAR_ON));
    CCMenuItemImage* star_off = CCMenuItemImage::create(getResPath(STORE_TABLE_STAR_OFF), getResPath(STORE_TABLE_STAR_OFF));
    table_star = CCMenuItemToggle::createWithTarget(this, menu_selector(StoreScene::tableHandler), star_off, star_off, NULL);
    table_star->setTag(TAG_STAR);
    table_star->setScale(SCALE);
    table_star->setPosition(ccp(240 * SCALEX, 306 * SCALEY));
    
//    CCMenuItemImage* bulb_on = CCMenuItemImage::create(getResPath(STORE_TABLE_BULB_ON), getResPath(STORE_TABLE_BULB_ON));
    CCMenuItemImage* bulb_off = CCMenuItemImage::create(getResPath(STORE_TABLE_BULB_OFF), getResPath(STORE_TABLE_BULB_OFF));
    table_bulb = CCMenuItemToggle::createWithTarget(this, menu_selector(StoreScene::tableHandler), bulb_off, bulb_off, NULL);
    table_bulb->setTag(TAG_BULB);
    table_bulb->setScale(SCALE);
    table_bulb->setPosition(ccp(350 * SCALEX, 306 * SCALEY));
    
//    CCMenuItemImage* matzahball_on = CCMenuItemImage::create(getResPath(STORE_TABLE_MATZAHBALL_ON), getResPath(STORE_TABLE_MATZAHBALL_ON));
    CCMenuItemImage* matzahball_off = CCMenuItemImage::create(getResPath(STORE_TABLE_MATZAHBALL_OFF), getResPath(STORE_TABLE_MATZAHBALL_OFF));
    table_matzahball = CCMenuItemToggle::createWithTarget(this, menu_selector(StoreScene::tableHandler), matzahball_off, matzahball_off, NULL);
    table_matzahball->setTag(TAG_MATZAHBALL);
    table_matzahball->setScale(SCALE);
    table_matzahball->setPosition(ccp(460 * SCALEX, 306 * SCALEY));
    
//    CCMenuItemImage* matzah_on = CCMenuItemImage::create(getResPath(STORE_TABLE_MATZAH_ON), getResPath(STORE_TABLE_MATZAH_ON));
    CCMenuItemImage* matzah_off = CCMenuItemImage::create(getResPath(STORE_TABLE_MATZAH_OFF), getResPath(STORE_TABLE_MATZAH_OFF));
    table_matzah = CCMenuItemToggle::createWithTarget(this, menu_selector(StoreScene::tableHandler), matzah_off, matzah_off, NULL);
    table_matzah->setTag(TAG_MATZAH);
    table_matzah->setScale(SCALE);
    table_matzah->setPosition(ccp(570 * SCALEX, 306 * SCALEY));
    
    CCMenu* table_menu = CCMenu::create(table_pencil, table_fish, table_star, table_bulb, table_matzahball, table_matzah, NULL);
//    table_menu->setPosition(ccp(winSize.width * 0.5, 306 * SCALEY));
    table_menu->setPosition(CCPointZero);
//    table_menu->alignItemsHorizontallyWithPadding(10 * SCALEX);
    this->addChild(table_menu, ZORDEER_MENU);
    
    // Add MainMenu Button
    CCMenuItemImage* btn_mainmenu = CCMenuItemImage::create(getResPath(STORE_MAINMENU_IMG_NOR), getResPath(STORE_MAINMENU_IMG_PRS), this, menu_selector(StoreScene::gotoMainMenu));
    btn_mainmenu->setPosition(ccp(winSize.width * 0.5, 55 * SCALEY));
    btn_mainmenu->setScale(SCALE);
    CCMenu* btn_menu = CCMenu::create(btn_mainmenu, NULL);
    btn_menu->setPosition(CCPointZero);
    this->addChild(btn_menu, ZORDEER_MENU);
    
    showItemPrice();
}

void StoreScene::showItemPrice()
{
    int item_fish_price = PRICE_FISH;
    int item_bulb_price = PRICE_BULB;
    int item_star_price = PRICE_STAR;
    int item_matzah_price = PRICE_MATZAH;
    int item_matzahball_price = PRICE_MATZAHBALL;
    
    CCPoint pos_fish = ccp(110 * SCALEX, 248 * SCALEY);
    CCPoint pos_star = ccp(220 * SCALEX, 248 * SCALEY);
    CCPoint pos_bulb = ccp(330 * SCALEX, 248 * SCALEY);
    CCPoint pos_matzahball = ccp(440 * SCALEX, 248 * SCALEY);
    CCPoint pos_matzah = ccp(550 * SCALEX, 248 * SCALEY);
    
    char price[10];
    sprintf(price, "%d", item_fish_price);
// Add fish
    CCSprite* coin_fish = CCSprite::create(getResPath(GAMERESULT_COIN_IMG));
    coin_fish->setScale(SCALE * COIN_IMG_SCALE);
    coin_fish->setPosition(pos_fish);
    coin_fish->setAnchorPoint(ccp(1, 0.5));
    this->addChild(coin_fish, 100);
    
    CCLabelTTF* fish_price = CCLabelTTF::create(price, STANDARD_FONT, COIN_FONTS_SIZE * SCALE);
    fish_price->setAnchorPoint(ccp(0, 0.5));
    fish_price->setPosition(pos_fish);
    this->addChild(fish_price, 100);
    
// Add Star
    sprintf(price, "%d", item_star_price);
    CCSprite* coin_star = CCSprite::create(getResPath(GAMERESULT_COIN_IMG));
    coin_star->setScale(SCALE * COIN_IMG_SCALE);
    coin_star->setPosition(pos_star);
    coin_star->setAnchorPoint(ccp(1, 0.5));
    this->addChild(coin_star, 100);
    
    CCLabelTTF* star_price = CCLabelTTF::create(price, STANDARD_FONT, COIN_FONTS_SIZE * SCALE);
    star_price->setAnchorPoint(ccp(0, 0.5));
    star_price->setPosition(pos_star);
    this->addChild(star_price, 100);

// Add Bulb
    sprintf(price, "%d", item_bulb_price);
    CCSprite* coin_bulb = CCSprite::create(getResPath(GAMERESULT_COIN_IMG));
    coin_bulb->setScale(SCALE * COIN_IMG_SCALE);
    coin_bulb->setPosition(pos_bulb);
    coin_bulb->setAnchorPoint(ccp(1, 0.5));
    this->addChild(coin_bulb, 100);
    
    CCLabelTTF* bulb_price = CCLabelTTF::create(price, STANDARD_FONT, COIN_FONTS_SIZE * SCALE);
    bulb_price->setAnchorPoint(ccp(0, 0.5));
    bulb_price->setPosition(pos_bulb);
    this->addChild(bulb_price, 100);

// Add Matzah Ball
    sprintf(price, "%d", item_matzahball_price);
    CCSprite* coin_matzahball = CCSprite::create(getResPath(GAMERESULT_COIN_IMG));
    coin_matzahball->setScale(SCALE * COIN_IMG_SCALE);
    coin_matzahball->setPosition(pos_matzahball);
    coin_matzahball->setAnchorPoint(ccp(1, 0.5));
    this->addChild(coin_matzahball, 100);
    
    CCLabelTTF* matzahball_price = CCLabelTTF::create(price, STANDARD_FONT, COIN_FONTS_SIZE * SCALE);
    matzahball_price->setAnchorPoint(ccp(0, 0.5));
    matzahball_price->setPosition(pos_matzahball);
    this->addChild(matzahball_price, 100);
    
// Add Matzah
    sprintf(price, "%d", item_matzah_price);
    CCSprite* coin_matzah = CCSprite::create(getResPath(GAMERESULT_COIN_IMG));
    coin_matzah->setScale(SCALE * COIN_IMG_SCALE);
    coin_matzah->setPosition(pos_matzah);
    coin_matzah->setAnchorPoint(ccp(1, 0.5));
    this->addChild(coin_matzah, 100);
    
    CCLabelTTF* matzah_price = CCLabelTTF::create(price, STANDARD_FONT, COIN_FONTS_SIZE * SCALE);
    matzah_price->setAnchorPoint(ccp(0, 0.5));
    matzah_price->setPosition(pos_matzah);
    this->addChild(matzah_price, 100);
}
void StoreScene::tableHandler(cocos2d::CCObject *sender)
{
    int current_coins = options->getCoins();
    int item_no = ((CCMenuItem*)sender)->getTag();
    
    currentCoin = options->getCoins();
// Set Item
    switch (item_no) {
        case TAG_PENCIL:
            options->setItem(item_Pencil);
            break;
        case TAG_FISH:
            if (options->isBoughtItem(item_Fish)) {
                options->setItem(item_Fish);
            }else
            {
                if (current_coins > PRICE_FISH) {
                    SoundEffects::getInstance()->playUnlockItem();
                    options->setItem(item_Fish);
                    options->setBuyItem(item_Fish);
                    targetCoin = current_coins - PRICE_FISH;
                    float waitTime = 2;
                    float interval = waitTime / PRICE_FISH / 10;
                    this->schedule(schedule_selector(StoreScene::updateCoinLabel), interval, PRICE_FISH / 10, 0);
                }else
                {
                    CCMessageBox(MSG_NOT_ENOUGH_COIN_TXT, MSG_NOT_ENOUGH_COIN_TITLE);
                    return;
                }
            }
            break;
        case TAG_STAR:
            if (options->isBoughtItem(item_JewishStar)) {
                options->setItem(item_JewishStar);
            }else
            {
                if (current_coins > PRICE_STAR) {
                    SoundEffects::getInstance()->playUnlockItem();
                    options->setItem(item_JewishStar);
                    options->setBuyItem(item_JewishStar);
                    targetCoin = current_coins - PRICE_STAR;
                    float waitTime = 2;
                    float interval = waitTime / PRICE_STAR / 10;
                    this->schedule(schedule_selector(StoreScene::updateCoinLabel), interval, PRICE_STAR / 10, 0);
                }else
                {
                    CCMessageBox(MSG_NOT_ENOUGH_COIN_TXT, MSG_NOT_ENOUGH_COIN_TITLE);
                    return;
                }
            }
            break;
        case TAG_BULB:
            if (options->isBoughtItem(item_LightBulb)) {
                options->setItem(item_LightBulb);
            }else
            {
                if (current_coins > PRICE_BULB) {
                    SoundEffects::getInstance()->playUnlockItem();
                    options->setItem(item_LightBulb);
                    options->setBuyItem(item_LightBulb);
                    targetCoin = current_coins - PRICE_BULB;
                    float waitTime = 2;
                    float interval = waitTime / PRICE_BULB / 10;
                    this->schedule(schedule_selector(StoreScene::updateCoinLabel), interval, PRICE_BULB / 10, 0);
                }else
                {
                    CCMessageBox(MSG_NOT_ENOUGH_COIN_TXT, MSG_NOT_ENOUGH_COIN_TITLE);
                    return;
                }
            }
            break;
        case TAG_MATZAHBALL:
            if (options->isBoughtItem(item_MatzahBall)) {
                options->setItem(item_MatzahBall);
            }else
            {
                if (current_coins > PRICE_MATZAHBALL) {
                    SoundEffects::getInstance()->playUnlockItem();
                    options->setItem(item_MatzahBall);
                    options->setBuyItem(item_MatzahBall);
                    targetCoin = current_coins - PRICE_MATZAHBALL;
                    float waitTime = 2;
                    float interval = waitTime / PRICE_MATZAHBALL / 10;
                    this->schedule(schedule_selector(StoreScene::updateCoinLabel), interval, PRICE_MATZAHBALL / 10, 0);
                }else
                {
                    CCMessageBox(MSG_NOT_ENOUGH_COIN_TXT, MSG_NOT_ENOUGH_COIN_TITLE);
                    return;
                }
            }
            break;
        case TAG_MATZAH:
            if (options->isBoughtItem(item_Matzah)) {
                options->setItem(item_Matzah);
            }else
            {
                if (current_coins > PRICE_MATZAH) {
                    SoundEffects::getInstance()->playUnlockItem();
                    options->setItem(item_Matzah);
                    options->setBuyItem(item_Matzah);
                    targetCoin = current_coins - PRICE_MATZAH;
                    float waitTime = 2;
                    float interval = waitTime / PRICE_MATZAH / 10;
                    this->schedule(schedule_selector(StoreScene::updateCoinLabel), interval, PRICE_MATZAH / 10, 0);
                }else
                {
                    CCMessageBox(MSG_NOT_ENOUGH_COIN_TXT, MSG_NOT_ENOUGH_COIN_TITLE);
                    return;
                }
            }
            break;
        default:
            break;
    }
// Change Character
    this->removeChildByTag(TAG_CHARACTER);
    int item = options->getItem();
    char frameName[50];
    sprintf(frameName, "character_shuk_%d.png", item);
    CCSprite* character = CCSprite::createWithSpriteFrameName(frameName);
    character->setTag(TAG_CHARACTER);
    character->setScale(SCALE);
    character->setPosition(ccp(232 * SCALEX, 378 * SCALEY));
    this->addChild(character, 1);
}

void StoreScene::gotoMainMenu(cocos2d::CCObject *sender)
{
    SoundEffects::getInstance()->playButtonEffect();
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.0, MainMenuScene::scene()));
}

void StoreScene::updateCoinLabel(float dt)
{
    char newValue[5];
    sprintf(newValue, "%d", currentCoin);
    currentCoin -= 10;
    ((CCLabelTTF*)this->getChildByTag(TAG_COIN))->setString(newValue);
}