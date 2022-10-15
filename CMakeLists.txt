cmake_minimum_required(VERSION 3.16)
project(ft_ping C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

add_executable(ft_ping
        srcs/main.c srcs/params/help.c srcs/parsing/handle_params.c srcs/memory/memory.c srcs/errors/errors.c includes/ft_ping.h includes/structures.h includes/definitions.h srcs/handlers/int_handler.c srcs/utils/utils.c includes/loop.h srcs/network/checksum.c srcs/network/dns.c srcs/network/sockets.c srcs/ft_ping.c)
