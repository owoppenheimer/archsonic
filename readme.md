## ArchSonic

The modern installer of Arch/Artix Linux written on C.
![MIT License](LICENSE)

## Branches

Just execute this command in your Arch/Artix liveiso:

`curl -fsSL https://raw.githubusercontent.com/owoppenheimer/archsonic/refs/heads/main/install/preinstall.sh | sh`

This will download an installation script


After that you need to execute ArchSonic installer:

`./install.sh`

!*ArchSonic installation script requires root access*! (in installation isos you're already root)

Dependecies:
- curl
- ncurses (build dependency)
- make (build dependency)
- clang (but you can use gcc, see ./Makefile)
