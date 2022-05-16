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

   while(true){
       cin >> codigo;
       if(codigo == "SAIR"){
           menu_inicial(filas_clientes);
           break;
       }
       adiciona_cliente_na_fila_certa(codigo,filas_clientes);
    }
}

void interface_atendente(list<classe> & filas_clientes){
    cout << "Escolha a opção:" << endl;
    cout << "1: Atender cliente" << endl;
    cout << "2: Sair da interface do atendente" << endl;
    int opcao;
    cin >> opcao;

    switch (opcao){
        case 1:
                for(auto & x: filas_clientes){
                    cout << x.fila.front().senha << endl;
                }if(opcao == 2){
                    menu_inicial(filas_clientes);
                }
            }
    }


void menu_inicial(list<classe> & filas_clientes){
    int opcao;

    cout << "Você é cliente ou atendente?" << endl;
    cout << "1: Cliente" << endl;
    cout << "2: Atendente" << endl;
    cout << endl;

    cin >> opcao;
    switch (opcao) {
        case 1:
            if (opcao == 1){
                interface_cliente(filas_clientes);
                break;case 2:
                interface_atendente(filas_clientes);
                break;
            }
        default:
            cout << "Opção inválida" << endl;
    }
}
