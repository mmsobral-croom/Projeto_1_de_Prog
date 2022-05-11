//
// Created by aluno on 06/05/22.
//

#include "processamento.h"

//Cria um temporizador que irá marcar o tempo de espera do cliente na lista;

void temporizador () {

    int segundo = 0, minuto = 0, hora = 0;

    while (true) {

        sleep(1);

        segundo++;


        if (segundo == 60) {
            minuto++;
            segundo = 0;
        }
        if (minuto == 60) {
            hora++;
            minuto = 0;
            segundo = 0;
        }
        system("clear");
        cout << hora << ":" << minuto << ":" << segundo;
    }

}

//Cria as listas de clientes

void cria_listas (int & qtd){
    list<cliente> clientes [qtd];
}

//Coloca os clientes na lista

void coloca_na_lista(cliente & cliente){

}

//Verifica se o CSV tá no formato correto

bool ler_o_arquivo(string & arquivo){

}

