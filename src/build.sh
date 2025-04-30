BRIGHT_GREEN='\033[1;92m'
NC='\033[0m'

echo -n "🛠️ Compilation en cours"
for i in {1..10}; do
    echo -ne "${BRIGHT_GREEN}▓${NC}"
    sleep 0.1
done

echo
if gcc main.c cc2d_graphics.c cc2d_font.c cc2d_keyboard.c -Iinclude -Llib -lSDL2 -lSDL2_image -lSDL2_ttf -o monprog 
then 

echo -e "\a"
echo "✅ Compilation terminée !"
echo "🚀 Lancement du programme !"
echo
echo
./monprog

else
echo -e "\a"
echo "🙊 Compilation impossible..."
echo

exit 1

fi
