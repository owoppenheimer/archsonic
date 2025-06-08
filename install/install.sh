#!/bin/sh

VERSION="alpha 0.1"
SOURCE="https://github.com/owoppenheimer/archsonic"
RELEASE="https://github.com/owoppenheimer/archsonic/releases/download/broken/archsonic"

greeter() {
   echo "
   _____                .__      _________             .__        
  /  _  \_______   ____ |  |__  /   _____/ ____   ____ |__| ____  
 /  /_\  \_  __ \_/ ___\|  |  \ \_____  \ /  _ \ /    \|  |/ ___\ 
/    |    \  | \/\  \___|   Y  \/        (  <_> )   |  \  \  \___ 
\____|__  /__|    \___  >___|  /_______  /\____/|___|  /__|\___  >
        \/            \/     \/        \/            \/        \/  $VERSION
        "
   echo "Welcome to the installation script."
   echo
   echo "You can compile ArchSonic yourself if you want. Or you can use pre-compiled binary."
   echo
}

depends() {
   pacman -S git ncurses clang
}

main() {
   if [[ `whoami` != "root" ]]; then
      echo "You aren't root! Please execute this script as root!" # HOWHOWHOWHOW ITS ARCHISO
      return 1
   fi
   curl https://google.com &> /dev/null
   if [[ $? != 0 ]]; then
      echo "You're not connected to the internet! Please use iwd (if you use wireless connection) or check your internet connection!"
      return 2
   fi

   pacman -Qs wget &> /dev/null
   if [[ $? != 0 ]]; then
      pacman -S wget
   fi
   pacman -Qs ncurses &> /dev/null
   if [[ $? != 0 ]]; then
      pacman -S ncurses
   fi
   clear

   greeter

   read -p "Compile binary? [Y/n]: " compile

   # Compile
   if [[ "$compile" == "" || $compile == "y" || $compile == "Y" ]]; then
      pacman -Qs make &> /dev/null
      if [[ $? == 0 ]]; then
         depends
         if [[ $? != 0 ]]; then
            echo "Something went wrong.. Couldn't install packages (git ncurses)"
         fi

         echo "Ok.. Downloading source from $SOURCE"
         git clone https://github.com/owoppenheimer/archsonic.git
         cd archsonic; make
         cp bin/* /sbin/

         clear
         echo "ArchSonic is now installed. Run it with 'archsonic'"
         return
      fi

      # HOW. JUST. HOW. 
      echo
      echo "Hmm.. How the **ck you don't have make? It is preinstalled in ArchISO! Did you delete it?"
      echo "Anyways, just install make with \"pacman -S make\" and dont **ck my brain anymore.."
      return 1

   # Don't compile
   else
      echo "Ok.. Downloading pre-compiled binary release from $RELEASE"

      wget $RELEASE
      chmod +x ./archsonic
      cp ./archsonic /sbin/

      echo "ArchSonic is now installed. Run it with 'archsonic'"
   fi
}

main "$@"
