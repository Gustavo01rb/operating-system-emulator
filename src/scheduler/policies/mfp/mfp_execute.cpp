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
    for(std::list<Process>::iterator iterator = this->super_low_priority_process.begin(); iterator != this->super_low_priority_process.end(); iterator++){
        iterator->add_token( this->tokens_available.back() );
        this->tokens_available.pop_back();
    }

}

bool Mfp::contains_token(int token)const{ return std::count(this->tokens_available.begin(), this->tokens_available.end(), token); }

void Mfp::raffle(std::list<Process>::iterator& iterator){
    bool number_valid = false;
    int luck_number;
    do{
        luck_number = this->radom_number(this->range_tokens_avaliables - 1);
        if(this->contains_token(luck_number)) continue;
        number_valid = true;
    }while(number_valid == false);

    std::cout<<"\nNúemro sorteado: " << luck_number << std::endl;

    for(iterator = this->super_low_priority_process.begin(); iterator != this->super_low_priority_process.end(); iterator++)
        if(iterator->contains_token(luck_number)) return;
    
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

    do{
        if(current_quantum <= 3){
            generate_tokens();
            distribute_tokens();
            raffle(current_process);
            recover_tokens(current_process);
            print_tokens(this->super_low_priority_process);

            std::cout<<"Processo sortado: " << current_process->get_id() << std::endl;
            current_quantum++;
            std::cout<<"\n\nTokens disponíveis: ";
            for(int x : this->tokens_available) std::cout<<"[" << x << "]  " ;
     std::cout<<std::endl;

        }


    }while(true);

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