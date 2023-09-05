#include <iostream>
#include "swap.h"

Swap::Swap(){
  op_code = "Swap";
  OP = 0x00000041;
}

void Swap::printOps(std::ofstream& file){
  file << op_code << "\n";
}

void Swap::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  std::cout << op_code << " " << std::hex << OP << "\n";  
}

