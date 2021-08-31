#ifndef Snake_hpp
#define Snake_hpp

#include <vector>
#include <iostream>
#include "Direction.hpp"

using namespace std;

class Snake{
  private:
    int vidas;
    int qtd_comida;
    //Primeira chave é X e a segunda é Y
    std::vector< std::pair< int, int > > posicao_corpo;
    Direction direcao_cabeca;

  public:
    int get_vidas( void );
    
    void set_vidas( int vidas_);

    int get_qtd_comida ( void );

    int get_tamanho ( void );

    Direction get_direcao_cabeca ( void );
    
    void set_direcao_cabeca ( Direction direcao_cabeca_);

    void set_qtd_comida ( int qtd_comida_ );
    
    void incluir_nova_posicao_corpo (std::pair< int, int> posicao_);

    bool verifica_corpo_na_posicao (std::pair< int, int > posicao_);

    std::pair< int, int > get_cabeca ( void );

    void aumentando_cobra (std::pair< int, int > posicao_);

    void movendo_cobra( std::pair< int, int > posicao_ );

    void resetar_cobra(std::pair< int, int > pos_cabeca);
};

#endif