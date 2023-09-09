#include <iostream>
#include <fstream>
#include <vector>


class StringBuffer{
public:
  StringBuffer();
  void serialize(std::ofstream& file);
  void printBuffer();
  void insertString(std::string str)
  std::vector<std::string> getBuffer();
private:
  std::vector<std::string> buffer;
};


