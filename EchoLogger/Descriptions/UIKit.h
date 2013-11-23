//
//  UIKit.h
//
//  Created by Stanislaw Pankevich on 9/7/13.
//  Copyright (c) 2013 Stanislaw Pankevich. All rights reserved.
//

#ifdef UIKIT_EXTERN

static inline NSString * __attribute__((overloadable)) LoggerDescription(CGRect rect) {
    NSString *string = [NSString stringWithFormat:@"(CGRect){%f, %f, %f, %f}", rect.origin.x, rect.origin.y, rect.size.width, rect.size.height];

    return string;
}

static inline NSString * __attribute__((overloadable)) LoggerDescription(CGSize size) {
    NSString *string = [NSString stringWithFormat:@"(CGSize){%f, %f}", size.width, size.height];
    return string;
}

static inline NSString * __attribute__((overloadable)) LoggerDescription(CGPoint point) {
    NSString *string = [NSString stringWithFormat:@"(CGPoint){%f, %f}", point.x, point.y];
    return string;
}

#endif
