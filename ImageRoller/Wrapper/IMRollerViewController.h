//
//  IMRollerViewController.h
//  ImageRoller
//
//  Created by Durgesh Lal on 7/10/13.
//  Copyright (c) 2013 Durgesh Lal. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MBProgressHUD.h"
#import "SMPageControl.h"

extern NSString * const PageControlImageNormal;
extern NSString * const PageControlImageHighlighted;

@protocol IMRollerDelegate <NSObject>

@optional

-(void)imageRollerImageTapped:(id)sender;

@end

@interface IMRollerViewController : UIViewController<UIScrollViewDelegate,MBProgressHUDDelegate>{
    MBProgressHUD *HUD;
	long long expectedLength;
	long long currentLength;
}
@property (strong,nonatomic)id <IMRollerDelegate> delegate;

@property (nonatomic,assign) float animationDuration;
@property (nonatomic,strong) NSMutableArray *IMRollerImageArray;
@property (nonatomic,assign) float marginBetweenImageAndBackground;
@property (nonatomic,strong) UIColor *backgroundColor;

/*
 * Create a view of specified frame.
 * @param frame to specify frame of the view
 */

-(id)initWithFrame: (CGRect)frame;

@end
