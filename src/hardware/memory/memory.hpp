#pragma once
#include <iostream>
#include "../hardware.hpp"

class Memory :public Hadware{
    private:
        int segments;            // Segmentos
        int allocated_segments;  // Segmentos alocados
        ContentData* ram;        // Representação dos segmentos
    
    public:
        Memory(int segments);
        void insert_process (Process process) override;
        void remove_process (int id)          override;
        void generate_report()          const override;     
   
    private:
        int  hashing_function(int key, int size);
    private:
        void print_list() const;
        void header_report() const;

};