//
//  DDAppDelegate.m
//  LighterReader
//
//  Created by 萧川 on 14-3-26.
//  Copyright (c) 2014年 CUAN. All rights reserved.
//

#import "DDAppDelegate.h"
#import "DDRootViewController.h"
@interface WBBaseRequest ()
- (void)debugPrint;
@end

@interface WBBaseResponse ()
- (void)debugPrint;
@end

@implementation DDAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [WeiboSDK enableDebugMode:YES];
    NSLog(@"%d",[WeiboSDK registerApp:kAppKey]);
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor whiteColor];

    // root view controller
    DDRootViewController *rootVC = [[DDRootViewController alloc] init];
    self.rootVC = rootVC;
    self.window.rootViewController = rootVC;

    // navi bar style
    [UIBarButtonItem appearance];
    
    [self.window makeKeyAndVisible];
    return YES;
}
- (void)didReceiveWeiboRequest:(WBBaseRequest *)request{
    
}

- (void)didReceiveWeiboResponse:(WBBaseResponse *)response{
    
    if ([response isKindOfClass:WBAuthorizeResponse.class]) {
        self.wbtoken = [(WBAuthorizeResponse *)response accessToken];
        if (self.wbtoken) {
            //success
            DDRootViewController *rootVC = (DDRootViewController *)[[((DDAppDelegate *)[[UIApplication sharedApplication] delegate]) window] rootViewController];
            [rootVC setLogin:YES];
            // notify login
            [[NSNotificationCenter defaultCenter] postNotificationName:@"login"
                                                                object:self
                                                              userInfo:@{@"isLogined":@"1"}];
            [rootVC disapearSignView];
        } else {
            
        }
    }
}

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation{
    
    return [WeiboSDK handleOpenURL:url delegate:self];
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
