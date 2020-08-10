CC=gcc
LD=ld

SRC_FOLDER=src/
SRC_FILES=$(wildcard $(SRC_FOLDER)*.c)

INCLUDES= -I$(SRC_FOLDER)

OBJECTS=$(foreach c_file, $(SRC_FILES), $(c_file:.c=.o))

OUTPUT=output/

HEX_FILE=main.hex

default: $(HEX_FILE)

clean:
	rm -rf $(SRC_FOLDER)*o *hex

%.o : %.c
	$(CC) $(INCLUDES) -c $< -o $@

$(HEX_FILE): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)
