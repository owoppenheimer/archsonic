main() {
   curl -fsSL https://raw.githubusercontent.com/owoppenheimer/archsonic/refs/heads/main/install/install.sh > ./install.sh &
   chmod +x ./install.sh

   echo "Installation script was successfully installed. Now you can run it. Just type \"./install.sh\""
}

main
