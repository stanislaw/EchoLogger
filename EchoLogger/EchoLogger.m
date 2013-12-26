//
//  EchoLogger
//
//  EchoLogger.m
//
//  Created by Stanislaw Pankevich on 9/7/13.
//  Copyright (c) 2013 Stanislaw Pankevich. All rights reserved.
//


#import "EchoLogger.h"


#pragma mark
#pragma mark L family methods


void __L(NSString *sourceInfo, NSString *logString) {
    NSMutableArray *resultComponents = [NSMutableArray array];

    if (sourceInfo) {
        [resultComponents addObject:sourceInfo];
    }

    if (logString) {
        [resultComponents addObject:logString];
    }

    NSString *resultString = [resultComponents componentsJoinedByString:@" "];

    if ([resultString hasSuffix:@"\n"] == NO) {
        resultString = [resultString stringByAppendingString:@"\n"];
	}

    fprintf(stdout, "%s", resultString.UTF8String);
}


#pragma mark
#pragma mark Focused mode


BOOL EchoLoggerFocusedModeEnabled = NO;


void __EchoLoggerRunInFocusedMode(void (^block)(void)) {
    if (EchoLoggerFocusedModeEnabled == NO) printf("\n/* Logger is entering in focused mode */\n\n");
    EchoLoggerFocusedModeEnabled = YES;

    block();
}


#pragma mark
#pragma mark Source information


NSString * __EchoLoggerSourceInfo(const char *file, int lineNumber, const char *funcName) {
    NSString *fileName = [[NSString stringWithUTF8String:file] lastPathComponent];

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    const char *queueLabel = dispatch_queue_get_label(dispatch_get_current_queue());
#pragma clang diagnostic pop

    NSString *sourceInfo = [NSString stringWithFormat:@"[%s] %s (%s:%d)", queueLabel, funcName, fileName.UTF8String, lineNumber];

    return sourceInfo;
}

