//
//  DDBuyView.h
//  「项目」中国银行
//
//  Created by 萧川 on 14-3-19.
//  Copyright (c) 2014年 CUAN. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DDBuyView : UIView

- (id)initWithFrame:(CGRect)frame productInfo:(NSDictionary *)productInfos;
@property (nonatomic, retain) NSDictionary *productInfos;

@end
