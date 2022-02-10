#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define STATUS_READY    "Pronto"
#define STATUS_AWAIT    "Em Execucao"
#define STATUS_BLOCK    "Bloqueado"
#define STATUS_FINISHED "Finalizado"

class Process{
    public:
        std::vector<int> tokens;
        int assist;

    private:
        int          id;
        float        cycles;
        short int    max_quantum;
        int          timestamp;
        int          priority;
        std::string  status;
        std::string  type;

    public:
        Process(int id):id(id){}
        Process( 
            int id, 
            float cycles, 
            const short int max_quantum, 
            int timestamp, 
            int priority, 
            std::string type);

    public:
        int         get_id()          const;
        int         get_cycles()      const;
        short int   get_max_quantum() const;
        int         get_timestamp()   const;
        int         get_priority()    const;
        std::string get_status()      const;
        std::string get_type()        const;        

    public:
        void add_timestamp();
        void sub_cycles(int quantum_drawn);

};
