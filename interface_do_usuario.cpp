//
// Created by aluno on 06/05/22.
//

#include "interface_do_usuario.h"
#include "processamento.h"

void interface_cliente(){
    cout << "Selecione o codigo" << endl;
    string codigo;
   while(codigo != "sair"){
       cin >> codigo;
       adiciona_cliente_na_fila_certa(codigo);
    }
}
