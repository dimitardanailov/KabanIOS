//
//  HomeViewController.m
//  KabanIOS
//
//  Created by Dimitar Danailov on 1.09.18.
//  Copyright © 2018 Dimitar Danailov. All rights reserved.
//

#import "SideMenuViewController.h"
#import "RevealViewController.h"

#import "HomeViewController.h"

@interface HomeViewController () <RevealViewControllerDelegate, UITabBarDelegate>

@end

@implementation HomeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSLog(@"Loaded");
    
    [self configureUserInterface];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Customization

- (void)configureUserInterface {
    // Customize RevealViewController
    self.revealViewController.leftViewRevealWidth = 300;
    self.revealViewController.delegate = self;
    
    [self configureSideButton];
}

- (void)configureSideButton {
    UIImage *image = [UIImage imageNamed:@"placeholder-profile-navbar"];
    
    // Customize left Bar button item
    CGRect frame = CGRectMake(0, 0, image.size.width, image.size.height);
    UIButton *sideButton = [[UIButton alloc] initWithFrame:frame];
    [sideButton setImage:image forState:UIControlStateNormal];
    
    [sideButton addTarget:self.revealViewController action:@selector(revealLeftView) forControlEvents:UIControlEventTouchUpInside];
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:sideButton];
}


@end
