//
//  main.m
//  TestsCommandLineApp
//
//  Created by Stanislaw Pankevich on 30/01/14.
//  Copyright (c) 2014 Stanislaw Pankevich. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "EchoLogger.h"

int main(int argc, const char * argv[])
{

    @autoreleasepool {
        

        id num = @(1);
        id string = @"String";
        id array = @[];

        L(num);
        L(num, string, array);

        L(num, string, array);
        L(num, string, array);
        L(num, string, array);
    }
    
    return 0;
}

