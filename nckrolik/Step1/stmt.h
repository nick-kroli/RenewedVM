#ifndef STMT_H_
#define STMT_H_
#include <iostream>
#include <string>
#include <fstream>


class Stmt{
public:
  virtual void printOps(std::ofstream& file)=0;
  virtual void printBin(std::ofstream& file)=0;
  std::string op_code;
  int OP;
  virtual std::string getLabelName();
  virtual void setLabelNum(int num);
  virtual void setNumDecl(int _num);
  int num;
  
};

#endif //STMT_H_