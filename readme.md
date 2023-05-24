# Labirinto: Busca em profundidade (DFS) e Largura (BFS)
 Trabalho da disciplina de Algoritmos e Estruturas de Dados I.
 
 Integrantes: Anielly Gonçalves e Emanuel Vieira Tavares.

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

Além da matriz de entrada que deve ser inserida no diretório do projeto, o usuário deve informar, ao início da execução, se deseja visualizar a busca imprimindo as matrizes no terminal ou se deseja apenas visualizar as informações de comparação de eficiência entre os três algoritmos abordados, atraves de um menu.

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/a57017a1-f41f-412f-af46-a7e743afebe9)


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
![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/8b076f47-3c36-4a6d-9955-2aef20a524f2)

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/0ce3f5d0-c0f5-438f-9fed-a1f7ac8c4322)
![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/6784f4c8-96d8-461e-a668-18912970844f)
![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/ca20734c-b2d6-4d46-a59c-92f7aecdadd5)

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/ec119ab7-70cb-4a39-a64f-63e16898fd6f)
![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/af01a5ac-2c15-4308-a8c0-97ca082178e9)
![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/1f597351-c63a-41f7-b30a-419a02d20e49)


 
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


## Busca em Largura (BFS) e Busca em Profundidade (DFS)
Os algoritmos de busca BFS e DFS apresentam carcaterísticas de implementação muito parecidas. A maior diferença entre os dois é a estrutura de dados auxiliar utilizada: fila ou pilha. Cada estrutura da características diferentes de movimentação quando visualizamos a execução do algoritmo, além de apresentarem número de iterações e tempo de execuções distintos por tomarem decisões diferentes de movimentação ao longo da execução da busca.

O BFS é implementado com a utilização da estrutura de dados fila, que da uma carcaterística de propagação de onda nos movimentos. 

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/2e9352f4-6f57-413e-99c6-ec3e5cc9496a)


O DFS por sua vez é implementado utilizando a estrutura de dados pilha, que da uma carterística de "reta" na propagação do movimento.

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/c78eeb2b-5022-4266-8f76-a4d26088508d)


### Análise de Posições Válidas
Tanto o BFS quanto o DFS usam uma função que recebe a coordenada (x,y) da posição analisada e retorna se a posição é válida ou não. Essa função é importante para a estratégia de movimentação adotada para ambos os algoritmos.

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/2b819212-f5a4-46b4-a9df-4ea1fee9e44f)

As direções de movimentação são: cima, esquerda, baixo, direita.

### Gerar Novos Movimentos
Para gerar novos movimentos, posições precisam ser inseridas na fila e na pilha para serem executados nas próximas iterações. Para isso, a posição corrente tem seus vizinhos verificados pela função "isValidPosition" e verifica-se também se são posições diferentes do elemento de parede (#) que precisa ser desviado. Caso a posição seja válida e diferente de parede, ela é inserida na estrutura de dados. 

As posições são verificadas com um laço for que percorre as 4 possíveis direções que são representadas por 2 vetores de direção: dr para movimentar em linhas e dc para movimentar em colunas.

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/392e5310-1d47-46ba-ab93-b1e2c78d5edf)

A posição corrente é somada com a posição dos vetores dr e dc para obter-se uma nova posição a ser validada e inserida na estrutura:

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/52439664-e614-46b1-8879-d887be767995)

Dessa forma, para essa sequencia de movimentos dos vetores dr e dc as posições da matriz a serem analisadas são:
- Para i = 0: posição de cima 
- Para i = 1: posição de baixo 
- Para i = 2: posição da esquerda 
- Para i = 3: posição da direita

## Critérios de parada
Os critérios de parada para o BFS e para o DFS são:
- Encontrar a posição do ponto de chegada (?).
- A estrutura de dados ficar vazia (fila para o BFS e pilha para o DFS).

## Ciclo de execução BFS:
Fora do loop de execução, ao iniciar o algoritmo, a posição inicial (0,0) é inserida na fila. 
Após isso, o algoritmo entra em um loop while que executa até encontrar um dos critérios de parada.
- Loop:
  - Incrementa o número de iterações;
  - Atribui o primeiro elemento da fila para a posição corrente;
  - Desenfileira, removendo o primeiro elemento;
  - Verifica se a posição corresponde ao ponto de chegada (?)
   - Caso atenda, o algoritmo é encerrado e é apresentado as informações na saída.
  - Verifica se a posição corrente corresponde a elemento de dano;
   - Caso seja:
     - Limpa a fila;
     - Enfileira novamente, inserindo a primeira posição (0,0) da matriz ma fila;
     - Muda a posição de ( * ) para ( 1 ), tornando a caminho livre;
     - Continua para a próxima iteração;
  - Verifica os vizinhos da posição corrente se são válidos e diferentes de parede (#). 
  - Os vizinhos que forem válidos são inseridos na fila com a ordem de prioridade de verificação: cima, baixo, direita, esquerda.
  - Caso o usuário tenha selecionado a opção de impressão das matrizes, imprime a matriz no estado corrente.

#### Exemplo:
Comportamento do algoritmo BFS em uma matriz 5x5 com caminho livre:

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/cf18893c-8547-43f6-8206-f3ed7c9a4026)

Ordem da fila: 1, 6, 2, 11, 7, 3, 16, 12, 8, 4, 21, 17, 13, 9, 5, 22, 18, 14, 10, 23, 19, 15, 24, 20, 25.




## Ciclo de execução DFS:
Fora do loop de execução, ao iniciar o algoritmo, a posição inicial (0,0) é inserida na pilha. 
Após isso, o algoritmo entra em um loop while que executa até encontrar um dos critérios de parada.
- Loop:
  - Incrementa o número de iterações;
  - Atribui o topo da pilha para a posição corrente;
  - Desempilha, removendo o topo da iterção corrente;
  - Verifica se a posição corresponde ao ponto de chegada (?)
   - Caso atenda, o algoritmo é encerrado e é apresentado as informações na saída.
  - Verifica se a posição corrente corresponde a elemento de dano ( * );
   - Caso seja:
     - Limpa a pilha;
     - Insere a primeira posição (0,0) da matriz na pilha;
     - Muda a posição de ( * ) para ( 1 ), tornando a caminho livre;
     - Continua para a próxima iteração;
  - Verifica os vizinhos da posição corrente se são válidos e diferentes de parede (#). 
  - Os vizinhos que forem válidos são inseridos na pilha com a ordem de prioridade de verificação: esquerda, cima, direita, baixo.
  - Caso o usuário tenha selecionado a opção de impressão das matrizes, imprime a matriz no estado corrente.

#### Exemplo:
Comportamento do algoritmo DFS em uma matriz 5x5 com caminho livre:

O caminho que o algoritmo de fato percorre é o caminho colorido. Porém é possível observar que as setas apontam para possíveis posições vizinhas que também são adicionadas na pilha. Entretanto, como a pilha remove o ultimo elemento, e o algoritmo torna o topo da pilha na posição corrente, a matriz recebe esse formato de caminhamento profundo em linha reta.

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/6a4f3ce4-d786-46d0-90ab-4bf0582f9c22)

Ordem da pilha: 1*, 2, 6*, 7, 11*, 12, 16*, 17, 21*, 22*, 23*, 18, 24*, 19, 25*.

As posições marcadas com * foram as posições desempilhadas, que nesse caso, para uma matriz com caminhos livres, coincide com o caminho até a condição de parada.


Obs.: A matriz sem elemetos de dano ( * ) e sem elementos de parede (#) estão presentes apenas para exemplificar como os algoritmos BFS E DFS executam de acordo com a estrutura de dados que cada um utiliza.

# Saída
A saída da execução é apresentada de duas maneiras: um arquivo output.data no diretório dataset e impressão no terminal.

## Arquivo Output:
O arquivo de saída gerado apresenta o estado da matriz em consequência da execução de cada um dos algoritmos de busca, a posição encontrada e o número de iterações.
### Exemplo de saída para uma matriz de entrada simples:
#### Entrada
![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/7bc711da-a5ea-428d-bd6f-6cebfe726428)

#### Arquivo de Saída

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/71ec9372-edd1-4509-b248-56a58b5e09e3)

## Saída do terminal:
A saída do terminal depende da escolha do usuário no início da execução do algoritmo.

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/a57017a1-f41f-412f-af46-a7e743afebe9)

### Visualizando as Matrizes
A cada iteração de cada algoritmo, a matriz no estado corrente é impressa no terminal e, em seguida, a função system("clear") limpa a tela com um delay estabelecido para cada algoritmo de forma que favoreça a visualização da busca.

![Captura de tela de 2023-05-24 08-11-28](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/ecde00cc-c951-41d0-9915-f4391b8eb9cd)
![Captura de tela de 2023-05-24 08-11-39](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/610d5a88-4bf6-4bf3-99a1-f5b46473e043)
![Captura de tela de 2023-05-24 08-11-44](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/31d8aba2-c728-4137-9523-71b2babdd5d1)

Ao fim da execução das buscas, as informações de tempo de execução e número de iterações são informadas. É importante ressaltar que devido ao atraso de impressão, o tempo apresentado é muito maior, mas o número de iterações é coerente.

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/0d31aaeb-b68d-4d75-9deb-93de39743a98)

### Somente Tempo de Execução
Somente o resultado da execução é impresso no terminal.

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/16cf75d6-f695-4b3a-a6f0-16d6e277b65a)


# Tempo de execução
O tempo de execução é calculado utilizando a biblioteca chrono. O contador é iniciado antes do início da execução de um algoritmo na chamada da função start e finaliza após a execução da busca.  

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/ea974dc0-7ad2-4ae1-b4e2-a57a8953a36e)

# Testes e comparação de execução
Para analisar o comportamento dos algoritmos de busca em diferentes matrizes, cada matriz testada foi executada 10 vezes. Em cada teste, valores distintos de tempo de execução foram gerados. 
Para comparar o valor de tempo de execução de cada um dos algoritmos, foi calculada a média aritmética simples dos tempos de execução apresentados em 10 execuções junto do desvio padrão da média.
O desvio padrão irá indicar a dispersão dos dados.

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/519788a3-70b3-4a52-8af8-4ff357348097)
![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/3d03ff33-4ca0-4e1e-9f6c-316fa5a47241)

## Teste 1
Matriz 50x50 com itens # e * formando o labirinto, com o ponto de chegada na ultima posição.

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/30e97e1c-9f89-451a-b968-4bfe79775deb)

### Tempos de execução (em microssegundos)
RND: 1505586, 17532928,14409801,15174466,16635947,14491748,17462575,14651139,14045105,24636014. 

BFS: 1836,1482,1793,1310,1696,1991,1514,1366,1292,1685. 

DFS: 802,571,787,742,750,804,550,603,774,607.

### Média

Media RND: 15054531 microssegundos.

Media BFS: 1597 microssegundos.

Media DFS: 699 microssegundos.

### Desvio Padrão:

DP RND: 5693556 microssegundos.

DP BFS: 240 microssegundos.

DP DFS: 103 microssegundos.
##

Para esse caso de teste o algoritmo de busca em profundidade se mostrou mais eficiente.

## Teste 2
Matriz 50x50 com itens # e * formando o labirinto, com o ponto de chegada no centro da matriz.

![image](https://github.com/em4nuelvt/LabirintoDFSeBFS/assets/64996505/62af7d11-c9fd-4559-b653-150e821fa404)

### Número de iterações

Iterações BFS: 159613

Iterações DFS: 170542

Iterações RND (em média): 305242

### Tempos de execução (em microssegundos)

RND:  24937388,13723787,16328157,25950108,20894583,20194111,21518451,24933455,17318563,17865103

BFS:  18924,20892,21251,24831,19115,19261,21882,22345,22688,28846

DFS:  26855, 25081,25023,25517,25585,24822,28099,25657,24463,39600

### Média

RND: 20366371 microssegundos

BFS: 22004 microssegundos

DFS: 27070 microssegundos

### Desvio Padrão:
RND: 4089867 microssegundos
BFS: 3029 microssegundos
DFS: 4530 microssegundos


# Conclusão
Analisar de forma geral o custo e tempo de execução dos 3 algoritmos e tentar especular qual é mais eficiente, por que, em qual caso, etc.

# Referências (caso precise)

# Especificações de Hardware (talvez)

# Compilação e execução:

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
