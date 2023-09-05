#include <iostream>
#include "gosublabel.h"

GoSubLabel::GoSubLabel(std::string _label){
  op_code = "GoSubLabel ";
  OP = 0x00000015;
  label_name = _label;
}

void GoSubLabel::printOps(std::ofstream& file){
  file << op_code << label_numloc << "\n";
}

void GoSubLabel::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  file.write((char*)&label_numloc, sizeof(int));
  std::cout << op_code << label_numloc <<  " " << std::hex << OP << "\n";  
}

void GoSubLabel::setLabelNum(int num){
  label_numloc = num;
}

std::string GoSubLabel::getLabelName(){
  return label_name;
}