#ifndef Servicos_hpp
#define Servicos_hpp

#include <vector>
#include <iostream>

using namespace std;

class Servicos{
  private:

  public:
    /*! 
      @brief transoforma uma string em um inteiro.
      @param str_ string que será convertida para inteiro. 
      @return returna true caso a conversão tenha funcionado e false caso a conversão tenha falhado.
    */
    bool stringIsInteger(const string& str);
    
    /*! 
      @brief Transforma uma linha de comando em um vetor de strings separando cada string pelo caractere " ".
      @param comando linha de comando que será transformada. 
      @return vetor de string separado.
    */
    std::vector<string> separador_linha_comando(string comando);
};

#endif