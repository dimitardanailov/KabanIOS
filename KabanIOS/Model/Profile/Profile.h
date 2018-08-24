//
//  Profile.h
//  KabanIOS
//
//  Created by Dimitar Danailov on 22.08.18.
//  Copyright © 2018 Dimitar Danailov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseModel.h"

@interface Profile: BaseModel

/**
 * User's profile id
 */
@property (copy, readonly, nullable) NSString *profileId;
    
/**
 * User's google plus id
 */
@property (copy, readonly, nullable) NSString *googlePlusId;

/**
 * User's name
 */
@property (copy, readonly, nullable) NSString *name;
    
/**
 * User's given name
 */
@property (copy, readonly, nullable) NSString *givenName;
    
/**
 * User's family name
 */
@property (copy, readonly, nullable) NSString *familyName;
    
/**
 * User's family email
 */
@property (copy, readonly, nullable) NSString *email;
    
@end
