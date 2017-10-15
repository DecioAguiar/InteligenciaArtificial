#include <iostream>
#include "action.h"
#include "perception.h"
#include "tabledrivenagent.h"
#include "simplereflexagent.h"
#include "enviroment.h"
#include <map>

using namespace std;

int main()
{

    //tabela de acoes do trabledrivenagent
    map < pair<bool,bool>, string> table;
    table[make_pair(0,1)] = "Aspirar";
    table[make_pair(0,0)] = "Direita";
    table[make_pair(1,0)] = "Esquerda";
    table[make_pair(1,1)] = "Aspirar";

    //Sala que o agente está
    map < bool, string > sala;
    sala[0] = "A";
    sala[1] = "B";

    //Estado da sala
    map<bool, string> estado;
    estado[0] = "Limpo";
    estado[1] = "Sujo";

    //Inicializando tableagent
    TableDrivenAgent agent;
    agent.table = table;

    //inicializando simplereflexagent
    SimpleReflexAgent agentsr;

    //Numero de Iteracoes
    int N;

    //Inicializando ambiente
    Enviroment ambiente;

    cout << "Informe a configuracao inicial do ambiente: " << endl;
    cout << "Se A esta sujo digite 1, 0 caso contrario." << endl;

    cin >> ambiente.isDirtyA;

    cout << "Se B esta sujo digite 1, 0 caso contrario." << endl;

    cin >> ambiente.isDirtyB;

    cout << "Se o agente esta em A digite 0, 1 caso contrario " << endl;

    cin >> ambiente.agentLocation;

    //Percepcao inicial do agente
    Perception perception;
    if(ambiente.agentLocation){
        perception.isDirty = ambiente.isDirtyB;
        perception.location = ambiente.agentLocation;
    } else {
        perception.isDirty = ambiente.isDirtyA;
        perception.location = ambiente.agentLocation;
    }




    cout << "Digite o numero de iteracoes: " << endl;
    cin >> N;

    cout<< "Escolha qual agente deseja utilizar: " << endl;
    cout<< "Digite 1 para Table Driven Agent."<< endl;
    cout<< "Digite 2 para Simple Reflex Agent." << endl;

    int key;
    cin >> key;

    switch(key){
        case 1:
            while(N > 0){
               cout << "Localizacao do agente: " << sala[ambiente.agentLocation] << endl;
               cout << "Estado do Ambiente A: " << estado[ambiente.isDirtyA] << endl;
               cout << "Estado do Ambiente B: " << estado[ambiente.isDirtyB] << endl;
               Action a = agent.selectAction(perception);
               cout << "Acao selecionada: " << a.name << endl;
               cout << endl;

               perception = ambiente.updateEnviroment(a);

               N--;
            }
        break;

        case 2:
            while(N > 0){
               cout << "Localizacao do agente: " << sala[ambiente.agentLocation] << endl;
               cout << "Estado do Ambiente A: " << estado[ambiente.isDirtyA] << endl;
               cout << "Estado do Ambiente B: " << estado[ambiente.isDirtyB] << endl;
               Action a = agentsr.selectAction(perception);
               cout << "Acao selecionada: " << a.name << endl;
               cout << endl;

               perception = ambiente.updateEnviroment(a);

               N--;
            }
        break;
    }

    return 0;

}

