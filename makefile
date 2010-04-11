supercrash9000: main.o mainmenu.o supercrash.o superengine.o supergame.o supermenu.o map.o mappoint.o mapside.o highscore.o pausemenu.o
	g++ -o supercrash9000 main.o mainmenu.o supercrash.o superengine.o supergame.o supermenu.o map.o mappoint.o mapside.o highscore.o pausemenu.o -lglut
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
map.o: Map.cpp
	g++ -c -o map.o Map.cpp
mappoint.o: MapPoint.cpp
	g++ -c -o mappoint.o MapPoint.cpp
mapside.o: MapSide.cpp
	g++ -c -o mapside.o MapSide.cpp
highscore.o: HighScore.cpp
	g++ -c -o highscore.o HighScore.cpp
pausemenu.o: PauseMenu.cpp
	g++ -c -o pausemenu.o PauseMenu.cpp
clean:
	rm main.o mainmenu.o supercrash.o superengine.o supergame.o supermenu.o map.o mappoint.o mapside.o highscore.o pausemenu.o supercrash9000
