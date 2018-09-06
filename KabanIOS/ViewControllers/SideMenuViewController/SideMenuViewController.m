//
//  SideMenuViewController.m
//  KabanIOS
//
//  Created by Dimitar Danailov on 6.09.18.
//  Copyright © 2018 Dimitar Danailov. All rights reserved.
//

#import "SideMenuViewController.h"
#import "RevealViewController.h"
#import "ProfileManager.h"

@interface SideMenuViewController ()

/**
 Menu handlers blocks
 */
@property (strong, nonatomic) NSMutableArray *handlersArray;

@end

@implementation SideMenuViewController

- (instancetype)init {
    self = [super init];
    
    if (self) {
        self.handlersArray = [NSMutableArray array];
    }
    
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSLog(@"SideMenuViewController was loaded");
    
    // Uncomment the following line to preserve selection between presentations.
    self.tableView.tableFooterView = [[UIView alloc] initWithFrame:CGRectZero];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    // Note: should not be necessary but current iOS bug requires it.
    [tableView deselectRowAtIndexPath:indexPath animated:NO];
    
    // Hide the side menu
    [self.revealViewController hideLeftViewAnimated:YES];
}

#pragma mark - Helpers

- (void)addHandler:(void(^)(void))handler {
    [self.handlersArray addObject:handler];
}

- (void)clearHandlersArray {
    [self.handlersArray removeAllObjects];
}

@end
