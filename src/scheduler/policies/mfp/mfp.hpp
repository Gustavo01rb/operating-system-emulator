#pragma once
#include <iostream>
#include "../../scheduler.hpp"
#include "../../../kernel/kernel.hpp"

class Mfp : public Scheduler{
    public:
        Mfp(Kernel* kernel_ref):Scheduler(kernel_ref, false){}
        void execute_list_processes() override;
    private:
        void execute_based_on_fifo(std::list<Process>& current_list, std::list<Process>& next_list);
};