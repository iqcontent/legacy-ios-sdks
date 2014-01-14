/*	CFNumberFormatter.h
	Copyright (c) 2003-2010, Apple Inc. All rights reserved.
*/

#if !defined(__COREFOUNDATION_CFNUMBERFORMATTER__)
#define __COREFOUNDATION_CFNUMBERFORMATTER__ 1

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFNumber.h>
#include <CoreFoundation/CFLocale.h>

#if MAC_OS_X_VERSION_10_3 <= MAC_OS_X_VERSION_MAX_ALLOWED || __IPHONE_2_0 <=  __IPHONE_OS_VERSION_MAX_ALLOWED

CF_EXTERN_C_BEGIN

typedef struct __CFNumberFormatter *CFNumberFormatterRef;

// CFNumberFormatters are not thread-safe.  Do not use one from multiple threads!

CF_EXPORT
CFTypeID CFNumberFormatterGetTypeID(void) CF_AVAILABLE(10_3, 2_0);

enum {	// number format styles
	kCFNumberFormatterNoStyle = 0,
	kCFNumberFormatterDecimalStyle = 1,
	kCFNumberFormatterCurrencyStyle = 2,
	kCFNumberFormatterPercentStyle = 3,
	kCFNumberFormatterScientificStyle = 4,
	kCFNumberFormatterSpellOutStyle = 5
};
typedef CFIndex CFNumberFormatterStyle;


CF_EXPORT
CFNumberFormatterRef CFNumberFormatterCreate(CFAllocatorRef allocator, CFLocaleRef locale, CFNumberFormatterStyle style) CF_AVAILABLE(10_3, 2_0);
	// Returns a CFNumberFormatter, localized to the given locale, which
	// will format numbers to the given style.

CF_EXPORT
CFLocaleRef CFNumberFormatterGetLocale(CFNumberFormatterRef formatter) CF_AVAILABLE(10_3, 2_0);

CF_EXPORT
CFNumberFormatterStyle CFNumberFormatterGetStyle(CFNumberFormatterRef formatter) CF_AVAILABLE(10_3, 2_0);
	// Get the properties with which the number formatter was created.

CF_EXPORT
CFStringRef CFNumberFormatterGetFormat(CFNumberFormatterRef formatter) CF_AVAILABLE(10_3, 2_0);

CF_EXPORT
void CFNumberFormatterSetFormat(CFNumberFormatterRef formatter, CFStringRef formatString) CF_AVAILABLE(10_3, 2_0);
	// Set the format description string of the number formatter.  This
	// overrides the style settings.  The format of the format string
	// is as defined by the ICU library, and is similar to that found
	// in Microsoft Excel and NSNumberFormatter (and Java I believe).
	// The number formatter starts with a default format string defined
	// by the style argument with which it was created.


CF_EXPORT
CFStringRef CFNumberFormatterCreateStringWithNumber(CFAllocatorRef allocator, CFNumberFormatterRef formatter, CFNumberRef number) CF_AVAILABLE(10_3, 2_0);

CF_EXPORT
CFStringRef CFNumberFormatterCreateStringWithValue(CFAllocatorRef allocator, CFNumberFormatterRef formatter, CFNumberType numberType, const void *valuePtr) CF_AVAILABLE(10_3, 2_0);
	// Create a string representation of the given number or value
	// using the current state of the number formatter.


enum {
    kCFNumberFormatterParseIntegersOnly = 1	/* only parse integers */
};
typedef CFOptionFlags CFNumberFormatterOptionFlags;

CF_EXPORT
CFNumberRef CFNumberFormatterCreateNumberFromString(CFAllocatorRef allocator, CFNumberFormatterRef formatter, CFStringRef string, CFRange *rangep, CFOptionFlags options) CF_AVAILABLE(10_3, 2_0);

CF_EXPORT
Boolean CFNumberFormatterGetValueFromString(CFNumberFormatterRef formatter, CFStringRef string, CFRange *rangep, CFNumberType numberType, void *valuePtr) CF_AVAILABLE(10_3, 2_0);
	// Parse a string representation of a number using the current state
	// of the number formatter.  The range parameter specifies the range
	// of the string in which the parsing should occur in input, and on
	// output indicates the extent that was used; this parameter can
	// be NULL, in which case the whole string may be used.  The
	// return value indicates whether some number was computed and
	// (if valuePtr is not NULL) stored at the location specified by
	// valuePtr.  The numberType indicates the type of value pointed
	// to by valuePtr.


CF_EXPORT
void CFNumberFormatterSetProperty(CFNumberFormatterRef formatter, CFStringRef key, CFTypeRef value) CF_AVAILABLE(10_3, 2_0);

CF_EXPORT
CFTypeRef CFNumberFormatterCopyProperty(CFNumberFormatterRef formatter, CFStringRef key) CF_AVAILABLE(10_3, 2_0);
	// Set and get various properties of the number formatter, the set of
	// which may be expanded in the future.

CF_EXPORT const CFStringRef kCFNumberFormatterCurrencyCode CF_AVAILABLE(10_3, 2_0);		// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterDecimalSeparator CF_AVAILABLE(10_3, 2_0);	// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterCurrencyDecimalSeparator CF_AVAILABLE(10_3, 2_0); // CFString
CF_EXPORT const CFStringRef kCFNumberFormatterAlwaysShowDecimalSeparator CF_AVAILABLE(10_3, 2_0); // CFBoolean
CF_EXPORT const CFStringRef kCFNumberFormatterGroupingSeparator CF_AVAILABLE(10_3, 2_0);	// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterUseGroupingSeparator CF_AVAILABLE(10_3, 2_0);	// CFBoolean
CF_EXPORT const CFStringRef kCFNumberFormatterPercentSymbol CF_AVAILABLE(10_3, 2_0);		// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterZeroSymbol CF_AVAILABLE(10_3, 2_0);		// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterNaNSymbol CF_AVAILABLE(10_3, 2_0);		// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterInfinitySymbol CF_AVAILABLE(10_3, 2_0);		// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterMinusSign CF_AVAILABLE(10_3, 2_0);		// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterPlusSign CF_AVAILABLE(10_3, 2_0);		// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterCurrencySymbol CF_AVAILABLE(10_3, 2_0);		// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterExponentSymbol CF_AVAILABLE(10_3, 2_0);		// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterMinIntegerDigits CF_AVAILABLE(10_3, 2_0);	// CFNumber
CF_EXPORT const CFStringRef kCFNumberFormatterMaxIntegerDigits CF_AVAILABLE(10_3, 2_0);	// CFNumber
CF_EXPORT const CFStringRef kCFNumberFormatterMinFractionDigits CF_AVAILABLE(10_3, 2_0);	// CFNumber
CF_EXPORT const CFStringRef kCFNumberFormatterMaxFractionDigits CF_AVAILABLE(10_3, 2_0);	// CFNumber
CF_EXPORT const CFStringRef kCFNumberFormatterGroupingSize CF_AVAILABLE(10_3, 2_0);		// CFNumber
CF_EXPORT const CFStringRef kCFNumberFormatterSecondaryGroupingSize CF_AVAILABLE(10_3, 2_0);	// CFNumber
CF_EXPORT const CFStringRef kCFNumberFormatterRoundingMode CF_AVAILABLE(10_3, 2_0);		// CFNumber
CF_EXPORT const CFStringRef kCFNumberFormatterRoundingIncrement CF_AVAILABLE(10_3, 2_0);	// CFNumber
CF_EXPORT const CFStringRef kCFNumberFormatterFormatWidth CF_AVAILABLE(10_3, 2_0);		// CFNumber
CF_EXPORT const CFStringRef kCFNumberFormatterPaddingPosition CF_AVAILABLE(10_3, 2_0);	// CFNumber
CF_EXPORT const CFStringRef kCFNumberFormatterPaddingCharacter CF_AVAILABLE(10_3, 2_0);	// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterDefaultFormat CF_AVAILABLE(10_3, 2_0);		// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterMultiplier CF_AVAILABLE(10_4, 2_0);		// CFNumber
CF_EXPORT const CFStringRef kCFNumberFormatterPositivePrefix CF_AVAILABLE(10_4, 2_0);		// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterPositiveSuffix CF_AVAILABLE(10_4, 2_0);		// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterNegativePrefix CF_AVAILABLE(10_4, 2_0);		// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterNegativeSuffix CF_AVAILABLE(10_4, 2_0);		// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterPerMillSymbol CF_AVAILABLE(10_4, 2_0);		// CFString
CF_EXPORT const CFStringRef kCFNumberFormatterInternationalCurrencySymbol CF_AVAILABLE(10_4, 2_0); // CFString
CF_EXPORT const CFStringRef kCFNumberFormatterCurrencyGroupingSeparator CF_AVAILABLE(10_5, 2_0); // CFString
CF_EXPORT const CFStringRef kCFNumberFormatterIsLenient CF_AVAILABLE(10_5, 2_0);		// CFBoolean
CF_EXPORT const CFStringRef kCFNumberFormatterUseSignificantDigits CF_AVAILABLE(10_5, 2_0);	// CFBoolean
CF_EXPORT const CFStringRef kCFNumberFormatterMinSignificantDigits CF_AVAILABLE(10_5, 2_0);	// CFNumber
CF_EXPORT const CFStringRef kCFNumberFormatterMaxSignificantDigits CF_AVAILABLE(10_5, 2_0);	// CFNumber

enum {
    kCFNumberFormatterRoundCeiling = 0,
    kCFNumberFormatterRoundFloor = 1,
    kCFNumberFormatterRoundDown = 2,
    kCFNumberFormatterRoundUp = 3,
    kCFNumberFormatterRoundHalfEven = 4,
    kCFNumberFormatterRoundHalfDown = 5,
    kCFNumberFormatterRoundHalfUp = 6
};
typedef CFIndex CFNumberFormatterRoundingMode;

enum {
    kCFNumberFormatterPadBeforePrefix = 0,
    kCFNumberFormatterPadAfterPrefix = 1,
    kCFNumberFormatterPadBeforeSuffix = 2,
    kCFNumberFormatterPadAfterSuffix = 3
};
typedef CFIndex CFNumberFormatterPadPosition;


CF_EXPORT
Boolean CFNumberFormatterGetDecimalInfoForCurrencyCode(CFStringRef currencyCode, int32_t *defaultFractionDigits, double *roundingIncrement) CF_AVAILABLE(10_3, 2_0);
	// Returns the number of fraction digits that should be displayed, and
	// the rounding increment (or 0.0 if no rounding is done by the currency)
	// for the given currency.  Returns false if the currency code is unknown
	// or the information is not available.
	// Not localized because these are properties of the currency.

CF_EXTERN_C_END

#endif

#endif /* ! __COREFOUNDATION_CFNUMBERFORMATTER__ */

