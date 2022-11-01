
CFLAGS = -O2 -Wall -std=c++11
#-fopenmp -mfpu=neon-vfpv4
#-D_GLIBCXX_USE_CXX11_ABI=0

CC := g++

INC_FLAGS := -I./include/json -I./include -I./

LINK_LIBS := -L./
LINK_LIBS += -ljsoncpp

CFLAGS += $(INC_FLAGS)

#SRCPP := $(wildcard *.cpp) #$(wildcard ./src/lib_json/*.cpp)
SRCPP := $(wildcard track_param.cpp)

OBJCPP := $(SRCPP:%.cpp=%.o)

.PHONY : clean all

TARGET := main

all: $(TARGET)

$(TARGET): $(OBJCPP)
	#arm-himix200-linux-g++ $(CFLAGS) -o $@ $^ -L./lib/ -ldlib -lopencv_world -ljasper -ljpeg-turbo -lpng -ltiff -lwebp -lIlmImf -lzlib -lsecurec -ldl -lm -lpthread -lstdc++
	$(CC) $(CFLAGS) -o $@ $^ $(LINK_LIBS) -ldl -lm -lpthread
	#$(CC) $(CFLAGS) -o $@ $^ -ldl -lm -lpthread

$(OBJCPP): %.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $< -lpthread -lm -ldl

clean:
	@rm -f $(TARGET)
	@rm -f $(OBJ)
	@rm -f $(OBJCPP)
