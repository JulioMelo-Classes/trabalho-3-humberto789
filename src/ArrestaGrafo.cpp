#include "ArrestaGrafo.hpp"

std::pair< int, int > ArrestaGrafo::get_inicio( void ){
  return inicio;
}
std::pair< int, int > ArrestaGrafo::get_destino( void ){
  return destino;
}
int ArrestaGrafo::get_tipo( void ){
  return tipo;
}

void ArrestaGrafo::set_inicio(std::pair< int, int > inicio_){
  inicio = inicio_;
}
void ArrestaGrafo::set_destino(std::pair< int, int > destino_){
  destino = destino_;
}
void ArrestaGrafo::set_tipo(int tipo_){
  tipo = tipo_;
}