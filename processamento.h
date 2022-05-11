//
// Created by aluno on 06/05/22.
//

#ifndef PROJETO_1_DE_PROG_PROCESSAMENTO_H
#define PROJETO_1_DE_PROG_PROCESSAMENTO_H

#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <unistd.h>


using namespace std;

struct cliente{
    int horario;
    string senha;
};

struct classe {
    char codigo;
    int prio;
    int tempo_limite;
    string descricao;
    queue<cliente> fila;
};


void ler_arquivo_inicial();

list<classe>(string & classe);



#endif //PROJETO_1_DE_PROG_PROCESSAMENTO_H
