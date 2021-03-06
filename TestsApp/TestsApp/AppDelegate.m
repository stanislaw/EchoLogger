//
//  AppDelegate.m
//  TestsApp
//
//  Created by Stanislaw Pankevich on 23/11/13.
//  Copyright (c) 2013 Stanislaw Pankevich. All rights reserved.
//

#import "AppDelegate.h"

#import "EchoLogger.h"
#import <NSStringFromAnyObject/UIKit.h>

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    // Override point for customization after application launch.
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];


    [self seeEchoLoggerInAction];

    return YES;
}

- (void)seeEchoLoggerInAction {
    int intNumber = 10;
    double doubleNumber = 5.55;
    BOOL boolValue = YES;
    NSUInteger unsignedIntNumber = 7;
    NSNumber *number = @(18);
    NSString *string = @"I'am the string!";
    CGRect frame = (CGRect){0, 0, 200, 200};
    CGSize size = (CGSize){200, 200};

    printf("\nL()\n\n");

    L(intNumber, doubleNumber, boolValue, unsignedIntNumber, number, string);
    L(frame, size);

    L(1);
    L(@"A string", 111);
    L(self, [NSObject new]);
    L([NSArray new], [NSDictionary new], NSMakeRange(0, 5));
    L(self);


    printf("\nLL()\n\n");

    LL(intNumber, doubleNumber, boolValue, unsignedIntNumber, number, string);
    LL(frame, size);

    LL(self, [NSObject new]);
    LL([NSArray new], [NSDictionary new], NSMakeRange(0, 5));
    LL(1);
    LL(self);


    EchoLoggerFocusedModeEnabled = NO;

    id value = nil;
    LF(value);
    LF(@(1));
    LF([NSNumber class]);
    LF(1);

    LF(self);
    LF(self, [NSObject new]);
    LF([NSArray new], [NSDictionary new], NSMakeRange(0, 5));

    printf("\nLLog()\n\n");

    LLog(@"123");
    LLog(@"NSLog like %@", [NSObject new]);

    printf("\nLLLog()\n\n");

    LLLog(@"NSLog like %@", [NSObject new]);

    printf("\nLFLog()\n\n");
    LFLog(@"NSLog like");

    printf("\nLLFog()\n\n");
    LLFLog(@"NSLog like");
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
