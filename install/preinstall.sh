main() {
   curl -fsSL https://raw.githubusercontent.com/owoppenheimer/archsonic/refs/heads/arch/install/install.sh > ./install.sh &
   chmod +x ./install.sh
   echo "Ok, now just execute installer with './install.sh'"
}

main
