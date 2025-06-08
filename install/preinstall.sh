main() {
   curl -fsSL https://raw.githubusercontent.com/owoppenheimer/archsonic/refs/heads/main/install/install.sh > ./install.sh &
   chmod +x ./install.sh

   # exectute the script
   su -c "./install.sh"
}

main