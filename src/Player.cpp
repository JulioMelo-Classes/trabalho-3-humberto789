#include "Player.hpp"
#include <map>

//Algoritmo que encontra uma direção aleatoria que não levará a morte
Direction Player::direcao_proximo_movimento_randomica( void ){

  int id_direcao = rand()%solucoes_labirinto_randomico.size();

  for(int i = 0; i<solucoes_labirinto_randomico.size(); i++){
    if(i == id_direcao){
      return solucoes_labirinto_randomico[i];
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

bool Player::procurando_solucao_randomica(Level level_, Snake cobra_){
  Direction direcao_atual = cobra_.get_direcao_cabeca();
  solucoes_labirinto_randomico.clear();
  int contador_solucoes = 0;
  //Se for Direita => Só pode se movimentar para ( cima, direita, baixo )
  if(((int)direcao_atual)==1){
    if(verificar_direcao_pra_cima(level_, cobra_)){
      direcao_atual = Direction::CIMA;
      solucoes_labirinto_randomico.push_back(direcao_atual);
      contador_solucoes++;
    }
    if(verificar_direcao_direita(level_, cobra_)){
      solucoes_labirinto_randomico.push_back(direcao_atual);
      contador_solucoes++;
    }
    if(verificar_direcao_pra_baixo(level_, cobra_)){
      direcao_atual = Direction::BAIXO;
      solucoes_labirinto_randomico.push_back(direcao_atual);
      contador_solucoes++;
    }
  }
  //Se for CIMA => Só pode se movimentar para ( cima, direita, esquerda )
  else if(((int)direcao_atual)==2){
    if(verificar_direcao_pra_cima(level_, cobra_)){
      solucoes_labirinto_randomico.push_back(direcao_atual);
      contador_solucoes++;
    }
    if(verificar_direcao_direita(level_, cobra_)){
      direcao_atual = Direction::DIREITA;
      solucoes_labirinto_randomico.push_back(direcao_atual);
      contador_solucoes++;
    }
    if(verificar_direcao_esquerda(level_, cobra_)){
      direcao_atual = Direction::ESQUERDA;
      solucoes_labirinto_randomico.push_back(direcao_atual);
      contador_solucoes++;
    }
  }
  //Se for ESQUERDA => Só pode se movimentar para ( esquerda, cima, baixo )
  else if(((int)direcao_atual)==3){
    if(verificar_direcao_pra_cima(level_, cobra_)){
      direcao_atual = Direction::CIMA;
      solucoes_labirinto_randomico.push_back(direcao_atual);
      contador_solucoes++;
    }
    if(verificar_direcao_esquerda(level_, cobra_)){
      solucoes_labirinto_randomico.push_back(direcao_atual);
      contador_solucoes++;
    }
    if(verificar_direcao_pra_baixo(level_, cobra_)){
      direcao_atual = Direction::BAIXO;
      solucoes_labirinto_randomico.push_back(direcao_atual);
      contador_solucoes++;
    }
  }
  //Se for BAIXO => Só pode se movimentar para ( baixo, esquerda, direita )
  else if(((int)direcao_atual)==4){
    if(verificar_direcao_pra_baixo(level_, cobra_)){
      solucoes_labirinto_randomico.push_back(direcao_atual);
      contador_solucoes++;
    }
    if(verificar_direcao_esquerda(level_, cobra_)){
      direcao_atual = Direction::ESQUERDA;
      solucoes_labirinto_randomico.push_back(direcao_atual);
      contador_solucoes++;
    }
    if(verificar_direcao_direita(level_, cobra_)){
      direcao_atual = Direction::DIREITA;
      solucoes_labirinto_randomico.push_back(direcao_atual);
      contador_solucoes++;
    }
  }
  if(contador_solucoes!=0){
    return true;
  }
  return false;
}

//Solução com base no algoritmo de busca em prondundidade

int Player::get_contador_jogada( void ){
  return contador_jogada;
}

void Player::set_contador_jogada( int contador_jogada_ ){
  contador_jogada = contador_jogada_;
}

map < std::pair<int, int> , vector< std::pair< int, int > > > Player::gerar_map_vertices_vizinhos( vector< ArrestaGrafo > arrestas, vector <std::pair<int, int> > vertices ){

  map < std::pair<int, int>, vector< std::pair< int, int > > > map_resultado;

  for(int i = 0; i < vertices.size(); i++){
    
    vector< std::pair< int, int > > vizinhos_vertices;

    for( int j = 0; j< arrestas.size(); j++){

      if(arrestas[j].get_inicio() == vertices[i]){

        vizinhos_vertices.push_back(arrestas[j].get_destino());

      }else if(arrestas[j].get_destino() == vertices[i]){

        vizinhos_vertices.push_back(arrestas[j].get_inicio());

      }
    }

    map_resultado[vertices[i]] = vizinhos_vertices;
  }

  return map_resultado;

}

//Metodo que realiza o calculo da busca de profundidade.
void Player::busca_em_profundidade(vector <std::pair<int, int>> vertices, vector< ArrestaGrafo > arrestas, std::pair<int, int > inicio, std::pair<int,int> destino, vector<ArrestaGrafo> *arrestas_resultado , int *cont, bool *achou, Direction direcao_cabeca , map < std::pair<int, int>, vector< std::pair< int, int > > > vizinhos){
  
  //Marcando a posição como visitada.
  visitados[inicio] = true;
  bool condicao_inicial = true;
  

  //Passando por todos os vizinhos daquela arresta
  for(int i = 0; i < vizinhos[inicio].size(); i++){
    if(*(achou)){
      return;
    }

    //Só executa essa logica se a posição ainda não foi visitada.
    if(!visitados[vizinhos[inicio][i]] && condicao_inicial){

      ArrestaGrafo ar;

      ar.set_inicio(inicio);
      ar.set_destino(vizinhos[inicio][i]);
      ar.set_tipo(0);
      arrestas_resultado->push_back(ar);
      (*cont)++;
      
      //Verificação se já chegamos no objetivo.
      if(vizinhos[inicio][i] == destino){
        *achou = true;
        return;
      }
      
      //Chamada recursiva passando como posição de inicio o vizinho da posicao selecionada no for.
      busca_em_profundidade(vertices, arrestas, vizinhos[inicio][i], destino, arrestas_resultado , cont, achou, direcao_cabeca,  vizinhos);

      if(!(*achou)){
        ArrestaGrafo ar2;
        ar2.set_inicio(inicio);
        ar2.set_destino(vizinhos[inicio][i]);
        ar2.set_tipo(1);
        arrestas_resultado->push_back(ar2);
        (*cont)++;
      }
    }
  }
}

vector<ArrestaGrafo> Player::busca_em_profundidade_grafo(Level level_, Snake cobra_){
  int cont = 0;
  bool achou = false;

  //vetor com as arrestas da solução;
  vector<ArrestaGrafo> arrestas_resultado;

  //vetor com todos os vertices = posições válidas do mapa.
  vector <std::pair<int, int>> vertices = level_.gerando_vetor_vertices_mapa();

  //vetor com todas as arrestas (conexões entre vertices disponiveis) do mapa.
  vector< ArrestaGrafo > arrestas = level_.gerando_arrestas_grafo_mapa();

  Direction direcao_cabeca = cobra_.get_direcao_cabeca();
  for(int i = 0; i < arrestas.size(); i++){
    if(arrestas[i].get_inicio() == cobra_.get_cabeca()){
      //cabeça pra cima
      if(((int)direcao_cabeca)==1){
        //verificar se a posição vizinha escolhida foi para a esquerda
        if(arrestas[i].get_destino().first == cobra_.get_cabeca().first - 1){
          arrestas.erase(arrestas.begin()+i);
          break;
        }
      }
      //cabeça pra cima
      else if(((int)direcao_cabeca)==2){
        //verificar se a posição vizinha escolhida foi para a baixo
        if(arrestas[i].get_destino().second == cobra_.get_cabeca().second + 1){
          arrestas.erase(arrestas.begin()+i);
          break;
        }
      }
      //cabeça pra esquerda
      else if(((int)direcao_cabeca)==3){
        //verificar se a posição vizinha escolhida foi para a direita
        if(arrestas[i].get_destino().first == cobra_.get_cabeca().first + 1){
          arrestas.erase(arrestas.begin()+i);
          break;
        }
      }
      //cabeça pra baixo
      else if(((int)direcao_cabeca)==4){
        //verificar se a posição vizinha escolhida foi para a cima
        if(arrestas[i].get_destino().second == cobra_.get_cabeca().second - 1){
          arrestas.erase(arrestas.begin()+i);
          break;
        }
      }
    }else if(arrestas[i].get_destino() == cobra_.get_cabeca()){
      //cabeça pra cima
      if(((int)direcao_cabeca)==1){
        //verificar se a posição vizinha escolhida foi para a esquerda
        if(arrestas[i].get_inicio().first == cobra_.get_cabeca().first - 1){
          arrestas.erase(arrestas.begin()+i);
          break;
        }
      }
      //cabeça pra cima
      else if(((int)direcao_cabeca)==2){
        //verificar se a posição vizinha escolhida foi para a baixo
        if(arrestas[i].get_inicio().second == cobra_.get_cabeca().second + 1){
          arrestas.erase(arrestas.begin()+i);
          break;
        }
      }
      //cabeça pra esquerda
      else if(((int)direcao_cabeca)==3){
        //verificar se a posição vizinha escolhida foi para a direita
        if(arrestas[i].get_inicio().first == cobra_.get_cabeca().first + 1){
          arrestas.erase(arrestas.begin()+i);
          break;
        }
      }
      //cabeça pra baixo
      else if(((int)direcao_cabeca)==4){
        //verificar se a posição vizinha escolhida foi para a cima
        if(arrestas[i].get_inicio().second == cobra_.get_cabeca().second - 1){
          arrestas.erase(arrestas.begin()+i);
          break;
        }
      }
    }
  }

  //map <  posicao_vertice, vetor_com_as_posicoes_dos_vizinhos > vizinhos
  map < std::pair<int, int>, vector< std::pair< int, int > > > vizinhos = gerar_map_vertices_vizinhos( arrestas, vertices );

  //map com todas as posicões visitadas.
  visitados.clear();

  //inicializando todas as posicoes válidas como não visitadas.
  for(int i = 0; i < vertices.size(); i++){
    visitados[vertices[i]] = false;
  }

  //Chamando o método que vai calcular recursivamente a busca por profundidade

  busca_em_profundidade(vertices, arrestas, cobra_.get_cabeca() ,  level_.get_posicao_comida(), &arrestas_resultado , &cont, &achou, cobra_.get_direcao_cabeca(), vizinhos);

  vector<ArrestaGrafo> arrestas_resultado_aux = arrestas_resultado;

  arrestas_resultado.clear();

  for(int i = 0; i < arrestas_resultado_aux.size(); i++){
    if(arrestas_resultado_aux[i].get_tipo() == 0){
      
      bool nao_eh_volta = true;

      for(int j = 0; j < arrestas_resultado_aux.size(); j++){
        if(arrestas_resultado_aux[j].get_tipo() == 1){
          if(arrestas_resultado_aux[i].get_inicio() == arrestas_resultado_aux[j].get_inicio() && arrestas_resultado_aux[i].get_destino() == arrestas_resultado_aux[j].get_destino()){
            nao_eh_volta = false;
          }
        }
      }

      if(nao_eh_volta){
        arrestas_resultado.push_back(arrestas_resultado_aux[i]);
      }
    }
  }

  return arrestas_resultado;

}

//Procurando uma solução possivel para o labirinto => true = achou e false = não achou
bool Player::procurando_solucao(Level level_, Snake cobra_){
  vector<ArrestaGrafo> arrestas =  busca_em_profundidade_grafo(level_, cobra_);

  solucoes_labirinto.clear();

  if( arrestas[0].get_inicio() == cobra_.get_cabeca() && arrestas[arrestas.size()-1].get_destino() != level_.get_posicao_comida() || arrestas[0].get_inicio() != cobra_.get_cabeca() && arrestas[arrestas.size()-1].get_destino() == level_.get_posicao_comida() ){
    return false;
  }


  for(int i = 0; i < arrestas.size(); i++){
    Direction direcao;
    if(arrestas[i].get_inicio().first < arrestas[i].get_destino().first){
      direcao = Direction::DIREITA;
    }else if(arrestas[i].get_inicio().first > arrestas[i].get_destino().first){
      direcao = Direction::ESQUERDA;
    }else if(arrestas[i].get_inicio().second < arrestas[i].get_destino().second){
      direcao = Direction::BAIXO;
    }else if(arrestas[i].get_inicio().second > arrestas[i].get_destino().second){
      direcao = Direction::CIMA;
    }

    solucoes_labirinto.push_back(direcao);
  }

  if(solucoes_labirinto.size() > 1){
    return true;
  }else{
    return false;
  }
}

//Pegando o proximo movimento dá jogada
Direction Player::direcao_proximo_movimento( void ){

  Direction direcao;

  if(contador_jogada < solucoes_labirinto.size()){
    direcao = solucoes_labirinto[contador_jogada];
    contador_jogada++;
  }

  return direcao;
}

void Player::resetar_atributos( void ) {
  contador_jogada = 0;
  solucoes_labirinto.clear();
  visitados.clear();
}