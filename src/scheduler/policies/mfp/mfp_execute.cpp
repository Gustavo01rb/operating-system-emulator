#include "mfp.hpp"
void print_tokens(const std::list<Process> list);

void Mfp::generate_tokens(){
    int number_of_tokens_generated = (int) this->super_low_priority_process.size() - (int) this->tokens_available.size();

    if(number_of_tokens_generated <= 0) return; // Já possuo todos os tokens que preciso (pelo menos 1 token para cada processo)

    for(int i = 0; i < number_of_tokens_generated; i++)
        this->tokens_available.push_back(range_tokens_avaliables + i);
    
    this->range_tokens_avaliables += number_of_tokens_generated;
}

void Mfp::distribute_tokens(){
    if(this->super_low_priority_process.empty()) return;
    int division = (int) this->tokens_available.size() / (int) this->super_low_priority_process.size();
    for(int i = 0; i < division; i++)
    for(std::list<Process>::iterator iterator = this->super_low_priority_process.begin(); iterator != this->super_low_priority_process.end(); iterator++){
        iterator->add_token( this->tokens_available.back() );
        this->tokens_available.pop_back();
    }

}

bool Mfp::contains_token(int token)const{  
    for(int i : this->tokens_available)
        if(token == i) return true;
    return false;  
}

void Mfp::raffle(std::list<Process>::iterator& iterator){
    if(this->super_low_priority_process.size() == 1){
        iterator = this->super_low_priority_process.begin();
        return;
    }
    bool number_valid = false;
    int luck_number;
    int attempts = 15;
    while(attempts > 0){

        do{
            luck_number = this->radom_number(this->range_tokens_avaliables - 1);
            if(this->contains_token(luck_number)) continue;
            number_valid = true;
        }while(number_valid == false);

        for(iterator = this->super_low_priority_process.begin(); iterator != this->super_low_priority_process.end(); iterator++)
            if(iterator->contains_token(luck_number)) return;
        attempts--;
    }
    std::cout<<"Erro crítico, ninguém tem o número sorteado: "<< luck_number << std::endl;
    exit(90);
}

void Mfp::recover_tokens(std::list<Process>::iterator& iterator){
    std::vector<int> assit = iterator->get_and_remove_tokens();
    for(int x : assit)
        this->tokens_available.push_back(x);
}

void Mfp::execute_based_on_mfp(){
    if(this->super_low_priority_process.empty()){
        std::cout<<"Erro[44]-> Não há processos a serem executados."<<std::endl;
        return;
    }

    int current_quantum = 0;
    std::list<Process>::iterator current_process;
    int initial_size_list_process = (int) this->super_low_priority_process.size();

    do{
        if(current_quantum <= 0){
            generate_tokens();
            distribute_tokens();
            /*print_tokens(this->super_low_priority_process);
            std::cout<<"\n\nTokens avaliables: " ;
            for(int x : this->tokens_available) std::cout<<"[" << x << "]  " ;*/
            raffle(current_process);
            recover_tokens(current_process);
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

        if(current_quantum <= 0 && current_process != this->super_low_priority_process.end()){
            this->check_remove_cpu(current_process);
            current_process->set_status_ready();
        }


    }while((int) this->finalized.size() < initial_size_list_process);

}


void print_tokens(const std::list<Process> list){
     std::cout<<std::endl;
    for(Process teste : list){
        std::cout<<"\nProcesso " << teste.get_id() << ": ";
        std::vector<int> tokens = teste.get_and_remove_tokens();
        for(int x : tokens) std::cout<<"[" << x << "]  " ;
    }
     std::cout<<std::endl;


}