//
//  SocialGame.m
//  AlephBet
//
//  Created by Fredric on 2/1/16.
//
//

#include "SocialGame.h"
#include "AppController.h"

void SocialGame::sendemail(const char* mailbody)
{
    AppController* appDel = (AppController*)[UIApplication sharedApplication].delegate;
    if (appDel != nil) {
        [appDel sendEmail:[NSString stringWithFormat:@"%s", mailbody]];
    }
}

void SocialGame::openWebSite()
{
    AppController* appDel = (AppController*)[UIApplication sharedApplication].delegate;
    if (appDel != nil) {
        [appDel openWebSite];
    }
}

void SocialGame::sendemailWithScreenShot(const char* filePath, const char* mailBody)
{
    AppController* appDel = (AppController*)[UIApplication sharedApplication].delegate;
    NSString* path = [NSString stringWithFormat:@"%s", filePath];
    NSString* body = [NSString stringWithFormat:@"%s", mailBody];
    if (appDel != nil) {
        [appDel sendEmailWithScreen:path MailBody:body];
    }
}
