#include "Stmt.h"
#include <fstream>

class Op_prints : public Stmt{
public:
  Op_prints(int opnd);
  void operations(std::vector<std::shared_ptr<Stmt>> s_buff, std::ofstream& file); 
  int getOper();
private: 
  int oper;
};