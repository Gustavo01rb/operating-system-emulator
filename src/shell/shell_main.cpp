#include "shell.hpp"
#include <pthread.h>


std::string selected_option;
bool ignore = true;

void* select_option( void* t ){
    std::cin >> selected_option;
    ignore = false;
    pthread_exit(t);
}

void Shell::start_os(){
    pthread_t thread_shell_option; 

    if((pthread_create(&thread_shell_option, NULL, select_option, NULL) != 0)){
        printf("Erro ao criar a thread.");
        exit(EXIT_FAILURE);
    }
    
    do{
        if(ignore) continue;

        if(selected_option == "help" || selected_option == "0" ){
            this->help_command();
            ignore = true;
        }   
        
        else if(selected_option == "meminfo"    || selected_option == "1" ){}  
        
        else if(selected_option == "diskinfo"   || selected_option == "2" ){}  
        
        else if(selected_option == "cpuinfo"    || selected_option == "3" ){}  
        
        else if(selected_option == "load"       || selected_option == "4" ){}  
        
        else if(selected_option == "queueschell"|| selected_option == "5" ){}  
        
        else if(selected_option == "execute"    || selected_option == "6" ){}   
        
        else if(selected_option == "kill -9"    || selected_option == "7" ){}   
        
        else if(selected_option == "exit"                                 ){} ;


    }while(selected_option != "8");



}