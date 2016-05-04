//
//  PACommon.h
//  pushapps
//
//  Created by Grisha on 2/16/16.
//  Copyright © 2016 pushapps.mobi. All rights reserved.
//

#ifndef PACommon_h
#define PACommon_h

@protocol PAPopupDelegate <NSObject>
@required
-(void)paPopupDismissed;
@end

typedef void (^registerDeviceCompletion)(NSError *error);
typedef void (^setTokenCompletion)(NSError *error);
typedef void (^getWidgetFeedCompletion)(NSArray *articles, NSError *error);

#endif /* PACommon_h */
