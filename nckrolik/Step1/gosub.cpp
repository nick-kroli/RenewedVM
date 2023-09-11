#include <iostream>
#include "gosub.h"

GoSub::GoSub(std::string _label){
  op_code = "GoSub ";
  OP = 0x00000013;
  label_name = _label;
}

void GoSub::printOps(std::ofstream& file){
  file << op_code << label_numloc << "\n";
}

void GoSub::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  file.write((char*)&label_numloc, sizeof(int));
  // std::cout << op_code << label_numloc <<  " " << std::hex << OP << "\n";  
}

void GoSub::setLabelNum(int num){
  label_numloc = num;
}

std::string GoSub::getLabelName(){
  return label_name;
}