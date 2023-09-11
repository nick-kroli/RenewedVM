#include <iostream>
#include "printtos.h"



PrintTos::PrintTos(){
  op_code = "PrintTOS";
  OP = 0x00000061;
}

void PrintTos::printOps(std::ofstream& file){
  file << op_code << "\n";
}

void PrintTos::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  // std::cout << op_code << " " << std::hex << OP << "\n";   
}