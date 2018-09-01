//
//  FacebookLoginHelper.m
//  KabanIOS
//
//  Created by Dimitar Danailov on 1.09.18.
//  Copyright © 2018 Dimitar Danailov. All rights reserved.
//

#import "FacebookLoginHelper.h"
#import "Profile.h"

@interface FacebookLoginHelper()


@end

@implementation FacebookLoginHelper

- (instancetype)init
{
    self = [super init];
    
    if (self) {
        self.profileManager = [[ProfileManager alloc] init];
    }
    
    return self;
}

- (void)initializeFacebookProfile:(void (^)(FBSDKGraphRequestConnection *connection, id result, NSError *error))block {
    NSDictionary *params = [Profile facebookParams];

    [[[FBSDKGraphRequest alloc] initWithGraphPath:@"me" parameters:params]
     startWithCompletionHandler: block];
}

@end
