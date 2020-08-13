//
//  ModelController.h
//  AUAC
//
//  Created by Nyameaama Gambrah on 8/13/20.
//  Copyright © 2020 Nyameaama Gambrah. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DataViewController;

@interface ModelController : NSObject <UIPageViewControllerDataSource>

- (DataViewController *)viewControllerAtIndex:(NSUInteger)index storyboard:(UIStoryboard *)storyboard;
- (NSUInteger)indexOfViewController:(DataViewController *)viewController;

@end

