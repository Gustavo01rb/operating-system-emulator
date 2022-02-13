#include "fifo.hpp"

bool Fifo::continuity_test(std::list<Process>::iterator& iterator, int& current_quantum) const{
    if( this->super_low_priority_process.empty() ){ current_quantum--; return false;}
    if(iterator != this->super_low_priority_process.end()) return true;
    iterator++;
    return true;
}


void Fifo::execute_list_processes(){
    if(this->super_low_priority_process.empty()){
        std::cout<<"Erro[44] -> Não há processos para serem executados, tente o comando 'load' para carregar processos." << std::endl;
        return;
    }
    std::list<Process>::iterator current_process = this->super_low_priority_process.end();
    int current_quantum = 0;

    do{

        if(current_quantum <= 0){
            current_process++;
            if(!this->continuity_test(current_process, current_quantum)){
                usleep(100000);
                continue;
            }
            
            current_quantum = this->radom_number(current_process->get_max_quantum());
            current_process->sub_cycles(current_quantum);
        }

        if(current_process->get_status() == STATUS_READY)
            this->execute_process(current_process);
        
        this->add_time();
        this->check_remove_memory_storage();
        this->check_finished_process(current_process);

        usleep(100000);
        current_quantum--;

        if(current_quantum <= 0) this->check_remove_cpu(current_process);
    }while(true);

} 