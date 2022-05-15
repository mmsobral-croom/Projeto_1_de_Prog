//
// Created by aluno on 06/05/22.
//

#include "interface_do_usuario.h"
#include "processamento.h"

void interface_cliente(list<classe> & filas_clientes){
    string codigo;
    int opcao;

    cout << "Selecione o codigo" << endl;
    cout << endl;

    filas_clientes.sort(ordena_em_codigo);

    for(auto & x: filas_clientes){
        cout << x.codigo << ":" << x.descricao << endl;
    }
    cout << endl;

    cout << "Digite SAIR para sair do menu do cliente" << endl;

   while(true){
       cin >> codigo;
       if(codigo == "SAIR"){
           menu_inicial(filas_clientes);
           break;
       }
       adiciona_cliente_na_fila_certa(codigo,filas_clientes);
       cout << endl;
       cout << "Continuar no menu de cliente?" << endl;
       cout << "1: SIM" << endl;
       cout << "2: NÃO, Voltar ao Menu principal" << endl;
       cin >> opcao;
       cout << endl;
       if(opcao == 1){
           cout << "Então digite mais um código" << endl << endl;
       } else if(opcao == 2) {
           cout << "Retornando ao menu principal..." << endl << endl;
           sleep(1);
           menu_inicial(filas_clientes);
           break;
       }
   }
}

void interface_atendente(list<classe> & filas_clientes) {
    cout << "Escolha a opção:" << endl;
    cout << "1: Atender cliente" << endl;
    cout << "2: Sair da interface do atendente" << endl;
    int opcao;
    cin >> opcao;
    cout << endl;

    switch (opcao) {
        case 1:
            retira_cliente_da_fila(filas_clientes);
            break;

        case 2:
            menu_inicial(filas_clientes);
            break;

        default:
            cout << "Opção inválida" << endl;
            cout << endl;
            interface_atendente(filas_clientes);
            break;
    }
}


void menu_inicial(list<classe> &filas_clientes) {
    int opcao;

    cout << "Você é cliente ou atendente?" << endl;
    cout << "1: Cliente" << endl;
    cout << "2: Atendente" << endl;
    cout << "3: Sair" << endl;
    cout << endl;

    cin >> opcao;

    switch (opcao) {

        case 1:
            interface_cliente(filas_clientes);
            break;

        case 2:
            interface_atendente(filas_clientes);
            break;

        case 3:
            cout << "Encerrando aplicação em..." << endl;
            cout << "3" << endl;
            sleep(1);
            cout << "2" << endl;
            sleep(1);
            cout << "1" << endl;
            sleep(1);
            cout << "Até logo!" << endl;
            sleep(1);
            break;

        default:
            cout << "Opção inválida" << endl << endl;
            menu_inicial(filas_clientes);
    }
}