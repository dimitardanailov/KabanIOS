//
//  Profile.m
//  KabanIOS
//
//  Created by Dimitar Danailov on 22.08.18.
//  Copyright © 2018 Dimitar Danailov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Profile.h"

@interface Profile ()
@end

@implementation Profile

- (nullable instancetype)init {
    self = [super init];
    
    return self;
}

- (void)updateThroughFacebookAttributes:(NSDictionary *)fbAttributes {
    _email = fbAttributes[@"email"];
}

+ (NSDictionary *)facebookParams {
    return @{@"fields": @"email,name"};
}

@end
