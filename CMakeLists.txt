cmake_minimum_required(VERSION 3.5)
project(Snaze VERSION 0.1 LANGUAGES CXX )


set ( CMAKE_CXX_FLAGS "-Wall -fsanitize=address" )
set (CMAKE_CXX_STANDARD 14)

#Diretório contendo os .hpp
include_directories( include )

#Executavel
add_executable( Snaze
                src/Level.cpp
                src/Snaze.cpp 
								src/Player.cpp 
								src/Servicos.cpp 
								src/Snake.cpp 
								src/SnakeGame.cpp 
                )

# The end