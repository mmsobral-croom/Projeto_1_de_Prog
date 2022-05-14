//
// Created by aluno on 06/05/22.
//

#include "interface_do_usuario.h"
#include "processamento.h"


int main () {
    list<classe> lista_teste;
    cria_classes_ordenadas("/home/aluno/CLionProjects/Projeto_1_de_Prog/teste.txt", lista_teste);
    cout << endl;
    menu_inicial(lista_teste);
}

