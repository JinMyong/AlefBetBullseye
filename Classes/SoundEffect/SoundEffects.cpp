//
//  SoundEffects.cpp
//  AlephBet
//
//  Created by Fredric on 1/9/16.
//
//

#include "SoundEffects.hpp"
#include "Const.h"
#include "HebrewUtils.hpp"
#include "Global.hpp"
//#include "AudioEngine.h"

#define MUSIC_VOLUME    0.2
#define EFFECT_VOLUME   1.0

SoundEffects* SoundEffects::sharedSoundEffects = NULL;

SoundEffects* SoundEffects::getInstance()
{
    srandom((int)time(NULL));
    if (sharedSoundEffects == NULL) {
        sharedSoundEffects = new SoundEffects();
    }
    return sharedSoundEffects;
}

SoundEffects::SoundEffects()
{
    preloadSounds();
}

SoundEffects::~SoundEffects()
{
    
}

void SoundEffects::playLetterSound(int letterIndex)
{
    string soundFileName = HebrewUtils::getInstance()->getLetterName(letterIndex);
    GameOptions* options = GameOptions::getInstance();
    bool isBoySound = options->getPlayerType();
    if (isBoySound) {
        soundFileName = "sounds/voice_boy/" + soundFileName + "_boy.mp3";
    }else
    {
        soundFileName = "sounds/voice_girl/" + soundFileName + "_girl.mp3";
    }
    
    if (soundFileName != "") {
//        SimpleAudioEngine::sharedEngine()->stopAllEffects();
        SimpleAudioEngine::sharedEngine()->playEffect(getResPath(soundFileName.c_str()));
    }
}

void SoundEffects::playButtonEffect()
{
    SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_BUTTON));
}

void SoundEffects::playTargetHit(ThrowThings item, bool wasGoodHit)
{
    if (wasGoodHit) {
        switch (item) {
            case item_Pencil:
                SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_PENCIL_HIT));
                break;
            case item_Fish:
                SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_FISH_HIT));
                break;
            case item_JewishStar:
                SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_STAR_HIT));
                break;
            case item_LightBulb:
                SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_BULB_HIT));
                break;
            case item_Matzah:
                SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_MATZAH_HIT));
                break;
            case item_MatzahBall:
                SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_MATZAHBALL_HIT));
                break;
            default:
                break;
        }
    }else
    {
        switch (item) {
            case item_Pencil:
                SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_PENCIL_MISS));
                break;
            case item_Fish:
                SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_FISH_MISS));
                break;
            case item_JewishStar:
                SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_STAR_MISS));
                break;
            case item_LightBulb:
                SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_BULB_MISS));
                break;
            case item_Matzah:
                SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_MATZAH_MISS));
                break;
            case item_MatzahBall:
                SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_MATZAHBALL_MISS));
                break;
            default:
                break;
        }
    }
}

void SoundEffects::playLevelComplete(bool success)
{
    if (success) {
        SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_LEVEL_COMPLETE));
    }else
    {
        SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_LEVEL_FAILED));
    }
}

void SoundEffects::playThrowItem()
{
    SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_THROW_ITEM));
}

void SoundEffects::playUnlockItem()
{
    SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_UNLOCK_ITEM));
}

void SoundEffects::playGetCoin()
{
    SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_GET_COIN));
}

void SoundEffects::playTick()
{
    SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_TICK));
}

void SoundEffects::playTickOne()
{
    tick_index = SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_TICK_ONE), true);
}

void SoundEffects::playAlarm()
{
//    SimpleAudioEngine::sharedEngine()->stopEffect(tick_index);
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
    SimpleAudioEngine::sharedEngine()->playEffect(getResPath(EFFECT_ALARM));
}

void SoundEffects::playThemeBackgroundMusic()
{
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(getResPath(BG_MUSIC_THEME), true);
}

void SoundEffects::playLevelBackgroundMusic()
{
    char fileName[50];
    int num = rand() % 3 + 1;
    sprintf(fileName, "%s%d.mp3", BG_MUSIC_LEVEL_NAME, num);
    
    CCLog("Background Music is '%s'", fileName);
    
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(getResPath(fileName), true);
}

void SoundEffects::preloadSounds()
{
    SimpleAudioEngine* audioEngine = SimpleAudioEngine::sharedEngine();
    HebrewUtils* hUtil = HebrewUtils::getInstance();
    for (int letterIndex = 0; letterIndex < 43; letterIndex++) {
        string soundFileName = hUtil->getLetterName(letterIndex);
        soundFileName = "sounds/voice_boy/" + soundFileName + "_boy.mp3";
        audioEngine->preloadEffect(getResPath(soundFileName.c_str()));
        soundFileName = hUtil->getLetterName(letterIndex);
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

void SoundEffects::pauseEffects()
{
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

void SoundEffects::resumeEffects()
{
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
