#include <iostream>
#include <string>
#include <pthread.h>

#include "shell/shell.hpp"
#include "kernel/kernel.hpp"
#include "scheduler/scheduler.hpp"
#include "scheduler/policies/fifo/fifo.hpp"
#include "scheduler/policies/lru/lru.hpp"


#include <list>

using namespace std;

int main(){
    system("clear");
    Kernel* kernel = new Kernel();
    Scheduler* scheduler = new Lru(kernel); 
    Shell*  shell  = new Shell(kernel, scheduler);

    shell->start_os();
    return 0;
}


