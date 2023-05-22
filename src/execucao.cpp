#include "execucao.hpp"
#include <chrono>   
#include <string>
void execucao(){
    
    string exibe;
    int iteracoesRandom=0, iteracoesBfs=0, iteracoesDfs=0;

    auto start_time1 = chrono::high_resolution_clock::now();
    startRandom(&iteracoesRandom,&exibe);
    auto end_time1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end_time1 - start_time1);

    auto start_time2 = chrono::high_resolution_clock::now();
    startBfs(&iteracoesBfs, &exibe);
    auto end_time2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end_time2 - start_time2);

    auto start_time3 = chrono::high_resolution_clock::now();
    startDfs(&iteracoesDfs,&exibe);
    auto end_time3 = chrono::high_resolution_clock::now();
    auto duration3 = chrono::duration_cast<chrono::microseconds>(end_time3 - start_time3);

    cout<<exibe;

    cout << "Tempo de execução RND: " << duration1.count() << " microssegundos\n";
    cout << "Tempo de execução BFS: " << duration2.count() << " microssegundos\n";
    cout << "Tempo de execução DFS: " << duration3.count() << " microssegundos\n";

    return ;

}