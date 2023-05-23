# Labirinto: Busca em profundidade (DFS) e Largura (BFS)
 Trabalho da disciplina de algoritmos e estruturas de dados 1

## Exercício Proposto 

 - Há uma única matriz de tamanho NxN que possui 4 tipos de elementos espalhados aleatoriamente.

 - Quando a posição estiver preenchida pelo número um (1), a passagem será livre.

 - Se a posição possuir um carácter asterisco (*)  representará um dano. E ele faz com que o caminhamento volte para a posição inicial (0,0) e a posição acessada que tinha um dano * vire passagem livre (1).

 - Caso seja uma parede (#) não há como caminhar por ela. Por ser um obstáculo, deverá contorná-la.

 - E existe o ponto de chegada (?) que quando encontrado encerrará o caminhamento.

 - Para essa atividade a matriz será lida de um arquivo input.data e também precisará ser precorrida através de três métodos: randômico, BFS(largura) e DFS(profundidade). Por eles será possível observar o custo computacional e o comportamento do algoritmo.

## Visão Geral

A porposta consiste na utilização de uma estratégia  de caminhamento randômica em que as posições posteriores são geradas aleatoriamente e na estratégida de caminhamento de largura e profudidade em que as posições posteriores seguirão padrões que serão explicados. Nos três métodos haverá o critério de parada que é o ponto de chegada(?).

## Caminhamento dentro da matriz

As decisões de movimentação são baseadas na posição em que se encontra na matriz, pois as possibilidades de movimento vão depender se está em algum vértice, nas laterais(primeiras e ultimas linhas e colunas) ou no centro do labirinto. Essa posição relativa foi subdividida em 9 casos. São eles:
Vertice superior esquerdo: movimenta para a direita ou para baixo.
1. Vertice superior direito: Movimenta para esquerda ou para baixo

2. Vertice inferior esquerdo: Movimenta para direita ou para cima.

3. Vertice inferior direito: Movimenta para esquerda ou para cima.

4. Primeira Linha: Movimenta para esquerda, para direita, para baixo.

5. Primeira Coluna: Movimenta para cima, para baixo, bara direita.

6. última linha: Movimenta para direita, para a esquerda, para cima.

7. Última coluna: Movimenta para cima, para baixo, para a esquerda.

8. Meio da matriz: Movimenta em todas as direções.   


