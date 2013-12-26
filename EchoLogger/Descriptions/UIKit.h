//
//  EchoLogger
//
//  Descriptions/UIKit.h
//
//  Created by Stanislaw Pankevich on 9/7/13.
//  Copyright (c) 2013 Stanislaw Pankevich. All rights reserved.
//


#import <UIKit/UIKit.h>


static inline NSString * __attribute__((overloadable)) EchoLoggerDescription(CGRect rect) {
    NSString *string = [NSString stringWithFormat:@"(CGRect){%f, %f, %f, %f}", rect.origin.x, rect.origin.y, rect.size.width, rect.size.height];

    return string;
}


static inline NSString * __attribute__((overloadable)) EchoLoggerDescription(CGSize size) {
    NSString *string = [NSString stringWithFormat:@"(CGSize){%f, %f}", size.width, size.height];

    return string;
}


static inline NSString * __attribute__((overloadable)) EchoLoggerDescription(CGPoint point) {
    NSString *string = [NSString stringWithFormat:@"(CGPoint){%f, %f}", point.x, point.y];
    
    return string;
}

