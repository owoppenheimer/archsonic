## ArchSonic

The modern installer of Arch/Artix Linux written on C.
![MIT License](LICENSE)

It uses notcurses, modern TUI Library that provides many useful and cool features!

## How to install and use?

Just execute this command in your Arch/Artix liveiso:
`curl -fsSL https://raw.githubusercontent.com/owoppenheimer/archsonic/refs/heads/main/install/preinstall.sh | sh`
This will download an installation script

After that you need to execute ArchSonic installer:
`./install.sh`

!*ArchSonic installation script requires root access*! (in installation iso's you're already root)

Dependecies:
- curl
- notcurses (build dependency)
- make (build dependency)
