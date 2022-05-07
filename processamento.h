//
// Created by aluno on 06/05/22.
//

#ifndef PROJETO_1_DE_PROG_PROCESSAMENTO_H
#define PROJETO_1_DE_PROG_PROCESSAMENTO_H

#include <iostream>
#include <string>
#include <queue>
#include <list>

using namespace std;

struct cliente{
    string classe;
    int prioridade;
    int senha;
    string descricao;
};

void cria_filas (int & classe_opcao);

#endif //PROJETO_1_DE_PROG_PROCESSAMENTO_H
