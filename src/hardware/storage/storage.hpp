#pragma once
#include <iostream>
#include "../hardware.hpp"
#include <list>

class Storage :public Hadware{
    private:
        int size_blocks;               // Segmentos
        int allocated_blocks;          // Segmentos alocados
        std::list<ContentData> blocks; // Representação dos segmentos
    
    public:
        Storage(int blocks_size);
        void insert_process (Process process) override;
        void remove_process (int id)          override;
        void generate_report()          const override;     
   
    private:
        void print_list() const;
        void header_report() const;

};