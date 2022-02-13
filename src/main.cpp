#include <iostream>
#include <string>
#include <pthread.h>

#include "shell/shell.hpp"
#include "kernel/kernel.hpp"
#include "scheduler/scheduler.hpp"
#include "scheduler/policies/fifo/fifo.hpp"

#include <list>

using namespace std;

int main(){
    system("clear");
    Kernel* kernel = new Kernel();
    Scheduler* scheduler = new Fifo(kernel); 
    Shell*  shell  = new Shell(kernel, scheduler);

    shell->start_os();
    return 0;
}


/*void cav(list<int>::iterator iter){(*iter)++;}
int main(){
    
    list<int> teste1;
    list<int> teste2;
    list<int>::iterator teste_i1;
    list<int>::iterator teste_i2;
    teste1.push_back(10);
    teste1.push_back(20);
    teste1.push_back(30);
    teste_i1 = teste1.begin();


    cout<<"Elementos lista 1: " << endl;
    for(int i = 0; i < 10; i++){
        cout<<"Valor de i: " << i << "  Valor do elemento: " << *teste_i1 << endl;
        cav(teste_i1);
    }

    return 0;
}*/

/*void remove(list<int>::iterator iter, list<int>& teste){
    cout<<"Elemento removido: " << *iter<<endl;
    teste.erase(iter);
}
int main(){
    
    list<int> teste1;
    list<int>::iterator teste_i1;
    list<int>::iterator teste_i2;
    teste1.push_back(10);
    teste1.push_back(20);
    teste1.push_back(30);
    teste_i1 = teste1.begin();
    cout<<"Iterator 1: " << *teste_i1 << endl;
    teste_i1++;
    remove((teste_i1--), teste1);
    cout<<"Iterator 1: " << *teste_i1 << endl;

    teste_i1++;
    teste_i1++;
    teste_i1++;
    teste_i1++;
    teste_i1++;
    teste_i1++;

    cout<<"Iterator 1: " << *teste_i1 << endl;
    cout<<"Primeiro elemento: " << teste1.front() << endl;


    return 0;
}*/