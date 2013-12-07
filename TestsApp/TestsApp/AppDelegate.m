//
//  AppDelegate.m
//  TestsApp
//
//  Created by Stanislaw Pankevich on 23/11/13.
//  Copyright (c) 2013 Stanislaw Pankevich. All rights reserved.
//

#import "AppDelegate.h"

#import "EchoLogger.h"

#import "UIKit.h"
#import "CoreLocation.h"
#import "MapKit.h"

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
    int n = 10;
    double d = 5.55;
    BOOL b = YES;
    NSUInteger uint = 7;
    NSNumber *nsnum = @(18);
    NSString *nsstring = @"I'am the string!";
    LS(n, d, b, uint, nsnum, nsstring);

    CGRect frame = (CGRect){0, 0, 200, 200};
    CGSize size = (CGSize){200, 200};
    LS(frame, size);

    LS(MKMapRectMake(0, 0, 200, 200));

    L();
    L(1);
    L(@"A string", 111);
    L(self, [NSObject new]);
    L([NSArray new], [NSDictionary new], NSMakeRange(0, 5));
    L(@"NSLOG like %@", [NSObject new]);
    L(self);

    LS();
    LS(self, [NSObject new]);
    LS([NSArray new], [NSDictionary new], NSMakeRange(0, 5));
    LS(1);
    LS(self);

    LLog(@"123");
    LLog(@"NSLog like %@", [NSObject new]);

    LSLog(@"NSLog like %@");
    LSLog(@"NSLog like %@", [NSObject new]);

    LFLog(@"NSLog like %@");
    LSFLog(@"NSLog like %@");

    LOGGER_FOCUSED_MODE = NO;

    LF();
    id value = nil;
    LF(value);
    LF(@(1));
    LF([NSNumber class]);
    LF(1);

    LF(self);
    LF(self, [NSObject new]);
    LF([NSArray new], [NSDictionary new], NSMakeRange(0, 5));

    LSF(1);
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
