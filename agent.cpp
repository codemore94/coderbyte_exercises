#include <string>
#include <iostream>

class Agent{
public:
  Agent();
  virtual ~Agent();
  bool set_state();
  bool set_framework();
  bool unset_framework();
  Framework* ret_ptr_to_fw();
private:
  enum state{SLEEPING,AWAKE};
  int status_;
  std::string identity_;
  class Framework{
    public:
      Framework();
    private:
      int refcount_;
  };
  Framework* base;
  
  //Framework::Framework(){}
};

Agent::Agent(){}
Agent::~Agent(){
}
 Agent::set_state(){
  state start = AWAKE;
  return true;
}
Framework* Agent::ret_ptr_to_fw(){
  return base;
}

bool Agent::set_framework(){
  Framework* base = new Framework();
}
bool Agent::unset_framework(){
  delete base;
}

Agent::Framework::Framework():refcount_(0){}

#define PROMPT '#'

int main(){
  //
  Agent agent;
  std::string out;
  
  while(agent.set_state()){
    std::cout<< PROMPT << '\t' ;
    std::cin>> out;
    if(out == "exit"){
      if(agent.ret_ptr_to_fw()){
	delete ret_ptr_to_fw();
      }
      return 0;
    }
    else{
      else if(out == "start framework"){
	agent.set_framework();
      }
    }
  }
}
