#include "execucao.hpp"
#include <chrono>   
#include <string>

void execucao(){
    int escolha;

    ofstream outFile("dataset/output.data");

    system("clear");
    cout<<"----------------------------------MENU---------------------------------"<<endl;
    cout<<"1- Visualizar matrizes (tempo de execução significativamente maior)"<<endl;
    cout<<"2- Somente exibir tempo de execução"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    while(true){
        cout<<"Digite uma opção: ";
        cin>>escolha;
        if(cin.fail()||(escolha>2)||(escolha<1)){
            cout<<"Digite um número válido!"<<endl;
            cin.clear();
            setbuf(stdin,0);
            continue;
        }
        else{
            break;
        }
    }   
    string exibe;
    int iteracoesRandom=0, iteracoesBfs=0, iteracoesDfs=0;



    auto start_time2 = chrono::high_resolution_clock::now();
    startBfs(&iteracoesBfs, &exibe,escolha,outFile);
    auto end_time2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end_time2 - start_time2);

    auto start_time3 = chrono::high_resolution_clock::now();
    startDfs(&iteracoesDfs,&exibe, escolha,outFile);
    auto end_time3 = chrono::high_resolution_clock::now();
    auto duration3 = chrono::duration_cast<chrono::microseconds>(end_time3 - start_time3);

    auto start_time1 = chrono::high_resolution_clock::now();
    startRandom(&iteracoesRandom,&exibe, escolha,outFile);
    auto end_time1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end_time1 - start_time1);

    cout<<exibe;
    outFile<<endl<<exibe;

    cout << "Tempo de execução RND: " << duration1.count() << " microssegundos\n";
    cout << "Tempo de execução BFS: " << duration2.count() << " microssegundos\n";
    cout << "Tempo de execução DFS: " << duration3.count() << " microssegundos\n";

    outFile << "Tempo de execução RND: " << duration1.count() << " microssegundos\n";
    outFile << "Tempo de execução BFS: " << duration2.count() << " microssegundos\n";
    outFile << "Tempo de execução DFS: " << duration3.count() << " microssegundos\n";

    outFile.close();
    return ;

}