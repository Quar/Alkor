#import <Foundation/Foundation.h>

@interface NSArray (NGSIndexExtensions)
/*!
@method			subarrayWithIndicies:
@author			Nicholas Shanks
@created		January 2004
@abstract		Returns an immutable array of the objects at the given indicies.
*/
- (NSArray *)subarrayWithIndicies:(NSIndexSet *)indicies;
@end

@interface NSArray (NGSKeyValueExtensions)
/*!
@method			indexOfFirstObjectReturningValue:forKey:
@author			Nicholas Shanks
@created		January 2003
@discussion		Calls <tt>valueForKey:</tt> on each object in the array, returning the index of the first one encountered which itself returned the value passed in, according to <tt>isEqual:</tt>, or returns <tt>NSNotFound</tt> if no object matched for the given key/value pair. Mostly useful just for increasing code readability, as the methd is only one line long, but one that's not easy to understand at first glance.
@change			NGS 2005-02-23: Removed unnecessary code, <tt>indexOfObject:</tt> already returns <tt>NSNotFound</tt> for me.
*/
- (int)indexOfFirstObjectReturningValue:(id)value forKey:(id)key;
/*!
@method			firstObjectReturningValue:forKey:
@author			Nicholas Shanks
@created		January 2003
@discussion		Calls <tt>valueForKey:</tt> on each object in the array, returning the first one encountered which itself returned the value passed in, according to <tt>isEqual:</tt>. Returns <tt>nil</tt> if no matching object is found.
@change			NGS 2005-02-23: Removed message to <tt>indexOfFirstObjectReturningValue:forKey:</tt>, incorperated that method's code into this one.
*/
- (id)firstObjectReturningValue:(id)value forKey:(id)key;
/*!
@method			objectsReturningValue:forKey:
@author			Nicholas Shanks
@created		January 2003
@abstract		Returns an array containing all objects in the receiver which have <tt>value</tt> set for key <tt>key</tt>.
@discussion		Calls <tt>valueForKey:</tt> on each object in the array, returning a new array containing all objects which themselves returned the value passed in, according to <tt>isEqual:</tt>. If no objects matched, this method returns an empty array.
*/
- (NSArray *)objectsReturningValue:(id)value forKey:(id)key;
- (NSArray *)arrayByMakingObjectsPerformSelector:(SEL)selector withObject:(id)inObject;
@end

@interface NSCharacterSet (NGSNewlineExtensions)
#if MAC_OS_X_VERSION_MAX_ALLOWED <= MAC_OS_X_VERSION_10_4
/*!
@method			newlineCharacterSet
@author			Nicholas Shanks
@created		March 2005
@abstract		Returns a character set containing only the newline and nextline characters (U+000A�U+000D, U+0085).
*/
+ (NSCharacterSet *)newlineCharacterSet;
#endif
/*!
@method			tabCharacterSet
@author			Nicholas Shanks
@created		March 2005
@abstract		Returns a character set containing only the horizontal and vertical tab characters (U+0009, U+000B).
*/
+ (NSCharacterSet *)tabCharacterSet;
@end

@interface NSIndexSet (NGSIndicies)
+ (id)indexSetWithIndiciesInRange:(NSRange)range;
- (id)initWithIndiciesInRange:(NSRange)range;
- (unsigned int)getIndicies:(unsigned int *)indexBuffer maxCount:(unsigned int)bufferSize inIndexRange:(NSRangePointer)range;
- (BOOL)containsIndiciesInRange:(NSRange)range;
- (BOOL)containsIndicies:(NSIndexSet *)indexSet;
- (BOOL)intersectsIndiciesInRange:(NSRange)range;
@end

@interface NSMutableIndexSet (NGSIndicies)
- (void)addIndicies:(NSIndexSet *)indexSet;
- (void)removeIndicies:(NSIndexSet *)indexSet;
- (void)removeAllIndicies;
- (void)addIndiciesInRange:(NSRange)range;
- (void)removeIndiciesInRange:(NSRange)range;
- (void)shiftIndiciesStartingAtIndex:(unsigned int)index by:(int)delta;   
@end

@interface NSNumber (NGSRangeExtensions)
/*!
@method			isWithinRange:
@author			Nicholas Shanks
@created		February 2003
*/
- (BOOL)isWithinRange:(NSRange)range;				// location <= self <= location+length
/*!
@method			isExclusivelyWithinRange:
@author			Nicholas Shanks
@created		February 2003
*/
- (BOOL)isExclusivelyWithinRange:(NSRange)range;	// location < self < location+length
/*!
@method			isBoundedByRange:
@author			Nicholas Shanks
@created		February 2003
*/
- (BOOL)isBoundedByRange:(NSRange)range;			// location <= self < location+length
@end

@interface NSString (NGSFSSpecExtensions)
/*!
@method			createFSRef
@author			Nicholas Shanks
@created		November 2002
@abstract		Returns an <tt>FSRef</tt> for the absolute path represented by the receiver. The caller is responsible for disposing of the <tt>FSRef</tt>.
*/
- (FSRef *)createFSRef;
/*!
@method			createFSSpec
@author			Nicholas Shanks
@created		November 2002
@abstract		Returns an <tt>FSSpec</tt> for the absolute path represented by the receiver. The caller is responsible for disposing of the <tt>FSSpec</tt>.
*/
- (FSSpec *)createFSSpec;
@end

@interface NSString (NGSBooleanExtensions)
#if MAC_OS_X_VERSION_MAX_ALLOWED <= MAC_OS_X_VERSION_10_4
/*!
@method			boolValue
@author			Nicholas Shanks
@created		March 2001
*/
- (BOOL)boolValue;
#endif
/*!
@method			stringWithBool:
@author			Nicholas Shanks
@created		March 2001
*/
+ (NSString *)stringWithBool:(BOOL)boolean;
@end

#pragma mark -
#import <AppKit/AppKit.h>

@interface NSOutlineView (NGSSelectedItemExtensions)
/*!
@method			selectedItem
@author			Nicholas Shanks
@created		September 2001
*/
- (id)selectedItem;
/*!
@method			selectedItems
@author			Nicholas Shanks
@created		September 2001
*/
- (NSArray *)selectedItems;
@end

#if MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_5
@interface NSGradient (NGSGradientExtensions)
/*!
@method			aquaGradient
@method			aquaGradientWithAlpha:
@method			gradientWithAlpha:
@author			Nicholas Shanks
@created		May 2007
*/
+ (NSGradient *)aquaGradient;
+ (NSGradient *)aquaGradientWithAlpha:(CGFloat)alpha;
- (NSGradient *)gradientWithAlpha:(CGFloat)alpha;
@end
#endif

#pragma mark -
#import <OpenGL/OpenGL.h>

@interface NSOpenGLContext (CGLContextAccess)
- (CGLContextObj)cglContext;
@end