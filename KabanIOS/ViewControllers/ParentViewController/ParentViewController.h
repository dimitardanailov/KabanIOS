//
//  ParentViewController.h
//  KabanIOS
//
//  Created by Dimitar Danailov on 1.09.18.
//  Copyright © 2018 Dimitar Danailov. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIViewController+Additions.h"

@interface ParentViewController : UIViewController

- (void)loadViewController:(NSString *)storyIdentifier animated:(BOOL)animated;

@end
