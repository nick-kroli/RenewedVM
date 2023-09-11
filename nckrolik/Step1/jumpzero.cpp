#include <iostream>
#include "jumpzero.h"

JumpZero::JumpZero(std::string _label){
  op_code = "JumpZero, ";
  OP = 0x00000011;
  label_name = _label;
}

void JumpZero::printOps(std::ofstream& file){
  file << "JumpZero " << label_numloc << "\n";
}

void JumpZero::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  file.write((char*)&label_numloc, sizeof(int));
  // std::cout << "JumpZero " << label_numloc << " " << std::hex << OP << "\n";  
}

void JumpZero::setLabelName(std::string _label){
  label_name = _label;
}

void JumpZero::setLabelNum(int num){
  label_numloc = num;
}

std::string JumpZero::getLabelName(){
  return label_name;
}