#include <iostream>
#include "exit.h"

Exit::Exit(){
  op_code = "Exit";
  OP = 0x00000018;
}

void Exit::printOps(std::ofstream& file){
  file << op_code;
}

void Exit::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  // std::cout << op_code << " " << std::hex << OP << "\n";  
}