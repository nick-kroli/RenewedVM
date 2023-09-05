#include "StringBuffer.h"


StringBuffer::StringBuffer(){

}

void StringBuffer::serialize(std::ofstream& file){
  int length = buffer.size();
  file.write((char*)(&length), sizeof(int));
  for(int i = 0; i < length; i++){
    int str_len = buffer[i].size();
    file.write((char*)(&str_len), sizeof(int));
    file.write(buffer[i].c_str(), sizeof(char)*str_len);
  }

  
}


std::vector<std::string> StringBuffer::getBuffer(){
  return buffer;
}

void StringBuffer::printBuffer(){
  for(int i = 0; i < buffer.size(); i++){
    std::cout << buffer[i] << std::endl;
  }
  // std::cout << buffer.back();
}

void StringBuffer::insertString(std::string str){
  buffer.push_back(str);
}

