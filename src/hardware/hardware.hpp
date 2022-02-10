#pragma once
#include <iostream>
#include "../Process/process.hpp"

class Hadware{
    public:
        virtual void insert_process(Process process) = 0;
        virtual void remove_process(int id) = 0;
        virtual void generate_report() const = 0;
};