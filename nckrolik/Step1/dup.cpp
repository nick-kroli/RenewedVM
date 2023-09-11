#include <iostream>
#include "dup.h"

Dup::Dup(){
  op_code = "Dup";
  OP = 0x00000040;
}

void Dup::printOps(std::ofstream& file){
  file << op_code << "\n";
}

void Dup::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  // std::cout << op_code << " " << std::hex << OP << "\n";  
}