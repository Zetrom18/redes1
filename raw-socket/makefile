CC=gcc
CFLAGS=-I.
DEPS = main.h crs.h master.h slave.h
OBJ = main.o ConexaoRawSocket.o master.o slave.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

teste: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
