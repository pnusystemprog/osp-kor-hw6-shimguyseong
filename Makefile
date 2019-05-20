CC      = /usr/bin/gcc
CFLAGS  = -W -Wall
OBJECTS = phoneBookMain.o register.o search.o delete.o

TARGET  = phoneBook
RM      = rm -rf

.SUFFIXES : .c .o

$(TARGET) : $(OBJECTS)
        $(CC) $(CFLAGS) $^ -o $@

.c .o :
        $(CC) $(CFLAGS) -c $<

clean :
        $(RM) $(OBJECTS) $(TARGET)
