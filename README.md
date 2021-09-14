# Snaze: A Snake Trapped in a Maze, Programming Project
 Repositório contendo as especificações do Trabalho 3 da disciplina de LP1

## Requisitos para o programa
- Cmake >= 3.5
- C++ >= 14

## Como usar?

No mesmo diretório do projeto, crie uma pasta de sua preferência, após isso, abra um terminal dentro dessa pasta e execute os seguintes comandos:

1. `cmake ..`
2. `cmake --build .`

Após isso seu programa estará compilado e pronto para uso, basta usar o seguinte comando com o terminal aberto na pasta que você criou anteriormente:

### Para modo_jogo com rabo, usar:

- `./Snaze "arquivo de entrada" com_rabo`

### Para modo_jogo sem rabo, usar:

- `./Snaze "arquivo de entrada" sem_rabo`

### Para deixar os niveis infinitos, usar:

- `./Snaze "arquivo de entrada" modo_jogo loop` 

### Para deixar a posição inicial da cobra aleatória , usar:

- `./Snaze "arquivo de entrada" modo_jogo random` 

### Exemplo com o modo de jogo sem rabo, os niveis infinitos e a possição inicial da cobra aleatória:

- `./Snaze "arquivo de entrada" sem_rabo loop random` 

## Testes pré-definidos
Os testes estão em desenvolvimento, mas há um mapa para testes dentro do diretório "data"