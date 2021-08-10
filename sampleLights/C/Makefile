CC=gcc 			
CFLAGS= -g -Wall -Wpedantic -Wextra  -Werror -Wuninitialized -fsanitize=address
LIBS= -lm	    
TARGET= lights

sourceFILES = debuggingLights.cpp
#headerFILES = $(wildcard *.c)
objectFiles = $(wildcard *.o)



.phony: all
all:  $(TARGET)

$(TARGET):$(objectFiles)
	$(CC) $(CFLAGS) -o $(TARGET) $(sourceFILES) $(LIBS)

test.o: debuggingLights.cpp
	$(CC) -c $(CFLAGS) -o test.o debuggingLights.cpp


#$(CC) -o $(TARGET) $(objectFiles)

.PHONY : clean
clean:
	-rm $(TARGET) $(objectFiles)
