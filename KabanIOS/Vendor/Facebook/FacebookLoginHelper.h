//
//  FacebookLoginHelper.h
//  KabanIOS
//
//  Created by Dimitar Danailov on 1.09.18.
//  Copyright © 2018 Dimitar Danailov. All rights reserved.
//

#import <FBSDKCoreKit/FBSDKCoreKit.h>
#import <Foundation/Foundation.h>
#import "ProfileManager.h"

@interface FacebookLoginHelper : NSObject

@property (strong, nonatomic) NSString *token;
@property (strong, nonatomic) ProfileManager *profileManager;

- (void)initializeFacebookProfile:(void (^)(FBSDKGraphRequestConnection *connection, id result, NSError *error))block;

@end

