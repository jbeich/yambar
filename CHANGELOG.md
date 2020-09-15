# Changelog

* [Unreleased](#unreleased)
* [1.5.0](#1-5-0)


## Unreleased
### Added

* Support for grapheme shaping. Yambar must be linked against
[utf8proc](https://github.com/JuliaStrings/utf8proc) **and**
[fcft](https://codeberg.org/dnkl/fcft) built with
[HarfBuzz](https://github.com/harfbuzz/harfbuzz) support. This can be
disabled at build-time with the `-Dtext-shaping=disabled|enabled|auto`
meson command line option.


### Deprecated
### Removed
### Changed

* Yambar now requires fcft >= 2.3.0.


### Fixed
### Security
### Contributors


## 1.5.0

### Added

* battery: support for drivers that use 'charge\_\*' (instead of
  'energy\_\*') sys files.
* removables: SD card support.
* removables: new 'ignore' property.
* Wayland: multi-seat support.
* **Experimental**: 'river': new module for the river Wayland compositor.


### Changed

* Requires fcft-2.2.x.
* battery: a poll value of 0 disables polling.


### Fixed

* mpd: check of return value from `thrd_create`.
* battery: handle 'manufacturer' and 'model_name' not being present.
* Wayland: handle runtime scaling changes.
