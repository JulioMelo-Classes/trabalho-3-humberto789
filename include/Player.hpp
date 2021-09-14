#ifndef Player_hpp
#define Player_hpp

#include <vector>
#include <iostream>
#include "Direction.hpp"
#include "Snake.hpp"
#include "Level.hpp"
#include "ArrestaGrafo.hpp"

using namespace std;

class Player{
  private:
    std::vector<Direction> solucoes_labirinto;
    std::vector<Direction> solucoes_labirinto_randomico;
    map <std::pair<int, int>, bool > visitados;
    int contador_jogada;

  public:


    /*! 
      @brief Recupera a direção da próxima jogada
      @return Enum contendo a direção a ser jogada
    */
    Direction direcao_proximo_movimento( void );

    /*! 
      @brief Encontra uma direção aleatoria que não levará a morte
      @return Enum contendo a direção a ser jogada
    */
    Direction direcao_proximo_movimento_randomica( void );

    /*! 
      @brief Verifica se é possivel ir em direção à direita
      @param level_ Nivel atual
      @param cobra_ A cobra que está em execução
      @return True caso seja possível ir para direita, e False caso tenha algum obstaculo
    */
    bool verificar_direcao_direita(Level level_, Snake cobra_);

    /*! 
      @brief Verifica se é possivel ir em direção à esquerda
      @param level_ Nivel atual
      @param cobra_ A cobra que está em execução
      @return True caso seja possível ir para esquerda, e False caso tenha algum obstaculo
    */
    bool verificar_direcao_esquerda(Level level_, Snake cobra_);

    /*! 
      @brief Verifica se é possivel ir para cima
      @param level_ Nivel atual
      @param cobra_ A cobra que está em execução
      @return True caso seja possível ir para cima, e False caso tenha algum obstaculo
    */
    bool verificar_direcao_pra_cima(Level level_, Snake cobra_);

    /*! 
      @brief Verifica se é possivel ir para baixo
      @param level_ Nivel atual
      @param cobra_ A cobra que está em execução
      @return True caso seja possível ir para baixo, e False caso tenha algum obstaculo
    */
    bool verificar_direcao_pra_baixo(Level level_, Snake cobra_);


    /*! 
      @brief Verifica se é possivel ir para alguma direção
      @param level_ Nivel atual
      @param cobra_ A cobra que está em execução
      @return True caso haja pelo menos uma solução possivel e False se não houver nenhuma solução
    */
    bool procurando_solucao_randomica(Level level_, Snake cobra_);

    /*! 
      @brief Procura uma solução com uso de busca em profundidade
      @param level_ Nivel atual
      @param cobra_ A cobra que está em execução
      @return True caso haja pelo menos uma solução possivel e False se não houver nenhuma solução
    */
    bool procurando_solucao(Level level_, Snake cobra_);
    
    /*! 
      @brief Gera um map contendo os vertices e todos os seus vizinhos
      @param arrestas Vetor contendo todas as arrestas
      @param vertices Vetor de pares contendo todos os vertices
      @return Retorna um Map contendo um par e um vetor de par, onde o par é o vertice e o vetor de par é os vizinhos desse vertice
    */
    map < std::pair<int, int>, vector< std::pair< int, int > > > gerar_map_vertices_vizinhos( vector< ArrestaGrafo > arrestas, vector <std::pair<int, int>> vertices );


    /*! 
      @brief Realiza o calculo da busca em profundadidade, armazenando no array arrestas_resultado todas as arrestas que fazem parte da solução, sendo do tipo 0 que é a ida a solução, como no tipo 1 que é voltando porque encontrar um caminho errado.
      @param vertices Vetor de pares contendo todos os vertices
      @param arrestas Vetor contendo todas as arrestas
      @param inicio Par que determina a posicao de inicio do labirinto.
      @param destino Par que determina a posição final do labirinto, a posição que queremos encontrar.
      @param *arrestas_resultado Ponteiro que aponta para o vetor de arrestas que conterá o resultado do calculo de busca em profundadidade contendo todas as arrestas que fazem parte da solução, sendo do tipo 0 que é a ida a solução, como no tipo 1 que é voltando porque encontrar um caminho errado.
      @param *cont Ponteiro que aponta para um inteiro que servirá como contador.
      @param *achou Ponteiro que aponta para um boolean que indica se achou ou não o destino.
      @param direcao_cabeca Direction que indica qual a direcao inicial da cabeca da cobra.
      @param vizinhos Um Map contendo um par e um vetor de par, onde o par é o vertice e o vetor de par é os vizinhos desse vertice
    */
    void busca_em_profundidade(vector <std::pair<int, int>> vertices, vector< ArrestaGrafo > arrestas, std::pair<int, int > inicio, std::pair<int,int> destino, vector<ArrestaGrafo> *arrestas_resultado , int *cont, bool *achou, Direction direcao_cabeca, map < std::pair<int, int>, vector< std::pair< int, int > > > vizinhos);

    /*! 
      @brief Gera um vetor de ArrestasGrafo contendo todas as arrestas que fazem parte da solução que a cobra até a comida, utilizando a busca em profundidade para gerar esse vetor.
      @param level_ O nivel que será usado para a analise
      @param cobra_ A cobra que está sendo utiliada.
      @return Retorna um vetor de ArrestasGrafo contendo todas as arrestas que fazem parte da solução que a cobra até a comida
    */
    vector<ArrestaGrafo> busca_em_profundidade_grafo(Level level_, Snake cobra_);

    /*! 
      @brief Recupera o contador de jogadas
      @return Retorna inteiro contendo o contador
    */
    int get_contador_jogada( void );

    /*! 
      @brief Define o contador de jogadas
      @param contador_jogada_ Inteiro contendo o contador
    */
    void set_contador_jogada( int contador_jogada_ );

    /*! 
      @brief Reseta os atributos privados que fazem parte da solução do algoritmo busca em profundidade.
    */
    void resetar_atributos( void );

};

#endif