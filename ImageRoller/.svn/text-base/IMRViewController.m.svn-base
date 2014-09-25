//
//  IMRViewController.m
//  ImageRoller
//
//  Created by Durgesh Lal on 10/24/13.
//  Copyright (c) 2013 Sapient Nitro. All rights reserved.
//

#import "IMRViewController.h"

@interface IMRViewController ()

@end

@implementation IMRViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    CGRect frame = CGRectMake(20, 20, 280, 300);
    IMRollerViewController *IM = [[IMRollerViewController alloc]initWithFrame:frame];
    [IM setDelegate:self];
    IM.animationDuration = 3 ;
    IM.marginBetweenImageAndBackground = 10;
    IM.backgroundColor = [UIColor greenColor];
    IM.IMRollerImageArray=[[NSMutableArray alloc]initWithObjects:
                           @"image1.jpg",
                           @"image2.jpg",
                           @"image3.jpg",
                           @"image4.jpg",
                           @"image1.jpg",
                           @"image2.jpg",
                           @"image3.jpg",
                           @"image4.jpg",
                           @"image1.jpg",
                           @"image2.jpg",
                           @"image3.jpg",
                           @"image4.jpg",
                           nil];
    [self.view addSubview:IM.view];
    
	// Do any additional setup after loading the view, typically from a nib.
}
// IMRoller Delegate
-(void)imageRollerImageTapped:(id)sender{
    
    UIButton *tempButton = (UIButton *)sender;
    NSLog(@"Tag Value is %ld",(long)tempButton.tag);
    if (tempButton.tag == 1000) {
        // To Do.
    }
    else if (tempButton.tag == 2000){
        // To Do.
    }
    else{
        // To Do.
    }
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
