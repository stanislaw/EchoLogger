# Logger

`Logger` is one more simple variation of drop-in replacements for `NSLog` method. It was created to make a log-and-drop debugging routine more simple, more informative and faster than it currently is with `NSLog`. Actually, after you have `Logger` installed in your app, it becomes the easiest and the fastest way of doing a logging on a daily basis. 

## Installation

Just add `Logger/` folder to your project.

Or add into your Podfile:

```ruby
pod 'Logger', :git => 'https://github.com/stanislaw/Logger'
```

It is a good idea to add `Logger` to .pch file of your project like:

```objective-c
#import <Logger.h>
```

And you may want to add the inspection strings for specific data types from Cocoa frameworks (only Foundation stuff is included by default): 

```objective-c
#import <Logger/Descriptions/MapKit.h>
#import <Logger/Descriptions/CoreLocation.h>
```

See definitions in `Logger/Descriptions/` for details.

## L-methods

Logger has the following two methods to produce logging information: method `L` and its less verbose companion `LS()`.

### L()

`L` stands for __"log"__. `L` method can work in two ways:

1) `L` is very similar to NSLog if you pass it "format + arguments", but produces better, more informative output.

```objective-c
L(@"Boolean variable: %d", YES);
L(@"Int variable: %d", 5);
L(@"Float variable: %f", 5.5);
L(@"NSUInteger variable: %u", (NSUInteger)5);
L(@"NSNumber variable: %@", @5);
L(@"a C string: %s", "I'am the string!");
```

will result in:

```
[com.apple.main-thread] int main(int, char **) (main.m:7) Boolean variable: 1
[com.apple.main-thread] int main(int, char **) (main.m:8) Int variable: 5
[com.apple.main-thread] int main(int, char **) (main.m:9) Float variable: 5.500000
[com.apple.main-thread] int main(int, char **) (main.m:10) NSUInteger variable: 5
[com.apple.main-thread] int main(int, char **) (main.m:11) NSNumber variable: 5
[com.apple.main-thread] int main(int, char **) (main.m:12) a C string: I'am the string!
```

2) The second way of using `L()` is to just pass it one object of almost any type (ask if you need a type that `Logger` does not support yet). The following code:

```objective-c
L(YES);
L(5);
L((float)5.5);
L((NSUInteger)5);
L(@5);
L(@"I'am the string!");
L((CGRect){0, 0, 200, 200});
L((CGSize){200, 200});
```

will produce:

```
[com.apple.main-thread] int main(int, char **) (main.m:7) (BOOL)Yes
[com.apple.main-thread] int main(int, char **) (main.m:8) (int)5
[com.apple.main-thread] int main(int, char **) (main.m:9) (float)5.500000
[com.apple.main-thread] int main(int, char **) (main.m:10) (NSUInteger)5
[com.apple.main-thread] int main(int, char **) (main.m:11) (__NSCFNumber) 5
[com.apple.main-thread] int main(int, char **) (main.m:12) (__NSCFConstantString) I'am the string!
[com.apple.main-thread] int main(int, char **) (main.m:13) (CGRect){0.000000, 0.000000, 200.000000, 200.000000}
[com.apple.main-thread] int main(int, char **) (main.m:14) (CGSize){200.000000, 200.000000}
```

### LS()

`L` method has its `S`-postfixed companion: `LS`, which means __"log shortly"__ - `LS()` produce the similar output the `L()` method does, but without inclusion of any environment information: queue label, method name from which S-method is called, and a file with line number where it is located _are not displayed_.

```objective-c
LS(@"Boolean variable: %d", YES);
LS(@"Int variable: %d", 5);
LS(@"Float variable: %f", 5.5);
LS(@"NSUInteger variable: %u", (NSUInteger)5);
LS(@"NSNumber variable: %@", @5);
LS(@"a C string: %s", "I'am the string!");
```

Will produce just:

```
Boolean variable: 1
Int variable: 5
Float variable: 5.500000
NSUInteger variable: 5
NSNumber variable: 5
a C string: I'am the string!
```

### Focused logging

Besides `L` and `LS` Logger has corresponding `LF` - __"log focused"__ and `LSF` - __"log shortly, focused"__ methods.

The idea of focused logging was taken from description of Cedar's feature: [Focused specs](https://github.com/pivotal/cedar) (see Focused specs section there).

The light variant of focused logging is that all `L()` and `LS()` methods will fall silent after the first invocation of any of the F-postfixed methods:

```objective-c
// All L methods before LF will produce output
L(...) // Will produce output
LS(...) // Will produce output
...
LF(...) // All L methods except F-postfixed will fall silent at this point
... 
L(...) // Will produce nothing.
L(...) // Will produce nothing.

LF(...) // Will produce output
// ...
```

If you need to maximize a focused logging (heavy variant), do the following as early as possible in your code, something like:

```objective-c
int main(int argc, char *argv[])
{
    #define NSLog(args...) // indent for readability
    LOGGER_FOCUSED_MODE = YES;

    // From this point you will never see any output except that F-methods produce

    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil,
NSStringFromClass([AppDelegate class]));
    }
}
```

## Notes

* It is a good idea to place one `#import <Logger.h>` to the `.pch` file of your project to not import `Logger.h` every time you need to run Logger's methods. 

* `Logger` has special `Logger/Silence.h` file which you may use if you want to disable Logger in the specific cases. For example: if you want to completely disable Logger when your app performs its flight in production, write the following code utilizing `#ifdef DEBUG` check to have Logger methods working only in DEBUG configuration (it is default Xcode preprocessor macros `DEBUG=1` for Debug configuration):

```objective-c
// Your app's global .pch header file
#ifdef DEBUG
// We do import Logger and the descriptions we want to use:
#import <Logger/Logger.h>
#import <Logger/Descriptions/...>
// Now L, LS, LSF, LF are defined, the logging does work.
#else
#import <Logger/Silence.h>
// L, LS, LSF, LF are defined as nothing so no logging occurs.
See <Logger/Silence.h> for details.
#endif 
```

* Logger is able to `L()` the variables of composite types like structs: CGRect, CGSize, CGPoint. It is very easy to add a support for any new type that Logger does not support yet.

* There are separate files like `<Logger/Descriptions/UIKit.h>` containing definitions for inspection of typed variables of corresponding framework, for example CGRect and CGSize are there in `Descriptions/UIKit.h`. Import these files if you want to log specific types from these frameworks. They are all extracted into the separate files to not couple main Logger.h file with the frameworks you might not need at all.

* See [Examples](https://github.com/stanislaw/Logger/wiki/Examples)

* To repeat the text from the beginning of this README: `Logger` was created to make a log-and-drop debugging routine more simple, more informative and faster than it currently is with NSLog. It means that it's main purpose is to log something very quickly, catch the idea, and then drop the log line. It does not aim to have dozens of logging levels, or logging targets, it is not intended to be used for constant logging, so the logs could be used for future analysis. If you do need a such level of complexity, consider using much more serious tools like [CocoaLumberjack](https://github.com/robbiehanson/CocoaLumberjack).

Having that said, the author claims that he would be very thankful for any suggestions, feature requests, criticism or any other kind of a feedback (see also `TODO` section).

## Credits

Karl Kraft's [DebugLog](http://www.karlkraft.com/index.php/2009/03/23/114/) is the only source of inspiration for `Logger` - it did borrowed the following tricks from DebugLog:

* Capturing the method's original environment by using `__FILE__`, `__LINE__`, `__PRETTY_FUNCTION__` from inside the `#define` directives. 
* Importing Logger inside `#ifdef DEBUG ... endif` condition to enable its work only in Debug configuration.  
* `DebugLog` logs current thread's name and it highly inspires `Logger` to log a current queue's label.

The idea of focused logging is inspired by "Focused specs" feature of [Cedar](https://github.com/pivotal/cedar) testing framework.

## TODO

* Configuration property (C function pointer) to allow Logger to output its content to some function other than current `fprintf` - TFLog is a good candidate as a possible alternative.
* Customize and/or allow to customize Logger's output: for example, provide a non-horizontal, not-NSLog-like, output: each L() call could produce nicely formatted columns ('one line - one Logger string item' fx 'dispatch queue\nsource file\n') so they would be much easier to read in the context of all other iOS app's console output.

Besides the above features, there is nothing I see that could be added to the current set of `Logger` features. Let me know, if you do.

Ideally, `Logger` should accumulate all the possible awesome logging features in one place - feel free to ask for a one you know it lacks - open an issue on the `Logger's` [issue tracker](https://github.com/stanislaw/Logger/issues).

## Copyright

Copyright (c) 2013, Stanislaw Pankevich. See LICENSE for details.
