#ifndef EXIT_H_
#include <iostream>
#include <fstream>
#include "stmt.h"

class Exit : public Stmt{
public:
  Exit();
  void printOps(std::ofstream& file);
  void printBin(std::ofstream& file);
};
#endif 