//
// Created by aluno on 06/05/22.
//

#include "interface_do_usuario.h"
#include "processamento.h"

void interface_cliente(list<classe> & filas_clientes){
    string codigo;

    cout << "Selecione o codigo" << endl;
    cout << endl;

    filas_clientes.sort(ordena_em_codigo);

    for(auto & x: filas_clientes){
        cout << x.codigo << ":" << x.descricao << endl;
    }
    cout << endl;

   while(codigo != "Sair"){
       cin >> codigo;
       adiciona_cliente_na_fila_certa(codigo,filas_clientes);
    }
}
