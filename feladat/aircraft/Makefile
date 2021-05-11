all:
	gcc -Iinclude/ src/skybox.c src/texture.c src/object.c src/obj/draw.c src/obj/info.c src/obj/load.c src/obj/model.c src/obj/transform.c src/callbacks.c src/camera.c src/init.c src/main.c src/scene.c src/utils.c -lSOIL -lopengl32 -lglu32 -lglut32 -lm -o aircraft.exe -Wall -Wextra -Wpedantic

linux:
	gcc -Iinclude/ src/skybox.c src/texture.c src/object.c src/obj/draw.c src/obj/info.c src/obj/load.c src/obj/model.c src/obj/transform.c src/callbacks.c src/camera.c src/init.c src/main.c src/scene.c src/utils.c -lSOIL -lGL -lGLU -lglut -lm -o aircraft.exe -Wall -Wextra -Wpedantic
	
