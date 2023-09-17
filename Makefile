# This should allow us to easily compile our files.

# With the sfml library shit its probably going to be stored in different locations for each of our computers, so we should have seperate make commands.
# I (Ben) used homebrew on mac to download it to a good place. Bellow points to the directories of it on my computer for the complier.



BensVersion: main.cpp
# arch -x86_64 is just for my computer to make it compatible.
# -I"/sfml/include/directory"
# -L"/sfml/library/directory" 
	arch -x86_64 clang++ main.cpp -I"/usr/local/Homebrew/Cellar/sfml/2.6.0/include" -L"/usr/local/Homebrew/Cellar/sfml/2.6.0/lib" -lsfml-graphics -lsfml-window -lsfml-system


KostasVersion: main.cpp
	clang++ main.cpp -I"      " -L"       " -lsfml-graphics -lsfml-window -lsfml-system

JamesVersion: main.cpp
	clang++ main.cpp -I"         " -L"        " -lsfml-graphics -lsfml-window -lsfml-system