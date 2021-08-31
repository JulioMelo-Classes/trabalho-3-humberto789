#include <iostream>
#include "SnakeGame.hpp"

using namespace std;

int main(int argc, char *argv[]){

  srand(time(NULL));

  SnakeGame game(argv[1], argv[2]);

  game.loop(); //bloqueia aqui e só saí quando o jogo termina

    return 0;
}
