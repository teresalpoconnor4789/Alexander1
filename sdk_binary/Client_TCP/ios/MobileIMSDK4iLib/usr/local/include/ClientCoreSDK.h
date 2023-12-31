//  ----------------------------------------------------------------------
//  Copyright (C) 2021  即时通讯网(52im.net) & Jack Jiang.
//  The MobileIMSDK_TCP (MobileIMSDK v6.x TCP版) Project.
//  All rights reserved.
//
//  > Github地址: https://github.com/JackJiang2011/MobileIMSDK
//  > 文档地址:    http://www.52im.net/forum-89-1.html
//  > 技术社区：   http://www.52im.net/
//  > 技术交流群： 215477170 (http://www.52im.net/topic-qqgroup.html)
//  > 作者公众号： “即时通讯技术圈】”，欢迎关注！
//  > 联系作者：   http://www.52im.net/thread-2792-1-1.html
//
//  "即时通讯网(52im.net) - 即时通讯开发者社区!" 推荐开源工程。
//  ----------------------------------------------------------------------

#import <Foundation/Foundation.h>
#import "ClientCoreSDK.h"
#import "ChatMessageEvent.h"
#import "ChatBaseEvent.h"
#import "MessageQoSEvent.h"
#import "CompletionDefine.h"
#import "PLoginInfo.h"

@interface ClientCoreSDK : NSObject

//## 受制于iOS没有精确的网络事件通知机制，本字段的维护在当前的方案下，会不精确（比如模拟器下，电脑断开和连接时，模拟器小概率能收到断开事件，但无法收到已连接事件），所以干脆去掉这个鸡肋字段了
//@property (nonatomic, assign) BOOL localDeviceNetworkOk;

@property (nonatomic, assign) BOOL connectedToServer;
@property (nonatomic, assign) BOOL loginHasInit;
@property (nonatomic, retain) PLoginInfo *currentLoginInfo;

@property (nonatomic, retain) id<ChatMessageEvent> chatMessageEvent;
@property (nonatomic, retain) id<ChatBaseEvent> chatBaseEvent;
@property (nonatomic, retain) id<MessageQoSEvent> messageQoSEvent;


//------------------------------------------------------
#pragma mark - 静态方法
+ (ClientCoreSDK *)sharedInstance;
+ (BOOL) isENABLED_DEBUG;
+ (void) setENABLED_DEBUG:(BOOL)enabledDebug;
+ (BOOL) isAutoReLogin;
+ (void) setAutoReLogin:(BOOL)arl;

+ (void) setSSL:(BOOL)ssl;
+ (int) isSSL;


//------------------------------------------------------
#pragma mark - 实例方法
- (BOOL) isInitialed;
- (void)initCore;
- (void) releaseCore;

- (void) saveFirstLoginTime:(long)firstLoginTime;
- (NSString *) currentLoginUserId;
@end
