//
// Created by aluno on 06/05/22.
//

#include "interface_do_usuario.h"
#include "processamento.h"

void interface_cliente(list<classe> & filas_clientes){
    string codigo;

    cout << "Digite o código de acordo com o serviço:" << endl;
    cout << endl;

    filas_clientes.sort(ordena_em_codigo);

    for(auto & x: filas_clientes){
        cout << x.codigo << ": " << x.descricao << endl;
    }
    cout << endl;

    cout << "Você pode sair do menu cliente a qualquer momento digitando  SAIR" << endl;

    while(true){
       cin >> codigo;
       if(codigo == "SAIR"){
           menu_inicial(filas_clientes);
           break;
       }
       adiciona_cliente_na_fila_certa(codigo,filas_clientes);
       cout << endl;
   }
}

void interface_atendente(list<classe> & filas_clientes) {
    string opcao;

    cout << "Escolha a opção:" << endl;
    cout << "1: Atender cliente" << endl;
    cout << "2: Sair da interface do atendente" << endl;

    cin >> opcao;
    cout << endl;

    if(opcao == "1"){
        retira_cliente_da_fila(filas_clientes);
        return;
    }else if (opcao == "2"){
        menu_inicial(filas_clientes);
        return;
    } else {
        cout << "Opção inválida" << endl;
        cout << endl;
        interface_atendente(filas_clientes);
        return;
    }
}


void menu_inicial(list<classe> &filas_clientes) {
    string opcao;

    cout << "Você é cliente ou atendente?" << endl;
    cout << "1: Cliente" << endl;
    cout << "2: Atendente" << endl;
    cout << "3: Sair" << endl;
    cout << endl;

    cin >> opcao;

    if(opcao == "1"){
        interface_cliente(filas_clientes);
        return;
    }else if(opcao == "2"){
        interface_atendente(filas_clientes);
        return;
    }else if(opcao == "3"){
        cout << "Encerrando aplicação em..." << endl;
        cout << "3" << endl;
        sleep(1);
        cout << "2" << endl;
        sleep(1);
        cout << "1" << endl;
        sleep(1);
        cout << "Até logo!" << endl;
        sleep(1);
        return;
    } else {
        cout << "Opção inválida" << endl;
        menu_inicial(filas_clientes);
    }

}