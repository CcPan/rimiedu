//
//  DDBlockButton.h
//  「UI」BlockCircularReference
//
//  Created by 萧川 on 3/4/14.
//  Copyright (c) 2014 CUAN. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DDBlockButton : UIButton

@property (nonatomic, copy) void (^clickBlock)(DDBlockButton *);

@end
