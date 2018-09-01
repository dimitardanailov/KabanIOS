//
//  UIViewController+Additions.m
//  KabanIOS
//
//  Created by Dimitar Danailov on 1.09.18.
//  Copyright © 2018 Dimitar Danailov. All rights reserved.
//

#import "UIViewController+Additions.h"

@implementation UIViewController (Additions)

+ (NSString *)storyboardIdentifier {
    return NSStringFromClass(self);
}

@end
