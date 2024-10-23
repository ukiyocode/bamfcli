CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lbamf3
INCLUDE_DIRS = -I/usr/include/libbamf3\
               -I/usr/lib/x86_64-linux-gnu/libbamf3/include\
               -I/usr/include/glib-2.0\
               -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
               
TARGET = bamfcli

all: $(TARGET)

$(TARGET): bamfcli.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $(TARGET) bamfcli.c $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
