# mcu-max

## Overview

mcu-max is an MCU-optimized C-language chess game engine based on [micro-Max][micro-max-link].

This checkout supplies the engine sources used by the Centurion SDCC chess program. The upstream release also includes an Arduino serial example and a UCI example for chess GUIs. [Upstream release](https://github.com/Gissio/mcu-max/tree/aa03caffce50729566b5db6965bf735c31f33eea)

When running on devices with little memory, you might want to adjust the max depth value to avoid stack overflows.

Try the [Rad Pro simulator](https://gissio.github.io/radpro-simulator/) (click the right button and select Game at the bottom of the menu) to test mcu-max.

## Features

* Configurable hashing.
* Configurable node limit.
* Configurable max depth.
* Valid move listing.
* Best-move search termination.

## Terms of use

mcu-max is freely available and distributed under the MIT license.

[micro-max-link]: https://home.hccnet.nl/h.g.muller/max-src2.html
