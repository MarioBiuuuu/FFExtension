//
//  FFManager.h
//  FFExtension
//
//  Created by hufeng on 21/9/18.
//  Copyright © 2018年 shensz. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, FFHookOption){
    FFHookOptionNone = 0,
    FFHookOptionUnrecognizedSelector = 1 << 0,
    FFHookOptionNSString = 1 << 1,
    FFHookOptionNSArray = 1 << 2,
    FFHookOptionNSDictionary = 1 << 3,
    FFHookOptionNSData = 1 << 4,
    FFHookOptionNSSet = 1 << 5,
    FFHookOptionNSUserDefaults = 1 << 6,
    FFHookOptionNSCache = 1 << 7,
    FFHookOptionAll = 0xFF,
};

@interface FFManager : NSObject



/**
 外部统一入口，调用后生效

 @param option hook的类型
 */
+ (void)startWorkWithOption:(FFHookOption)option;



/**
 对自定义的类增加unrecognized selector sent to instance拦截
 默认仅针对@[NSNumber，NSString，NSArray，NSDictionary]做拦截
 @param classPrefixs 类名前缀的集合，大小写敏感
 */
+ (void)addUnrecognizedSelectorWithClassPrefixs:(NSArray <NSString *>*)classPrefixs;

@end
