CC=gcc
CFLAGS=-I.
M_DEPS = master.h common.h crs.h messenger.h crc.h
M_OBJ = master.o common.o ConexaoRawSocket.o messenger.o crc.o
S_DEPS = slave.h common.h crs.h messenger.h crc.h
S_OBJ = slave.o common.o ConexaoRawSocket.o messenger.o crc.o

%.o: %.c $(M_DEPS) $(S_DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

master: $(M_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

slave: $(S_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o *~
