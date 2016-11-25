cmake_minimum_required(VERSION 3.4)
project(c-multihash)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -g -O2 -std=c99 \
	-Wall -Wextra" )

include_directories(include)

set(SOURCE_FILES 
	src/hashes.c
	src/errors.c
	src/multihash.c
	src/base64.c
	src/dec.c
	src/hex.c
	src/operations.c
	src/main.c)

add_executable(c-multihash ${SOURCE_FILES})
