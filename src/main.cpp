#include <iostream>
#include <string>
#include <pthread.h>

#include "shell/shell.hpp"
#include "kernel/kernel.hpp"

using namespace std;

int main(){
    system("clear");
    Kernel* kernel = new Kernel();
    Shell*  shell  = new Shell(kernel); 

    shell->start_os();
}