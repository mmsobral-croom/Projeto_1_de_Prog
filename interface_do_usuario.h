// Created by aluno on 06/05/22.
//

#ifndef PROJETO_1_DE_PROG_INTERFACE_DO_USUARIO_H
#define PROJETO_1_DE_PROG_INTERFACE_DO_USUARIO_H

#include <iostream>
#include <string>
#include "processamento.h"

using namespace std;

//Cria e implementa interface do cliente
void interface_cliente(list<classe> & filas_clientes);

//Cria e implementa interface do atendente
void interface_atendente(list<classe> & filas_clientes);

//Apresenta o menu principal para o usuário
void menu_inicial(list<classe> & filas_clientes);

#endif //PROJETO_1_DE_PROG_INTERFACE_DO_USUARIO_H
