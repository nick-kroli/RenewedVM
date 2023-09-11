#include <iostream>
#include "prints.h"

Prints::Prints(std::string print_this, int print_count){
  op_code = "Prints";
  OP = 0x00000060;
  to_be_printed = print_this;
  print_num = print_count;
}



void Prints::printOps(std::ofstream& file){
  file << op_code << " " << print_num << "\n";
}

void Prints::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  file.write((char*)&print_num, sizeof(int));
  // std::cout << op_code << " "<< print_num << " "<< std::hex << OP << "\n";  
}