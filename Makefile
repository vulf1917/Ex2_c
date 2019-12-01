
# -*- MakeFile -*-
# made by simon pikalov


#variabeles
CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB_ONE=myBank.o
FLAGS= -Wall -g


#mak all the programs
all: myBanks mains

# static library
myBanks: $(OBJECTS_LIB_ONE)
	$(AR) -rcs libmyBank.a $(OBJECTS_LIB_ONE)


#main linked to static lib
mains: $(OBJECTS_MAIN) libmyBank.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a


myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -fPIC -c myBank.c

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all myBanks

clean:
	rm -f *.o *.a *.so mains maind
