#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>

#define App_URL         @"https://itunes.apple.com/us/app/alef-bet-bullseye/id1081250079?ls=1&mt=8"
@class RootViewController;

@interface AppController : NSObject <UIApplicationDelegate, MFMailComposeViewControllerDelegate> {
    UIWindow *window;
    RootViewController    *viewController;
    
    MFMailComposeViewController* picker;
}

-(void) sendEmail:(NSString*)mailbody;
-(void) openWebSite;
-(void) sendEmailWithScreen:(NSString*) filepath;
-(void) sendEmailWithScreen:(NSString*) filepath MailBody:(NSString*)mailbody;
@end

