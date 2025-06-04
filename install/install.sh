# Installation script. Version - alpha 0.1 |
#                                          |
# owoppenheimer, 06/04/2025                |
# ------------------------------------     |
# <owoppenheimer.ads@gmail.com>            |

VERSION="alpha 0.1"
SOURCE="https://github.com/owoppenheimer/archsonic"

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
   greeter

   read -p "Use pre-compiled binary? [Y/n]: " compile

   if [[ "$compile" == "" || $compile == "y" || $compile == "Y" ]]; then
      echo "Ok.. Downloading tar.gz release from $SOURCE"
   fi
}

main "$@"
