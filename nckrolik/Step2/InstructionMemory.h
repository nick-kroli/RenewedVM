#include <vector>
#include <memory>
#include "Stmt.h"


class InstructionMemory{
public:
  InstructionMemory(std::string fName, std::string binName);
  std::vector<std::shared_ptr<Stmt>> getInstructionMemory();
  std::vector<std::shared_ptr<Stmt>> getStringBuffer();
  std::vector<std::string> getStrings();
  void printIMem();
  
private:
  std::vector<std::shared_ptr<Stmt>> i_buffer;
  std::vector<std::shared_ptr<Stmt>> s_buff;
  std::vector<std::string> str_buff;
};