#pragma once
#include <iostream>
#include <fstream>

#include "../hardware/cpu/cpu.hpp"
#include "../hardware/storage/storage.hpp"
#include "../hardware/memory/memory.hpp"
#include "../../lib/json.hpp"

#define FILENAME "hardware.json"

class Kernel{
    private:
        Cpu     cpu;
        Memory  memory;
        Storage storage;
    public:
        Kernel();

        Cpu*     get_cpu_ref();
        Memory*  get_memory_ref();
        Storage* get_storage_ref();

        void report_component( const Hadware& component) const;


};