# wslcwd

Get the current path optimized for the Windows Subsystem for Linux.

Replaces

- `/home/<current_user>` with `~`
- `/mnt/<drive>` with `<drive>:/` for all configured drive letters

## Building

Running `make` will build the program with `c` as the only drive letter.

Running `make DRIVES=cid` will build the program with `c`, `i` and `d` as drive letters.

## Installing

Running `make install` will copy the program to `~/.local/bin`

Running `make install DIR=<dir>` will copy the program to `<dir>`
