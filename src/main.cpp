#include <iostream>
#include <string>
#include <pthread.h>

#include "shell/shell.hpp"
#include "hardware/cpu/cpu.hpp"

using namespace std;

int main(){
    system("clear");
    //Shell* shell_ref = new Shell();
    Cpu teste = Cpu(1);
    teste.generate_report();
    Process processo(20, 30, 15, 20, 5, "Bonito");

    teste.insert_process(processo);

    teste.generate_report();

    //shell_ref->start_os();
}