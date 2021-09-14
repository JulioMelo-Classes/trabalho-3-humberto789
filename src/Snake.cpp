#include "Snake.hpp"

int Snake::get_vidas( void ){
  return vidas;
}
    
void Snake::set_vidas( int vidas_){
  vidas = vidas_;
}

int Snake::get_tamanho ( void ){
  return posicao_corpo.size();
}

Direction Snake::get_direcao_cabeca ( void ){
  return direcao_cabeca;
}
    
void Snake::set_direcao_cabeca ( Direction direcao_cabeca_){
  direcao_cabeca = direcao_cabeca_;
}

int Snake::get_qtd_comida ( void ){
  return qtd_comida;
}

void Snake::set_qtd_comida ( int qtd_comida_ ){
  qtd_comida = qtd_comida_;
}

void Snake::incluir_nova_posicao_corpo (std::pair< int, int> posicao_){
  posicao_corpo.push_back(posicao_);
}

std::pair< int, int > Snake::get_cabeca ( void ) {
  return posicao_corpo[0];
}

bool Snake::verifica_corpo_na_posicao (std::pair< int, int > posicao_){
  for(std::pair< int, int> pos : posicao_corpo){
    if(pos.first == posicao_.first && pos.second == posicao_.second){
      return true;
    }
  }
  return false;
}

void Snake::aumentando_cobra (std::pair< int, int > posicao_){
  std::vector< std::pair< int, int > > pos_aux = posicao_corpo;

  int j = 0;
  for(int i = 0; i<posicao_corpo.size();i++){
    if(i == 0){
      posicao_corpo[i] = posicao_;
    }else{
      posicao_corpo[i] = pos_aux[j];
      j++;
    }
  }
  qtd_comida++;
  posicao_corpo.push_back(pos_aux[j]);
}

void Snake::movendo_cobra( std::pair< int, int > posicao_ ){
  std::vector< std::pair< int, int > > pos_aux = posicao_corpo;

  int j = 0;
  for(int i = 0; i<posicao_corpo.size();i++){
    if(i == 0){
      posicao_corpo[i] = posicao_;
    }else{
      posicao_corpo[i] = pos_aux[j];
      j++;
    }
  }
}

void Snake::resetar_cobra(std::pair< int, int > pos_cabeca, Direction direcao_cabeca){
  posicao_corpo.clear();
  qtd_comida = 0;
  posicao_corpo.push_back(pos_cabeca);
  direcao_cabeca = direcao_cabeca;
}
