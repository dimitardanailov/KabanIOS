//
//  AppDelegate.h
//  KabanIOS
//
//  Created by Dimitar Danailov on 22.08.18.
//  Copyright © 2018 Dimitar Danailov. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>
@import GoogleSignIn;

@interface AppDelegate : UIResponder <UIApplicationDelegate, GIDSignInDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong) NSPersistentContainer *persistentContainer;

- (void)saveContext;


@end

