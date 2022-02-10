#pragma once
#include <iostream>
#include <vector>
#include "../hardware.hpp"
#include "../../Process/process.hpp"

class Cpu: public Hadware{
    private:
        int size_cores;
        std::vector<Process> cores;
        Process history_process;
    public:
        Cpu(int cores);
        void insert_process (Process process) override;
        void remove_process (int id)          override;
        void generate_report()          const override;
    private:
        void print_list() const;
        void header_report() const;
        
};