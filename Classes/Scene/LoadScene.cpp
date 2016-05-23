//
//  LoadScene.cpp
//  AlephBet
//
//  Created by Fredric on 2/2/16.
//
//

#include "LoadScene.hpp"
#include "Global.hpp"
#include "Const.h"
#include "SimpleAudioEngine.h"
#include "MainMenuScene.hpp"

using namespace CocosDenshion;
using namespace std;

CCScene* LoadScene::scene()
{
    CCScene* scene = CCScene::create();
    LoadScene* layer = LoadScene::create();
    scene->addChild(layer);
    return scene;
}

bool LoadScene::init()
{
    if (!CCLayer::init()) {
        return false;
    }
    winSize = CCDirector::sharedDirector()->getWinSize();
    createUI();
    loadResources();
    return true;
}

void LoadScene::createUI()
{
    CCSprite* bg = CCSprite::create(getResPath("images/loadScene/load_bg.png"));
    bg->setScaleX(SCALEX);
    bg->setScaleY(SCALEY);
    bg->setPosition(ccp(winSize.width * 0.5, winSize.height * 0.5));
    this->addChild(bg);
    
    CCSprite* target = CCSprite::create(getResPath("images/loadScene/load_target.png"));
    target->setScale(SCALE);
    target->setPosition(ccp(374 * SCALEX, 670 * SCALEY));
    this->addChild(target);
    
    CCSprite* character = CCSprite::create(getResPath(CHOOSE_CHARACTER_IMG));
    character->setScale(SCALE);
    character->setPosition(ccp(218 * SCALEX, 500 * SCALEY));
    this->addChild(character);
    
    CCSprite* title = CCSprite::create(getResPath("images/loadScene/load_title.png"));
    title->setScale(SCALE);
    title->setPosition(ccp(winSize.width * 0.5, 970 * SCALEY));
    this->addChild(title);
    
    spLoadingProgress = CCSprite::create(getResPath("images/loadScene/loading_progress.png"));
    spLoadingProgress->setScaleY(SCALEY);
    spLoadingProgress->setScaleX(0);
    spLoadingProgress->setAnchorPoint(ccp(0, 0.5));
    spLoadingProgress->setPosition(ccp(0, 30 * SCALEY));
    this->addChild(spLoadingProgress);
}

void LoadScene::loadResources()
{
    preloadSounds();
    
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/global/main_bg.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/global/chair_blue.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/global/chair_yellow.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/global/mainmenu_bg.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/global/character_boy_main.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/global/character_boy_choose.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/global/btn_play_nor.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/global/btn_play_prs.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/global/btn_mainmenu_nor.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/global/btn_mainmenu_prs.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/global/letterboard_bg.png"),this,callfuncO_selector(LoadScene::onLoad));
    
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/mainmenuScene/btn_choose_nor.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/mainmenuScene/btn_choose_prs.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/mainmenuScene/btn_options_nor.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/mainmenuScene/btn_options_prs.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/global/btn_highscore_nor.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/global/btn_highscore_prs.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/mainmenuScene/btn_store_nor.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/mainmenuScene/btn_store_prs.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/mainmenuScene/btn_about_nor.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/mainmenuScene/btn_about_prs.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/mainmenuScene/btn_reset_nor.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/mainmenuScene/btn_reset_prs.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/mainmenuScene/mainmenu_top_title.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/mainmenuScene/mainmenu_bottom_title.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/introScene/intro_text.png"),this,callfuncO_selector(LoadScene::onLoad));

    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/introScene/character_boy_intro.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/chooseLetterScene/btn_all_nor.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/chooseLetterScene/btn_all_prs.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/chooseLetterScene/btn_clear_nor.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/chooseLetterScene/btn_clear_prs.png"),this,callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/chooseLetterScene/choose_top_title.png"), this, callfuncO_selector(LoadScene::onLoad));
    
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/title_difficult.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/title_sound.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/title_effect.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/title_voice.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/title_font_style.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/title_text_color.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/normal_on.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/normal_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/hard_on.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/hard_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/sound_on_on.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/sound_on_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/sound_off_on.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/sound_off_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/sound_on_on.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/sound_on_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/sound_off_on.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/sound_off_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/voice_boy_on.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/voice_boy_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/voice_girl_on.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/voice_girl_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/font_print_on.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/font_print_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/font_script_on.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/font_script_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/font_color_white_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/font_color_black_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/font_color_pink_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/font_color_blue_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/font_color_white_on.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/font_color_black_on.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/font_color_pink_on.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/optionScene/font_color_blue_on.png"), this, callfuncO_selector(LoadScene::onLoad));
    
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/storeScene/table.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/storeScene/title_shuk.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/storeScene/table_bulb_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/storeScene/table_fish_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/storeScene/table_matzah_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/storeScene/table_matzahball_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/storeScene/table_star_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/storeScene/table_pencil_off.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/aboutScene/btn_email_nor.png"), this, callfuncO_selector(LoadScene::onLoad));
    
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/aboutScene/btn_email_prs.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/aboutScene/btn_link_nor.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/aboutScene/btn_link_prs.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/aboutScene/title_about.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/aboutScene/title_about_game.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/aboutScene/txt_game.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/global/letterboard_bg.png"), this, callfuncO_selector(LoadScene::onLoad));
    
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/gameScene/btn_pause_nor.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/gameScene/btn_pause_prs.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/gameScene/btn_continue_nor.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/gameScene/btn_continue_prs.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/gameScene/btn_quit_nor.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/gameScene/btn_quit_nor.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/gameScene/game_letter_bg.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/gameScene/diff_hint.png"), this, callfuncO_selector(LoadScene::onLoad));
    
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/gameResultScene/btn_restart_nor.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/gameResultScene/btn_restart_prs.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/gameResultScene/btn_next_nor.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/gameResultScene/btn_next_prs.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/gameResultScene/btn_email_teacher_nor.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/gameResultScene/btn_email_teacher_prs.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/gameResultScene/btn_missedletter_nor.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/gameResultScene/btn_missedletter_prs.png"), this, callfuncO_selector(LoadScene::onLoad));

    
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/missedLetterScene/btn_back_nor.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/missedLetterScene/btn_back_prs.png"), this, callfuncO_selector(LoadScene::onLoad));
    
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/highScoreScene/email_teacher_prs.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/highScoreScene/email_teacher_prs.png"), this, callfuncO_selector(LoadScene::onLoad));
    CCTextureCache::sharedTextureCache()->addImageAsync(getResPath("images/highScoreScene/email_teacher_prs.png"), this, callfuncO_selector(LoadScene::onFinishLoad));
    
}

void LoadScene::preloadSounds()
{
    SimpleAudioEngine* audioEngine = SimpleAudioEngine::sharedEngine();
    HebrewUtils* hUtil = HebrewUtils::getInstance();
    for (int letterIndex = 0; letterIndex < LETTER_COUNT; letterIndex++) {
        string soundFileName = hUtil->getLetterName(letterIndex);
        soundFileName = "sounds/voice_boy/" + soundFileName + "_boy.mp3";
        audioEngine->preloadEffect(getResPath(soundFileName.c_str()));
        soundFileName = "sounds/voice_girl/" + soundFileName + "_girl.mp3";
        audioEngine->preloadEffect(getResPath(soundFileName.c_str()));
    }
    
    audioEngine->preloadEffect(getResPath(EFFECT_BULB_HIT));
    audioEngine->preloadEffect(getResPath(EFFECT_BULB_MISS));
    audioEngine->preloadEffect(getResPath(EFFECT_BUTTON));
    audioEngine->preloadEffect(getResPath(EFFECT_FISH_HIT));
    audioEngine->preloadEffect(getResPath(EFFECT_FISH_MISS));
    audioEngine->preloadEffect(getResPath(EFFECT_GET_COIN));
    audioEngine->preloadEffect(getResPath(EFFECT_LEVEL_COMPLETE));
    audioEngine->preloadEffect(getResPath(EFFECT_LEVEL_FAILED));
    audioEngine->preloadEffect(getResPath(EFFECT_MATZAHBALL_HIT));
    audioEngine->preloadEffect(getResPath(EFFECT_MATZAHBALL_MISS));
    audioEngine->preloadEffect(getResPath(EFFECT_MATZAH_HIT));
    audioEngine->preloadEffect(getResPath(EFFECT_MATZAH_MISS));
    audioEngine->preloadEffect(getResPath(EFFECT_PENCIL_HIT));
    audioEngine->preloadEffect(getResPath(EFFECT_PENCIL_MISS));
    audioEngine->preloadEffect(getResPath(EFFECT_STAR_HIT));
    audioEngine->preloadEffect(getResPath(EFFECT_STAR_MISS));
    audioEngine->preloadEffect(getResPath(EFFECT_THROW_ITEM));
    audioEngine->preloadEffect(getResPath(EFFECT_UNLOCK_ITEM));
    audioEngine->preloadEffect(getResPath(EFFECT_TICK));
    audioEngine->preloadEffect(getResPath(EFFECT_ALARM));
    
    char fileName[50];
    for (int num = 1; num < 4; num++) {
        sprintf(fileName, "%s%d.mp3", BG_MUSIC_LEVEL_NAME, num);
        audioEngine->preloadBackgroundMusic(getResPath(fileName));
    }
    
}


void LoadScene::onLoad(cocos2d::CCObject *sender)
{
    static int nLoadCount = 0;
    
    nLoadCount++;
    
    spLoadingProgress->setScaleX(nLoadCount * SCALEX / 102);
    
    CCLog("%d resources loaded", nLoadCount);
}

void LoadScene::onFinishLoad(cocos2d::CCObject *sender)
{
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f, MainMenuScene::scene()));
}