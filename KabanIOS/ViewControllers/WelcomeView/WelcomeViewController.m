//
//  ViewController.m
//  KabanIOS
//
//  Created by Dimitar Danailov on 22.08.18.
//  Copyright © 2018 Dimitar Danailov. All rights reserved.
//

#import <FBSDKCoreKit/FBSDKCoreKit.h>
#import <FBSDKLoginKit/FBSDKLoginKit.h>

#import "WelcomeViewController.h"

@interface WelcomeViewController ()
@end

@implementation WelcomeViewController

-(void)viewDidLoad {
    [super viewDidLoad];
    
    // Facebook
    [self loadFacebookSignButton];
    if ([FBSDKAccessToken currentAccessToken]) {
        NSLog(@"User is logged through Facebook ...");
    }
    
    // Google plus
    [self initializeGooglePlus];
}


-(void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
    
# pragma mark - Facebook
    
-(void)loadFacebookSignButton {
    FBSDKLoginButton *loginButton = [[FBSDKLoginButton alloc] init];
    // Optional: Place the button in the center of your view.
    loginButton.center = self.view.center;
    loginButton.readPermissions = @[@"public_profile", @"email"];
    
    [self.view addSubview:loginButton];
}
    
# pragma mark - Google plus
    
-(void)initializeGooglePlus {
    // TODO(developer) Configure the sign-in button look/feel
    
    [GIDSignIn sharedInstance].uiDelegate = self;
    
    // Uncomment to automatically sign in the user.
    [[GIDSignIn sharedInstance] signInSilently];
}
    
    // Present a view that prompts the user to sign in with Google
-(void)signIn:(GIDSignIn *)signIn presentViewController:(UIViewController *)viewController {
    [self presentViewController:viewController animated:YES completion:nil];
}

// Dismiss the "Sign in with Google" view
-(void)signIn:(GIDSignIn *)signIn
dismissViewController:(UIViewController *)viewController {
    [self dismissViewControllerAnimated:YES completion:nil];
}


@end
