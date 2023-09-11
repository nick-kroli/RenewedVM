#include <iostream>
#include "jumpnzero.h"

JumpNZero::JumpNZero(std::string _label){
  op_code = "JumpNZero, ";
  OP = 0x00000012;
  label_name = _label;
}

void JumpNZero::printOps(std::ofstream& file){
  file << "JumpNZero " << label_numloc << "\n";
}

void JumpNZero::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  file.write((char*)&label_numloc, sizeof(int));
  // std::cout << "JumpNZero " << label_numloc << " " << std::hex << OP << "\n";  
}

void JumpNZero::setLabelName(std::string _label){
  label_name = _label;
}

void JumpNZero::setLabelNum(int num){
  label_numloc = num;
}

std::string JumpNZero::getLabelName(){
  return label_name;
}