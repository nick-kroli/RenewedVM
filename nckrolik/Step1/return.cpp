#include <iostream>
#include "return.h"


Return::Return(){
  op_code = "Return";
  OP = 0x00000014;
}

void Return::printOps(std::ofstream& file){
  file << op_code << "\n";
}

void Return::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  // std::cout << op_code << " " << OP << "\n";  
}