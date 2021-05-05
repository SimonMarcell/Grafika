all:
	gcc -Iinclude/ src/callbacks.c src/camera.c src/init.c src/main.c src/scene.c src/utils.c -lopengl32 -lglu32 -lglut32 -lm -o helicopter.exe -Wall -Wextra -Wpedantic

linux:
	gcc -Iinclude/ src/callbacks.c src/camera.c src/init.c src/main.c src/scene.c src/utils.c -lGL -lGLU -lglut -lm -o helicopter.exe -Wall -Wextra -Wpedantic
	
