//
//  TodayViewController.m
//  Recommendations
//
//  Created by Asaf Ron on 6/23/15.
//  Copyright (c) 2015 Groboot. All rights reserved.
//

#import "TodayViewController.h"
#import <NotificationCenter/NotificationCenter.h>
#import <AdSupport/AdSupport.h>
#import <PushApps/PushApps.h>

@interface TodayViewController () <NCWidgetProviding, UICollectionViewDelegate, UICollectionViewDataSource>

@property (weak, nonatomic) IBOutlet UICollectionView *collectionView;
@property (nonatomic, strong) NSArray *currentRecommendations;

@end

@implementation TodayViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // Register to PushApps
    [PushApps registerDeviceWithSdkKey:@"d7cca984-5eba-403d-b830-b5ae21769da2"];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    self.preferredContentSize = CGSizeMake(320, 310);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

#pragma mark - NCWidgetProviding

- (void)widgetPerformUpdateWithCompletionHandler:(void (^)(NCUpdateResult))completionHandler
{
    [PushApps getWidgetFeedForParams:@{@"campaign_id" : @"42CXIgcu"} withCompletionBlock:^(id object, NSError *error) {
        
        self.currentRecommendations = [NSArray arrayWithArray:object];
        
        if (self.currentRecommendations.count == 0) {
            self.preferredContentSize = CGSizeMake(320, 0);
        } else {
            self.preferredContentSize = CGSizeMake(320, 310);
        }
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self.collectionView reloadData];
        });
        
        completionHandler(NCUpdateResultNewData);
        
    }];
}

#pragma mark - Widget view

- (UIEdgeInsets)widgetMarginInsetsForProposedMarginInsets:(UIEdgeInsets)defaultMarginInsets
{
    return UIEdgeInsetsMake(5, 5, 5, 5);
}

#pragma mark - UICollectionView

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView
{
    if ([self.currentRecommendations count] > 3) {
        return 1;
    }
    return 0;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section
{
    if ([self.currentRecommendations count] > 3) {
        return 4;
    }
    return 0;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath
{
    UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:@"cell" forIndexPath:indexPath];
    
    NSDictionary *dictionary = [self.currentRecommendations objectAtIndex:indexPath.row];
    
    UIImageView *imageView = (UIImageView *)[cell.contentView viewWithTag:990];
    imageView.image = nil;
    NSString *urlString = [dictionary objectForKey:@"thumb_url"];
    NSURL *url = [NSURL URLWithString:urlString];
    dispatch_queue_t downloadQueue = dispatch_queue_create("mobi.pushapps.demo.PushAppsDemo.images", NULL);
    dispatch_async(downloadQueue, ^{
        NSError *urlError = nil;
        NSData *imageData = [NSData dataWithContentsOfURL:url options:0 error:&urlError];
        dispatch_async(dispatch_get_main_queue(), ^{
            imageView.image = [UIImage imageWithData:imageData];
        });
    });
    
    UILabel *label = (UILabel *)[cell.contentView viewWithTag:991];
    label.text = [dictionary objectForKey:@"title"];
    [label sizeToFit];
    
    return cell;
}

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath
{
    [collectionView deselectItemAtIndexPath:indexPath animated:YES];
    
    NSDictionary *dictionary = [self.currentRecommendations objectAtIndex:indexPath.row];
    NSString *urlString = [dictionary objectForKey:@"url"];
    NSURL *url = [NSURL URLWithString:urlString];
    [self.extensionContext openURL:url completionHandler:nil];
}

@end
