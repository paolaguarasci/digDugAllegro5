all: 
	g++ -L/usr/local/lib -lallegro -lallegro_main -lallegro_font -lallegro_ttf -lallegro_image -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_tiled -lallegro_dialog -std=c++14 *.cpp

clean:
	rm *.out