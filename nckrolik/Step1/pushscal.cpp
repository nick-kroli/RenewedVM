#include <iostream>
#include "pushscal.h"


PushScal::PushScal(std::string _var,int _loc){
  op_code = "PushScalar ";
  OP = 0x00000020;
  var = _var;
  loc = _loc;
}

void PushScal::printOps(std::ofstream& file){
  file << op_code << loc << "\n";
}

void PushScal::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  file.write((char*)&loc, sizeof(int));
  // std::cout << op_code << loc << " " << std::hex << OP << "\n";  
}