#include <iostream>
#include "label.h"

Label::Label(){
  op_code = "label";
}

void Label::printOps(std::ofstream& file){
  file << op_code << "\n";
}

void Label::printBin(std::ofstream& file){
  // std::cout << op_code << " " << std::hex << OP << "\n";  
}


