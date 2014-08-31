# Echo Logger examples

## L

Input:

```
int intNumber = 10;
double doubleNumber = 5.55;
BOOL boolValue = YES;
NSUInteger unsignedIntNumber = 7;
NSNumber *number = @(18);
NSString *string = @"I'am the string!";
CGRect frame = (CGRect){0, 0, 200, 200};
CGSize size = (CGSize){200, 200};

L(intNumber, doubleNumber, boolValue, unsignedIntNumber, number, string);
L(frame, size);
```

Output:

```
EL> intNumber, doubleNumber, boolValue, unsignedIntNumber, number, string
-> (int)10; (double)5.550000; YES; 7; @(18); (__NSCFConstantString)I'am the string!
EL> frame, size
-> (CGRect){0.000000, 0.000000, 200.000000, 200.000000}; (CGSize){200.000000, 200.000000}
```

## LL

Input:

```
int intNumber = 10;
double doubleNumber = 5.55;
BOOL boolValue = YES;
NSUInteger unsignedIntNumber = 7;
NSNumber *number = @(18);
NSString *string = @"I'am the string!";
CGRect frame = (CGRect){0, 0, 200, 200};
CGSize size = (CGSize){200, 200};

LL(intNumber, doubleNumber, boolValue, unsignedIntNumber, number, string);
LL(frame, size);
```

Output:

```
EL: AppDelegate.m:52; -[AppDelegate seeEchoLoggerInAction]; com.apple.main-thread> intNumber, doubleNumber, boolValue, unsignedIntNumber, number, string
-> (int)10; (double)5.550000; YES; 7; @(18); (__NSCFConstantString)I'am the string!
EL: AppDelegate.m:53; -[AppDelegate seeEchoLoggerInAction]; com.apple.main-thread> frame, size
-> (CGRect){0.000000, 0.000000, 200.000000, 200.000000}; (CGSize){200.000000, 200.000000}
```

