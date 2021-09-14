#include <iostream>
#include "SnakeGame.hpp"

using namespace std;

int main(int argc, char *argv[]){

  srand(time(NULL));

  if(argc==1){
    SnakeGame game;
    game.loop();
  }else if(argc==2){
    SnakeGame game(argv[1]);
    game.loop();
  }else if(argc==3){
    SnakeGame game(argv[1], argv[2]);
    game.loop();
  }else if(argc==4){
    SnakeGame game(argv[1], argv[2], argv[3]);
    game.loop();
  }else{
    SnakeGame game(argv[1], argv[2], argv[3], argv[4]);
    game.loop();
  }

  return 0;
}
