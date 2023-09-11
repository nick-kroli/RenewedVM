#include <iostream>
#include "pop.h"

Pop::Pop(){
  op_code = "Pop";
  OP = 0x00000032;
}

void Pop::printOps(std::ofstream& file){
  file << op_code << std::endl;
}

void Pop::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  // std::cout << op_code << " " << std::hex << OP << "\n";  
}