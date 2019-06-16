cmake_minimum_required(VERSION 3.10)
project(raw_socket C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(raw_socket
        common.c
        common.h
        ConexaoRawSocket.c
        crs.h
        master.c
        master.h
        messenger.c
        messenger.h
#        slave.c
#        slave.h
#        tmp.c)
        )