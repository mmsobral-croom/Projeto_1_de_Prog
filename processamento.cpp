#include "processamento.h"
#include "interface_do_usuario.h"


void separa(const string & algo, char sep, queue<string> & q) { //Declara a função separa

    string aux;
    int i = 0;

    if (! algo.empty()) { //Se não for passado como parâmetro para essa função uma string vazia...

        while (i != string::npos) { //Enquanto i não for a última posição da string...
            int pos1 = algo.find_first_not_of(sep,i); //Procure a primeira posição que não é o char separador à partir da posição i. Defina pos1 como essa posição
            int pos2 = algo.find(sep,pos1); //Procure a primeira posição do char separador a paritr de pos1. Defina pos2 como essa posição
            if (pos2 == string::npos) algo.substr(pos1); //Se a pos2 for uma posição inválida, somente copie os chars de pos1 até o fim da string
            aux = algo.substr(pos1,pos2-pos1); //Guarde na variável auxiliar a cópia dos chars entre pos1 e pos2
            q.push(aux); //Coloque na fila q, a substring aux;
            i = pos2; //Defina i como sendo a próxima pos2, para que a busca passe a acontecer a partir do próximo trecho entre chars separadores.
        }

    }
}

//Função que será utilizada para organizar a lista de classes com base na prioridade do cliente
bool ordena_em_prioridade (const classe & c1, const classe & c2){
    return c1.prio < c2.prio;
}

//Função que será utilizada para organizar a lista de classes com base no código do cliente (vai ser útil para menu do cliente)
bool ordena_em_codigo (const classe & c1, const classe & c2){
    return c1.codigo < c2.codigo;
}

//Função que cria as listas contendo todas as classes declaradas no arquivo CSV, já ordenando-as
void cria_classes_ordenadas (const string & csv_file, list<classe> & filas) {
    //Variáveis locais da função:
    string linha_do_csv;
    char separador = ',';
    queue<string> parametros_separados;
    classe uma_classe;

    //Abertura do arquivo csv passado como parâmetro
    ifstream arq(csv_file);

    //Caso o arquivo não tenha sido aberto...
    if (!arq.is_open()){
        cout << "Arquivo Inválido" << endl; //Alerte que o arquivo é inválido
        return; //Encerra a função
    }

    while(getline(arq,linha_do_csv)){ //Enquanto ler uma linha do arquivo csv...
        separa(linha_do_csv,separador,parametros_separados); //Separa as strings da linha e coloque na fila "parâmetros separados"
        while(!parametros_separados.empty()){
            uma_classe.codigo = parametros_separados.front(); //Adicione o primeiro item como sendo o código da classe
            parametros_separados.pop();
            uma_classe.prio = stoi(parametros_separados.front()); //O segundo item como sendo a prioridade (convertida para um inteiro)
            parametros_separados.pop();
            uma_classe.tempo_limite = stoi(parametros_separados.front()); //O terceiro item como o tempo_limite que o cliente dessa classe deve ficar na fila (convertido para um inteiro)
            parametros_separados.pop();
            uma_classe.descricao = parametros_separados.front(); //E o quarto item sendo a descrição da classe
            parametros_separados.pop();
            filas.push_back(uma_classe); //Guarde a classe com seus novos parâmetros dentro de uma lista de classes denominada de "filas"
        }
    }
    filas.sort(ordena_em_prioridade); //Organize a lista de classes com base na prioridada com a qual cada classe deve ser atendida

}

//Função que irá adicionar o cliente na sua respectiva fila, dado o código que ofereceu como entrada ao programa
void adiciona_cliente_na_fila_certa (string & codigo, list<classe> & filas_de_atendimento) {
    cliente cliente_novo;  //Variável local da função

    for(auto & x: filas_de_atendimento){ //Para cada classe da fila de atendimento...
        if(codigo == x.codigo){ //Verificar se o código digitado pelo cliente é igual ao código da classe onde o iterador está atualmente
            if(x.fila.size()<9){ //Se a fila da classe ainda não atingiu tamanho "9"
                cliente_novo.senha = x.codigo + "00" + to_string(x.fila.size()+1); //Atribuir ao cliente a senha "00[tamanho da fila +1]"
            }else if (x.fila.size() >= 9 && x.fila.size() < 99){ //Se a fila da classe está com tamanho entre 9 e 99...
                cliente_novo.senha = x.codigo + "0" + to_string(x.fila.size()+1); //Atribuir ao cliente a senha "0[tamanho da fila +1]"
            }else if (x.fila.size()>=99){ //Se a fila possui tamanho igual ou superior a 99
                cliente_novo.senha = to_string(x.fila.size()+1); //Atribuir ao cliente a senha sendo o tamanho da fila + 1
            }
            x.fila.push(cliente_novo); //Colocar o cliente na fila correspondente ao código que escolheu
            cout << cliente_novo.senha << endl; //Mostra a senha para o cliente
        }
    }
}

void retira_cliente_da_fila(list<classe> & filas_de_clientes) {

    filas_de_clientes.sort(ordena_em_prioridade); //Ordena novamente a lista de classes  em prioridade (precisou ser ordenada em código no menu do cliente)

    auto atual = filas_de_clientes.begin(); //Cria um iterador para o começo da lista de classes
    auto fim = filas_de_clientes.end(); //Cria um iterador para o fim da lista de classes
    fim--; //Coloca o iterador na última classe dentro da lista de classes


    while (atual != filas_de_clientes.end()) { //Enquanto o iterador não estiver no fim da lista

        if (atual == fim && fim->fila.empty()) { //Se o iterador estiver na última classe da lista e a fila desta classe estiver vazia, significa que todas as filas estão vazias...
            cout << "As filas estão vazias, retornando ao menu principal..." << endl << endl; //Então avise que está voltando ao menu inicial
            sleep(3);
            menu_inicial(filas_de_clientes); //Volta para o menu inicial da aplicação após 3 segundos
            return; //Encerre a função

        } else { //Caso contrário...
            if (!atual->fila.empty()) { //Se a fila da classe atual não estiver vazia...
                cout << "Atendendo: " << atual->fila.front().senha << endl << endl; //Mostre o cliente que está atendendo no momento
                atual->fila.pop();
                sleep(1);
                interface_atendente(filas_de_clientes); //Volte para o menu do atendente após 1 segundo
                return; //Encerra a função
            } else { //Caso a fila da classe atual esteja vazia, avance para a próxima classe da lista de classes
                atual++;
            }
        }
    }
}