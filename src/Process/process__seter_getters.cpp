#include "process.hpp"

void Process::set_penalty_time(int penalty_time){
    if(penalty_time < 0 || penalty_time > 10){
        std::cout<<"Erro[15]-> Não foi possível atribuir um valor de penalidade de tempo ao processo." <<std::endl;
        return;
    }
    this->penalty_time = penalty_time;
}

int         Process::get_id()          const{ return this->id;          }
int         Process::get_cycles()      const{ return this->cycles;      }
int         Process::get_penalty_time()const{ return this->penalty_time;}
short int   Process::get_max_quantum() const{ return this->max_quantum; }
int         Process::get_timestamp()   const{ return this->timestamp;   }
int         Process::get_priority()    const{ return this->priority;    }
std::string Process::get_status()      const{ return this->status;      }
std::string Process::get_type()        const{ return this->type;        }
