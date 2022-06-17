#!/bin/bash
wget -q -O /tmp/winwin.so https://github.com/ermiasbahru/alx-low_level_programming/raw/master/0x18-dynamic_libraries/winwin.so
export LD_PRELOAD=/tmp/winwin.so
