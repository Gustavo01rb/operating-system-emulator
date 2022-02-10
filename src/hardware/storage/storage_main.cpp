#include "storage.hpp"

Storage::Storage(int blocks_size):size_blocks(blocks_size), allocated_blocks(0){
    for(int i = 0; i < blocks_size; i++)
        this->blocks.push_back( ContentData() );
}


void Storage::insert_process (Process process){
    if(allocated_blocks == size_blocks){
        std::cout<<"Erro [012] -> Não foi possível adicionar pois não há espaço suficiente" << std::endl;
        return;
    }
    ContentData data = Hadware::convert_processes_to_contentData(process);
    for(std::list<Hadware::ContentData>::iterator iter = this->blocks.begin(); iter != this->blocks.end(); iter++){
        if(iter->alocated) continue;
        *iter = data;
        this->allocated_blocks++;
        return;
    }
}

void Storage::remove_process (int id){
    if(this->allocated_blocks == 0){ 
        std::cout<<"Erro [0112] -> O contúdo não pôde ser removido pois não existe, ou não está alocado" << std::endl;
        return;
    }
    for(std::list<Hadware::ContentData>::iterator iter = this->blocks.begin(); iter != this->blocks.end(); iter++){
        if(iter->id != id) continue;
        *iter = Hadware::ContentData();
        this->allocated_blocks--;
        return;
    }
    std::cout<<"Erro [0112] -> O contúdo não pôde ser removido pois não existe, ou não está alocado" << std::endl;
}
