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


    public:
        Scheduler(Kernel* kernel_ref);
        void load_list_processes(bool use_single_row);
        bool report_processes() const;

};

