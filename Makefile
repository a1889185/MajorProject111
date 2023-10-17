# This should allow us to easily compile our files.

BensVersion: main.cpp Entity.cpp NonMoveableEntity.cpp MoveableEntity.cpp Player.cpp Enemy.cpp Map.cpp HUD.cpp GameMenu.cpp
# arch -x86_64 is just for my computer to make it compatible.
# -I"/sfml/include/directory"
# -L"/sfml/library/directory" 
	arch -x86_64 clang++ main.cpp Entity.cpp NonMoveableEntity.cpp MoveableEntity.cpp Player.cpp Enemy.cpp Map.cpp HUD.cpp GameMenu.cpp \
	\-o main \
	\-I"/usr/local/Homebrew/Cellar/sfml/2.6.0/include" -L"/usr/local/Homebrew/Cellar/sfml/2.6.0/lib" -lsfml-graphics -lsfml-window -lsfml-system; \
	\./main; \

RunBensVersion:main
	arch -x86_64 ./main

KostasVersion: main.cpp Entity.cpp NonMoveableEntity.cpp MoveableEntity.cpp Player.cpp Map.cpp Enemy.cpp HUD.cpp GameMenu.cpp

	clang++ main.cpp Entity.cpp NonMoveableEntity.cpp MoveableEntity.cpp Player.cpp Map.cpp Enemy.cpp HUD.cpp GameMenu.cpp \
	\-o main \
	\-I"/opt/homebrew/Cellar/sfml/2.6.0/include" -L"/opt/homebrew/Cellar/sfml/2.6.0/lib" -lsfml-graphics -lsfml-window -lsfml-system; \
	\./main; \

JamesVersion: main.cpp Entity.cpp NonMoveableEntity.cpp MoveableEntity.cpp Player.cpp Map.cpp Enemy.cpp HUD.cpp GameMenu.cpp

	clang++ main.cpp Entity.cpp NonMoveableEntity.cpp MoveableEntity.cpp Player.cpp Map.cpp Enemy.cpp HUD.cpp GameMenu.cpp \
	\-o main \
	\-I"/usr/local/Cellar/sfml/2.6.0/include" -L"/usr/local/Cellar/sfml/2.6.0/lib" -lsfml-graphics -lsfml-window -lsfml-system; \
	\./main; \