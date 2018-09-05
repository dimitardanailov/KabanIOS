//
//  WelcomeViewController.m
//  KabanIOS
//
//  Created by Dimitar Danailov on 2.09.18.
//  Copyright © 2018 Dimitar Danailov. All rights reserved.
//

#import <FBSDKCoreKit/FBSDKCoreKit.h>

#import "WelcomeViewController.h"
#import "HomeViewController.h"
#import "WelcomeLoginViewController.h"
#import "RevealViewController.h"

@interface WelcomeViewController ()

@end

@implementation WelcomeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self loadDependsSocialProviderData];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    self.navigationController.navigationBarHidden = YES;
}

#pragma mark - Navigation

/**
 * @method loadDependsSocialProviderData
 * @abstract If user is logged through Facebook or Google Plus
 * Application should load HomeView otherwise Application must load
 * WelcomeLoginView
 */
- (void)loadDependsSocialProviderData {
    if ([FBSDKAccessToken currentAccessToken]) {
        NSLog(@"RevealViewController");
        [self loadViewController:RevealViewController.storyboardIdentifier animated:NO];
    } else {
        NSLog(@"WelcomeLoginView");
        [self loadViewController:WelcomeLoginViewController.storyboardIdentifier animated:YES];
    }
}

@end
