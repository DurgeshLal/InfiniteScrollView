//
//  IMRollerViewController.m
//  ImageRoller
//
//  Created by Durgesh Lal on 7/10/13.
//  Copyright (c) 2013 Durgesh Lal. All rights reserved.
//

#import "IMRollerViewController.h"

@interface IMRollerViewController ()
{
    UIImageView *backgroundView;
    float xCoordinate;
    float yCoordinate;
    float width;
    float height;
    int index;
    int paginationIndex;
    BOOL isRightSwipe;
    BOOL isFirstRightSwipe;
    float progress;
}
@property (nonatomic,strong) UIScrollView *imageRollerScrollView;
@property (nonatomic,strong) SMPageControl *pageNiation;
@property (nonatomic,strong) NSTimer *timer;

@end



@implementation IMRollerViewController
@synthesize imageRollerScrollView;
@synthesize pageNiation;
@synthesize timer;


-(id)initWithFrame: (CGRect)frame {
    self = [super init];
    if (self) {
        xCoordinate = frame.origin.x;
        yCoordinate = frame.origin.y;
        width = frame.size.width;
        height = frame.size.height;
        self.IMRollerImageArray = [[NSMutableArray alloc]init];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    [self createRollerView];
    
    index = 1;
    progress = 0.0f;
    
    [self createHUD];
    [self startTimer];
    
    
	// Do any additional setup after loading the view, typically from a nib.
}


- (void)scrollViewDidScroll:(UIScrollView *)scrollView{
   
    progress = 0.0;
    [self createHUD];
}

#pragma mark Timer method
- (void) handleTimer: (NSTimer *)localTimer
{
    
    index = (int)(self.imageRollerScrollView.contentOffset.x)/width;// Get the current index value of object.
    index ++;
    
   
    if (index== [self.IMRollerImageArray count]+2) {
        index = 2;
    }
    
    if (self.imageRollerScrollView.contentOffset.x == 0) {
		// user is scrolling to the left from image 1 to image last
		// reposition offset to show image last that is on the right in the scroll view
		[self.imageRollerScrollView scrollRectToVisible:CGRectMake([self.IMRollerImageArray count]*width,yCoordinate,width,height) animated:NO];
	}
	else if (self.imageRollerScrollView.contentOffset.x == width*([self.IMRollerImageArray count]+1)) {
		// user is scrolling to the right from image last to image 1
		// reposition offset to show image 1 that is on the left in the scroll view
		[self.imageRollerScrollView scrollRectToVisible:CGRectMake(width,yCoordinate,width,height) animated:NO];
        [self.imageRollerScrollView setContentOffset:CGPointMake(width*2, 0) animated:YES];
        index = 2;
	}
    
    else{
        [self.imageRollerScrollView setContentOffset:CGPointMake(index*width, 0) animated:YES];
    }
    isRightSwipe = NO;
    [self updatePagination];
}

#pragma mark Gesture Methods
- (void) swipeLeft: (UISwipeGestureRecognizer *)gesture
{
    [self stopTimer:timer];
    index = (int)(self.imageRollerScrollView.contentOffset.x)/width;// Get the current index value of object.
    index ++;
    
    
    if (index== [self.IMRollerImageArray count]+2) {
        index = 2;
    }
    
    if (self.imageRollerScrollView.contentOffset.x == 0) {
		// user is scrolling to the left from image 1 to image last
		// reposition offset to show image last that is on the right in the scroll view
		[self.imageRollerScrollView scrollRectToVisible:CGRectMake([self.IMRollerImageArray count]*width,yCoordinate,width,height) animated:NO];
	}
	else if (self.imageRollerScrollView.contentOffset.x == width*([self.IMRollerImageArray count]+1)) {
		// user is scrolling to the right from image last to image 1
		// reposition offset to show image 1 that is on the left in the scroll view
		[self.imageRollerScrollView scrollRectToVisible:CGRectMake(width,yCoordinate,width,height) animated:NO];
        [self.imageRollerScrollView setContentOffset:CGPointMake(width*2, 0) animated:YES];
        index = 2;
	}
    
    else{
        [self.imageRollerScrollView setContentOffset:CGPointMake(index*width, 0) animated:YES];
       
    }
   
    
    [self startTimer];
    isRightSwipe = NO;
    [self updatePagination];
    
   
}

- (void) swipeRight: (UISwipeGestureRecognizer *)gesture
{
    [self stopTimer:timer];
    index = (int)(self.imageRollerScrollView.contentOffset.x)/width;// Get the current index value of object.
    index --;
   
    if (index== [self.IMRollerImageArray count]+2) {
        index = 2;
    }
    
    if (self.imageRollerScrollView.contentOffset.x == 0) {
		// user is scrolling to the left from image 1 to image last
		// reposition offset to show image last that is on the right in the scroll view
		[self.imageRollerScrollView scrollRectToVisible:CGRectMake([self.IMRollerImageArray count]*width,yCoordinate,width,height) animated:NO];
	}
	else if (self.imageRollerScrollView.contentOffset.x == width*([self.IMRollerImageArray count]+1)) {
		// user is scrolling to the right from image last to image 1
		// reposition offset to show image 1 that is on the left in the scroll view
		[self.imageRollerScrollView scrollRectToVisible:CGRectMake(width,yCoordinate,width,height) animated:NO];
        [self.imageRollerScrollView setContentOffset:CGPointMake(width*2, 0) animated:YES];
        index = 2;
	}
    
    else{
        [self.imageRollerScrollView setContentOffset:CGPointMake(index*width, 0) animated:YES];
    }
   
    [self startTimer];
    isRightSwipe = YES;
    [self updatePagination];
}

#pragma mark Upadet Pagination
-(void)updatePagination {
   
    if (isRightSwipe) {
        paginationIndex = paginationIndex-1;
    }
    else{
        paginationIndex = paginationIndex+1;
    }
    
    if (paginationIndex == [self.IMRollerImageArray count]) {
        paginationIndex = 0;// Pagination index set to 0 if its count become equal to number ob abject added.
    }
    else if (paginationIndex == -1){
        paginationIndex = (int)[self.IMRollerImageArray count]-1;
    }
    self.pageNiation.currentPage = paginationIndex;


}
-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    
}
- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark Creat View and HUD
-(void)createHUD{
    if (!HUD) {
        
        UIView *hudView = [[UIView alloc]initWithFrame:CGRectMake(xCoordinate, yCoordinate, width, height)];
        HUD = [[MBProgressHUD alloc]initWithView:hudView];
        [self.view addSubview:HUD];
        // Set determinate mode
        HUD.mode = MBProgressHUDModeDeterminate;
        HUD.delegate = self;
        HUD.labelText = nil;
        // myProgressTask uses the HUD instance to update progress
        [HUD showWhileExecuting:@selector(myProgressTask) onTarget:self withObject:nil animated:YES];
    }
    
}


- (void)myProgressTask {
	// This just increases the progress indicator in a loop
    
	while (progress < 1.0f) {
		progress += 0.01f;
		HUD.progress = progress;
		usleep((self.animationDuration-1)*10000);
	}
    [MBProgressHUD hideAllHUDsForView:self.view animated:YES];
    HUD = nil;
}


#pragma mark Create ScrollView
-(void)createRollerView{
    
    //***************************************** Creating Background View*******************************************
    backgroundView = [[UIImageView alloc]initWithFrame:CGRectMake(xCoordinate-self.marginBetweenImageAndBackground, yCoordinate-self.marginBetweenImageAndBackground, width+ 2*self.marginBetweenImageAndBackground, height+(2*self.marginBetweenImageAndBackground))];
    [backgroundView setBackgroundColor:self.backgroundColor];
    [self.view addSubview:backgroundView];
    
    //***************************** Creating ScrollView *************************************************************/
    self.imageRollerScrollView = [[UIScrollView alloc]initWithFrame:CGRectMake(xCoordinate, yCoordinate, width, height)];
    [self.imageRollerScrollView setScrollEnabled:NO];
    [self.imageRollerScrollView setPagingEnabled:YES];
    [self.imageRollerScrollView setBounces:NO];
    [self.imageRollerScrollView setDelegate:self];
    self.imageRollerScrollView.showsHorizontalScrollIndicator = NO;
    self.imageRollerScrollView.showsVerticalScrollIndicator = NO;
    [self.view addSubview:self.imageRollerScrollView];
    
    UISwipeGestureRecognizer *gesture;
    gesture = [[UISwipeGestureRecognizer alloc]initWithTarget:self action:@selector(swipeLeft:)];
    [gesture setDirection:UISwipeGestureRecognizerDirectionLeft];
    [self.imageRollerScrollView addGestureRecognizer:gesture];
    
    gesture = [[UISwipeGestureRecognizer alloc]initWithTarget:self action:@selector(swipeRight:)];
    [gesture setDirection:UISwipeGestureRecognizerDirectionRight];
    [self.imageRollerScrollView addGestureRecognizer:gesture];
    
    //***************************** Creating Pagination *******************************************/
    paginationIndex = 0; // index used to change Pagination current page
    self.pageNiation = [[SMPageControl alloc]initWithFrame:CGRectMake(xCoordinate, height+25,width,30)];
    self.pageNiation.numberOfPages=[self.IMRollerImageArray count];
    [self.pageNiation setCurrentPage:0];
    [self.pageNiation setUserInteractionEnabled:NO];
    [self.pageNiation setActivePageColor:[UIColor redColor]];
	[self.pageNiation setInactivePageColor:[UIColor blueColor]];
    [self.pageNiation setBackgroundColor:[UIColor clearColor]];
    [self.view addSubview:self.pageNiation];
    
    
    // add the last image (last) into the first position
	[self addImageWithName:[self.IMRollerImageArray lastObject] atPosition:0];
	
	// add all of the images to the scroll view
	for (int i = 1; i < [self.IMRollerImageArray count]+1; i++) {
		[self addImageWithName:[self.IMRollerImageArray objectAtIndex:i-1] atPosition:i];
	}
	
	// add the first image (image1) into the last position
	[self addImageWithName:[self.IMRollerImageArray objectAtIndex:0] atPosition:[self.IMRollerImageArray count]+1];
	
	self.imageRollerScrollView.contentSize = CGSizeMake(([self.IMRollerImageArray count]+2)* width, height);
	[self.imageRollerScrollView scrollRectToVisible:CGRectMake(width,yCoordinate,width,height) animated:NO];
    

}

# pragma mark In a loop Create scrollView and Add images.

- (void)addImageWithName:(NSString*)imageString atPosition:(NSUInteger)position {
	// add image to scroll view
	UIImage *image = [UIImage imageNamed:imageString];
	UIButton *imageButton = [[UIButton alloc] init];
    [imageButton setBackgroundImage:image forState:UIControlStateNormal];
	imageButton.frame = CGRectMake(position*width, 0, width, height);
    [imageButton setTag:position];
    [imageButton addTarget:self action:@selector(imageButtontapped:) forControlEvents:UIControlEventTouchUpInside];
	[self.imageRollerScrollView addSubview:imageButton];
}


#pragma mark Timer call
-(void)startTimer{
    self.timer = [NSTimer scheduledTimerWithTimeInterval:_animationDuration target: self selector: @selector(handleTimer:)  userInfo:nil  repeats: YES];
}

#pragma mark To stop Timer
- (void)stopTimer:(id)sender
{
    if (self.timer != nil)
    {
        [self.timer invalidate];
        self.timer = nil;
    }
}



# pragma mark Delegate method
-(void)imageButtontapped:(id)sender{
    
    NSLog(@"Tapped");
    
    if ([self.delegate respondsToSelector:@selector(imageRollerImageTapped:)]) {
        [self.delegate imageRollerImageTapped:sender];
    }
      
}

@end
