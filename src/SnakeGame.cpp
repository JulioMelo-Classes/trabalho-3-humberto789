#include "SnakeGame.hpp"

#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep

using namespace std;

SnakeGame::SnakeGame(){
    choice = "";
    frameCount = 0;
    nivel_atual = 0;
    initialize_game();
}

SnakeGame::SnakeGame(std::string caminho_arquivo_, std::string tipo_jogo_){
  choice = "";
  frameCount = 0;
  nivel_atual = 0;
  caminho_arquivo = caminho_arquivo_;
  tipo_jogo = tipo_jogo_;

  initialize_game();
}

std::string SnakeGame::get_caminho_arquivo( void ){
  return caminho_arquivo;
}

void SnakeGame::set_caminho_arquivo ( std::string caminho_arquivo_ ){
  caminho_arquivo = caminho_arquivo_;
}

std::string SnakeGame::get_tipo_jogo( void ){
  return tipo_jogo;
}

void SnakeGame::set_tipo_jogo (std::string tipo_jogo_){
  tipo_jogo = tipo_jogo_;
}

void SnakeGame::initialize_game(){

  cout<<"Caminho:" << caminho_arquivo << endl;
  ifstream levelFile(caminho_arquivo);
  Servicos servicos;

  bool continuar_loop = true;

  while(continuar_loop){

    int lineCount = 0;
    string line;
    bool valor_entrada = true;

    int macas;
    int colunas;
    int linhas = 1;

    if(levelFile.is_open()){
      for(int i = 0; i<=linhas; i++){

          getline(levelFile, line);

          if(line=="" || line.empty()){
            continuar_loop = false;
          }

          if(!valor_entrada){
              maze.push_back(line);
          }else{
            vector<string> comandos_separados = servicos.separador_linha_comando(line);
            int contador = 0;
            for(string comando : comandos_separados){
              if(servicos.stringIsInteger(comando)){
                int valor = stoi(comando);

                if(contador==0){
                  linhas = valor;
                  contador++;
                }else if(contador==1){
                  colunas = valor;
                  contador++;
                }else if(contador==2){
                  macas = valor;
                  contador++;
                }

              }
            }

            valor_entrada = false;
          }
          lineCount++;
          line = "";
      }
    }

    if(continuar_loop){
      Level level;

      

      level.gerar_mapa(maze);
      level.set_qtd_macas(macas);
      level.set_qtd_linhas(linhas);
      level.set_qtd_colunas(colunas);

      ModoJogo modo_jogo;

      if(tipo_jogo == "sem_rabo"){
        modo_jogo = ModoJogo::SEM_RABO;
      }else{
        modo_jogo = ModoJogo::COM_RABO;
      }

      level.set_modo_jogo(modo_jogo);

      level.set_posicao_inicial(level.capturando_posicao_inicial_do_mapa());

      level.incluir_cobra_mapa( cobra );

      level.colocando_comida_mapa ( cobra );

      leveis.push_back(level);

      maze.clear();

    }

  }

  for(Level l : leveis){
    l.exibir_mapa();
    cout<< "macas: " << l.get_qtd_macas();
    cout<< "linhas: " << l.get_qtd_linhas();
    cout<< "colunas: " << l.get_qtd_colunas() << endl;
  }

  //Setando as variaveis principais da cobra

  Direction dir_cobra = Direction::CIMA;

  cobra.set_direcao_cabeca(dir_cobra);
  cobra.set_vidas(5);
  cobra.set_qtd_comida(0);

  cobra.incluir_nova_posicao_corpo (leveis[nivel_atual].get_posicao_inicial());

  state = RUNNING;
}



void SnakeGame::process_actions(){
    //processa as entradas do jogador de acordo com o estado do jogo
    //nesse exemplo o jogo tem 3 estados, WAITING_USER, RUNNING e GAME_OVER.
    //no caso deste trabalho temos 2 tipos de entrada, uma que vem da classe Player, como resultado do processamento da IA
    //outra vem do próprio usuário na forma de uma entrada do teclado.
    switch(state){
        case WAITING_USER: //o jogo bloqueia aqui esperando o usuário digitar a escolha dele
            cin>>std::ws>>choice;
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

void SnakeGame::update(){
    //atualiza o estado do jogo de acordo com o resultado da chamada de "process_input"
    switch(state){
        case RUNNING:
            if(frameCount>0 && frameCount%10 == 0) //depois de 10 frames o jogo pergunta se o usuário quer continuar
                state = WAITING_USER;
            break;
        case WAITING_USER: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if(choice == "n"){
                state = GAME_OVER;
                game_over();
            }
            else{
                //pode fazer alguma coisa antes de fazer isso aqui
                state = RUNNING;
            }
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

/**
 * @brief função auxiliar para fazer o programa esperar por alguns milisegundos
 * @param ms a quantidade de segundos que o programa deve esperar
 */
void wait(int ms){
    this_thread::sleep_for(chrono::milliseconds(ms));
}


/**
 * @brief função auxiliar para limpar o terminal
 */
void clearScreen(){
//some C++ voodoo here ;D
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void SnakeGame::render(){
    //clearScreen();
    bool jogo_terminou = false;
    if (((int) state) == 0){
      //desenha todas as linhas do labirinto

      cout << "VIDA: " << cobra.get_vidas() << " | MAÇÃS COMIDAS: " << cobra.get_qtd_comida() << " DE " << leveis[nivel_atual].get_qtd_macas() << " | NIVEL: " << (nivel_atual+1) << endl; 

      if(jogador.procurando_solucao(leveis[nivel_atual], cobra)){
        cobra.set_direcao_cabeca( jogador.direcao_proximo_movimento() );
      }

      pair< int, int > movimento_da_jogada = leveis[nivel_atual].direcao_para_posicao_movimento( cobra );

      leveis[nivel_atual].aplicar_jogada( &cobra, movimento_da_jogada );

      leveis[nivel_atual].exibir_mapa();
      
      if(leveis[nivel_atual].verificar_venceu_level()){
        cout << "Parabéns você venceu o nivel " << (nivel_atual+1) << " :D" << endl;
        nivel_atual++;
        if(nivel_atual==leveis.size()){
          jogo_terminou = true;
        }else{
          cobra.resetar_cobra(leveis[nivel_atual].get_posicao_inicial());
        }
      }else if(leveis[nivel_atual].verificar_perdeu_level(cobra)){
        cout << "Infelizmente você ficou sem vidas :c" << endl;
        jogo_terminou = true;
      }
    }else if(((int) state) == 2){
      cout<<"Você quer continuar com o jogo? (s/n)"<<endl;
    }else if(((int) state) == 1){
      cout<<"O jogo terminou!"<<endl;
    }

    if(jogo_terminou){
      state = GAME_OVER;
    }

    frameCount++;
}

void SnakeGame::game_over(){
}

void SnakeGame::loop(){
    while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(1000);// espera 1 segundo entre cada frame
    }
}