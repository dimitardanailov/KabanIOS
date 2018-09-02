//
//  ParentViewController.m
//  KabanIOS
//
//  Created by Dimitar Danailov on 1.09.18.
//  Copyright © 2018 Dimitar Danailov. All rights reserved.
//

#import "ParentViewController.h"
#import "HomeViewController.h"

@interface ParentViewController ()

@end

@implementation ParentViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void)loadViewController:(NSString *)storyIdentifier animated:(BOOL)animated {
    ParentViewController *vc = [self.storyboard instantiateViewControllerWithIdentifier:storyIdentifier];
    
    [self.navigationController pushViewController:vc animated:animated];
}


@end
