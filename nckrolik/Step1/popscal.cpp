#include <iostream>
#include "popscal.h"

PopScal::PopScal(std::string _var,int _loc){
  op_code = "PopScalar ";
  OP = 0x00000030;
  var = _var;
  loc = _loc;
}

void PopScal::printOps(std::ofstream& file){
  file << op_code << loc << "\n";
}

void PopScal::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  file.write((char*)&loc, sizeof(int));
  std::cout << op_code << loc << " " <<std::hex << OP << "\n";  
}