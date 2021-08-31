#ifndef Player_hpp
#define Player_hpp

#include <vector>
#include <iostream>
#include "Direction.hpp"
#include "Snake.hpp"
#include "Level.hpp"

using namespace std;

class Player{
  private:
    std::vector<Direction> solucoes_labirinto;
  public:

    Direction direcao_proximo_movimento( void );

    bool verificar_direcao_direita(Level level_, Snake cobra_);

    bool verificar_direcao_esquerda(Level level_, Snake cobra_);

    bool verificar_direcao_pra_cima(Level level_, Snake cobra_);

    bool verificar_direcao_pra_baixo(Level level_, Snake cobra_);

    bool procurando_solucao(Level level_, Snake cobra_);
    

};

#endif