main() {
   curl -fsSL https://raw.githubusercontent.com/owoppenheimer/archsonic/refs/heads/arch/install/install.sh > ./install.sh &
   chmod +x ./install.sh

   # exectute the script
   su -c "./install.sh"
}

main
