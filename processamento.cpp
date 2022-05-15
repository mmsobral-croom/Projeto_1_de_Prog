

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
    ifstream arq(csv_file);

    if (!arq.is_open()){
    cout << "Arquivo Inválido" << endl;
    return;
    }

    string linha;
    char separador = ',';
    queue<string> parametros_separados;

    classe uma_classe;

    while(getline(arq,linha)){
        separa(linha,separador,parametros_separados);
        while(!parametros_separados.empty()){
            uma_classe.codigo = parametros_separados.front();
            parametros_separados.pop();
            uma_classe.prio = stoi(parametros_separados.front());
            parametros_separados.pop();
            uma_classe.tempo_limite = stoi(parametros_separados.front());
            parametros_separados.pop();
            uma_classe.descricao = parametros_separados.front();
            parametros_separados.pop();
            filas.push_back(uma_classe);
        }
    }
    filas.sort(ordena_em_prioridade);

}

//Função que irá adicionar o cliente na sua respectiva fila, dado o código que ofereceu como entrada ao programa
void adiciona_cliente_na_fila_certa (string & codigo, list<classe> & filas_de_atendimento) {
    list<classe> lista_classe;
    cliente um_cliente;
    //time_t time1;
    for(auto & x: filas_de_atendimento){
        if(codigo == x.codigo){
            //um_cliente.horario = time1;
            if(x.fila.size()<9){
                um_cliente.senha = x.codigo + "00" + to_string(x.fila.size()+1);
            }else if (x.fila.size() >= 9 && x.fila.size() < 99){
                um_cliente.senha = x.codigo + "0" + to_string(x.fila.size()+1);
            }else if (x.fila.size()>=99){
                um_cliente.senha = to_string(x.fila.size()+1);
            }
            x.fila.push(um_cliente);
            cout << um_cliente.senha << endl;
        }
    }
}

void retira_cliente_da_fila(list<classe> & filas_de_clientes) {
    time_t time0;
    filas_de_clientes.sort(ordena_em_prioridade);

    auto atual = filas_de_clientes.begin();
    auto fim = filas_de_clientes.end();
    fim--;

    while(atual != filas_de_clientes.end()){
        if(atual == fim && fim->fila.empty()){
            cout << "As filas estão vazias, retornando ao menu princial..." << endl << endl;
            sleep(3);
            menu_inicial(filas_de_clientes);
            break;
        } else {
            if (!atual->fila.empty()) {
                cout << atual->fila.front().senha << endl << endl;
                atual->fila.pop();
                sleep(1);
                interface_atendente(filas_de_clientes);
                return;
            } else {
                atual++;
            }
        }
    }
}
