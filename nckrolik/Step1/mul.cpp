#include <iostream>
#include "mul.h"

Mul::Mul(){
  op_code = "Mul";
  OP = 0x00000052;
}

void Mul::printOps(std::ofstream& file){
  file << op_code << "\n";
}

void Mul::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  // std::cout << op_code << " " << std::hex << OP << "\n";  
}