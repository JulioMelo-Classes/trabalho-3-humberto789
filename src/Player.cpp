#include "Player.hpp"



Direction Player::direcao_proximo_movimento( void ){

  int id_direcao = rand()%solucoes_labirinto.size();

  for(int i = 0; i<solucoes_labirinto.size(); i++){
    if(i == id_direcao){
      return solucoes_labirinto[i];
    }
  }
  Direction direcao;
  return direcao;
}

bool Player::verificar_direcao_direita(Level level_, Snake cobra_){
  std::pair< int, int > pos_movimento = cobra_.get_cabeca();

  //Movimento para a direita
  pos_movimento.first = pos_movimento.first + 1;

  if(level_.verificar_cobra_encontrou_obstaculo(pos_movimento)){
    return false;
  }
  return true;
}

bool Player::verificar_direcao_esquerda(Level level_, Snake cobra_){
  std::pair< int, int > pos_movimento = cobra_.get_cabeca();

  //Movimento para a esquerda
  pos_movimento.first = pos_movimento.first - 1;

  if(level_.verificar_cobra_encontrou_obstaculo(pos_movimento)){
    return false;
  }
  return true;
}

bool Player::verificar_direcao_pra_cima(Level level_, Snake cobra_){
  std::pair< int, int > pos_movimento = cobra_.get_cabeca();

  //Movimento para cima
  pos_movimento.second = pos_movimento.second - 1;

  if(level_.verificar_cobra_encontrou_obstaculo(pos_movimento)){
    return false;
  }
  return true;
}

bool Player::verificar_direcao_pra_baixo(Level level_, Snake cobra_){
  std::pair< int, int > pos_movimento = cobra_.get_cabeca();

  //Movimento para baixo
  pos_movimento.second = pos_movimento.second + 1;

  if(level_.verificar_cobra_encontrou_obstaculo(pos_movimento)){
    return false;
  }
  return true;
}

bool Player::procurando_solucao(Level level_, Snake cobra_){
  Direction direcao_atual = cobra_.get_direcao_cabeca();
  solucoes_labirinto.clear();
  int contador_solucoes = 0;
  //Se for Direita => Só pode se movimentar para ( cima, direita, baixo )
  if(((int)direcao_atual)==1){
    if(verificar_direcao_pra_cima(level_, cobra_)){
      direcao_atual = Direction::CIMA;
      solucoes_labirinto.push_back(direcao_atual);
      contador_solucoes++;
    }
    if(verificar_direcao_direita(level_, cobra_)){
      solucoes_labirinto.push_back(direcao_atual);
      contador_solucoes++;
    }
    if(verificar_direcao_pra_baixo(level_, cobra_)){
      direcao_atual = Direction::BAIXO;
      solucoes_labirinto.push_back(direcao_atual);
      contador_solucoes++;
    }
  }
  //Se for CIMA => Só pode se movimentar para ( cima, direita, esquerda )
  else if(((int)direcao_atual)==2){
    if(verificar_direcao_pra_cima(level_, cobra_)){
      solucoes_labirinto.push_back(direcao_atual);
      contador_solucoes++;
    }
    if(verificar_direcao_direita(level_, cobra_)){
      direcao_atual = Direction::DIREITA;
      solucoes_labirinto.push_back(direcao_atual);
      contador_solucoes++;
    }
    if(verificar_direcao_esquerda(level_, cobra_)){
      direcao_atual = Direction::ESQUERDA;
      solucoes_labirinto.push_back(direcao_atual);
      contador_solucoes++;
    }
  }
  //Se for ESQUERDA => Só pode se movimentar para ( esquerda, cima, baixo )
  else if(((int)direcao_atual)==3){
    if(verificar_direcao_pra_cima(level_, cobra_)){
      direcao_atual = Direction::CIMA;
      solucoes_labirinto.push_back(direcao_atual);
      contador_solucoes++;
    }
    if(verificar_direcao_esquerda(level_, cobra_)){
      solucoes_labirinto.push_back(direcao_atual);
      contador_solucoes++;
    }
    if(verificar_direcao_pra_baixo(level_, cobra_)){
      direcao_atual = Direction::BAIXO;
      solucoes_labirinto.push_back(direcao_atual);
      contador_solucoes++;
    }
  }
  //Se for BAIXO => Só pode se movimentar para ( baixo, esquerda, direita )
  else if(((int)direcao_atual)==4){
    if(verificar_direcao_pra_baixo(level_, cobra_)){
      solucoes_labirinto.push_back(direcao_atual);
      contador_solucoes++;
    }
    if(verificar_direcao_esquerda(level_, cobra_)){
      direcao_atual = Direction::ESQUERDA;
      solucoes_labirinto.push_back(direcao_atual);
      contador_solucoes++;
    }
    if(verificar_direcao_direita(level_, cobra_)){
      direcao_atual = Direction::DIREITA;
      solucoes_labirinto.push_back(direcao_atual);
      contador_solucoes++;
    }
  }
  if(contador_solucoes!=0){
    return true;
  }
  return false;
}
