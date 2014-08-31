//
//  EchoLogger
//
//  EchoLogger.h
//
//  Created by Stanislaw Pankevich on 9/7/13.
//  Copyright (c) 2013 Stanislaw Pankevich. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "libextobjc/metamacros.h"


#import <NSStringFromAnyObject/NSStringFromAnyObject.h>


#define metamacro_argcount_alt(...) _metamacro_argcount_alt(0, ##__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define _metamacro_argcount_alt(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N


FOUNDATION_EXPORT BOOL EchoLoggerFocusedModeEnabled;
void __EchoLoggerRunInFocusedMode(void (^block)(void));


void __L(NSString *sourceInfo, NSString *logString);
NSString * __EchoLoggerSourceInfo(const char *file, int lineNumber, const char *funcName);


#define __L__ITER(INDEX, ARG) \
    NSStringFromAnyObject(ARG),


#define L(...) do { \
    if (EchoLoggerFocusedModeEnabled) break; \
    \
    NSString *echoedInput = @("EL> " #__VA_ARGS__ ""); \
    \
    NSString *describedOutput = [@[ \
                                   metamacro_foreach(__L__ITER,, __VA_ARGS__) \
                                   ] componentsJoinedByString:@"; "]; \
    \
    NSString *finalString = [@[ echoedInput, describedOutput] componentsJoinedByString:@"\n-> "]; \
    fprintf(stdout, "%s\n", finalString.UTF8String); \
} while(0)


#define LL(...) do { \
    if (EchoLoggerFocusedModeEnabled) break; \
    \
    NSString *finalString; \
    \
    NSString *echoedInput = @("" #__VA_ARGS__ ""); \
    \
    NSString *describedOutput = [@[ \
        metamacro_foreach(__L__ITER,, __VA_ARGS__) \
    ] componentsJoinedByString:@"; "]; \
    \
    finalString = [@[ echoedInput, describedOutput] componentsJoinedByString:@"\n-> "]; \
    \
    fprintf(stdout, "EL: %s> %s\n", __EchoLoggerSourceInfo(__FILE__, __LINE__, __PRETTY_FUNCTION__).UTF8String, finalString.UTF8String); \
} while(0)


#define LF(...) do { \
    NSString *echoedInput = @("EL:focused> " #__VA_ARGS__ ); \
    \
    NSString *describedOutput = [@[ \
        metamacro_foreach(__L__ITER,, __VA_ARGS__) \
    ] componentsJoinedByString:@"; "]; \
    \
    NSString *finalString = [@[ echoedInput, describedOutput] componentsJoinedByString:@"\n-> "]; \
    fprintf(stdout, "%s\n", finalString.UTF8String); \
} while(0);


// NSLog compatibility
#define LLog(...) do { \
    if (EchoLoggerFocusedModeEnabled) break; \
    \
    NSString *logString; \
    metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))( \
        logString = metamacro_head(__VA_ARGS__); \
    )( \
        logString = [NSString stringWithFormat:metamacro_head(__VA_ARGS__), metamacro_tail(__VA_ARGS__)]; \
    ) \
    printf("EL> %s\n", logString.UTF8String); \
} while(0)


#define LLLog(...) do { \
    if (EchoLoggerFocusedModeEnabled) break; \
    NSString *logString; \
    metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))( \
        logString = metamacro_head(__VA_ARGS__); \
    )( \
        logString = [NSString stringWithFormat:metamacro_head(__VA_ARGS__), metamacro_tail(__VA_ARGS__)]; \
    ) \
    fprintf(stdout, "EL: %s> %s\n", __EchoLoggerSourceInfo(__FILE__, __LINE__, __PRETTY_FUNCTION__).UTF8String, logString.UTF8String); \
} while(0)


#define LFLog(...) do { \
    NSString *logString; \
    metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))( \
        logString = metamacro_head(__VA_ARGS__); \
    )( \
        logString = [NSString stringWithFormat:metamacro_head(__VA_ARGS__), metamacro_tail(__VA_ARGS__)]; \
    ) \
    fprintf(stdout, "EL:focused> %s\n", logString.UTF8String); \
} while(0);


#define LLFLog(...) do { \
    NSString *logString; \
    metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))( \
        logString = metamacro_head(__VA_ARGS__); \
    )( \
        logString = [NSString stringWithFormat:metamacro_head(__VA_ARGS__), metamacro_tail(__VA_ARGS__)]; \
    ) \
    fprintf(stdout, "EL:focused %s> %s\n", __EchoLoggerSourceInfo(__FILE__, __LINE__, __PRETTY_FUNCTION__).UTF8String, logString.UTF8String); \
} while(0);
