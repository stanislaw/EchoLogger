//
//  Foundation.h
//
//  Created by Stanislaw Pankevich on 9/7/13.
//  Copyright (c) 2013 Stanislaw Pankevich. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>


static inline NSString * __attribute__((overloadable)) LoggerDescription(void) {
    return nil;
}

#pragma mark
#pragma mark NSLog behavior: format and arguments or NSObjects

static inline NSString * __attribute__((overloadable)) LoggerDescription(id objectOrFormat, ...) {
    if (class_isMetaClass(object_getClass(objectOrFormat))) {
        return [NSString stringWithFormat:@"(%@)%@", @"Class", objectOrFormat]; NSStringFromClass(objectOrFormat);
    }

    if ([objectOrFormat isKindOfClass:[NSString class]] == NO) {
        return [NSString stringWithFormat:@"(%@)%@", [objectOrFormat class], objectOrFormat];
    }

    va_list ap;

    va_start(ap, objectOrFormat);

    NSString *body = [[NSString alloc] initWithFormat:objectOrFormat arguments:ap];

  	va_end(ap);

    return body;
}

#pragma mark
#pragma mark BOOL

static inline NSString * __attribute__((overloadable)) LoggerDescription(BOOL yes_or_no) {
    if (yes_or_no)
        return(@"(BOOL)Yes");
    else
        return(@"(BOOL)No");
}

#pragma mark
#pragma mark Numeric

static inline NSString * __attribute__((overloadable)) LoggerDescription(int number) {
    NSString *string = [NSString stringWithFormat:@"(int)%d", number];
    return string;
}

static inline NSString * __attribute__((overloadable)) LoggerDescription(long number) {
    NSString *string = [NSString stringWithFormat:@"(long)%ld", number];
    return string;
}

static inline NSString * __attribute__((overloadable)) LoggerDescription(float number) {
    NSString *string = [NSString stringWithFormat:@"(float)%f", number];
    return string;
}

static inline NSString * __attribute__((overloadable)) LoggerDescription(NSUInteger number) {
    NSString *string = [NSString stringWithFormat:@"(NSUInteger)%lu", (unsigned long)number];
    return string;
}

static inline NSString * __attribute__((overloadable)) LoggerDescription(NSTimeInterval timeInterval) {     NSString *string = [NSString stringWithFormat:@"(NSTimeInterval)%f", (double)timeInterval];
    return string;
}

#pragma mark
#pragma mark C string

static inline NSString * __attribute__((overloadable)) LoggerDescription(char *obj) {
    NSString *string = [NSString stringWithFormat:@"(C string char*)%s", obj];
    return string;
}

#pragma mark
#pragma mark Structs

static inline NSString * __attribute__((overloadable)) LoggerDescription(NSRange range) {
    NSString *string = [NSString stringWithFormat:@"(NSRange){%lu, %lu}", (unsigned long)range.location, (unsigned long)range.length];
    return string;
}
