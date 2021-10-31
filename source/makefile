LIBS=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

all: starship

asteroid.o: asteroid.cpp
	g++ -c "asteroid.cpp" -o asteroid.o

background.o: background.cpp
	g++ -c "background.cpp" -o background.o
	
player.o: player.cpp
	g++ -c "player.cpp" -o player.o

bullet.o: bullet.cpp
	g++ -c "bullet.cpp" -o bullet.o

boss.o: boss.cpp
	g++ -c "boss.cpp" -o boss.o

collision.o: collision.cpp
	g++ -c "collision.cpp" -o collision.o

items.o: items.cpp
	g++ -c "items.cpp" -o items.o

HUD.o: HUD.cpp
	g++ -c "HUD.cpp" -o HUD.o

menu.o: menu.cpp
	g++ -c "menu.cpp" -o menu.o

sfx.o: sfx.cpp
	g++ -c "sfx.cpp" -o sfx.o

main.o: main.cpp
	g++ -c "main.cpp" -o main.o

starship: asteroid.o background.o player.o bullet.o boss.o collision.o items.o HUD.o menu.o sfx.o main.o
	@echo "Entering OUTER SPACE"
	g++ -o starship_meltdown asteroid.o background.o player.o bullet.o boss.o collision.o items.o HUD.o menu.o sfx.o main.o $(LIBS)

clean:
	@echo "Exiting the galaxy"
	rm -f starship *.o
