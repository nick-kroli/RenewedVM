#include <iostream>
#include "start.h"

Start::Start(){
  op_code = "Start";
  OP = 0x00000017;
}

void Start::printOps(std::ofstream& file){
  file << op_code << " " << num_decl << std::endl;
}

void Start::printBin(std::ofstream& file){
  file.write((char*) &OP, sizeof(int));
  file.write((char*) &num_decl, sizeof(int));
  // std::cout << op_code << " " << num_decl << " " << std::hex << OP << "\n";  
}

void Start::setNumDecl(int _num_decl){
  num_decl = _num_decl;
}
