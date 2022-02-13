#pragma once

#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <time.h>
#include <unistd.h>

#include "../Process/process.hpp"
#include "../kernel/kernel.hpp"
#include "../../lib/json.hpp"
#include "../hardware/cpu/cpu.hpp"
#include "../hardware/memory/memory.hpp"
#include "../hardware/storage/storage.hpp"

#define PROCESSES_FILE "processos.json"
#define LIST_NAME "all"


class Scheduler{
    protected:
        Kernel*  kernel_ref;
        Cpu*     cpu_ref;
        Memory*  memory_ref;
        Storage* storage_ref;

        std::list<Process> high_priority_process;
        std::list<Process> medium_priority_process;
        std::list<Process> low_priority_process;
        std::list<Process> super_low_priority_process;

        std::list<Process> block;
        std::list<Process> finalized;
        bool single_list;

    public:
        Scheduler(Kernel* kernel_ref, bool single_list);
        void load_list_processes();
        virtual void execute_list_processes() = 0;
        bool report_processes() const;
    
    protected:
        int radom_number(int max) const;
        void execute_process(std::list<Process>::iterator& iterator);
        void insert_process_block_list(std::list<Process>::iterator iterator);
    
};

