#include <iostream>
#include <string>
#include <pthread.h>

#include "shell/shell.hpp"
#include "kernel/kernel.hpp"
#include "scheduler/scheduler.hpp"
#include "scheduler/policies/fifo/fifo.hpp"
#include "scheduler/policies/lru/lru.hpp"
#include "scheduler/policies/mfp/mfp.hpp"


#include <vector>

using namespace std;

int main(){
    system("clear");
    Kernel* kernel = new Kernel();
    Scheduler* scheduler = new Mfp(kernel); 
    Shell*  shell  = new Shell(kernel, scheduler);

    shell->start_os();
    return 0;
}

/*int main(){
    vector<int> teste;
    teste.push_back(20);
    teste.push_back(30);
    teste.push_back(40);
    teste.push_back(50);

    cout<<"A função contém o número 80?"<<endl;
    bool resposta = count(teste.begin(), teste.end(), 80);
    if(resposta)
        cout<<"Sim" << endl;
    else
        cout<<"Não" << endl;

    vector<int> teste2 = teste;
    teste.clear();
    cout<<"\nValores em teste 1: ";
    for(int x : teste){
        cout<<"["<<x<<"]";
    }
    cout<<"\nValores em teste 2: ";
    for(int x : teste2){
        cout<<"["<<x<<"]";
    }
    


    return 0;
}*/


