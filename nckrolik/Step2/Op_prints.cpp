#include "Op_prints.h"
#include <iostream>
#include <stdio.h>


Op_prints::Op_prints(int opnd){
  name_buffer = "prints";
  oper = opnd;
}

void Op_prints::operations(std::vector<std::shared_ptr<Stmt>> s_buff, std::ofstream& file){
  std::cout << s_buff[oper]->name_buffer << std::endl;
  file << s_buff[oper]->name_buffer << "\n";
}

int Op_prints::getOper( ) {
  return oper;
}