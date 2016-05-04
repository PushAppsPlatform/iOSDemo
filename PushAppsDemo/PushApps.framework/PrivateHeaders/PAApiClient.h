//
//  PAApi.h
//  pushapps
//
//  Created by Grisha on 2/15/16.
//  Copyright © 2016 pushapps.mobi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PABaseHttpRequest.h"
#import "PACommon.h"

@interface PAApiClient : PABaseHttpRequest

@property NSString* sdkKey;

+ (PAApiClient*)sharedClient;

-(NSURLSessionTask*) standartApiRequest:(NSString*)func parameters:(NSDictionary*)parameters
                              parseJson:(BOOL)parseJson completion:(HttpRequestCompletion)completion;

-(NSURLSessionTask*) registerDevice: (registerDeviceCompletion)completion;
-(NSURLSessionTask*) setToken:(NSString*)token completion:(setTokenCompletion)completion;
-(NSURLSessionTask*) reportClick:(NSDictionary *)params completion:(setTokenCompletion)completion;
-(NSURLSessionTask*) getWidgetFeed:(NSDictionary *)params completion:(getWidgetFeedCompletion)completion;

@end
