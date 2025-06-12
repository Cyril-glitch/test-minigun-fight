BRIGHT_GREEN='\033[1;92m'
NC='\033[0m'

echo -n "🛠️ Compilation en cours"
for i in {1..10}; do
    echo -ne "${BRIGHT_GREEN}▓${NC}"
    sleep 0.1
done


if gcc -mconsole -g  -Wall -Wextra -Werror main.c cc2d/cc2d_graphics.c cc2d/cc2d_font.c cc2d/cc2d_keyboard.c cc2d/cc2d_game.c cc2d/cc2d_init.c -Iinclude -Llib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf  -o ../bin/monprog.exe 
then 

echo -e "\a"
echo "✅ Compilation terminée !"
echo "🚀 Lancement du programme !"
echo
echo
cd ../bin
./monprog.exe

else
echo -e "\a"
echo "🙊 Compilation impossible..."
echo

exit 1

fi
