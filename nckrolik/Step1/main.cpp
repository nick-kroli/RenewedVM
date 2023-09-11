#include <iostream>
#include "parse.h"
#include "stmt.h"
#include <string>
#include <vector>
#include "Instruction.h"


int main(int argc, char** argv){
  std::string fName = argv[1];
  Parse parser(fName);
}