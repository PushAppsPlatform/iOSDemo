//
//  PAPopup.h
//  exampleApp
//
//  Created by Grisha on 2/18/16.
//  Copyright © 2016 pushapps.mobi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PACommon.h"

enum PAPopupAnimation_t : NSUInteger {
    PAAnimationFromTop = 0,
    PAAnimationFromBottom,
    PAAnimationFromLeft,
    PAAnimationFromRight,
    PAAnimationCustom
};

typedef enum PAPopupAnimation_t PAPopupAnimation;

@interface PAPopup : UIView <UIWebViewDelegate>
@property PAPopupAnimation popupAnimationType;
@property NSString* URL;
@property NSDictionary* parameters;
@property id<PAPopupDelegate> delegate;

+(PAPopup*)showPopupWithSize:(CGSize)size inView:(UIView*)superView andAnimation:(PAPopupAnimation)popupAnimation
                      andURL:(NSString*)url andParameters:(NSDictionary *)parameters;
-(void)dismiss;

@end
