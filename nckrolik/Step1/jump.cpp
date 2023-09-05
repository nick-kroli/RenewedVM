#include <iostream>
#include "jump.h"
#include <fstream>
Jump::Jump(std::string _label){
  op_code = "Jump, ";
  OP = 0x00000010;
  label_name = _label;
}

void Jump::printOps(std::ofstream& file){
  file << "Jump " << label_numloc << "\n";
}

void Jump::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  file.write((char*)&label_numloc, sizeof(int));
  std::cout << "Jump " << label_numloc << " " <<std::hex << OP << "\n";   
}

void Jump::setLabelName(std::string _label){
  label_name = _label;
}

void Jump::setLabelNum(int num){
  label_numloc = num;
}

std::string Jump::getLabelName(){
  return label_name;
}