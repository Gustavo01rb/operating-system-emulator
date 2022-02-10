#include "process.hpp"

int         Process::get_id()          const{ return this->id;          }
int         Process::get_cycles()      const{ return this->cycles;      }
short int   Process::get_max_quantum() const{ return this->max_quantum; }
int         Process::get_timestamp()   const{ return this->timestamp;   }
int         Process::get_priority()    const{ return this->priority;    }
std::string Process::get_status()      const{ return this->status;      }
std::string Process::get_type()        const{ return this->type;        }