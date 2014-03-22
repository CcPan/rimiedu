//
//  DDOptional.m
//  「项目」中国银行
//
//  Created by 萧川 on 14-3-10.
//  Copyright (c) 2014年 CUAN. All rights reserved.
//

#import "DDCustomCellView.h"

@implementation DDCustomCellView

- (void)dealloc
{
    NSLog(@"%@ is dealloced", [self class]);
    [_tapDetailAction   release];
    [_tapBuyAction release];
    [_contentView release];
    [_titleLabel release];
    [super dealloc];
}

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        self.frame = CGRectMake(0, 0, 290, 290);
        UIImageView *imageView = [[UIImageView alloc] initWithFrame:self.frame];
        imageView.image = [UIImage imageNamed:@"未标题-1_01"]; // cache
        [self addSubview:imageView];
        [imageView release];
        
        _titleLabel = [[UILabel alloc] init];
        _titleLabel.bounds = CGRectMake(0,
                                       0,
                                       CGRectGetWidth(imageView.bounds),
                                       CGRectGetHeight(imageView.bounds) * 0.2);
        _titleLabel.center = CGPointMake(CGRectGetMidX(imageView.bounds),
                                        CGRectGetMidY(_titleLabel.bounds));
        _titleLabel.textAlignment = NSTextAlignmentCenter;
        _titleLabel.text = @"test";
        [imageView addSubview:_titleLabel];
        
        // 详情按钮
        UIButton *detailButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        detailButton.bounds = CGRectMake(0, 0, 60, 30);
        detailButton.tag = kDetailButtonTag;
        detailButton.center = CGPointMake(CGRectGetMidX(_titleLabel.bounds) -
                                          CGRectGetMidX(detailButton.bounds) - 10,
                                          CGRectGetMaxY(imageView.bounds) -
                                          CGRectGetHeight(detailButton.bounds));
        [detailButton setBackgroundImage:[UIImage imageNamed:@"详情_01"]
                                forState:UIControlStateNormal]; // cache
        [detailButton addTarget:self
                   action:@selector(processTap:)
         forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:detailButton];
        
        // 选购按钮
        UIButton *chooseButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        chooseButton.bounds = detailButton.bounds;
        chooseButton.center = CGPointMake(CGRectGetWidth(imageView.bounds) -
                                          CGRectGetMidX(detailButton.frame),
                                          detailButton.center.y);
        [chooseButton setBackgroundImage:[UIImage imageNamed:@"选购_03"]
                                forState:UIControlStateNormal]; // chche
        [chooseButton addTarget:self
                   action:@selector(processTap:)
         forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:chooseButton];
        
        // 内容视图
        _contentView = [[UIView alloc] init];
        _contentView.bounds = CGRectMake(0, 0, 270, 170);
        _contentView.center = CGPointMake(CGRectGetMidX(imageView.bounds),
                                          CGRectGetMidY(imageView.bounds) + 10);
        [imageView addSubview:_contentView];
    }
    return self;
}

- (void)processTap:(UIButton *)sender
{
    NSInteger index = sender.tag;
    if (kDetailButtonTag == index) {
        // 查看详情
        if (_tapDetailAction) {
            _tapDetailAction(sender);
        }
    } else {
        // 购买
        if (_tapBuyAction) {
            _tapBuyAction(sender);
        }
    }
}

@end
