//
// Created by aluno on 06/05/22.
//

#include "interface_do_usuario.h"
#include "processamento.h"


int main () {
    int opcao;
    cliente cliente_teste;
    cin >> opcao;
    cria_filas(opcao);
    cin >> cliente_teste.classe;
    cliente_teste.prioridade = opcao;
}
