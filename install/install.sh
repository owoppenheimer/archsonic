VERSION="alpha 0.1"
SOURCE="https://github.com/owoppenheimer/archsonic"
CHECKWGET=`sudo pacman -Qs wget`

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

main() {
   if [[ `whoami` != "root" ]]; then
      echo "You aren't root! Please execute this script as root!"
      return 1
   fi
   greeter

   read -p "Use pre-compiled binary? [Y/n]: " compile

   if [[ "$compile" == "" || $compile == "y" || $compile == "Y" ]]; then
      if [[  ]]
      echo "Ok.. Downloading tar.gz release from $SOURCE"
      wget https://github.com/user-attachments/files/20644346/as.tar.gz
   fi
}

main "$@"
