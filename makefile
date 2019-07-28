all: 
	g++ -L/usr/local/lib  -lallegro -lallegro_main -lallegro_font -lallegro_ttf -lallegro_image -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_dialog -lallegro_tiled -std=c++14 main.cpp -o game && ./game

compile: 
	g++ -L/usr/local/lib  -lallegro -lallegro_main -lallegro_font -lallegro_ttf -lallegro_image -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_dialog -lallegro_tiled -std=c++14 main.cpp -o game

clean:
	rm game