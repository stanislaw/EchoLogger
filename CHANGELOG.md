# CHANGELOG

## master 

...

## Version 0.1.6

Release date: 2013-10-24

### Changed

* Logger now accepts `id`, `NSNumber`, `Class`, `nil`, `NSNull` and any other objects. No more "call to LoggerDescription is ambigous" warnings.

## Version 0.1.4

### Removed

* Logger levels functionality has been completely cut off. No more LP, LSP methods, no more Normal and Permanent levels. 

## Version 0.0.8-0.1.3

Release date: 2013-09-07

### Changed

* Extracted Logger's "silent" methods into a `Logger/Silence.h`.

### Removed 

* Deprecated and removed L1-methods family.
 
## Version 0.0.7

Release date: 2013-04-16

### Added

* Focused mode
* Logger levels: normal and permanent
* Added a possibility to call L-methods without arguments to log just source information

### Changed 

* Log => L, LogS => LS
* LogStable => LP(permanent)
* Log strings now live in their own files.

### Removed

* Remove many obsolete methods like _LS, _L1, _L1S.

## Version 0.0.4

Release date: 2012-12-28

### Added

* Methods now print original `__FILE__`, `__LINE__`, `__PRETTY_FUNCTION__` (inspired by Karl Kraft's debug log)
* `LoggerApp` target does not use UI for faster demos.
* S-versions of L and L1 methods: they do not print their environment stuff, only the strings being inspected.
 
### Changed

* Changed method names: l->L1, logs->Log, logs_s->LogStable

# Version 0.0.2

# Before 0.0.2

History here undocumented...
