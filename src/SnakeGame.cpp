#include "SnakeGame.hpp"

#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep

using namespace std;

SnakeGame::SnakeGame(){
    choice = "";
    frameCount = 0;
    nivel_atual = 0;
    pontuacao = 0;
    inicio_rodada = true;
    rodada_tem_solucao = false;
    modo_loop = false;
    inicio_randomico = false;
    cobra.set_vidas(5);
    caminho_arquivo = "../data/maze.txt";

    modo_jogo = ModoJogo::SEM_RABO;
    

    initialize_game();
}

SnakeGame::SnakeGame(std::string caminho_arquivo_){
    choice = "";
    frameCount = 0;
    nivel_atual = 0;
    pontuacao = 0;
    inicio_rodada = true;
    rodada_tem_solucao = false;
    modo_loop = false;
    inicio_randomico = false;
    cobra.set_vidas(5);
    caminho_arquivo = caminho_arquivo_;

    modo_jogo = ModoJogo::SEM_RABO;

    initialize_game();
}

SnakeGame::SnakeGame(std::string caminho_arquivo_, std::string primeiro_parametro){
    choice = "";
    frameCount = 0;
    nivel_atual = 0;
    pontuacao = 0;
    inicio_rodada = true;
    rodada_tem_solucao = false;
    modo_loop = false;
    inicio_randomico = false;
    cobra.set_vidas(5);
    caminho_arquivo = caminho_arquivo_;

    if(primeiro_parametro == "com_rabo"){
      modo_jogo = ModoJogo::COM_RABO;
    }else{
      modo_jogo = ModoJogo::SEM_RABO;
    }

    if(primeiro_parametro == "loop"){
    modo_loop = true;
    }
    else if(primeiro_parametro == "random"){
      inicio_randomico = true;
    }

    initialize_game();
}

SnakeGame::SnakeGame(std::string caminho_arquivo_, std::string primeiro_parametro, std::string segundo_parametro){
  choice = "";
  frameCount = 0;
  nivel_atual = 0;
  pontuacao = 0;
  caminho_arquivo = caminho_arquivo_;
  inicio_rodada = true;
  rodada_tem_solucao = false;
  modo_loop = false;
  inicio_randomico = false;
  cobra.set_vidas(5);
  bool modo_jogo_com_rabo = false;

  if(primeiro_parametro == "com_rabo"){
    modo_jogo_com_rabo =true;
  }

  if(primeiro_parametro == "loop"){
  modo_loop = true;
  }
  else if(primeiro_parametro == "random"){
    inicio_randomico = true;
  }

  if(segundo_parametro == "com_rabo"){
    modo_jogo_com_rabo =true;
  }

  if(segundo_parametro == "loop"){
  modo_loop = true;
  }
  else if(segundo_parametro == "random"){
    inicio_randomico = true;
  }

  if(modo_jogo_com_rabo){
    modo_jogo = ModoJogo::COM_RABO;
  }
  else{
    modo_jogo = ModoJogo::SEM_RABO;
  }

  initialize_game();
}

SnakeGame::SnakeGame(std::string caminho_arquivo_, std::string primeiro_parametro, std::string segundo_parametro, std::string terceiro_parametro){
  choice = "";
  frameCount = 0;
  nivel_atual = 0;
  pontuacao = 0;
  caminho_arquivo = caminho_arquivo_;
  inicio_rodada = true;
  rodada_tem_solucao = false;
  modo_loop = false;
  inicio_randomico = false;
  cobra.set_vidas(5);
  bool modo_jogo_com_rabo = false;

  if(primeiro_parametro == "com_rabo"){
    modo_jogo_com_rabo =true;
  }

  if(primeiro_parametro == "loop"){
  modo_loop = true;
  }
  else if(primeiro_parametro == "random"){
    inicio_randomico = true;
  }

  if(segundo_parametro == "com_rabo"){
    modo_jogo_com_rabo =true;
  }

  if(segundo_parametro == "loop"){
  modo_loop = true;
  }
  else if(segundo_parametro == "random"){
    inicio_randomico = true;
  }

  if(terceiro_parametro == "com_rabo"){
    modo_jogo_com_rabo =true;
  }

  if(terceiro_parametro == "loop"){
  modo_loop = true;
  }
  else if(terceiro_parametro == "random"){
    inicio_randomico = true;
  }

  if(modo_jogo_com_rabo){
    modo_jogo = ModoJogo::COM_RABO;
  }
  else{
    modo_jogo = ModoJogo::SEM_RABO;
  }

  initialize_game();
}

std::string SnakeGame::get_caminho_arquivo( void ){
  return caminho_arquivo;
}

void SnakeGame::set_caminho_arquivo ( std::string caminho_arquivo_ ){
  caminho_arquivo = caminho_arquivo_;
}

void SnakeGame::initialize_game(){

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

      level.set_modo_jogo(modo_jogo);

      if(!inicio_randomico){
        level.set_posicao_inicial(level.capturando_posicao_inicial_do_mapa());
      }else{
        level.set_posicao_inicial(level.capturando_posicao_inicial_aleatoria_do_mapa());
      }

      level.colocando_comida_mapa ( cobra );

      leveis.push_back(level);

      maze.clear();
    }

  }

  
  //Setando as variaveis principais da cobra

  //Resetando a cobra, mas mantendo a mesma quantidade de vida
  int vidas = cobra.get_vidas();
  Snake cobra2;
  cobra = cobra2;
  cobra.set_vidas(vidas);

  Direction dir_cobra = leveis[nivel_atual].gerando_uma_direcao_inicial_cobra_possivel();

  cobra.set_direcao_cabeca(dir_cobra);
  cobra.set_qtd_comida(0);

  cobra.incluir_nova_posicao_corpo (leveis[nivel_atual].get_posicao_inicial());

  leveis[nivel_atual].incluir_cobra_mapa( cobra );

  jogador.set_contador_jogada(0);

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

      if(leveis[nivel_atual].get_posicao_comida().second == 0 && leveis[nivel_atual].get_posicao_comida().first == 0){
        leveis[nivel_atual].colocando_comida_mapa (cobra);
      }

      cout << "VIDA: " << cobra.get_vidas() << " | MAÇÃS COMIDAS: " << cobra.get_qtd_comida() << " | FALTAM " << leveis[nivel_atual].get_qtd_macas() << " MAÇÃS | NIVEL: " << (nivel_atual+1) << " | PONTUAÇÃO: " << pontuacao <<endl;

      if(inicio_rodada){
        if(jogador.procurando_solucao(leveis[nivel_atual], cobra)){
          rodada_tem_solucao = true;
        }else{
          rodada_tem_solucao = false;
        }
        inicio_rodada = false;
      }

      if(rodada_tem_solucao){
        cobra.set_direcao_cabeca( jogador.direcao_proximo_movimento() );
      }else{
        //Caso não encontre uma solução pela busca em profundidade ele vai tentar dar o proximo passo aleatorio evitando os obstaculos
        if(jogador.procurando_solucao_randomica(leveis[nivel_atual], cobra)){
          cobra.set_direcao_cabeca( jogador.direcao_proximo_movimento_randomica());
        }
      }

      int quantidade_comida_level = leveis[nivel_atual].get_qtd_macas();
      int vida_cobra = cobra.get_vidas();
        
      pair< int, int > movimento_da_jogada = leveis[nivel_atual].direcao_para_posicao_movimento( cobra );

      leveis[nivel_atual].aplicar_jogada( &cobra, movimento_da_jogada );

      //verificando se é uma nova rodada (a cobra encontrou a comida ou a cobra perdeu uma vida)
      if(quantidade_comida_level > leveis[nivel_atual].get_qtd_macas()|| vida_cobra > cobra.get_vidas()){
        inicio_rodada = true;
        rodada_tem_solucao = false;

        if(quantidade_comida_level > leveis[nivel_atual].get_qtd_macas()){
          pontuacao++;
        }
      }

      leveis[nivel_atual].exibir_mapa();
      
      if(leveis[nivel_atual].verificar_venceu_level()){
        cout<<"----------SNAZE-----------"<<endl;
        cout<<"VIDA RESTANTE: " << cobra.get_vidas() << " | PONTUAÇÃO: " << pontuacao <<endl;
        cout<<"--------------------------"<<endl;
        cout << "Parabéns você venceu o nivel " << (nivel_atual+1) << " :D" << endl;
        nivel_atual++;
        inicio_rodada = true;
        rodada_tem_solucao = false;
        pontuacao = pontuacao + 3;
        if(nivel_atual==leveis.size()){
          if(modo_loop){
            nivel_atual = 0;
            //cobra.resetar_cobra(leveis[nivel_atual].get_posicao_inicial(), leveis[nivel_atual].gerando_uma_direcao_inicial_cobra_possivel());
            leveis.clear();
            initialize_game();

          }else{
            jogo_terminou = true;
          }
        }else{
          cobra.resetar_cobra(leveis[nivel_atual].get_posicao_inicial(), leveis[nivel_atual].gerando_uma_direcao_inicial_cobra_possivel());
        }
      }else if(leveis[nivel_atual].verificar_perdeu_level(cobra)){
        cout<<"----------SNAZE-----------"<<endl;
        cout<<"VIDA RESTANTE: " << cobra.get_vidas() << " | PONTUAÇÃO: " << pontuacao <<endl;
        cout<<"--------------------------"<<endl;
        cout << "Infelizmente você ficou sem vidas :c" << endl;
        jogo_terminou = true;
      }

      if(inicio_rodada){
        jogador.set_contador_jogada(0);
        jogador.resetar_atributos();
      }

    }else if(((int) state) == 2){
      cout<<"Você quer continuar com o jogo? (s/n)"<<endl;
    }else if(((int) state) == 1){
      cout<<"----------SNAZE-----------"<<endl;
      cout<<"VIDA RESTANTE: " << cobra.get_vidas() << " | PONTUAÇÃO: " << pontuacao <<endl;
      cout<<"--------------------------"<<endl;
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
        wait(100);// espera 1 segundo entre cada frame
    }
}