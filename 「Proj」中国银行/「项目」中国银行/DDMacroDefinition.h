//
//  DDMacroDefinition.h
//  「项目」中国银行
//
//  Created by 萧川 on 14-3-24.
//  Copyright (c) 2014年 CUAN. All rights reserved.
//

#ifndef _________DDMacroDefinition_h
#define _________DDMacroDefinition_h

#import "DDHTTPManager.h"

// 动画时长
#define kAnimateDuration 1.0f
// 更新数据事件间隔
#define kDataUpdateTimeInterval 600
// 获取图片
#define kImageWithNameHaveSuffix(NAME) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] \
pathForAuxiliaryExecutable:NAME]] // 获取图片
#define kImageWithName(NAME) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:NAME ofType:@"png"]]
// 随机颜色
#define kRandomColor [UIColor colorWithRed:arc4random() % 128 / 255.0f green:arc4random() % 64 / 255.0f blue:arc4random() % 255 / 255.0f alpha:1.000]
// 根视图
#define kRootView [[[((DDAppDelegate *)[[UIApplication sharedApplication] delegate]) window] rootViewController] view]
// 根控制器
#define kRootViewController [[((DDAppDelegate *)[[UIApplication sharedApplication] delegate]) window] rootViewController]

// 详情按钮tag
#define kDetailButtonTag 777
// 搜索按钮tag
#define kSearchTextFieldTag 121

// 根视图宽度
#define kRootViewWidth           1024
// 根视图高度
#define kRootViewHeight          768

// 根控制器
#ifndef _ROOT_VIEW_CONTROLLER_
#define _ROOT_VIEW_CONTROLLER_
#define kHeaderViewHeight    80     // 头部视图高度
#define kNaviBarViewWidth    88     // 左侧导航栏宽度
#define kNaviBarBaseViewWidth 80    // 左侧导航栏底图宽度
#define kNaviBarButtonHeight 107    // 导航栏按钮高度
#define kButtonTag           100    // 导航栏按钮tag基准值
#define kBottomImageViewHeight 20   // 下面图片视图高度
#endif

// 主界面
// 主界面宽度
#define kMainViewWidth (kRootViewWidth - kNaviBarBaseViewWidth)
// 主界面高度
#define kMainViewHeight (kRootViewHeight - kHeaderViewHeight)
// 主界面frame
#define kMainViewFrame (CGRectMake(kNaviBarBaseViewWidth, kHeaderViewHeight, kMainViewWidth, kMainViewHeight))
// 主界面bounds
#define kMainViewBounds (CGRectMake(0, 0, kMainViewWidth, kMainViewHeight))
// 主界面center
#define kMainViewCenter (CGPointMake((kNaviBarBaseViewWidth) + (kMainViewWidth / 2), (kHeaderViewHeight) + (kMainViewHeight / 2)))
// 主界面center
#define kMainViewCenterUp (CGPointMake((kNaviBarBaseViewWidth) + (kMainViewWidth / 2), - kMainViewHeight / 2 + kHeaderViewHeight))
// 主界面center
#define kMainViewCenterDown (CGPointMake((kNaviBarBaseViewWidth) + (kMainViewWidth / 2), kRootViewHeight + kMainViewHeight / 2))

// 登录界面
#ifndef _DDLOGIN_
#define _DDLOGIN_
// 背景图片视图tag
#define kBackgroundImageViewTag 200
#define kUserInfoKey @"userInfo"
#define kUserInfoActivationKey @"activation"
#define kUserInfoActivationCode @"activationCode"
#define kUserInfoBirthday @"birthday"
#define kUserInfoDepartment @"department"
#define kUserInfoEmail @"email"
#define kUserInfoEmployeeId @"employeeId"
#define kUserInfoErrorCount @"errorCount"
#define kUserInfoErrorIp @"errorIp"
#define kUserInfoErrorTime "errorTime"
#define kUserInfoGender @"gender"
#define kUserInfoId @"id"
#define kUserInfoJob @"job"
#define kUserInfoLastLoginIp @"lastLoginIp"
#define kUserInfoLastLoginTime @"lastLoginTime"
#define kUserInfoLoginCount @"loginCount"
#define kUserInfoMsn @"msn"
#define kUserInfoPassword @"password"
#define kUserInfoPhone @"phone"
#define kUserInfoQQ @"qq"
#define kUserInfoRealname @"realname"
#define kUserInfoRegisterIp @"registerIp"
#define kUserInfoRegisterTime @"registerTime"
#define kUserInfoResetKey @"resetKey"
#define kUserInfoResetPwd @"resetPwd"
#define kUserInfoUserImg @"userImg"
#define kUserInfoUserSignature @"userSignature"
#define kUserInfoUsername @"username"
#endif

// 首页
#ifndef _INDEX_
#define _INDEX_
// 循环图片键
#define kLoopImagesURLKey @"loopImagesURLKey"
// 最新消息键
#define kLatestNewsKey @"latestNewsKey"
// 最热消息键
#define kHotNewsKey @"hotNewsKey"
// 自定义产品
#define kCustomKey @"customProduct"
// 最热视图键
#define kHotCollectionViewTag 300
// 自定义产品视图键
#define kCustomProjectCollectionViewTag 301
// 最新消息原件bounds
#define kHotNewsShowComponentBounds (CGRectMake(0, 0, 240, 100))
// 自定义产品原件bounds
#define kCustomProjectComponentBounds (CGRectMake(0, 0, 120, 100))

#define kPhotoRULKey @"photo"
#define kContentKey @"content"
#define kNewsTitleKey @"title"
#define kNewsDetailKey @"content"
#define kNewsDetailContentKey @"detail"

#endif

// 出国
#ifndef _ABROAD_
#define _ABROAD_
// title tag
#define kTitleButtonTag 400
// 按钮tag
#define kLeftButtonTag 420
#endif

// 理财产品
#ifndef _FINANCE_PRODUCTS_
#define _FINANCE_PRODUCTS_
// 理财产品页tag
#define kFinanceButtonTag 500
#define kMetalButtonTag 550

#endif

// 购物车
#ifndef _SHOPCART_
#define _SHOPCART_
#define kCartButtonTag 600
#endif

//A better version of NSLog
#define NSLog(format, ...) do {                                             \
fprintf(stderr, "<%s : %d> %s\n",                                           \
[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String],  \
__LINE__, __func__);                                                        \
(NSLog)((format), ##__VA_ARGS__);                                           \
fprintf(stderr, "-------\n");                                               \
} while (0)

#define echo() NSLog(@"---\n content = %@, \n --- \n resultCode = %@", content, resultCode)

// 购买产品数量和产品信息
#define kBuyNumer @"buynumber"
#define kBuyProductInfo @"buyProductInfo"
#define kOrderInfo @"orderInfo"

#define PATH [NSHomeDirectory() stringByAppendingPathComponent:@"productInfo.plist"]
#define PATH_ORDER [NSHomeDirectory() stringByAppendingPathComponent:@"orderInfo.plist"]


#endif
