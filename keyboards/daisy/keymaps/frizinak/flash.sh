#! /bin/bash
set -e

# sorry windudes

dir='lib/lufa/Bootloaders/HID/HostLoaderAppKTEC'
make -C "$dir"
"$dir/hid_bootloader_cli" $@
