CC=gcc
CFLAGS=-I.
M_DEPS = master.h common.h define.h crs.h
M_OBJ = master.o common.o ConexaoRawSocket.o
S_DEPS = slave.h common.h define.h crs.h
S_OBJ = slave.o common.o ConexaoRawSocket.o

%.o: %.c $(M_DEPS) $(S_DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

master: $(M_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

slave: $(S_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o *~
