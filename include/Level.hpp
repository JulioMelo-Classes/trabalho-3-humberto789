#ifndef Level_hpp
#define Level_hpp

#include <vector>
#include <iostream>
#include <map>
#include <random> 

#include "Snake.hpp"
#include "ModoJogo.hpp"
#include "ArrestaGrafo.hpp"
#include "Direction.hpp"

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

    /*! 
      @brief Recupera a quantidade de maçãs ainda restantes no mapa
      @return Retorna inteiro contendo a quantidade de maçãs ainda restantes no mapa
    */
    int get_qtd_macas( void );

    /*! 
      @brief Recupera a quantidade de linhas do mapa
      @return Retorna inteiro contendo a quantidade de linhas do mapa
    */
    int get_qtd_linhas( void );
    
    /*! 
      @brief Recupera a quantidade de colunas do mapa
      @return Retorna inteiro contendo a quantidade de colunas do mapa
    */
    int get_qtd_colunas( void );

    /*! 
      @brief Recupera um enum que indica qual o modo de jogo do level
      @return Retorna enumerator contendo que indica qual o modo de jogo do level
    */
    ModoJogo get_modo_jogo( void );

    /*! 
      @brief Define um enum que indica qual o modo de jogo do level
      @param modo_jogo_ Enumerator que indica qual o modo de jogo do level.
    */
    void set_modo_jogo ( ModoJogo modo_jogo_ );

    /*! 
      @brief Define a quantidade de macas no level
      @param qtd_macas_ Inteiro que indica a quantidade de macas no level
    */
    void set_qtd_macas( int qtd_macas_ );

    /*! 
      @brief Define a quantidade de linhas do mapa
      @param qtd_macas_ Inteiro que indica a quantidade de linhas do mapa
    */
    void set_qtd_linhas ( int qtd_linhas_ );

    /*! 
      @brief Define a quantidade de colunas do mapa
      @param qtd_macas_ Inteiro que indica a quantidade de colunas do mapa
    */
    void set_qtd_colunas (int qtd_colunas_ );

    /*! 
      @brief Gera o mapa do level apartir de um vetor de string contendo as linhas do arquivo.
      @param linhas_ Vetor de string contendo as linhas do arquivo.
      @return Retorna true caso o mapa foi gerado com sucesso e false caso tenha acontecido algum problema.
    */
    bool gerar_mapa( std::vector<std::string> linhas_);

    /*! 
      @brief Exibe o mapa do level.
    */
    void exibir_mapa( void );

    /*! 
      @brief Recupera um par de inteiros que indica a posicao inicial para iniciar no mapa.
      @return Retorna um par de inteiros que indica a posicao inicial para iniciar no mapa.
    */
    std::pair< int, int > get_posicao_inicial( void );

    /*! 
      @brief Define um par de inteiros que indica a posicao inicial para iniciar no mapa.
      @param posicao_inicial_ Um par de inteiros que indica a posicao inicial para iniciar no mapa.
    */
    void set_posicao_inicial( std::pair< int,int >posicao_inicial_);    

    /*! 
      @brief Insere a cobra no mapa.
      @param cobra_ A cobra que será inserida.
    */
    void incluir_cobra_mapa ( Snake cobra_ );

    /*! 
      @brief Retira a cobra no mapa.
      @param cobra_ A cobra que será retirada.
    */
    void excluir_cobra_mapa ( Snake cobra_ );

    /*! 
      @brief Insere uma nova comida no mapa.
      @param cobra_ A cobra que já está no mapa.
    */
    void colocando_comida_mapa ( Snake cobra_ );

    /*! 
      @brief Retira a comida do mapa.
    */
    void excluir_comida_mapa ( void );

    /*! 
      @brief Verifica se a posicao analisada encontrou uma comida.
      @param posicao_analizada Um par de inteiros que indica qual a posicao que será analisada.
      @return Retorna true se a posicao analisada encontrou uma comida e false caso contrario.
    */
    bool verificar_cobra_encontrou_comida (std::pair< int, int > posicao_analizada);

    /*! 
      @brief Verifica se a posicao analisada encontrou um obstaculo.
      @param posicao_analizada Um par de inteiros que indica qual a posicao que será analisada.
      @return Retorna true se a posicao analisada encontrou um obstaculo e false caso contrario.
    */
    bool verificar_cobra_encontrou_obstaculo (std::pair< int, int > posicao_analizada_);

    /*! 
      @brief Movimenta a cobra no mapa recendo uma posicao que será a nova posicao da cabeca.
      @param *cobra_ Ponteiro que aponta a cobra.
      @param movimento_jogada_ Par de inteiros que indica a posicao para onde a cobra irá se movimentar.
    */
    void aplicar_jogada( Snake *cobra_, std::pair< int, int > movimento_jogada_);

    /*! 
      @brief Verifica se o nivel foi vencido.
      @return Retorna true se o nivel foi vencido e false caso contrario.
    */
    bool verificar_venceu_level();

    /*! 
      @brief Verifica se a cobra perdeu nivel.
      @param cobra_ Cobra que será analisada.
      @return Retorna true se a cobra perdeu o nivel e false caso contrario.
    */
    bool verificar_perdeu_level(Snake cobra_);

    /*! 
      @brief Realiza a transformacao da direcao da cabeca da cobra para a proxima posicao que ela irá se movimentar.
      @param cobra_ Cobra que será analisada.
      @return Retorna um par de inteiros contendo a posicao que a cobra irá se movimentar.
    */
    std::pair< int, int > direcao_para_posicao_movimento(Snake cobra_);

    /*! 
      @brief Captura direto do mapa a posicao inicial do nivel.
      @return Retorna um par de inteiros contendo a posicao inicial do nivel.
    */
    std::pair< int, int > capturando_posicao_inicial_do_mapa( void );

    /*! 
      @brief Captura direto do mapa todas as posicoes possiveis e retorna uma  posicao aleatoria que sera utilizada como posicao inicial.
      @return Retorna um par de inteiros contendo a posicao inicial do nivel.
    */
    std::pair< int, int > capturando_posicao_inicial_aleatoria_do_mapa( void );

    /*! 
      @brief Gera um vetor de par de inteiros contendo todas as posicoes que são livres ou que é a cabeça da cobra que seram os vertices possiveis daquele mapa.
      @return Retorna um vetor de par de inteiros contendo todas as posicoes que são livres ou que é a cabeça da cobra que seram os vertices possiveis daquele mapa.
    */
    vector< std::pair<int, int > > gerando_vetor_vertices_mapa();

    /*! 
      @brief Gera um vetor de arrestas contendo todas as arrestas possiveis naquele mapa.
      @return Retorna um vetor de arrestas contendo todas as arrestas possiveis naquele mapa.
    */
    vector< ArrestaGrafo > gerando_arrestas_grafo_mapa();

    /*! 
      @brief Verifica se uma arresta já foi inserida em um vetor de arrestas.
      @param arrestas_ Vetor de arrestas que será analisado.
      @param arresta_analizada Arresta que será analisada.
      @return Retorna true caso a arresta já exista no mapa e false caso contrario.
    */
    bool verificar_arresta_existe(vector< ArrestaGrafo > arrestas_, ArrestaGrafo arresta_analizada);

    /*! 
      @brief Recupera um par de inteiros que indica a posicao da comida para iniciar no mapa.
      @return Retorna um par de inteiros que indica a posicao da comida para iniciar no mapa.
    */
    std::pair< int, int > get_posicao_comida();

    /*! 
      @brief Recupera um enum Direction que inidica qual a direcao que será a direção inicial da cobra.
      @return Retorna um enum Direction que inidica qual a direcao que será a direção inicial da cobra.
    */
    Direction gerando_uma_direcao_inicial_cobra_possivel( void );
};

#endif