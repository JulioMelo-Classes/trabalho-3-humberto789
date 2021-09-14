#ifndef ArrestaGrafo_hpp
#define ArrestaGrafo_hpp

#include <iostream>
#include <vector>

using namespace std;

class ArrestaGrafo{
  private:
    std::pair< int, int > inicio;
    std::pair< int, int > destino;
    int tipo;
  public:
    /*! 
      @brief Recupera as coordenadas de inicio
      @return Retorna um pair contendo as coordenadas de inicio
    */
    std::pair< int, int > get_inicio( void );
    /*! 
      @brief Recupera as coordenadas de destino
      @return Retorna um pair contendo as coordenadas de destino
    */
    std::pair< int, int > get_destino( void );

    /*! 
      @brief Recupera o tipo de busca
      @return Retorna um inteiro contendo o tipo da busca, 
      0 = Indo até a maçã
      1 = Voltando pois não achou a maçã
    */
    int get_tipo( void );

    /*! 
      @brief Define as coordenadas de inicio
      @param inicio_ Pair contendo as coordenadas de inicio
    */
    void set_inicio(std::pair< int, int > inicio_);
    /*! 
      @brief Define as coordenadas de destino
      @param inicio_ Pair contendo as coordenadas de destino
    */
    void set_destino(std::pair< int, int > destino_);
    
    /*! 
      @brief Define o tipo da busca o tipo da arresta, 0 => indo até a solução e 1 => voltando porque encontrou um caminho errado
      @param tipo_ Inteiro contendo o tipo da arresta, 0 => indo até a solução e 1 => voltando porque encontrou um caminho errado
    */ 
    void set_tipo(int tipo_);
};

#endif
