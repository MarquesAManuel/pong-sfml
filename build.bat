:: Compilo código objeto
g++ -c main.cpp -I"C:\mingw64\SFML-2.5.1\include"

:: Compilo el Binario
g++ main.o -o pong -L"C:\mingw64\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system

:: Limpio los códigos objeto
DEL .\*.o

:: Ejecuto el binario:
pong.exe

