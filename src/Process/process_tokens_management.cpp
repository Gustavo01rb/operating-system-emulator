#include "process.hpp"

void Process::add_token(int token) { this->tokens.push_back(token);}
bool Process::contains_token(int token){ return std::count(this->tokens.begin(), this->tokens.end(), token); }

std::vector<int> Process::get_and_remove_tokens(){
    std::vector<int> assist = this->tokens;
    this->tokens.clear();
    return assist;
}