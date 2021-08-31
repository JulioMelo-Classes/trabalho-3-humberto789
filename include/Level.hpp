#ifndef Level_hpp
#define Level_hpp

#include <vector>
#include <iostream>
#include <map>

#include "Snake.hpp"
#include "ModoJogo.hpp"
#include <random> 


using namespace std;

class Level{
  private:
    int qtd_colunas;
    int qtd_linhas;
    int qtd_macas;
    map<std::pair<int, int>, char > mapa;
    std::pair< int, int> posicao_inicial;
    ModoJogo modo_jogo;
  public:
    int get_qtd_macas( void );

    int get_qtd_linhas( void );
    
    int get_qtd_colunas( void );

    ModoJogo get_modo_jogo( void );

    void set_modo_jogo ( ModoJogo modo_jogo_ );

    void set_qtd_macas( int qtd_macas_ );

    void set_qtd_linhas ( int qtd_linhas_ );

    void set_qtd_colunas (int qtd_colunas_ );

    bool gerar_mapa( std::vector<std::string> linhas_);

    void exibir_mapa( void );

    std::pair< int, int > get_posicao_inicial( void );

    void set_posicao_inicial( std::pair< int,int >posicao_inicial_);    
    
    void incluir_cobra_mapa ( Snake cobra_ );

    void excluir_cobra_mapa ( Snake cobra_ );

    void colocando_comida_mapa ( Snake cobra_ );

    void excluir_comida_mapa ( void );

    bool verificar_cobra_encontrou_comida (std::pair< int, int > posicao_analizada);

    bool verificar_cobra_encontrou_obstaculo (std::pair< int, int > posicao_analizada_);

    void aplicar_jogada( Snake *cobra_, std::pair< int, int > movimento_jogada_);

    bool verificar_venceu_level();

    bool verificar_perdeu_level(Snake cobra_);

    std::pair< int, int > direcao_para_posicao_movimento(Snake cobra_);

    std::pair< int, int > capturando_posicao_inicial_do_mapa( void );
};

#endif