#include <iostream>
#include "add.h"

Add::Add(){
  op_code = "Add";
  OP = 0x00000050;
}

void Add::printOps(std::ofstream& file){
  file << op_code << "\n";
}

void Add::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  // std::cout << op_code << " " << std::hex << OP << "\n";  
}

