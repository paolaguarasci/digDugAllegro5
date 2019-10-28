#g++-9 -I/usr/local/Cellar/allegro/HEAD-25de4fa/include -L/usr/local/Cellar/allegro/HEAD-25de4fa/lib -lallegro_image -lallegro_main -lallegro *.cpp
#g++ -I/usr/local/Cellar/allegro/HEAD-25de4fa/include -L/usr/local/Cellar/allegro/HEAD-25de4fa/lib -lallegro_image -lallegro_main -lallegro *.cpp

OS := $(shell uname -s)
ifeq ($(OS), Darwin) 
	CC := g++-9
endif
ifeq ($(OS), Linux) 
	CC := g++
endif

# Su Mac e' un alias per clang, su linux e' proprio g++, va usato questo
# CC := g++
# g++
# CC := g++-9

CFLAGS := -Wall -std=c++14 -g `pkg-config --cflags allegro-5 allegro_acodec-5 allegro_audio-5 allegro_color-5 allegro_dialog-5 allegro_font-5 allegro_image-5 allegro_main-5 allegro_memfile-5 allegro_physfs-5 allegro_primitives-5 allegro_ttf-5`
LIBS := `pkg-config --libs allegro-5 allegro_acodec-5 allegro_audio-5 allegro_color-5 allegro_dialog-5 allegro_font-5 allegro_image-5 allegro_main-5 allegro_memfile-5 allegro_physfs-5 allegro_primitives-5 allegro_ttf-5`
SOURCES := $(shell find ./src -type f -name "*.cpp")
OBJECTS := $(SOURCES:.cpp=.o)
TARGET := game
 
all: $(SOURCES) $(TARGET)
 
$(TARGET): $(OBJECTS)
	@echo " Linking..."; $(CC) $^ $(LIBS) -o $@
 
%.o: %.cpp
	@echo " $(CC) $<"; $(CC) $(CFLAGS) -c -o $@ $<
 
clean:
	@echo " Cleaning..."; $(RM) src/*.o $(TARGET)
 
.PHONY: all clean