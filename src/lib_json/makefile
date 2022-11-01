# make .a && .so file

STATIC = 0

INC_FLAGS := -I../../include/json -I../../include
CC := gcc
CXX := /project/public/linaro-aarch64-2020.09-gcc10.2-linux5.4/bin/aarch64-linux-gnu-g++
AR = /project/public/linaro-aarch64-2020.09-gcc10.2-linux5.4/bin/aarch64-linux-gnu-ar
ARFLAGS = -rc
CFLAGS := -c -Wall #-std=c++11
LFLAGS := -Wall

#TARGET = libfunc

ifeq ($(STATIC), 1)
	TARGET = libjsoncpp.a
else
	TARGET = libjsoncpp.so
	CFLAGS += -fPIC
endif

CFLAGS += -O3 -Wall $(INC_FLAGS)

SOURCE_DIR := .
OBJS = $(patsubst %.cpp, %.o, $(wildcard $(SOURCE_DIR)/*.cpp))

.PHONY : clean all

all: $(TARGET)

ifeq ($(STATIC), 1)
$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
	#cp $(TARGET) ../lib
	#@rm $(TARGET)
else
$(TARGET): $(OBJS)
	$(CXX) $(LFLAGS) -shared $^ -o $@
	#cp $(TARGET) ../lib
	#@rm $(TARGET)
endif

$(OBJS):%.o:%.cpp
	$(CXX) $(CFLAGS) $< -o $@
	
clean: 
	-rm -f *.o ../lib/*
