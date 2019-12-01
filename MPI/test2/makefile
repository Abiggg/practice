CROSS =
CC = $(CROSS)gcc
CXX = $(CROSS)g++
DEBUG =
CFLAGS = $(DEBUG) -Wall -c
MV = mv -f
RM = rm -rf
LN = ln -sf


TOP_PATH = $(shell pwd)
SRC_PATH = $(TOP_PATH)/
BIN_PATH = $(TOP_PATH)/
LIB_PATH = $(TOP_PATH)/
INC_PATH = $(TOP_PATH)/

SRCS = $(wildcard $(SRC_PATH)*.cpp)

OBJS = $(patsubst %.cpp, %.o, $(SRCS))

DEPS = $($(SRC_PATH)*.o)
LIBS += -lpthread

LIBS +=

VERSION = 1.0.0.0
TARGET = sdk.out

all:$(TARGET)
	@echo "hello"
	@echo $(SRC)
	@echo $(OBJS)
	@echo $(DEPS)

$(TARGET) : $(OBJS)
	$(CXX) $^ -o $@ -L$(LIB_PATH) $(LIBS)

$(OBJS):%.o : %.cpp
	$(CXX) $(CFLAGS) $< -o $@ -I$(INC_PATH)


.PHONY : clean
clean:
	$(RM) $(TARGET) $(OBJS)
