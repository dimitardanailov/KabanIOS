//
//  ProfileManager.h
//  KabanIOS
//
//  Created by Dimitar Danailov on 22.08.18.
//  Copyright © 2018 Dimitar Danailov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Profile.h"

@interface ProfileManager : NSObject

+ (ProfileManager *)manager;
@property (strong, nonatomic) Profile *profile;

@end
