#include <iostream>
#include "pushi.h"


PushI::PushI(int op){
  op_code = "PushI";
  OP = 0x00000022;
  operand = op;
}

void PushI::printOps(std::ofstream& file){
  file << op_code << " " << operand << "\n";
}

void PushI::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  file.write((char*)&operand, sizeof(int));
  std::cout << op_code << " " << operand << " " <<std::hex << OP << "\n";  
}

