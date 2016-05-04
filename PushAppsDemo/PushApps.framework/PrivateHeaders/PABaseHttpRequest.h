//
//  BaseJsonRequest.h
//  pushapps
//
//  Created by Grisha on 2/15/16.
//  Copyright © 2016 pushapps.mobi. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^HttpRequestCompletion)(id object, NSError *error);

@interface PABaseHttpRequest : NSObject
@property BOOL completionInMainThread;

-(NSURLSessionTask*) GET:(NSString*)url additionalHeaders:(NSDictionary*)additionalHeaders completion:(HttpRequestCompletion)completion parseJson:(BOOL)parseJson;
-(NSURLSessionTask*) GET:(NSString*)url completion:(HttpRequestCompletion)completion;

-(NSURLSessionTask*) POST:(NSString*)url parseJson:(BOOL)parseJson additionalHeaders:(NSDictionary*)additionalHeaders httpBody:(NSData*)httpBody completion:(HttpRequestCompletion)completion;
-(NSURLSessionTask*) POST2:(NSString*)url parseJson:(BOOL)parseJson additionalHeaders:(NSDictionary*)additionalHeaders httpBody:(NSString*)httpBody completion:(HttpRequestCompletion)completion;


@end

