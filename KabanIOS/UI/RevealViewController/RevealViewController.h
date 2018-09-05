//
//  RevealViewController.h
//  RevealViewController
//

#import <UIKit/UIKit.h>

@class RevealViewController;
@protocol RevealViewControllerDelegate;

#pragma mark - UIViewController(RevealViewController) Category

/**
 *  A category of UIViewController to let childViewControllers easily access their parent RevealViewController.
 */
@interface UIViewController(RevealViewController)

- (RevealViewController *)revealViewController;

@end

#pragma mark - StoryBoard support Classes

/**
 *  String identifiers to be applied to segues on a storyboard.
 */
extern NSString* const SegueLeftIdentifier;   // this is @"rv_left"
extern NSString* const SegueMainIdentifier;   // this is @"rv_main"
extern NSString* const SegueRightIdentifier;  // this is @"rv_right"

/**
 *  Use this to segue to the initial state. View controller segues are "rv_left", "rv_main" and "rv_right".
 */
@interface RevealViewControllerSegueSetController : UIStoryboardSegue

@end

/**
 *  Use this to push a view controller from a storyboard.
 */
@interface RevealViewControllerSeguePushController : UIStoryboardSegue

@end

/**
 *  Constants for animating when a main view is pushed
 */
typedef NS_ENUM(NSInteger, RevealToggleAnimationType) {
    /**
     *  No anmmation
     */
    RevealToggleAnimationTypeNone,
    /**
     *  A transition that dissolves from one view to the next.
     */
    RevealToggleAnimationTypeCrossDissolve,
    /**
     *  A transition that the main view push the left/right view until it is hidden.
     */
    RevealToggleAnimationTypePushSideView,
    /**
     *  A transition that the side view move a little to right or left by the value of leftRevealOverdraw or rightRevealOverdraw before the main view push the left/right view until it is hidden.
     */
    RevealToggleAnimationTypeSpring,
    /**
     *  A transition provided by the delegate methods.
     *
     *  @see    -revealController:willAddViewController:forOperation:animated:
     *  @see    -revealController:animationBlockForOperation:fromViewController:toViewController:
     *  @see    -revealController:completionBlockForOperation:fromViewController:toViewController:
     *  @see    -revealController:blockForOperation:fromViewController:toViewController:finalBlock:
     *
     *  @warning    If -revealController:blockForOperation:fromViewController:toViewController:finalBlock: is implemented, the others methods are ignored.
     */
    RevealToggleAnimationTypeCustom
};

/**
 *  Constants for blur effect style to apply to left/right views (since iOS 8).
 */
typedef NS_ENUM(NSInteger, RevealBlurEffectStyle) {
    /**
     *  None.
     */
    RevealBlurEffectStyleNone = -1,
    /**
     *  The area of the view is lighter in hue than the underlying view.
     */
    RevealBlurEffectStyleExtraLight = UIBlurEffectStyleExtraLight,
    /**
     *  The area of the view is the same approximate hue of the underlying view.
     */
    RevealBlurEffectStyleLight = UIBlurEffectStyleLight,
    /**
     *  The area of the view is darker in hue than the underlying view.
     */
    RevealBlurEffectStyleDark = UIBlurEffectStyleDark
};

#pragma mark - RevealViewController

@interface RevealViewController : UIViewController

/**
 *  Instantiate a RevealViewController class programmatically
 *
 *  @param leftViewController  A subclass of UIViewController (optional).
 *  @param mainViewController  A subclass of UIViewController (required).
 *  @param rightViewController A subclass of UIViewController (optional).
 *
 *  @return RevealViewController instance.
 */
- (id)initWithLeftViewController:(UIViewController *)leftViewController mainViewController:(UIViewController *)mainViewController rightViewController:(UIViewController *)rightViewController;

/**
 *  Defines the radius of the main view's shadow, default is 2.5f.
 */
@property (nonatomic) CGFloat           mainViewShadowRadius;

/**
 *  Defines the main view's shadow offset, default is {0.0f,2.5f}.
 */
@property (nonatomic) CGSize            mainViewShadowOffset;

/**
 *  Defines the main view's shadow opacity, default is 1.0f.
 */
@property (nonatomic) CGFloat           mainViewShadowOpacity;

/**
 *  Defines the main view's shadow color, default is blackColor
 */
@property (nonatomic) UIColor           *mainViewShadowColor;

/**
 *  If YES (default is NO) the left view controller will be ofsseted vertically by the height of a navigation bar plus the height of status bar.
 */
@property (nonatomic) BOOL              leftPresentViewHierarchically;

/**
 *  If NO (default is YES) the left view controller will be presented below the main view controller.
 */
@property (nonatomic) BOOL              leftPresentViewOnTop;

/**
 *  Defines how much displacement is applied to the left view when animating or dragging the main view, default is 40.0f.
 */
@property (nonatomic) CGFloat           leftViewRevealDisplacement;

/**
 *  Defines the width of the left view when it is shown, default is 260.0f.
 */
@property (nonatomic) CGFloat           leftViewRevealWidth;

/**
 *  Defines the width of the left view when it is shown.
 *
 *  @param leftViewRevealWidth The left view width.
 *  @param animated            Specify YES to animate the new width or NO if you do not want it to be animated.
 */
- (void)setLeftViewRevealWidth:(CGFloat)leftViewRevealWidth animated:(BOOL)animated;

/**
 *  Duration for the left reveal/push animation, default is 0.5f.
 *
 *  @see    -animateWithDuration:delay:usingSpringWithDamping:initialSpringVelocity:options:animations:completion:
 */
@property (nonatomic) NSTimeInterval    leftToggleAnimationDuration;

/**
 *  The damping ratio for the spring animation, default is 0.8f.
 *
 *  @see    -animateWithDuration:delay:usingSpringWithDamping:initialSpringVelocity:options:animations:completion:
 */
@property (nonatomic) CGFloat           leftToggleSpringDampingRatio;

/**
 *  The initial spring velocity, default is 0.5f.
 *
 *  @see    -animateWithDuration:delay:usingSpringWithDamping:initialSpringVelocity:options:animations:completion:
 */
@property (nonatomic) CGFloat           leftToggleSpringVelocity;

/**
 *  Defines the radius of the left view's shadow, default is 2.5f.
 */
@property (nonatomic) CGFloat           leftViewShadowRadius;

/**
 *  Defines the left view's shadow offset, default is {0.0f, 2.5f}.
 */
@property (nonatomic) CGSize            leftViewShadowOffset;

/**
 *  Defines the left view's shadow opacity, default is 1.0f.
 */
@property (nonatomic) CGFloat           leftViewShadowOpacity;

/**
 *  Defines the left view's shadow color, default is blackColor
 */
@property (nonatomic) UIColor           *leftViewShadowColor;

/**
 *  Defines the left view's blur effect style, default is RevealBlurEffectStyleNone.
 */

@property (nonatomic) RevealBlurEffectStyle leftViewBlurEffectStyle;

/**
 * If YES (default is NO) the left view controller will be ofsseted vertically by the height of a navigation bar plus the height of status bar.
 */
@property (nonatomic) BOOL              rightPresentViewHierarchically;

/**
 *  If NO (default is YES) the right view controller will be presented below the main view controller.
 */
@property (nonatomic) BOOL              rightPresentViewOnTop;

/**
 *  Defines how much displacement is applied to the right view when animating or dragging the main view, default is 40.0f.
 */
@property (nonatomic) CGFloat           rightViewRevealDisplacement;

/**
 *  Defines the width of the right view when it is shown, default is 160.0f.
 */
@property (nonatomic) CGFloat           rightViewRevealWidth;

/**
 *  Defines the width of the right view.
 *
 *  @param rightViewRevealWidth The right view width.
 *  @param animated             Specify YES to animate the new width or NO if you do not want it to be animated.
 */
- (void)setRightViewRevealWidth:(CGFloat)rightViewRevealWidth animated:(BOOL)animated;

/**
 *  Duration for the right reveal/push animation, default is 0.5f.
 *
 *  @see    -animateWithDuration:delay:usingSpringWithDamping:initialSpringVelocity:options:animations:completion:
 */
@property (nonatomic) NSTimeInterval    rightToggleAnimationDuration;

/**
 *  The damping ratio for the spring animation, default is 0.8f.
 *
 *  @see    -animateWithDuration:delay:usingSpringWithDamping:initialSpringVelocity:options:animations:completion:
 */
@property (nonatomic) CGFloat           rightToggleSpringDampingRatio;

/**
 *  The initial spring velocity, default is 0.5f.
 *
 *  @see    -animateWithDuration:delay:usingSpringWithDamping:initialSpringVelocity:options:animations:completion:
 */
@property (nonatomic) CGFloat           rightToggleSpringVelocity;

/**
 *  Defines the radius of the lrighteft view's shadow, default is 2.5f.
 */
@property (nonatomic) CGFloat           rightViewShadowRadius;

/**
 *  Defines the right view's shadow offset, default is {0.0f, 2.5f}.
 */
@property (nonatomic) CGSize            rightViewShadowOffset;

/**
 *  Defines the right view's shadow opacity, default is 1.0f.
 */
@property (nonatomic) CGFloat           rightViewShadowOpacity;

/**
 *  Defines the right view's shadow color, default is blackColor
 */
@property (nonatomic) UIColor           *rightViewShadowColor;

/**
 *  Defines the right view's blur effect style, default is RevealBlurEffectStyleNone.
 */

@property (nonatomic) RevealBlurEffectStyle rightViewBlurEffectStyle;

/**
 *  Animation type, default is RevealToggleAnimationTypeNone.
 */
@property (nonatomic) RevealToggleAnimationType toggleAnimationType;

/**
 *  Defines how much of an overdraw can occur when pushing further than leftViewRevealWidth, default is 60.0f.
 */
@property (nonatomic) CGFloat           leftViewRevealOverdraw;

/**
 *  Defines how much of an overdraw can occur when pushing further than rightViewRevealWidth, default is 60.0f.
 */
@property (nonatomic) CGFloat           rightViewRevealOverdraw;

/**
 *  Duration for animated replacement of view controllers, default is 0.25f.
 */
@property (nonatomic) NSTimeInterval    replaceViewAnimationDuration;

/**
 *  Velocity required for the controller to toggle its state based on a swipe movement, default is 250.0f.
 */
@property (nonatomic) CGFloat           swipeVelocity;

/**
 *  YES if left view is completely open (read only).
 */
@property (nonatomic, readonly) BOOL    isLeftViewOpen;

/**
 *  YES if right view is completely open (read only).
 */
@property (nonatomic, readonly) BOOL    isRightViewOpen;

/**
 *  YES if left view is panning (read only).
 */
@property (nonatomic, readonly) BOOL    isLeftViewDragging;

/**
 *  YES if right view is panning (read only).
 */
@property (nonatomic, readonly) BOOL    isRightViewDragging;

#if TARGET_OS_TV

/**
 *  An optional invisible focusable button for revealing left view, default is nil, call [self tvOSLeftRevealButton] once to add it to the reveal view controller's view.
 */
@property (strong, nonatomic) UIButton  *tvOSLeftRevealButton;

/**
 *  An optional invisible focusable button for revealing right view, default is nil, call [self tvOSRightRevealButton] once to add it to the reveal view controller's view.
 */
@property (strong, nonatomic) UIButton  *tvOSRightRevealButton;

/**
 *  An optional swipe gesture recognizer for hidding left view, default is nil, call [self tvOSRightSwipeGestureRecognizer] once to add it to the reveal view controller's view.
 */
@property (strong, nonatomic) UISwipeGestureRecognizer  *tvOSRightSwipeGestureRecognizer;

/**
 *  An optional swipe gesture recognizer for hidding right view, default is nil, call [self tvOSLeftSwipeGestureRecognizer] once to add it to the reveal view controller's view.
 */
@property (strong, nonatomic) UISwipeGestureRecognizer  *tvOSLeftSwipeGestureRecognizer;

/**
 *  The preferred focused view on the main view.
 */
@property (strong, nonatomic) UIView    *tvOSMainPreferredFocusedView;

/**
 *  The preferred focused view on the left view.
 */
@property (strong, nonatomic) UIView    *tvOSLeftPreferredFocusedView;

/**
 *  The preferred focused view on the right view.
 */
@property (strong, nonatomic) UIView    *tvOSRightPreferredFocusedView;

/**
 *  If isPressTypeMenuAllowed is set to YES (default is NO), show left view when Apple TV Menu button is pressed, back to Apple TV home screen if left menu is open.
 */
@property (assign) BOOL                 isPressTypeMenuAllowed;

/**
 *  If isPressTypePlayPauseAllowed is set to YES (default is NO), hide left view if opened, show/hide right view when Apple TV PlayPause button is pressed.
 */
@property (assign) BOOL                 isPressTypePlayPauseAllowed;

#endif

/**
 *  The default tap gesture recognizer added to the main view. Default behavior will hide the left or right view.
 */
@property (strong, nonatomic) UITapGestureRecognizer *tapGestureRecognizer;

/**
 *  The default pan gesture recognizer added to the main view. Default behavior will drag the left or right view
 */
@property (strong, nonatomic) UIPanGestureRecognizer *panGestureRecognizer;

/**
 *  The default border width allowing pan gesture from left. If > 0.0, this is the acceptable starting width for the gesture.
 */
@property (nonatomic) CGFloat panFromLeftBorderWidth;

/**
 *  The default border width allowing pan gesture from right. If > 0.0, this is the acceptable starting width for the gesture.
 */
@property (nonatomic) CGFloat panFromRightBorderWidth;

/**
 *  Optional left view controller, can be nil if not used.
 */
@property (nonatomic) UIViewController *leftViewController;

/**
 *  Replace the left view controller.
 *
 *  @param leftViewController A subclass of UIViewController.
 *  @param animated           Specify YES to animate the replacement or NO if you do not want the replacement to be animated.
 *
 *  @see    -setRightViewController:animated:
 */
- (void)setLeftViewController:(UIViewController *)leftViewController animated:(BOOL)animated;

/**
 *  Main view controller, cannot be nil.
 */
@property (nonatomic) UIViewController *mainViewController;

/**
 *  Replace the main view controller.
 *
 *  @param mainViewController A subclass of UIViewController.
 *  @param animated           Specify YES to animate the replacement or NO if you do not want the replacement to be animated.
 */
- (void)setMainViewController:(UIViewController *)mainViewController animated:(BOOL)animated;

/**
 *  Optional right view controller, can be nil if not used.
 */
@property (nonatomic) UIViewController *rightViewController;

/**
 *  Replace the right view controller.
 *
 *  @param rightViewController A subclass of UIViewController.
 *  @param animated            Specify YES to animate the replacement or NO if you do not want the replacement to be animated.
 *
 *  @see    -setLeftViewController:animated:
 */
- (void)setRightViewController:(UIViewController *)rightViewController animated:(BOOL)animated;

/**
 *  Sets the mainViewController pushing it and hide left view controller.
 *
 *  @param mainViewController A subclass of UIViewController.
 *  @param animated           Specify YES to animate the replacement or NO if you do not want the replacement to be animated.
 *
 */
- (void)pushMainViewController:(UIViewController *)mainViewController animated:(BOOL)animated;

/**
 *  Reveal left view or hide it if shown. Hide the right view if it is open and show the left view.
 */
- (IBAction)revealLeftView;

/**
 *  Reveal right view or hide it if shown.  Hide the left view if it is open and show the right view.
 */
- (IBAction)revealRightView;

/**
 *  Hide left view.
 *
 *  @param animated Specify YES to animate the replacement or NO if you do not want the replacement to be animated.
 */
- (void)hideLeftViewAnimated:(BOOL)animated;

/**
 *  Hide right view.
 *
 *  @param animated Specify YES to animate the replacement or NO if you do not want the replacement to be animated.
 */
- (void)hideRightViewAnimated:(BOOL)animated;

/**
 *  The delegate of the RevealViewController object.
 */
@property (nonatomic,weak) id <RevealViewControllerDelegate> delegate;

@end

#pragma mark - RevealViewControllerDelegate Protocol

/**
 *  Constants for current operation.
 */
typedef NS_ENUM(NSInteger, RevealControllerOperation) {
    /**
     *  None.
     */
    RevealControllerOperationNone,
    /**
     *  Replacement of left view controller.
     */
    RevealControllerOperationReplaceLeftController,
    /**
     *  Replacement of main view controller.
     */
    RevealControllerOperationReplaceMainController,
    /**
     *  Replacement of right view controller.
     */
    RevealControllerOperationReplaceRightController,
    /**
     *  Pushing the main view controller from left view controller.
     */
    RevealControllerOperationPushMainControllerFromLeft,
    /**
     *  Pushing the main view controller from right view controller.
     */
    RevealControllerOperationPushMainControllerFromRight
};

/**
 *  Direction constants when panning.
 */
typedef NS_ENUM(NSInteger, RevealControllerPanDirection) {
    /**
     *  Panning to left. Should open right view controller.
     */
    RevealControllerPanDirectionLeft,
    /**
     *  Panning to right. Should open left view controller.
     */
    RevealControllerPanDirectionRight
};

/**
 *  Use a reveal view controller delegate (a custom object that implements this protocol) to modify behavior when a view controller is pushed or replaced. All methods are optionals.
 */
@protocol RevealViewControllerDelegate<NSObject>

@optional

/**
 *  Ask the delegate if the left view should be shown. Not called while a pan gesture.
 *
 *  @param revealController The reveal view controller object.
 *  @param controller       The left view controller object.
 *
 *  @return YES if the left view controller should be shown, NO otherwise.
 *
 *  @see    -revealControllerPanGestureShouldBegin:direction:
 */
- (BOOL)revealController:(RevealViewController *)revealController shouldShowLeftViewController:(UIViewController *)controller;

/**
 *  Called just before the left view controller is presented.
 *
 *  @param revealController The reveal view controller object.
 *  @param controller       The left view controller object.
 */
- (void)revealController:(RevealViewController *)revealController willShowLeftViewController:(UIViewController *)controller;

/**
 *  Called just after the left view controller is presented.
 *
 *  @param revealController The reveal view controller object.
 *  @param controller       The left view controller object.
 */
- (void)revealController:(RevealViewController *)revealController didShowLeftViewController:(UIViewController *)controller;

/**
 *  Called just before the left view controller is hidden.
 *
 *  @param revealController The reveal view controller object.
 *  @param controller       The left view controller object.
 */
- (void)revealController:(RevealViewController *)revealController willHideLeftViewController:(UIViewController *)controller;

/**
 *  Called just after the left view controller is hidden.
 *
 *  @param revealController The reveal view controller object.
 *  @param controller       The left view controller object.
 */
- (void)revealController:(RevealViewController *)revealController didHideLeftViewController:(UIViewController *)controller;

/**
 *  Ask the delegate if the right view should be shown. Not called while a pan gesture.
 *
 *  @param revealController The reveal view controller object.
 *  @param controller       The right view controller object.
 *
 *  @return YES if the right view controller should be shown, NO otherwise.
 *
 *  @see    -revealControllerPanGestureShouldBegin:direction:
 */
- (BOOL)revealController:(RevealViewController *)revealController shouldShowRightViewController:(UIViewController *)controller;

/**
 *  Called just before the right view controller is presented.
 *
 *  @param revealController The reveal view controller object.
 *  @param controller       The right view controller object.
 */
- (void)revealController:(RevealViewController *)revealController willShowRightViewController:(UIViewController *)controller;

/**
 *  Called just after the right view controller is presented.
 *
 *  @param revealController The reveal view controller object.
 *  @param controller       The right view controller object.
 */
- (void)revealController:(RevealViewController *)revealController didShowRightViewController:(UIViewController *)controller;

/**
 *  Called just before the right view controller is hidden.
 *
 *  @param revealController The reveal view controller object.
 *  @param controller       The right view controller object.
 */
- (void)revealController:(RevealViewController *)revealController willHideRightViewController:(UIViewController *)controller;

/**
 *  Called just after the right view controller is hidden.
 *
 *  @param revealController The reveal view controller object.
 *  @param controller       The right view controller object.
 */
- (void)revealController:(RevealViewController *)revealController didHideRightViewController:(UIViewController *)controller;

/**
 *  Implement this to return NO when you want the pan gesture recognizer to be ignored.
 *
 *  @param revealController The reveal view controller object.
 *  @param direction        The panning direction.
 *
 *  @return NO if you want the pan gesture recognizer to be ignored, YES otherwise.
 *
 *  @see    -panGestureRecognizer
 */
- (BOOL)revealControllerPanGestureShouldBegin:(RevealViewController *)revealController direction:(RevealControllerPanDirection)direction;

/**
 *  Implement this to return NO when you want the tap gesture recognizer to be ignored.
 *
 *  @param revealController The reveal view controller object.
 *
 *  @return NO if you want the tap gesture recognizer to be ignored, YES otherwise.
 *
 *  @see    -tapGestureRecognizer
 */
- (BOOL)revealControllerTapGestureShouldBegin:(RevealViewController *)revealController;

/**
 *  Implement this to return YES if you want other gesture recognizer to share touch events with the pan gesture.
 *
 *  @param revealController       The reveal view controller object.
 *  @param otherGestureRecognizer The other gesture recognizer.
 *
 *  @return YES if you want other gesture recognizer to share touch events with the pan gesture.
 *
 *  @see    -panGestureRecognizer
 */
- (BOOL)revealController:(RevealViewController *)revealController
panGestureRecognizerShouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer;

/**
 *  Implement this to return YES if you want other gesture recognizer to share touch events with the tap gesture.
 *
 *  @param revealController       The reveal view controller object.
 *  @param otherGestureRecognizer The other gesture recognizer.
 *
 *  @return YES if you want other gesture recognizer to share touch events with the tap gesture.
 *
 *  @see    -tapGestureRecognizer
 */
- (BOOL)revealController:(RevealViewController *)revealController
tapGestureRecognizerShouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer *)otherGestureRecognizer;

/**
 *  Called when the gestureRecognizer began.
 *
 *  @param revealController The reveal view controller object.
 *  @param direction        The panning direction.
 *
 *  @see    -panGestureRecognizer
 */
- (void)revealControllerPanGestureBegan:(RevealViewController *)revealController direction:(RevealControllerPanDirection)direction;

/**
 *  Called when the gestureRecognizer moved.
 *
 *  @param revealController The reveal view controller object.
 *  @param direction        The panning direction.
 *
 *  @see    -panGestureRecognizer
 */
- (void)revealControllerPanGestureMoved:(RevealViewController *)revealController direction:(RevealControllerPanDirection)direction;

/**
 *  Called when the gestureRecognizer ended.
 *
 *  @param revealController The reveal view controller object.
 *  @param direction        The panning direction.
 *
 *  @see    -panGestureRecognizer
 */
- (void)revealControllerPanGestureEnded:(RevealViewController *)revealController direction:(RevealControllerPanDirection)direction;

/**
 *  Called just before child controller replacement (left, main or right).
 *
 *  @param revealController The reveal view controller object.
 *  @param viewController   The child view controller.
 *  @param operation        The current operation.
 *  @param animated         YES if you want the replacement to be animated, NO otherwise.
 *
 *  @see    -revealController:didAddViewController:forOperation:animated:
 */
- (void)revealController:(RevealViewController *)revealController willAddViewController:(UIViewController *)viewController forOperation:(RevealControllerOperation)operation animated:(BOOL)animated;

/**
 *  Called just after child controller replacement (left, main or right).
 *
 *  @param revealController The reveal view controller object.
 *  @param viewController   The child view controller.
 *  @param operation        The current operation.
 *  @param animated         YES if you want the replacement to be animated, NO otherwise.
 *
 *  @see    -revealController:willAddViewController:forOperation:animated:
 */
- (void)revealController:(RevealViewController *)revealController didAddViewController:(UIViewController *)viewController forOperation:(RevealControllerOperation)operation animated:(BOOL)animated;

/**
 *  Ask for animation block while pushing main view controller.
 *
 *  @param revealController   The reveal view controller object.
 *  @param operation          The current operation (push from left or push from right).
 *  @param fromViewController The main view controller.
 *  @param toViewController   The new main view controller. When called the toViewController's view is behind the fromViewController's view.
 *
 *  @return A block to be inserted in the view animation.
 *
 *  @see    -revealController:blockForOperation:fromViewController:toViewController:finalBlock:
 */
- (void (^)(void))revealController:(RevealViewController *)revealController animationBlockForOperation:(RevealControllerOperation)operation fromViewController:(UIViewController *)fromViewController toViewController:(UIViewController *)toViewController;

/**
 *  Ask for completion block while pushing main view controller.
 *
 *  @param revealController   The reveal view controller object.
 *  @param operation          The current operation (push from left or push from right).
 *  @param fromViewController The main view controller.
 *  @param toViewController   The new main view controller. When called the toViewController's view is behind the fromViewController's view.
 *
 *  @return A block to be inserted in the view animation completion.
 *
 *  @see    -revealController:blockForOperation:fromViewController:toViewController:finalBlock:
 */
- (void (^)(void))revealController:(RevealViewController *)revealController completionBlockForOperation:(RevealControllerOperation)operation fromViewController:(UIViewController *)fromViewController toViewController:(UIViewController *)toViewController;

/**
 *  Ask for a block with animation and completion while replacing/pushing child view controllers, please add the final block to your completion.
 *
 *  @param revealController   The reveal view controller object.
 *  @param operation          The current operation (push from left or push from right).
 *  @param fromViewController The main view controller.
 *  @param toViewController   The new main view controller. When called the toViewController's view is behind the fromViewController's view.
 *  @param finalBlock         The final block provided by the reveal view controller object. This block must be inserted in your completion block.
 *
 *  @see    -revealController:animationBlockForOperation:fromViewController:toViewController:
 *  @see    -revealController:completionBlockForOperation:fromViewController:toViewController:
 *  @see    -revealController:animationControllerForTransitionFromViewController:toViewController:forOperation:
 
 */
- (void (^)(void))revealController:(RevealViewController *)revealController blockForOperation:(RevealControllerOperation)operation fromViewController:(UIViewController *)fromViewController toViewController:(UIViewController *)toViewController finalBlock:(void(^)(void))finalBlock;

/**
 *  Ask for custom transition animations controller while replacing/pushing child view controllers. If implemented, it will be fired in response to calls setXXXViewController or pushXXXViewController child view controller (since iOS 7).
 *
 *  @param revealController   The reveal view controller object.
 *  @param fromViewController The child view controller to replace.
 *  @param toViewController   The new child view controller.
 *  @param operation          The current operation (push from left, push from right, or replace).
 *
 *  @return The animator object adopting the UIViewControllerAnimatedTransitioning protocol.
 */
- (id <UIViewControllerAnimatedTransitioning>)revealController:(RevealViewController *)revealController animationControllerForTransitionFromViewController:(UIViewController *)fromViewController toViewController:(UIViewController *)toViewController forOperation:(RevealControllerOperation)operation;

@end

