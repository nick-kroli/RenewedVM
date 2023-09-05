#include <iostream>
#include "pusharr.h"

PushArr::PushArr(std::string _var,int _loc){
  op_code = "PushArr ";
  OP = 0x00000021;
  var = _var;
  loc = _loc;
}

void PushArr::printOps(std::ofstream& file){
  file << "PushArray " << loc << "\n";
}

void PushArr::printBin(std::ofstream& file){
  file.write((char*)&OP, sizeof(int));
  file.write((char*)&loc, sizeof(int));
  std::cout << op_code << loc <<  " " << std::hex << OP << "\n";  
}