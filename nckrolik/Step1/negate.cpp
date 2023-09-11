#include <iostream>
#include "negate.h"

Negate::Negate(){
  op_code = "Negate";
  OP = 0x00000051;
}

void Negate::printOps(std::ofstream& file){
  file << op_code << "\n";
}

void Negate::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  // std::cout << op_code << " " << std::hex << OP << "\n";  
}