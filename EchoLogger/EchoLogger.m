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
#pragma mark Focused mode


BOOL EchoLoggerFocusedModeEnabled = NO;


#pragma mark
#pragma mark Source information


NSString * __EchoLoggerSourceInfo(const char *file, int lineNumber, const char *funcName) {
    NSString *fileName = [[NSString stringWithUTF8String:file] lastPathComponent];

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    const char *queueLabel = dispatch_queue_get_label(dispatch_get_current_queue());
#pragma clang diagnostic pop

    NSString *sourceInfo = [NSString stringWithFormat:@"%s:%d; %s; %s", fileName.UTF8String, lineNumber, funcName, queueLabel];

    return sourceInfo;
}

