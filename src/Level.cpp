#include "Level.hpp"

int Level::get_qtd_macas ( void ){
  return qtd_macas;
}

int Level::get_qtd_linhas( void ){
  return qtd_linhas;
}
  
int Level::get_qtd_colunas (void) {
  return qtd_colunas;
}

ModoJogo Level::get_modo_jogo( void ){
  return modo_jogo;
}

void Level::set_modo_jogo ( ModoJogo modo_jogo_ ){
  modo_jogo = modo_jogo_;
}

void Level::set_qtd_macas (int qtd_macas_){
  qtd_macas = qtd_macas_;
}

void Level::set_qtd_linhas (int qtd_linhas_){
  qtd_linhas = qtd_linhas_;
}

void Level::set_qtd_colunas (int qtd_colunas_) {
  qtd_colunas = qtd_colunas_;
}


std::pair< int, int > Level::get_posicao_inicial( void ){
  return posicao_inicial;
}

void Level::set_posicao_inicial( std::pair< int, int > posicao_inicial_){
  posicao_inicial = posicao_inicial_;
}

std::pair< int, int > Level::capturando_posicao_inicial_do_mapa( void ){
  std::pair< int, int > pos_result;
  for(auto i = mapa.begin(); i != mapa.end();){
    if(i->second == '*'){
      pos_result.first = i->first.first;
      pos_result.second = i->first.second;
    }
    i++;
  }
  return pos_result;
}

std::pair< int, int > Level::capturando_posicao_inicial_aleatoria_do_mapa( void ){
  vector< std::pair< int, int > > vetor_posicoes_livres;
  for(auto i = mapa.begin(); i != mapa.end();){
    if(i->second == '*'){
      i->second = ' ';
    }
    if(i->second == ' '){
      std::pair<int, int>pos;
      pos.first = i->first.first;
      pos.second = i->first.second;
      vetor_posicoes_livres.push_back(pos);
    }
    i++;
  }

  int id_posicao_sorteada = rand()%vetor_posicoes_livres.size();

  return vetor_posicoes_livres[id_posicao_sorteada];
}

Direction Level::gerando_uma_direcao_inicial_cobra_possivel( void ){
  vector< Direction > vetor_direcoes_possiveis;
  
  std::pair<int, int > posicao_direita = posicao_inicial;
  posicao_direita.first = posicao_direita.first+1;

  std::pair<int, int > posicao_esquerda = posicao_inicial;
  posicao_esquerda.first = posicao_esquerda.first-1;

  std::pair<int, int > posicao_cima = posicao_inicial;
  posicao_cima.second = posicao_cima.second-1;

  std::pair<int, int > posicao_baixo = posicao_inicial;
  posicao_baixo.second = posicao_baixo.second+1;

  Direction direcao;
  for(auto i = mapa.begin(); i != mapa.end();){
    if(i->first == posicao_direita && (i->second == ' ' || i->second == 'M')){
      direcao = Direction::DIREITA;
      vetor_direcoes_possiveis.push_back(direcao);
    }else if(i->first == posicao_esquerda && (i->second == ' ' || i->second == 'M')){
      direcao = Direction::ESQUERDA;
      vetor_direcoes_possiveis.push_back(direcao);
    }else if(i->first == posicao_cima && (i->second == ' ' || i->second == 'M')){
      direcao = Direction::CIMA;
      vetor_direcoes_possiveis.push_back(direcao);
    }else if(i->first == posicao_baixo && (i->second == ' ' || i->second == 'M')){
      direcao = Direction::BAIXO;
      vetor_direcoes_possiveis.push_back(direcao);
    }
    i++;
  }

  int id_direcao_sorteada = rand()%vetor_direcoes_possiveis.size();

  return vetor_direcoes_possiveis[id_direcao_sorteada];

}

bool Level::gerar_mapa( std::vector<std::string> linhas_){
  int i = 0; // Representa o Y
  int j = 0; // Representa o X
  char caractere;
  for(std::string linha : linhas_){
    for(char caractere : linha){
      if(caractere==' ' || caractere=='.' || caractere=='#' || caractere=='*'){
        std::pair<int, int> posicao;
        posicao.first = j;
        posicao.second = i;
        mapa[posicao] = caractere;
        if(caractere=='*'){
          posicao_inicial = posicao;
        }
        j++;
      }else{
        return false;
      }
      if(j==linha.size()){
        j=0;
        i++;
      }
    }
  }
  return true;
}

void Level::exibir_mapa( void ){
  for(int i = 0; i<qtd_linhas; i++){
    for(int j = 0; j<qtd_colunas; j++){
      std::pair< int, int > posicao;
      posicao.first = j;
      posicao.second = i;
      cout<< mapa[posicao];
    }
    cout<<endl;
  }
}

void Level::incluir_cobra_mapa ( Snake cobra_ ) { 
  for(auto i = mapa.begin(); i != mapa.end();){
    if(cobra_.verifica_corpo_na_posicao (i->first)){
      if(cobra_.get_cabeca().first == i->first.first && cobra_.get_cabeca().second == i->first.second){
        i->second = 'V';
      }else{
        i->second = 'O';
      }
    }
    i++;
  }
}

void Level::excluir_cobra_mapa ( Snake cobra_ ){
  for(auto i = mapa.begin(); i != mapa.end();){
    if(cobra_.verifica_corpo_na_posicao (i->first)){
      i->second = ' ';
    }
    if(i->second == 'V' || i->second == 'O'){
      i->second == ' ';
    }
    i++;
  }
}

void Level::colocando_comida_mapa ( Snake cobra_ ) {
  std::vector< std::pair< int, int > > posicoes_sorteadas;
  
  for(auto i = mapa.begin(); i != mapa.end();){
    if(i->second == ' '){
      if(!(i->first.first == posicao_inicial.first && i->first.second == posicao_inicial.second)){
        posicoes_sorteadas.push_back(i->first);
      }

    }
    i++;
  }
  
  int id_posicao = 1+rand()%posicoes_sorteadas.size();
  
  for(auto i = mapa.begin(); i != mapa.end();){
    if(i->first.first == posicoes_sorteadas[id_posicao].first && i->first.second == posicoes_sorteadas[id_posicao].second){
      i->second = 'M';
    }
    i++;
  }
  bool encontrou_comida = false;

  for(auto i = mapa.begin(); i!=mapa.end();){
    if(i->second == 'M' && i->first.first != 0 && i->first.second !=0){
      encontrou_comida = true;
    }
    if(i->first.first == 0 && i->first.second == 0){
      i->second = '#';
    }
    i++;
  }

  if(!encontrou_comida){
    colocando_comida_mapa(cobra_);
  }
}

void Level::excluir_comida_mapa ( void ){
  for(auto i = mapa.begin(); i != mapa.end();){
    if(i->second == 'M'){
      i->second = ' ';
    }
    i++;
  }
  qtd_macas--;
}

bool Level::verificar_cobra_encontrou_comida (std::pair< int, int > posicao_analizada_){

  for(auto i = mapa.begin(); i != mapa.end();){
    if(i->first.first == posicao_analizada_.first && i->first.second == posicao_analizada_.second){
      if(i->second == 'M'){
        return true;
      }
    }
    i++;
  }
  return false;
}

bool Level::verificar_cobra_encontrou_obstaculo (std::pair< int, int > posicao_analizada){

  for(auto i = mapa.begin(); i != mapa.end();){
    if(i->first.first == posicao_analizada.first && i->first.second == posicao_analizada.second){
      if(i->second == '#' || i->second == '.' || i->second == 'O'){
        return true;
      }
    }
    i++;
  }
  return false;
}

void Level::aplicar_jogada( Snake *cobra_, std::pair< int, int > movimento_jogada_){

  if(verificar_cobra_encontrou_obstaculo(movimento_jogada_)){
    
    excluir_cobra_mapa( *cobra_ );
    cobra_->resetar_cobra(posicao_inicial, gerando_uma_direcao_inicial_cobra_possivel());
    incluir_cobra_mapa( *cobra_ );

    cobra_->set_vidas(cobra_->get_vidas()-1);

  }else{
    
    if(verificar_cobra_encontrou_comida (movimento_jogada_)){

      excluir_comida_mapa();
      excluir_cobra_mapa( *cobra_ );
      if(((int) modo_jogo) == 2){
        cobra_->aumentando_cobra(movimento_jogada_);
      }else{
        cobra_->movendo_cobra(movimento_jogada_);
        cobra_->set_qtd_comida(cobra_->get_qtd_comida()+1);
      }
      incluir_cobra_mapa( *cobra_ );

      if(qtd_macas!=0){
        colocando_comida_mapa ( *cobra_ );
      }
    }else{
      excluir_cobra_mapa( *cobra_ );
      cobra_->movendo_cobra(movimento_jogada_);
      incluir_cobra_mapa( *cobra_ );

    }

  }
}

bool Level::verificar_venceu_level(){
  if(qtd_macas==0){
    return true;
  }
  return false;
}

bool Level::verificar_perdeu_level(Snake cobra_){
  if(cobra_.get_vidas()==0){
    return true;
  }
  return false;
}

std::pair< int, int > Level::direcao_para_posicao_movimento(Snake cobra_){
  int id_direcao = (int) cobra_.get_direcao_cabeca();
  std::pair< int, int > resultado = cobra_.get_cabeca();

  if(id_direcao==1){
    resultado.first = resultado.first + 1;
  }else if(id_direcao==2){
    resultado.second = resultado.second - 1;
  }else if(id_direcao==3){
    resultado.first = resultado.first - 1;
  }else if(id_direcao==4){
    resultado.second = resultado.second + 1;
  }
  return resultado;
}

std::pair< int, int > Level::get_posicao_comida(){
  std::pair <int, int> posicao;

  for(auto i = mapa.begin(); i != mapa.end();){

    if(i->second == 'M'){

      posicao.first = i->first.first;
      posicao.second = i->first.second;
    }
    i++;
  }
  
  return posicao;
}

//Etapas para a construção do algoritmo de busca por profundidade

vector< std::pair<int, int > > Level::gerando_vetor_vertices_mapa(){

  vector< std::pair<int, int > > vetor_resultado;

   for(auto i = mapa.begin(); i != mapa.end();){

      if(i->second == ' ' || i->second == 'M' || i->second == 'V' || i->second == '*'){

        std::pair <int, int> posicao;
        posicao.first = i->first.first;
        posicao.second = i->first.second;
        vetor_resultado.push_back(posicao);

      }
      i++;
   }

   return vetor_resultado;
}

bool Level::verificar_arresta_existe(vector< ArrestaGrafo > arrestas_, ArrestaGrafo arresta_analizada){
  for(int i = 0; i<arrestas_.size(); i++){ 

    if( (arrestas_[i].get_inicio() == arresta_analizada.get_inicio() && arrestas_[i].get_destino() == arresta_analizada.get_destino()) || (arrestas_[i].get_inicio() == arresta_analizada.get_destino() && arrestas_[i].get_destino() == arresta_analizada.get_inicio()) ){
      return true;
      
    }
  }
  return false;
}


vector< ArrestaGrafo > Level::gerando_arrestas_grafo_mapa(){

  vector< ArrestaGrafo > vetor_resultado;

  for(auto i = mapa.begin(); i != mapa.end();){

      if(i->second == ' ' || i->second == 'M' || i->second == 'V' || i->second == '*'){

        std::pair <int, int> posicao;
        posicao.first = i->first.first;
        posicao.second = i->first.second;

        //verificar arresta pra cima

        std::pair<int, int > pos_aux = posicao;
        pos_aux.second = (i->first.second) - 1;

        if(pos_aux.second >= 0 && (mapa[pos_aux] == ' ' || mapa[pos_aux] == 'M' || mapa[pos_aux] == 'V' || mapa[pos_aux] == '*')){
         
          ArrestaGrafo arresta;
          arresta.set_inicio(posicao);
          arresta.set_destino(pos_aux);
          arresta.set_tipo(0);

          if( !verificar_arresta_existe( vetor_resultado, arresta) ){
            vetor_resultado.push_back(arresta);
          }

        }

        //verificar arresta pra esquerda

        pos_aux = posicao;
        pos_aux.first = (i->first.first) - 1;

        if(pos_aux.second >= 0 && ( mapa[pos_aux] == ' ' || mapa[pos_aux] == 'M' || mapa[pos_aux] == 'V' || mapa[pos_aux] == '*')){
         
          ArrestaGrafo arresta;
          arresta.set_inicio(posicao);
          arresta.set_destino(pos_aux);
          arresta.set_tipo(0);

          if( !verificar_arresta_existe( vetor_resultado, arresta) ){
            vetor_resultado.push_back(arresta);
          }

        }

        //verificar arresta pra baixo

        pos_aux = posicao;
        pos_aux.second = (i->first.second) + 1;

        if(pos_aux.second < qtd_linhas && ( mapa[pos_aux] == ' ' || mapa[pos_aux] == 'M' || mapa[pos_aux] == 'V' || mapa[pos_aux] == '*')){
         
          ArrestaGrafo arresta;
          arresta.set_inicio(posicao);
          arresta.set_destino(pos_aux);
          arresta.set_tipo(0);

          if( !verificar_arresta_existe( vetor_resultado, arresta) ){
            vetor_resultado.push_back(arresta);
          }

        }

        //verificar arresta pra direita

        pos_aux = posicao;
        pos_aux.first = (i->first.first) + 1;

        if(pos_aux.first < qtd_colunas && (mapa[pos_aux] == ' ' || mapa[pos_aux] == 'M' || mapa[pos_aux] == 'V' || mapa[pos_aux] == '*')){
         
          ArrestaGrafo arresta;
          arresta.set_inicio(posicao);
          arresta.set_destino(pos_aux);
          arresta.set_tipo(0);

          if( !verificar_arresta_existe( vetor_resultado, arresta) ){
            vetor_resultado.push_back(arresta);
          }

        }
      }
      i++;
   }

   return vetor_resultado;

}
