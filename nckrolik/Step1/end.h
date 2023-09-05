#ifndef END_H_
#include <iostream>
#include <fstream>
#include "stmt.h"

class End : public Stmt{
public:
  End();
  void printOps(std::ofstream& file);
  void printBin(std::ofstream& file);
};
#endif 