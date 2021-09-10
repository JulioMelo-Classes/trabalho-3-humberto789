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

### Para modo com rabo, usar:

- `./Snaze "arquivo de entrada" com_rabo`

### Para modo sem rabo, usar:

- `./Snaze "arquivo de entrada" sem_rabo`

## Testes pré-definidos
Os testes estão em desenvolvimento, mas há um mapa para testes dentro do diretório "data"

## Avaliação CP1

### Snake/Pacman
O jogo deveria conter o modo snake/pacman. Em ambos os modos não é possível andar pra trás. No modo snake deve ser desenhado o corpo.

**Avaliação**

ok

### Render.ui
O jogo deveria desenhar a UI corretamente, mostrando ao menos as vidas, o nível e o score.

**Avaliação**

Ok

### Render.mapa
O jogo deveria desenhar o mapa corretamente, com base no arquivo passado como argumento. Ok

**Avaliação**

ok

### Render.snake
O jogo deveria desenhar a snake corretamente.

**Avaliação**

ok

### Logic.colisão e Logic.comida
O jogo deve se comportar corretamente quando ocorre uma colisão com comida e com paredes.

**Avaliação**

ok

### Transição de mapas
O jogo deve ter transição de mapa uma vez que um mapa é terminado.

**Avaliação**

ok

### Interação com o usuário
O jogo deve perguntar ao usuário se quer continuar/reiniciar o nível/reiniciar o jogo a cada transição de mapa

**Avaliação**

Não implementado.

### Classe Level ou similar
O software deve encapsular as funcionalidades do nível em uma classe.

**Avaliação**

Ok

### Classe Player ou similar
O software deve encapsular as decisões do jogo em uma classe.

**Avaliação**

Ok

### Classe Snake ou similar
O software deve encapsular as funcionalidades relacionadas à snake em uma classe. 

**Avaliação**

OK

## Comentários gerais CP1
- Acho que você poderia tentar explorar mais o game loop pattern, como boa parte do CP1 foi entregue valeria a pena você tentar pensar em como distribuir as funcionalidades entre render/update e process_actions, de acordo com a lógica que você implementou.
- João não falou comigo para apresentar o CP1, se ele apresentar o CP2 vou considerar que ele tem 50% da nota neste CP.