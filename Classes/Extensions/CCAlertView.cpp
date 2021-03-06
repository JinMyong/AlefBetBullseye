#include "CCAlertView.h"
#include "Global.hpp"
#include "Const.h"

USING_NS_CC;
CCAlertView *CCAlertView::create(const char *_title, const char *_message, const char *_cancel, const char *_ok, CCObject *_object, SEL_CallFuncO _selector1, SEL_CallFuncO _selector2) {
    CCAlertView *pRet = new CCAlertView();
    if(pRet && pRet->init(_title, _message, _cancel, _ok, _object, _selector1, _selector2)) {
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);

	return NULL;
}

bool CCAlertView::init(const char *_title, const char *_message, const char *_cancel, const char *_ok, CCObject *_object, SEL_CallFuncO _selector1, SEL_CallFuncO _selector2) {
    this->setTouchPriority(0);
    object    = _object;
    selector1 = _selector1;
    selector2 = _selector2;

    CCSize size = CCDirector::sharedDirector()->getWinSize();
    this->setTouchEnabled(true);
    this->setPosition(ccp(size.width / 2.0f, size.height / 2.0f));

    CCSprite *bgSprite = CCSprite::create(getResPath("images/mainmenuScene/blank.png"));
    bgSprite->setTextureRect(CCRect(0, 0, size.width, size.height));
    bgSprite->setColor(ccc3(0, 0, 0));
	bgSprite->setOpacity(0);
    this->addChild(bgSprite, 1000);

    CCSprite *alertViewSprite = CCSprite::create(getResPath("images/mainmenuScene/alert_bg.png"));
    this->addChild(alertViewSprite, 1001);


    CCMenuItemImage *button1 = CCMenuItemImage::create(getResPath("images/mainmenuScene/btn_ok_nor.png"), getResPath("images/mainmenuScene/btn_ok_prs.png"), this, menu_selector(CCAlertView::button1Callback));
    CCMenuItemImage *button2 = CCMenuItemImage::create(getResPath("images/mainmenuScene/btn_cancel_nor.png"), getResPath("images/mainmenuScene/btn_cancel_prs.png"), this, menu_selector(CCAlertView::button2Callback));
//	button1->setOpacity(180);
//	button2->setOpacity(180);

    CCMenu *alertMenu = CCMenu::create(button1, button2, NULL);
    alertMenu->alignItemsHorizontallyWithPadding(20);
    alertMenu->setPosition(ccp(alertViewSprite->getContentSize().width / 2.0f, (button1->getContentSize().height / 2.0f)));
    alertViewSprite->addChild(alertMenu);
 
    //80,150
    
    
    CCLabelTTF *titleLabel = CCLabelTTF::create(_title, STANDARD_FONT, 70);
    titleLabel->setAnchorPoint(CCPoint(0.5, 1.0));
    titleLabel->setPosition(ccp(alertViewSprite->getContentSize().width / 2.0f, alertViewSprite->getContentSize().height - 20 * SCALE));
    alertViewSprite->addChild(titleLabel);

    CCLabelTTF *messageLabel = CCLabelTTF::create(_message, STANDARD_FONT, 40, CCSizeMake(alertViewSprite->getContentSize().width - 50 * SCALE, 0), kCCTextAlignmentCenter);
    messageLabel->setAnchorPoint(CCPoint(0.5, 1.0));
    messageLabel->setPosition(ccp(alertViewSprite->getContentSize().width / 2.0f, titleLabel->getPositionY() - 100));
    alertViewSprite->addChild(messageLabel);

    CCLabelTTF *cancelLabel = CCLabelTTF::create(_cancel, STANDARD_FONT, 18);
    cancelLabel->setPosition(ccp(button2->getContentSize().width / 2.0f, button2->getContentSize().height / 2.0f));
    button1->addChild(cancelLabel);

    CCLabelTTF *OKlabel = CCLabelTTF::create(_ok, STANDARD_FONT, 18);
    OKlabel->setPosition(ccp(button1->getContentSize().width / 2.0f, button1->getContentSize().height / 2.0f));
    button2->addChild(OKlabel);

    bgSprite->runAction(CCFadeTo::create(0.1f, 150));

//    CCFiniteTimeAction *scale1 = CCScaleTo::create(0.15f, 1.1f);
//    CCFiniteTimeAction *scale2 = CCScaleTo::create(0.1f, 0.9f);
//    CCFiniteTimeAction *scale3 = CCScaleTo::create(0.05f, 1.0f);
    alertViewSprite->setScaleX(SCALEX);
    alertViewSprite->setScaleY(SCALEY);
    //alertViewSprite->runAction(CCSequence::create(scale1, scale2, scale3, NULL));

	return true;
}

void CCAlertView::cleanUpCallback() {
    this->removeFromParentAndCleanup(true);
}

void CCAlertView::button1Callback(CCObject *pSender) {
    CCCallFuncO *first  = CCCallFuncO::create(object, selector1, object);
    CCCallFunc *second = CCCallFunc::create(this, callfunc_selector(CCAlertView::cleanUpCallback));
    this->runAction(CCSequence::create(first, second, NULL));
}

void CCAlertView::button2Callback(CCObject *pSender) {
    CCCallFuncO *first  = CCCallFuncO::create(object, selector2, object);
    CCCallFunc *second = CCCallFunc::create(this, callfunc_selector(CCAlertView::cleanUpCallback));
    this->runAction(CCSequence::create(first, second, NULL));
}
