//
// Created by aluno on 06/05/22.
//

#include "interface_do_usuario.h"
#include "processamento.h"

void interface_cliente(){
    cout << "Selecione o codigo" << endl;
    string codigo;
    cin >> codigo;
   // while(true){
        //if(codigo == "sair") break;
    adiciona_cliente_na_fila_certa(codigo);
    }
//}
