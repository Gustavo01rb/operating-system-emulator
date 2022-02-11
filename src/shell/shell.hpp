#pragma once
#include <iostream>
#include <string>
#include "../kernel/kernel.hpp"

#define QUANTUM_TIME 0.5

class Shell{
    private:
        Kernel* kernel_ref;
        bool    ignore = true;
        int     selected_option = -5;

    public:
        Shell(Kernel* kernel_ref):kernel_ref(kernel_ref){}
        int get_selected_option() const {return this->selected_option;} 
        void start_os();       // Função que inicializa os comandos do Sistema
        void select_option();

    private:        
        void help_command();   // Função que especifica os comandos disponíveis
        void message_exit();



};

