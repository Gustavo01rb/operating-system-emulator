#include "kernel.hpp"

Kernel::Kernel(){
    nlohmann::json hardware_info;
    std::ifstream(FileName) >> hardware_info;
    this->cpu    = Cpu     ( hardware_info["cores"]    );
    this->memory = Memory  ( hardware_info["segments"] );
    this->storage = Storage( hardware_info["storage"]);
}

Cpu*      Kernel::get_cpu_ref()     { return &this->cpu;     }
Memory*   Kernel::get_memory_ref()  { return &this->memory;  }
Storage*  Kernel::get_storage_ref() { return &this->storage; }