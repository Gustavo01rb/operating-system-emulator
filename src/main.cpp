#include <iostream>
#include <string>
#include <pthread.h>

#include "shell/shell.hpp"
#include "hardware/storage/storage.hpp"

using namespace std;

int main(){
    system("clear");
    //Shell* shell_ref = new Shell();
    Storage teste = Storage(5);
    //teste.generate_report();
    Process processo(20, 30, 15, 20, 5, "Bonito");

    teste.insert_process(processo);

    teste.generate_report();
    teste.remove_process(20);
    teste.generate_report();


    //shell_ref->start_os();
}