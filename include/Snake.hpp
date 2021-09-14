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
    /*! 
      @brief Recupera a quantidade de vidas
      @return Retorna um inteiro com a quantidade de vidas
    */
    int get_vidas( void );
    
    /*! 
      @brief Define a quantidade de vidas
      @param vidas_ um inteiro com a quantidade de vidas
    */
    void set_vidas( int vidas_);

    /*! 
      @brief Recupera a quantidade de comidas
      @return Retorna um inteiro com a quantidade de comidas
    */
    int get_qtd_comida ( void );

    /*! 
      @brief Recupera o tamanho da Snake
      @return Retorna um inteiro com a o tamanho da Snake
    */
    int get_tamanho ( void );

    /*! 
      @brief Recupera a direção que a cobra está olhando
      @return Retorna um enum contendo a direção que a cobra está olhando
    */
    Direction get_direcao_cabeca ( void );

    /*! 
      @brief Define a direção que a cobra está olhando
      @param direcao_cabeca_ enum contendo a direção da cabeça da cobra
    */    
    void set_direcao_cabeca ( Direction direcao_cabeca_);

    /*! 
      @brief Define a quantidade de comidas da cobra
      @param qtd_comida_ um inteiro com a quantidade de comidas da cobra
    */
    void set_qtd_comida ( int qtd_comida_ );

    /*! 
      @brief Insere dentro do array posicao_corpo um pair da nova posição do corpo 
      @param posicao_ pair cotendo as coordenadas da cobra
    */
    void incluir_nova_posicao_corpo (std::pair< int, int> posicao_);

    /*! 
      @brief Verifica se o corpo está na posição informada
      @param posicao_ um pair contendo as coordenadas para fazer a verificação
      @return True caso a posição informada corresponda com a posição do corpo, caso contrario retorna False
    */
    bool verifica_corpo_na_posicao (std::pair< int, int > posicao_);

    /*! 
      @brief Recupera a posição da cabeça da cobra
      @return um par contendo a coordenada da cabeça da cobra
    */
    std::pair< int, int > get_cabeca ( void );

    /*! 
      @brief Aumenta o tamanho da cobra ao comer uma maçã
      @param posicao_ Posição onde a comida foi encontrada
    */
    void aumentando_cobra (std::pair< int, int > posicao_);

    /*! 
      @brief Movimenta o corpo no maze
      @param posicao_ um pair contendo as coordenadas para onde a cobra deve andar
    */
    void movendo_cobra( std::pair< int, int > posicao_ );

    /*! 
      @brief Reseta as estatisticas da cobra para o padrão
      @param pos_cabeca Posição da cabeça inicial da cabeça
      @param direcao_cabeca Uma posição gerada e valida para a direção da cabeça
    */
    void resetar_cobra(std::pair< int, int > pos_cabeca, Direction direcao_cabeca);
};

#endif