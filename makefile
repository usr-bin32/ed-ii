# este makefile só deve funcionar no Linux
start:
	g++ ./src/*.cpp ./src/*/*.cpp -o ./project.out -Ofast
