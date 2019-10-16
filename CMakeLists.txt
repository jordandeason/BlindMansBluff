cmake_minimum_required(VERSION 3.0)
project(BlindMansBluff)

set(CMAKE_CXX_STANDARD 11)

add_executable(BlindMansBluff main.cpp Card.cpp Card.h Deck.cpp Deck.h)