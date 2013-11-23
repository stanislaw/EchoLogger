//
//  CoreLocation.h
//
//  Created by Stanislaw Pankevich on 9/7/13.
//  Copyright (c) 2013 Stanislaw Pankevich. All rights reserved.
//

#ifdef CL_EXTERN

static inline NSString * __attribute__((overloadable)) LoggerDescription(CLLocationCoordinate2D coordinate) {
    NSString *string = [NSString stringWithFormat:@"(CLLocationCoordinate2D){%f, %f}", coordinate.latitude, coordinate.longitude];
    return string;
}

#endif
