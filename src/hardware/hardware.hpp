#pragma once
#include <iostream>
#include "../Process/process.hpp"

class Hadware{
    public:
        virtual void insert_process(Process process) = 0;
        virtual void remove_process(int id) = 0;
        virtual void generate_report() const = 0;
        
        struct ContentData{
            int         id;                // ID do processo
            int         time;              // Tempo máximo de castigo
            int         current_time;      // Tempo que ele está na memoria
            bool        alocated;          // variável que define se está alocado ou não 
            std::string description;       // Tipo do processo 
            ContentData(){}
            ContentData(int id, int time, int current_time, std::string description):
                id(id),
                time(time),
                current_time(current_time),
                description(description)
            {
                this->alocated = false;
            }
            ContentData(int id, int time, int current_time, bool alocated, std::string description):
                id(id),
                time(time),
                current_time(current_time),
                alocated(alocated),
                description(description)
            {}
        };
    protected:
        ContentData convert_processes_to_contentData(Process process){
            return ContentData(
                process.get_id(),
                process.get_penalty_time(),
                0,
                true,
                process.get_type()
            );
        }
};