#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "StringTable.h"
#include "InstructionMemory.h"
#include "DataMemory.h"
#include "RunTime.h"

int main(int argc, char** argv){
  int pc = 0;
  std::string fName = argv[1];
  std::string binName = argv[2];
  static std::ofstream file;
  InstructionMemory imem(fName, binName);

  
  std::size_t lastSlashPos = fName.find_last_of('/');
  std::size_t firstDotPos = fName.find_last_of('.');
  std::string outFilename = "VMOutputTest/" + fName.substr(lastSlashPos + 1,firstDotPos + 1) + ".vout";
  file.open (outFilename);

  DataMemory* dm_stack = new DataMemory;
  std::vector<std::shared_ptr<Stmt>> i_mem = imem.getInstructionMemory();
  std::vector<std::shared_ptr<Stmt>> s_buff = imem.getStringBuffer();

  RunTime* rt_stack = new RunTime; 
  std::vector<int> return_add; 
  int end_index = 0;

  for(int i = 0; i < i_mem.size(); i++){
    if(i_mem[i]->name_buffer == "exit"){
      end_index = i;
    }
  }
  
  int sub_route_vars = 0;

  while(pc != end_index){

    if(i_mem[pc]->name_buffer == "start program"){
      i_mem[pc]->operation(dm_stack);
      pc++;
    }
    
    else if(i_mem[pc]->name_buffer == "enter sub"){
      i_mem[pc]->operation(dm_stack);
      sub_route_vars = i_mem[pc]->getOper();
      pc++;
    }
    
    else if(i_mem[pc]->name_buffer == "gosub"){
      return_add.push_back(pc + 1);
      pc = i_mem[pc]->getOper();
    }

    else if(i_mem[pc]->name_buffer == "return"){
      int temp = pc;
      i_mem[temp]->operation(dm_stack, sub_route_vars);
      pc = return_add.back();
      return_add.pop_back();
    }

    else if(i_mem[pc]->name_buffer == "jumpnzero"){
      int top = rt_stack->getLast();
      rt_stack->eraseBack();
      if(top != 0){
        pc = i_mem[pc]->getOper();
      }
      else{
        pc++;
      }
    }
    else if(i_mem[pc]->name_buffer == "jumpzero"){
      int top = rt_stack->getLast();
      rt_stack->eraseBack();
      if(top == 0){
        pc = i_mem[pc]->getOper();
      }

      else{
        pc++;
      }
    }

    else if(i_mem[pc]->name_buffer == "jump"){
      pc = i_mem[pc]->getOper();
    }

    else if(i_mem[pc]->name_buffer == "printtos"){
    i_mem[pc]->operation(rt_stack, file);
    pc++;
    }

    else if(i_mem[pc]->name_buffer == "pushi" || i_mem[pc]->name_buffer == "add" || i_mem[pc]->name_buffer == "mul" || i_mem[pc]->name_buffer == "dup" || i_mem[pc]->name_buffer == "negate" || i_mem[pc]->name_buffer == "swap" || i_mem[pc]->name_buffer == "pop" || i_mem[pc]->name_buffer == "div") {
      i_mem[pc]->operation(rt_stack);
      pc++;
    }

    else if(i_mem[pc]->name_buffer == "popScalar" || i_mem[pc]->name_buffer == "pushscalar"){
      i_mem[pc]->operation(rt_stack, dm_stack);
      pc++;
    }

    else if(i_mem[pc]->name_buffer == "pop array" || i_mem[pc]->name_buffer == "pusharray") {
      i_mem[pc]->operation(rt_stack, dm_stack);
      pc++;
    }

    else if(i_mem[pc]->name_buffer == "prints") {
      std::cout << s_buff[i_mem[pc]->getOper()]->name_buffer << std::endl;
      file << s_buff[i_mem[pc]->getOper()]->name_buffer << std::endl;
      pc++;
    }
  }
}
