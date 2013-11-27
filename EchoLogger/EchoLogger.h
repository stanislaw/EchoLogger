//
//  Logger.h
//
//  Created by Stanislaw Pankevich on 12/9/12.
//  Copyright (c) 2012 Stanislaw Pankevich. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "libextobjc/metamacros.h"

#import "Descriptions/Foundation.h"

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
    if (strlen(#__VA_ARGS__) == 0) { \
        finalString = @"L()"; \
    } else { \
        NSString *echoedInput = @("L(" #__VA_ARGS__ ")"); \
        \
        NSString *describedOutput = [@[ \
            metamacro_foreach(__L_ITER,, __VA_ARGS__) \
        ] componentsJoinedByString:@"; "]; \
        \
        finalString = [@[ echoedInput, describedOutput] componentsJoinedByString:@" ~> "]; \
    } \
    \
    __L(__LoggerSourceInfo(__FILE__, __LINE__, __PRETTY_FUNCTION__), finalString); \
} while(0)

#define LS(...) do { \
    if (LOGGER_FOCUSED_MODE) break; \
    if (strlen(#__VA_ARGS__) == 0) { \
        printf("LS()\n"); \
        break; \
    } \
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
    if (strlen(#__VA_ARGS__) == 0) { \
        finalString = @"LF()"; \
    } else { \
        NSString *echoedInput = @("LF(" #__VA_ARGS__ ")"); \
        \
        NSString *describedOutput = [@[ \
            metamacro_foreach(__L_ITER,, __VA_ARGS__) \
        ] componentsJoinedByString:@"; "]; \
        \
        finalString = [@[ echoedInput, describedOutput] componentsJoinedByString:@" ~> "]; \
    } \
    \
    __L(__LoggerSourceInfo(__FILE__, __LINE__, __PRETTY_FUNCTION__), finalString); \
})

#define LSF(...) __LoggerRunInFocusedMode(^{ \
    if (strlen(#__VA_ARGS__) == 0) { \
        printf("LF()\n"); \
        return; \
    } \
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
