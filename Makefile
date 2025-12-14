CC ?= gcc
AR ?= ar
RM ?= rm -f

NAME := rimia
SRC := rimia.c
OBJ := $(SRC:.c=.o)

ifeq ($(OBJ),Windows_NT)
	TARGET := $(NAME).dll
	CFLAGS += -O2
	LDFLAGS += -shared
	EXPORTS :=
	PIC :=
	LIBNAME :=
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		TARGET := lib$(NAME).dylib
		CFLAGS += -O2 -fPIC
		LDFLAGS += -dynamiclib
	else
		TARGET := lib$(NAME).so
		CFLAGS += -O2 -fPIC
		LDFLAGS += -shared
	endif
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(TARGET)

.PHONY: all clean
