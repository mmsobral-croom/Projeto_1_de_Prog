#include "interface_do_usuario.h"
#include "processamento.h"

//Função que faz a interface do cliente que está utilizando a  aplicação

void interface_cliente(list<classe> & filas_clientes){

    string codigo; //Variável local da função

    cout << "Digite o código de acordo com o serviço:" << endl;
    cout << endl;
    time_t t1;

    filas_clientes.sort(ordena_em_codigo); //Ordena a lista de classes em código para apresentar ao cliente as opções com o código em ordem alfabética

    cout << "==========================================================" << endl;
    for(auto & x: filas_clientes){ // Para cada item da lista de classes
        cout << x.codigo << ": " << x.descricao << endl; //Apresente o código e a descrição para o cliente escolher
    }
    cout << "==========================================================" << endl;

    cout << endl;

    cout << "Você pode sair do menu cliente a qualquer momento digitando SAIR" << endl;


    while(true){ //Enquanto o loop não for interrompido...
        cin >> codigo; //Leia o que o cliente digitou
        if(codigo == "SAIR"){ //Se o cliente digitou a string "SAIR"
            menu_inicial(filas_clientes); //voltar para o menu princiapl
            break; //Interromper o loop
        }
        adiciona_cliente_na_fila_certa(codigo,filas_clientes); //Adiciona o cliente na fila da classe correspondente ao código que digitou
        cout << endl;
    }
}

//FUnção que faz a interface do atendente que está utilizando a aplicação

void interface_atendente(list<classe> & filas_clientes) {

    string opcao; //Variável local da função

    cout << "Escolha a opção:" << endl;
    cout << "==========================================================" << endl;
    cout << "1: Atender cliente" << endl;
    cout << "2: Sair da interface do atendente" << endl;
    cout << "==========================================================" << endl;

    cin >> opcao; //Ler a opção digitada pelo atendente
    cout << endl;

    if(opcao == "1"){ //Se o atendente digitou 1...
        retira_cliente_da_fila(filas_clientes); //Retira o próximo cliente da fila
        return; //Fim da função
    }else if (opcao == "2"){ //Se o atendente digitou a opção 2...
        menu_inicial(filas_clientes); //Retorna ao menu inicial
        return; //Fim da função
    } else { //Caso não tenha escolhido nenhuma das opções acima...
        cout << "Opção inválida" << endl; //Avisa que a opção é inválida
        cout << endl;
        interface_atendente(filas_clientes); //Mostra a interface de novo para o atendente escolher uma opção
        return; //fim da função
    }
}

//Função que faz a interface do menu inicial da aplicação
void menu_inicial(list<classe> &filas_clientes) {

    string opcao; //Variável local da função

    cout << "Você é cliente ou atendente?" << endl << endl;
    cout << "==========================================================" << endl;
    cout << "1: Cliente" << endl;
    cout << "2: Atendente" << endl;
    cout << "3: Sair" << endl;
    cout << "==========================================================" << endl << endl;

    cin >> opcao; //Ler a opção digitada pelo usuário

    if(opcao == "1"){ //Se o usuário digitou opção 1...
        interface_cliente(filas_clientes); //Apresenta o menu do cliente
        return; //Finalize a função
    }else if(opcao == "2"){ //Se o usuário digitou opção 2...
        interface_atendente(filas_clientes); //Apresenta a interface de atendente
        return; //Finalize a função
    }else if(opcao == "3"){ //Se o cliente digitou opção 3, encerre o programa em 4 segundos e finalize a função
        cout << "==========================================================" << endl;
        cout << "Encerrando aplicação em..." << endl;
        cout << "3" << endl;
        sleep(1);
        cout << "2" << endl;
        sleep(1);
        cout << "1" << endl;
        sleep(1);
        cout << "Até logo!" << endl;
        cout << "==========================================================" << endl;
        sleep(1);
        return;
    } else { //Se o usuário não digitou nenhuma das funções acima...
        cout << "Opção inválida" << endl; //Alerte que a opção é inválida
        menu_inicial(filas_clientes); //E mostre novamente o menu principal.
    }

}