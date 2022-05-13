

#include "processamento.h"


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

bool ordena_em_prioridade (const classe & c1, const classe & c2){
    return c1.prio < c2.prio;
}

void cria_classes_ordenadas (list<classe> & filas) {
    ifstream arq("/home/lucas/CLionProjects/Projeto_1_de_Prog/teste.txt");
    string linha;
    char separador = ',';
    queue<string> parametros_separados;

    classe classe;

    while(getline(arq,linha)){
        separa(linha,separador,parametros_separados);
        while(!parametros_separados.empty()){
            classe.codigo = parametros_separados.front();
            parametros_separados.pop();
            classe.prio = stoi(parametros_separados.front());
            parametros_separados.pop();
            classe.tempo_limite = stoi(parametros_separados.front());
            parametros_separados.pop();
            classe.descricao = parametros_separados.front();
            parametros_separados.pop();
            filas.push_back(classe);
        }
    }
    filas.sort(ordena_em_prioridade);
}

void adiciona_cliente_na_fila_certa(string & codigo){
    list<classe> lista_classe;
    cliente cliente;
    cria_classes_ordenadas(lista_classe);
    time_t time1;
    for(auto & x: lista_classe){
        if(codigo == x.codigo){
            x.fila.push(cliente);
            cliente.horario = time1;
            cliente.senha = x.codigo + to_string(x.fila.size());
            cout << cliente.senha;
        }
    }
}

void retira_cliente();
