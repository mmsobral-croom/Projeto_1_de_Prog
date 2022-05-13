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
#include <fstream>
#include <time.h>

using namespace std;

struct cliente{
    int horario;
    string senha;
};

struct classe {
    basic_string<char> codigo;
    int prio;
    int tempo_limite;
    string descricao;
    queue<cliente> fila;
};

void separa (const string & algo, char sep, queue<string> & q);

void cria_classes_ordenadas (list<classe> & filas);

bool ordena_em_prioridade (const classe & c1, const classe & c2);

void adiciona_cliente_na_fila_certa(string & codigo);

void retira_cliente();


#endif //PROJETO_1_DE_PROG_PROCESSAMENTO_H
