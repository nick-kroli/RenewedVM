#include <iostream>
#include "div.h"

Div::Div(){
  op_code = "Div";
  OP = 0x00000053;
}

void Div::printOps(std::ofstream& file){
  file << op_code << "\n";
}

void Div::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  // std::cout << op_code << " " << std::hex << OP << "\n";  
}