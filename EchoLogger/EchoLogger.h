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
    metamacro_if_eq(0, metamacro_argcount_alt(__VA_ARGS__))( \
        printf("L()\n"); \
        break; \
    )( \
        NSString *echoedInput = @("L(" #__VA_ARGS__ ")"); \
        \
        NSString *describedOutput = [@[ \
                                       metamacro_foreach(__L__ITER,, __VA_ARGS__) \
                                       ] componentsJoinedByString:@"; "]; \
        \
        NSString *finalString = [@[ echoedInput, describedOutput] componentsJoinedByString:@" ~> "]; \
        __L(nil, finalString); \
    ); \
} while(0)


#define LL(...) do { \
    if (EchoLoggerFocusedModeEnabled) break; \
    \
    NSString *finalString; \
    metamacro_if_eq(0, metamacro_argcount_alt(__VA_ARGS__))( \
        finalString = @"LL()"; \
    )( \
        NSString *echoedInput = @("LL(" #__VA_ARGS__ ")"); \
        \
        NSString *describedOutput = [@[ \
            metamacro_foreach(__L__ITER,, __VA_ARGS__) \
        ] componentsJoinedByString:@"; "]; \
        \
        finalString = [@[ echoedInput, describedOutput] componentsJoinedByString:@" ~> "]; \
    ) \
    \
    __L(__EchoLoggerSourceInfo(__FILE__, __LINE__, __PRETTY_FUNCTION__), finalString); \
} while(0)


#define LF(...) __EchoLoggerRunInFocusedMode(^{ \
    metamacro_if_eq(0, metamacro_argcount_alt(__VA_ARGS__))( \
        printf("LF()\n"); \
    )( \
        NSString *echoedInput = @("LF(" #__VA_ARGS__ ")"); \
        \
        NSString *describedOutput = [@[ \
            metamacro_foreach(__L__ITER,, __VA_ARGS__) \
        ] componentsJoinedByString:@"; "]; \
        \
        NSString *finalString = [@[ echoedInput, describedOutput] componentsJoinedByString:@" ~> "]; \
        __L(nil, finalString); \
    ) \
})


#define LLF(...) __EchoLoggerRunInFocusedMode(^{ \
    NSString *finalString; \
    metamacro_if_eq(0, metamacro_argcount_alt(__VA_ARGS__))( \
        finalString = @"LLF()"; \
    )( \
        NSString *echoedInput = @("LLF(" #__VA_ARGS__ ")"); \
        \
        NSString *describedOutput = [@[ \
            metamacro_foreach(__L__ITER,, __VA_ARGS__) \
        ] componentsJoinedByString:@"; "]; \
        \
        finalString = [@[ echoedInput, describedOutput] componentsJoinedByString:@" ~> "]; \
    ) \
    \
    __L(__EchoLoggerSourceInfo(__FILE__, __LINE__, __PRETTY_FUNCTION__), finalString); \
})


// NSLog compatibility
#define LLog(...) do { \
    if (EchoLoggerFocusedModeEnabled) break; \
    NSString *logString; \
    metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))( \
        logString = metamacro_head(__VA_ARGS__); \
    )( \
        logString = [NSString stringWithFormat:metamacro_head(__VA_ARGS__), metamacro_tail(__VA_ARGS__)]; \
    ) \
    __L(nil, logString); \
} while(0)


#define LLLog(...) do { \
    if (EchoLoggerFocusedModeEnabled) break; \
    NSString *logString; \
    metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))( \
        logString = metamacro_head(__VA_ARGS__); \
    )( \
        logString = [NSString stringWithFormat:metamacro_head(__VA_ARGS__), metamacro_tail(__VA_ARGS__)]; \
    ) \
    __L(__EchoLoggerSourceInfo(__FILE__, __LINE__, __PRETTY_FUNCTION__), logString); \
} while(0)


#define LFLog(...) __EchoLoggerRunInFocusedMode(^{ \
    NSString *logString; \
    metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))( \
        logString = metamacro_head(__VA_ARGS__); \
    )( \
        logString = [NSString stringWithFormat:metamacro_head(__VA_ARGS__), metamacro_tail(__VA_ARGS__)]; \
    ) \
    __L(nil, logString); \
})


#define LLFLog(...) __EchoLoggerRunInFocusedMode(^{ \
    NSString *logString; \
    metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))( \
        logString = metamacro_head(__VA_ARGS__); \
    )( \
        logString = [NSString stringWithFormat:metamacro_head(__VA_ARGS__), metamacro_tail(__VA_ARGS__)]; \
    ) \
    __L(__EchoLoggerSourceInfo(__FILE__, __LINE__, __PRETTY_FUNCTION__), logString); \
})

