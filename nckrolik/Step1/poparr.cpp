#include <iostream>
#include "poparr.h"

PopArr::PopArr(std::string _var,int _loc){
  op_code = "PopArray ";
  OP = 0x00000031;
  var = _var;
  loc = _loc;
}

void PopArr::printOps(std::ofstream& file){
  file << op_code << loc << "\n";
}

void PopArr::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  file.write((char*)&loc, sizeof(int));
  std::cout << op_code << loc << " " << std::hex << OP << "\n";  
}