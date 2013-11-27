//
//  Logger.h
//
//  Created by Stanislaw Pankevich on 12/9/12.
//  Copyright (c) 2012 Stanislaw Pankevich. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "libextobjc/metamacros.h"

#import "Descriptions/Foundation.h"

#define metamacro_argcount2(...) _metamacro_argcount2(0, ##__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define _metamacro_argcount2(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N

/* Focused logging */
FOUNDATION_EXPORT BOOL LOGGER_FOCUSED_MODE;
void __LoggerRunInFocusedMode(void (^block)(void));

/* Logger internal methods */
void __L(NSString *sourceInfo, NSString *logString);
NSString * __LoggerSourceInfo(const char *file, int lineNumber, const char *funcName);

#define __L_ITER(INDEX, ARG) \
    LoggerDescription(ARG),

#define L(...) do { \
    if (LOGGER_FOCUSED_MODE) break; \
    \
    NSString *finalString; \
    metamacro_if_eq(0, metamacro_argcount2(__VA_ARGS__))( \
        finalString = @"L()"; \
    )( \
        NSString *echoedInput = @("L(" #__VA_ARGS__ ")"); \
        \
        NSString *describedOutput = [@[ \
            metamacro_foreach(__L_ITER,, __VA_ARGS__) \
        ] componentsJoinedByString:@"; "]; \
        \
        finalString = [@[ echoedInput, describedOutput] componentsJoinedByString:@" ~> "]; \
    ) \
    \
    __L(__LoggerSourceInfo(__FILE__, __LINE__, __PRETTY_FUNCTION__), finalString); \
} while(0)

#define LS(...) do { \
    if (LOGGER_FOCUSED_MODE) break; \
    \
    metamacro_if_eq(0, metamacro_argcount2(__VA_ARGS__))( \
        printf("LS()\n"); \
        break; \
    )(); \
    \
    NSString *echoedInput = @("LS(" #__VA_ARGS__ ")"); \
    \
    NSString *describedOutput = [@[ \
    metamacro_foreach(__L_ITER,, __VA_ARGS__) \
    ] componentsJoinedByString:@"; "]; \
    \
    NSString *finalString = [@[ echoedInput, describedOutput] componentsJoinedByString:@" ~> "]; \
    __L(nil, finalString); \
} while(0)

#define LF(...) __LoggerRunInFocusedMode(^{ \
    NSString *finalString; \
    metamacro_if_eq(0, metamacro_argcount2(__VA_ARGS__))( \
        finalString = @"LF()"; \
    )( \
        NSString *echoedInput = @("LF(" #__VA_ARGS__ ")"); \
        \
        NSString *describedOutput = [@[ \
            metamacro_foreach(__L_ITER,, __VA_ARGS__) \
        ] componentsJoinedByString:@"; "]; \
        \
        finalString = [@[ echoedInput, describedOutput] componentsJoinedByString:@" ~> "]; \
    ) \
    \
    __L(__LoggerSourceInfo(__FILE__, __LINE__, __PRETTY_FUNCTION__), finalString); \
})

#define LSF(...) __LoggerRunInFocusedMode(^{ \
    metamacro_if_eq(0, metamacro_argcount2(__VA_ARGS__))( \
        printf("LSF()\n"); \
        return; \
    )() \
    NSString *echoedInput = @("LSF(" #__VA_ARGS__ ")"); \
    \
    NSString *describedOutput = [@[ \
    metamacro_foreach(__L_ITER,, __VA_ARGS__) \
    ] componentsJoinedByString:@"; "]; \
    \
    NSString *finalString = [@[ echoedInput, describedOutput] componentsJoinedByString:@" ~> "]; \
    __L(nil, finalString); \
})

// NSLog compatibility
#define LLog(...) do { \
    if (LOGGER_FOCUSED_MODE) break; \
    NSString *logString; \
    metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))( \
        logString = metamacro_head(__VA_ARGS__); \
    )( \
        logString = [NSString stringWithFormat:metamacro_head(__VA_ARGS__), metamacro_tail(__VA_ARGS__)]; \
    ) \
    __L(__LoggerSourceInfo(__FILE__, __LINE__, __PRETTY_FUNCTION__), logString); \
} while(0)

#define LSLog(...) do { \
    if (LOGGER_FOCUSED_MODE) break; \
    NSString *logString; \
    metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))( \
        logString = metamacro_head(__VA_ARGS__); \
    )( \
        logString = [NSString stringWithFormat:metamacro_head(__VA_ARGS__), metamacro_tail(__VA_ARGS__)]; \
    ) \
    __L(nil, logString); \
} while(0)

#define LFLog(...) __LoggerRunInFocusedMode(^{ \
    NSString *logString; \
    metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))( \
        logString = metamacro_head(__VA_ARGS__); \
    )( \
        logString = [NSString stringWithFormat:metamacro_head(__VA_ARGS__), metamacro_tail(__VA_ARGS__)]; \
    ) \
    __L(__LoggerSourceInfo(__FILE__, __LINE__, __PRETTY_FUNCTION__), logString); \
})

#define LSFLog(...) __LoggerRunInFocusedMode(^{ \
    NSString *logString; \
    metamacro_if_eq(1, metamacro_argcount(__VA_ARGS__))( \
        logString = metamacro_head(__VA_ARGS__); \
    )( \
        logString = [NSString stringWithFormat:metamacro_head(__VA_ARGS__), metamacro_tail(__VA_ARGS__)]; \
    ) \
    __L(nil, logString); \
})
