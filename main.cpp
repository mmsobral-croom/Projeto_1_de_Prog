//
// Created by aluno on 06/05/22.
//

#include "interface_do_usuario.h"
#include "processamento.h"

//função main irá basicamente só fazer chamada das funções contidas nos outros arquivos

int main (int argc, char * argv[]) {
    list<classe> lista_com_classes; //Declara a lista com as classes, momentâneamente vazia
    cria_classes_ordenadas(argv[1], lista_com_classes); //Cria as classes e coloca na lista que anteriormente estava vazia
    cout << endl;

    if(!lista_com_classes.empty()){ //Se a lista de classes não estiver vazia
        menu_inicial(lista_com_classes); //Apresente o menu inicial para o usuário
    }
}
