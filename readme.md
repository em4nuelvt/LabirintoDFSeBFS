# Labirinto: Busca em profundidade (DFS) e Largura (BFS)
 Trabalho da disciplina de algoritmos e estruturas de dados 1

## O problema

Encontrar uma posição em um labirinto utilizando as estratégias de busca randomica, busca em largura(bfs) e busca em profundidade(dfs) de acordo com as seguintes regras:

- A matriz será lida de um arquivo input.data no diretorio dataset do projeto.

- Há uma única matriz de tamanho NxN (considerar testes em matrizes grandes).

- A matriz do labirinto é apresenta os seguintes elementos:

    - Caminho livre (1): Quando a posição estiver preenchida pelo número um (1), a passagem será livre.

    - Dano ( * ): Se a posição possuir um carácter asterisco (*) representará um dano. E ele faz com que o caminhamento volte para a posição inicial (0,0) e a posição acessada que    tinha um dano * vire passagem livre (1).

    - Parede (#): Caso seja uma parede (#) não há como caminhar por ela. Por ser um obstáculo, deverá contorná-la.

    - Ponto de chegada (?): é o objetivo de cada algoritmo, quando sua posição for encontrada a busca se encerra.

Dessa forma, analisando os três métodos de busca, deve-se apresentar uma análise de custo e tempo de execução de cada um, a fim de comparar cada algoritmo.

# Visão Geral

A proposta consiste na utilização de três métodos de busca para encontrar a posição que possui o elemento (?) dentro de uma matriz NxN e analisar o tempo de execução e número de iterações que cada algoritmo apresenta ao fim da execução.

Os três métodos de busca utilizados são:

- Busca Randômica: A partir da posição inicial, novas posições são geradas aleatoriamente para caminhar entre as posições da matriz.
- Busca em largura (bfs): A partir da posição inicial, as posições vizinhas são analisadas e, caso sejam posições válidas, são adicionadas a uma estrutura de dados fila que controla o caminhamento na matriz.
- Busca em profundidade (dfs): A partir da posição inicial, as posições vizinhas são analisadas e, caso sejam posições válidas, são adicionadas a uma pilha que controla o caminhamento na matriz.

Para esse algoritmo a posição inicial adotada é sempre a posição (0,0).

# Entrada

A entrada consiste de um arquivo "input.data" que se encontra no diretório "dataset" do projeto. O arquivo foi gerado a partir de um apicativo gerador disponibilizado pelo professor. O arquivo apresenta em sua primeira linha as informações da dimensão da matriz: número de linhas e número de colunas da matriz. Exemplo de entrada:

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/e60c21e4-0c81-4335-a337-5d2aab2658ab)

Obs.: A matriz de exemplo possui dimensões inferiores para simplificar a exemplificação da entrada. Porém o intuido é executar o algoritmo em matrizes de ordem 50 ou superior.

A matriz é alocada, lida ao inicio da execução de cada algoritmo e sua memória é liberada ao fim da execução.

Além da matriz de entrada que deve ser inserida no diretório do projeto, o usuário deve informar ao início da execução se deseja visualizar a busca imprimindo as matrizes ou se deseja apenas visualizar as informações de comparação de eficiência entre os três algoritmos abordados.

# Estratégias de Implementação
A implentação da solução foi feita em c++ somente para a utilização da biblioteca fstream para leitura de arquivos eescrita de arquivos.Por isso, o código não segue todos os padrões de orientação a objetos. Os algoritmos apresentam várias funções auxiliares de execução, mas o "cérebro" se encontra nas funções "start" que lidam com toda a execução.
Como trata-se de um projeto envolvendo 3 algoritmos distintos, a implementação foi dividida em  funções "start" diferentes que iniciam a execução de cada um deles.

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/47cfb764-1234-452a-8754-2b852da56a19)

As estratégias de movimentação na matriz e de implementação de cada um dos métodos de busca será detalhada a seguir:

## Busca Randômica
### Caminhamento dentro da matriz
As decisões de movimentação são baseadas na posição corrente da matriz, pois as possibilidades de movimento vão depender se a iteração atual se encontra em algum vértice, nas laterais(primeiras e ultimas linhas e colunas) ou no centro do labirinto.
Essa posição relativa foi subdividida em 9 casos. São eles:

1. Vertice superior esquerdo: movimenta para a direita ou para baixo.

2. Vertice superior direito: Movimenta para esquerda ou para baixo

3. Vertice inferior esquerdo: Movimenta para direita ou para cima.

4. Vertice inferior direito: Movimenta para esquerda ou para cima.

5. Primeira Linha: Movimenta para esquerda, para direita ou para baixo.

6. Primeira Coluna: Movimenta para cima, para baixo ou bara direita.

7. Ultima linha: Movimenta para direita, para a esquerda ou para cima.

8. Ultima coluna: Movimenta para cima, para baixo ou para a esquerda.

9. Meio da matriz: Movimenta em todas as direções (esquerda, cima, direito, baixo).

 Os casos estão representados a seguir
 
 ![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/93cf5a82-0f34-4fb1-a01c-3d722caf6694)
![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/4ff691c4-bf9a-4b2e-85fc-f10bcf32fd86)

 
 Para cada caso, valores são gerados aleatoriamente por uma função geradora que indica ao algoritmo qual sera o próximo movimento na matriz, dentre os movimentos possíveis.
 
### Critério de parada:
 No algoritmo randômico, o único critério de parada estabelecido é encontrar o caractere (?) que finaliza a execução.
 
### Ciclo de execução/implementação
 A execução é feita dentro de um laço while com o seguinte ciclo de execução:
 
 
* Verifica se atende ao critério de parada;
  * Caso atenda, sai do loop.
* Verifica a posição atual da matriz para executar alguma ação: 
  * Item de dano ( * ): reinicia matriz para posição (0,0);
* Gera um novo movimento aletoriamente com uma função;
      * Verificar se é parede, caso seja, entra em um ciclo até gerar um caminho possível;
