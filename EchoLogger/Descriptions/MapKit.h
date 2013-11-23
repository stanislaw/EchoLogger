//
//  MapKit.h
//
//  Created by Stanislaw Pankevich on 9/7/13.
//  Copyright (c) 2013 Stanislaw Pankevich. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef MK_EXTERN

static inline NSString * __attribute__((overloadable)) LoggerDescription(MKCoordinateRegion region) {
    NSString *string = [NSString stringWithFormat:@"(MKCoordinateRegion){%f, %f, %f, %f}", region.center.latitude, region.center.longitude, region.span.latitudeDelta, region.span.longitudeDelta];
    return string;
}

static inline NSString * __attribute__((overloadable)) LoggerDescription(MKMapRect rect) {
    NSString *string = [NSString stringWithFormat:@"(MKMapRect){%f, %f, %f, %f}", rect.origin.x, rect.origin.y, rect.size.width, rect.size.height];
    return string;
}

#endif
