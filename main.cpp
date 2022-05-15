//
// Created by aluno on 06/05/22.
//

#include "interface_do_usuario.h"
#include "processamento.h"


int main (int argc, char * argv[]) {
    list<classe> lista_teste;
    cria_classes_ordenadas(argv[1], lista_teste);
    cout << endl;

    if(!lista_teste.empty()){
        menu_inicial(lista_teste);
    }
}
