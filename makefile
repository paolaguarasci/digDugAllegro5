CC := g++
CFLAGS := -Wall -std=c++14
LIBS := `pkg-config --libs --libs allegro-5 allegro_acodec-5 allegro_audio-5 allegro_color-5 allegro_dialog-5 allegro_font-5 allegro_image-5 allegro_main-5 allegro_memfile-5 allegro_physfs-5 allegro_primitives-5 allegro_ttf-5`
SOURCES := $(shell find ./src -type f -name "*.cpp")
OBJECTS := $(SOURCES:.cpp=.o)
TARGET := game
 
all: $(SOURCES) $(TARGET)
 
$(TARGET): $(OBJECTS)
	@echo " Linking..."; $(CC) $^ -o $@ $(LIBS)
 
%.o: %.cpp
	@echo " g++ $<"; $(CC) $(CFLAGS) -c -o $@ $<
 
clean:
	@echo " Cleaning..."; $(RM) src/*.o $(TARGET)
 
.PHONY: all clean