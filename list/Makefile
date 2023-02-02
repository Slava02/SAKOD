TARGET = list
CC = g++
CFLAGS = -Wall -Werror -Wextra

all: clean list 

list : 
	$(CC) $(CFLAGS) *.cpp *.h -o $(TARGET)
	./list

clean : 
	rm -f *.o *.log $(TARGET) 


