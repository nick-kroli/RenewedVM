#include <iostream>
#include "end.h"

End::End(){
  op_code = "";
}

void End::printOps(std::ofstream& file){
  file << op_code << "\n";
}

void End::printBin(std::ofstream& file){
  // std::cout << op_code << " " << std::hex << OP << "\n";  
}