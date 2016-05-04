//
//  Utils.h
//  pushapps
//
//  Created by Grisha on 2/16/16.
//  Copyright © 2016 pushapps.mobi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PAUtils : NSObject

+(NSString *)getIPAddress:(BOOL)preferIPv4;
+(NSString *)getAppVersion;
+(NSString *)getAppBuildVersion;
+(NSString *)getDeviceDescription;
+(NSString *)getGmtOffset;
+(NSString *)encodeToken:(NSData*) token;
+(NSString *)identifierForAdvertising;
+(NSString *)deviceIdentifier;
+(BOOL)isDevelopmentBuild;

@end
