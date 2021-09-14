#ifndef SnakeGame_hpp
#define SnakeGame_hpp

#include <iostream>   // cout, endl
#include <vector>
#include <stdio.h>
#include <string.h>
#include <fstream>

#include "Level.hpp"
#include "Player.hpp"
#include "Servicos.hpp"
#include "Snake.hpp"
#include "Direction.hpp"
#include "ModoJogo.hpp"

using namespace std;

class SnakeGame{
    public:
        /**
        * @brief descreve os possíveis estados do jogo, fique à vontade para adicionar outros se necessário
        **/
        enum GameStates{
            RUNNING = 0, //<! quando o jogo está executando o estado é RUNNING
            GAME_OVER = 1, //<! quando o jogo deve terminar o estado é GAME_OVER
            WAITING_USER = 2 //<! quando o jogo deve esperar por uma entrada do usuário o estado é WAITING_USER
        };

    private:
        //<! atributos adicione outros se quiser
        std::vector<std::string> maze; //<! vector contendo o labirinto atual, pode ser interpretado como uma matriz
        int frameCount; //<! contador de frames, usado apenas como exemplo
        std::string choice; //<! usado na função process_actions para guardar a escolha do usuário
        GameStates state; //<! guarda o estado do jogo

        std::string caminho_arquivo;
        Snake cobra;
        Player jogador;
        std::vector< Level > leveis;
        int nivel_atual;
        int pontuacao;
        bool inicio_rodada;
        bool rodada_tem_solucao;
        bool modo_loop;
        bool inicio_randomico;
        ModoJogo modo_jogo;

    public:
        /**
        * @brief construtor padrão, fique à vontade para adicionar parâmetros se desejar
        **/
        SnakeGame();

        /**
        * @brief construtor padrão, fique à vontade para adicionar parâmetros se desejar
        **/
        SnakeGame(std::string caminho_arquivo_);


        /*! 
          @brief Construtor usando um parametros na entrada
          @param camonho_arquivo_ string com o local onde está o campo
          @param primeiro_parametro recebe o primeiro parametro da entrada
        */
        SnakeGame(std::string caminho_arquivo_, std::string primeiro_parametro);

        /*! 
          @brief Construtor usando dois parametros na entrada
          @param camonho_arquivo_ string com o local onde está o campo
          @param primeiro_parametro recebe o primeiro parametro da entrada
          @param segundo_parametro recebe o segundo parametro da entrada
        */
        SnakeGame(std::string caminho_arquivo_, std::string primeiro_parametro, std::string segundo_parametro);

        /*! 
          @brief Construtor usando três parametros na entrada
          @param camonho_arquivo_ string com o local onde está o campo
          @param primeiro_parametro recebe o primeiro parametro da entrada
          @param segundo_parametro recebe o segundo parametro da entrada
          @param terceiro_parametro recebe o terceiro parametro da entrada
        */
        SnakeGame(std::string caminho_arquivo_, std::string primeiro_parametro, std::string segundo_parametro, std::string terceiro_parametro);

        /**
        * @brief chamado no main, este loop executa o jogo indefinidamente até que o usuário escolha terminar!
        */
        void loop();

        /*! 
          @brief Retorna o caminho do arquivo que contem o maze
          @return retorna uma string com o caminho.
        */
        std::string get_caminho_arquivo( void );

        /*! 
          @brief Usado para setar o caminho do arquivo
          @param caminho_arquivo_ string contendo o caminho do arquivo
        */
        void set_caminho_arquivo ( std::string caminho_arquivo_ );     

    private:
        /**
        * @brief realiza a inicialização geral do jogo, fique à vontade para adicionar parâmetros se achar que deve
        **/
        void initialize_game();

        /**
        * @brief atualiza o estado do jogo, basicamente movendo os objetos, sorteando novas posições de comida
        **/
        void update();

        /**
        * @brief processa as entradas do jogador
        **/
        void process_actions();

        /**
        * @brief testa o estado do jogo e desenha a tela correspondente
        **/
        void render();

        /**
        * @brief é chamada quando o jogo termina a fim de destruir/resetar elementos do estado do jogo
        **/
        void game_over();
};

#endif //SnakeGame_h