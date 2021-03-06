# EchoLogger

`EchoLogger` is a logging utility. It was created to make a log-and-drop debugging routine more simple, more informative and faster than it currently is with `NSLog`. 

It's main purpose is to log something very quickly, catch the idea, and then drop the log line (ninja logging) - it does not aim to have dozens of logging levels, or logging targets, it is not intended to be used for constant logging, when the logs are to be used for future analysis. If you do need such level of complexity, consider using more serious tools (see "More serious loggers").

Key features:

* __"Echo"__ means that besides tracing the __values__ of what is logged, EchoLogger also echoes back the __what__ is logged.

* For its main L-methods EchoLogger does not follow traditional NSLog-like input format for arguments: `(@"Format string", args...)`.  Instead you pass the what you want to be logged - pass up to 20 different objects/variables you want to know about - each argument stands for one object.

* Logging variables of any kind. What you log is not restricted to what NSLog input would allow: EchoLogger supports logging of structs like CGRect, CGSize, MKCoordinateRegion.

After you have `EchoLogger` installed in your app, it becomes the easiest and the fastest way of doing a console logging on a daily basis. 

Author welcomes suggestions, feature requests, criticism or any other kind of a feedback (see also `TODO` section).

## Installation

Just add `EchoLogger/` folder to your project.

Or add into your Podfile:

```ruby
pod 'EchoLogger', :git => 'https://github.com/stanislaw/EchoLogger'
```

It is a good idea to add `EchoLogger` to .pch file of your project like:

```objective-c
#import <EchoLogger.h>
```

## L-methods

`L` stands for __"log"__.

EchoLogger has the following two methods to produce logging information: method `L` and its more verbose companion `LL()`.

> Q: Why such name for method: L()? 

> A: It is simple. "L" stands for "log" and it is the shortest possible name ever for a logging method.

### L()

```objective-c
L(self, [NSObject new]);
```

Will produce :

```
EL> self, [NSObject new]
-> (AppDelegate)<AppDelegate: 0x10a7261e0>; (NSObject)<NSObject: 0x10a7425e0>
```

See more examples on [Examples](https://github.com/stanislaw/EchoLogger/blob/master/Examples.md).

### LL()

```objective-c
L(self, [NSObject new]);
```

will produce console:

```
EL: AppDelegate.m:55; -[AppDelegate seeEchoLoggerInAction]; com.apple.main-thread> self, [NSObject new]
-> (AppDelegate)<AppDelegate: 0x10a7261e0>; (NSObject)<NSObject: 0x10a516300>
```

See more examples on [Examples](https://github.com/stanislaw/EchoLogger/blob/master/Examples.md).

## EchoLogger and NSStringFromAnyObject

EchoLogger has [NSStringFromAnyObject project](https://github.com/stanislaw/NSStringFromAnyObject) as its dependency. This project is used to provide EchoLogger with NSString representations for arbitrary objects be it Objective-C objects, C objects or custom structs found in frameworks like UIKit (CGRect, CGSize, CGPoint).

By default EchoLogger imports only the what NSStringObject has in its defaults: NSString representations for Objective-C, C, Foundation objects. UIKit is disabled by default to not couple EchoLogger with framework you might not need at all and to make it possible to also use EchoLogger within Mac environment.

Example: if you may want to be able to inspect structs specific to UIKit (like CGRect) import its specific NSStringFromAnyObject headers:

```objective-c
#import <EchoLogger.h>

#import <NSStringFromAnyObject/UIKit.h>
```

See [NSStringFromAnyObject project page](https://github.com/stanislaw/NSStringFromAnyObject) for details.

## Focused logging

Besides `L` and `LL` EchoLogger has corresponding `LF` - __"log focused"__ and `LLF` - __"log verbosely, focused"__ methods.

The idea of focused logging was taken from description of Cedar's feature: [Focused specs](https://github.com/pivotal/cedar) (see Focused specs section there).

The light variant of focused logging is that all `L()` and `LL()` methods will fall silent after the first invocation of any of the F-postfixed methods:

```objective-c
// All L methods before LF will produce output
L(...) // Will produce output
LL(...) // Will produce output
...
LF(...) // All L methods except F-postfixed will fall silent at this point
... 
L(...) // Will produce nothing.
L(...) // Will produce nothing.

LF(...) // Will produce output
// ...
```

If you need to maximize a focused logging (heavy variant), do the following as early as possible in your code:

```objective-c
EchoLoggerFocusedModeEnabled = YES;

// From this point you will never see any output except that F-methods produce
```

## Notes

* It is a good idea to place one `#import <EchoLogger.h>` to the `.pch` file of your project to not import `EchoLogger.h` every time you need to run EchoLogger's methods. 

* `EchoLogger` has special `EchoLogger/Silence.h` file which you may use if you want to disable EchoLogger in the specific cases. For example: if you want to completely disable EchoLogger when your app performs its flight in production, write the following code utilizing `#ifdef DEBUG` check to have EchoLogger methods working only in DEBUG configuration (it is default Xcode preprocessor macros `DEBUG=1` for Debug configuration):

```objective-c
// Your app's global .pch header file
#ifdef DEBUG
// We do import EchoLogger:
#import <EchoLogger/EchoLogger.h>
// Now L, LL, LF, LLF are defined, the logging does work.
#else
#import <EchoLogger/Silence.h>
// L, LL, LF, LLF are defined as nothing so no logging occurs.
// See <EchoLogger/Silence.h> for details.
#endif 
```

* EchoLogger is able to `L()` the variables of composite types like structs: CGRect, CGSize, CGPoint. It is very easy to add a support for any new type that EchoLogger does not support yet.

## More serious loggers

* [CocoaLumberjack](https://github.com/robbiehanson/CocoaLumberjack)

> fast & simple, yet powerful & flexible logging framework for Mac and
iOS

* [NSLogger](https://github.com/fpillet/NSLogger)

> A modern, flexible logging tool

For other loggers see [iOS-Projects-Catalogue: DebuggingTools/Logging](https://github.com/stanislaw/iOS-Projects-Catalogue#DebuggingTools/Logging).

## Credits

* EchoLogger uses `metamacros.h` from [libextobjc](https://github.com/jspahrsummers/libextobjc) library.

* Karl Kraft's [DebugLog](http://www.karlkraft.com/index.php/2009/03/23/114/) is the only source of inspiration for `EchoLogger` - it did borrow the following tricks from DebugLog:

  * Capturing the method's original environment by using `__FILE__`, `__LINE__`, `__PRETTY_FUNCTION__` from inside the `#define` directives. 
  * Importing EchoLogger inside `#ifdef DEBUG ... endif` condition to enable its work only in Debug configuration.  
  * `DebugLog` logs current thread's name and it highly inspires `EchoLogger` to log a current queue's label.

* The idea of focused logging is inspired by "Focused specs" feature of [Cedar](https://github.com/pivotal/cedar) testing framework.

## TODO

* Configuration property (C function pointer) to allow EchoLogger to output its content to some function other than current `fprintf` - TFLog is a good candidate as a possible alternative.
* Customize and/or allow to customize EchoLogger's output: for example, provide a non-horizontal, not-NSLog-like, output: each L() call could produce nicely formatted columns ('one line - one EchoLogger string item' fx 'dispatch queue\nsource file\n') so they would be much easier to read in the context of all other iOS app's console output.

Besides the above features, there is nothing I see that could be added to the current minimalistic set of `EchoLogger` features. Let me know, if you do.

Feel free to ask for a feature you know EchoLogger lacks - open an issue on the `EchoLogger's` [issue tracker](https://github.com/stanislaw/EchoLogger/issues).

## Copyright

Copyright (c) 2014, Stanislaw Pankevich. See LICENSE for details.

