supercrash9000: main.o mainmenu.o supercrash.o superengine.o supergame.o supermenu.o
	g++ -o supercrash9000 main.o mainmenu.o supercrash.o superengine.o supergame.o supermenu.o -IGL -lglut
main.o: main.cpp
	g++ -c -o main.o main.cpp
mainmenu.o: MainMenu.cpp
	g++ -c -o mainmenu.o MainMenu.cpp
supercrash.o: SuperCrash.cpp
	g++ -c -o supercrash.o SuperCrash.cpp
superengine.o: SuperEngine.cpp
	g++ -c -o superengine.o SuperEngine.cpp
supergame.o: SuperGame.cpp
	g++ -c -o supergame.o SuperGame.cpp
supermenu.o: SuperMenu.cpp
	g++ -c -o supermenu.o SuperMenu.cpp
clean:
	rm main.o mainmenu.o supercrash.o superengine.o supergame.o supermenu.o supercrash9000
