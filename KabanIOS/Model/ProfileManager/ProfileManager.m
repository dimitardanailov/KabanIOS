//
//  ProfileManager.m
//  KabanIOS
//
//  Created by Dimitar Danailov on 22.08.18.
//  Copyright © 2018 Dimitar Danailov. All rights reserved.
//

#import "ProfileManager.h"

@interface ProfileManager ()
@end

@implementation ProfileManager

+ (ProfileManager *)manager {
    static ProfileManager *sharedInstance;
    
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        sharedInstance = [[ProfileManager alloc] init];
    });
    
    return sharedInstance;
}
    
- (instancetype)init {
    self = [super init];
    
    if (!self) {
        return nil;
    }
    
    self.profile = [[Profile alloc] init];
    
    return self;
}

@end


