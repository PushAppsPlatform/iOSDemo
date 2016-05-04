//
//  pushapps.h
//  pushapps
//
//  Created by Grisha on 2/15/16.
//  Copyright © 2016 pushapps.mobi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "PACommon.h"

//! Project version number for pushapps.
FOUNDATION_EXPORT double pushappsVersionNumber;

//! Project version string for pushapps.
FOUNDATION_EXPORT const unsigned char pushappsVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <pushapps/PublicHeader.h>

typedef void (^PACompletionBlock)(id object, NSError *error);

@interface PushApps : NSObject

// check this flag to see if the Pushapps service is currently available
+(BOOL)isPushAppsServiceAvailable;

+(void)setDelegate:(id<PAPopupDelegate>)newDelegate;

// initialize push notifications for the application
+(void)registerForPushNotifications:(NSDictionary *)launchOptions;

// register to the Pushapps service
+(void)registerDeviceWithSdkKey:(NSString*)sdkKey;

// send APNS device token to the Pushapps service
+(void)setDevicePushToken:(NSData *)deviceToken;

// processes push notification
+(void)handleNotification:(NSDictionary *)userInfo;

+(void)getWidgetFeedForParams:(NSDictionary *)params withCompletionBlock:(PACompletionBlock)completion;

@end