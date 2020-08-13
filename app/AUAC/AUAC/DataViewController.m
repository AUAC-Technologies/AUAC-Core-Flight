//
//  DataViewController.m
//  AUAC
//
//  Created by Nyameaama Gambrah on 8/13/20.
//  Copyright © 2020 Nyameaama Gambrah. All rights reserved.
//

#import "DataViewController.h"

@interface DataViewController ()

@end

@implementation DataViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}


- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    self.dataLabel.text = [self.dataObject description];
}


@end
