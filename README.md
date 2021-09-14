# Snaze: A Snake Trapped in a Maze, Programming Project
 Repositório contendo as especificações do Trabalho 3 da disciplina de LP1

## Discentes envolvidos no projeto
- Humberto Vitalino da Silva Neto
- João Daniel Queiroz da Silva

## Requisitos para o programa
- Cmake >= 3.5
- C++ >= 14

## Como usar?

No mesmo diretório do projeto, crie uma pasta de sua preferência, após isso, abra um terminal dentro dessa pasta e execute os seguintes comandos:

1. `cmake ..`
2. `cmake --build .`

Após isso seu programa estará compilado e pronto para uso, basta usar um dos seguintes comandos com o terminal aberto na pasta que você criou anteriormente:

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
Para usar os testes basta substituir o arquivo de entrada por um dos abaixo que estão na pasta "data"

- maze.txt: Mapa com obstaculos e várias bifurcações
- maze1.txt: Mapa com mais de um nível
- maze2.txt: Mapa sem obstaculos e com muita maçã para a cobra colidir nela mesma
- maze3.txt: Mapa com espaço estreito para ver se a cobra se prende
- maze4.txt: Caminho sem saída para ver a decisão da cobra (Segue em frente ou tenta virar?)
- maze5.txt: Mapa com possibilidade da cobra fazer loop e assim ativar o modo de busca randomica e não mais de profundidade 
