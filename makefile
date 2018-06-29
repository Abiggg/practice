CROSS =
CC = $(CROSS)gcc
CXX = $(CROSS)g++
DEBUG =
CFLAGS = $(DEBUG) -Wall -c
MV = mv -f
RM = rm -rf
LN = ln -sf


TOP_PATH = $(shell pwd)
SRC_PATH = $(TOP_PATH)/src/
BIN_PATH = $(TOP_PATH)/bin/
LIB_PATH = $(TOP_PATH)/lib/
INC_PATH = $(TOP_PATH)/include/

SRCS = $(wildcard $(SRC_PATH)*.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
DEPS = $($(SRC_PATH)*.o)
#LIBS += $(LIB_PATH)libconfig.a
LIBS += -lpthread

VERSION = 1.0.0.0
TARGET = sdk.out

all:$(TARGET)
	$(MV) $(TARGET) $(BIN_PATH)
	$(LN) $(BIN_PATH)/$(TARGET) $(BIN_PATH)/sdk

$(TARGET) : $(OBJS)
	$(CC) $^ -o $@ -L$(LIB_PATH) $(LIBS)

$(OBJS):%.o : %.c
	$(CC) $(CFLAGS) $< -o $@ -I$(INC_PATH)


.PHONY : clean
clean:
	$(RM) $(TARGET) $(OBJS)
