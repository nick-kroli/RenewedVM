#include "InstructionMemory.h"
#include <iostream>
#include <fstream>
#include "Op_jumpnzero.h"
#include "Op_jumpzero.h"
#include "Op_jump.h"
#include "Op_gosub.h"
#include "Op_return.h"
#include "Op_pushscalar.h"
#include "Op_pusharray.h"
#include "Op_pushi.h"
#include "Op_pop.h"
#include "Op_mul.h"
#include "Op_div.h"
#include "Op_prints.h"
#include "Op_printtos.h"
#include "Op_pop_scalar.h"
#include "Op_pop_array.h"
#include "Op_dup.h"
#include "Op_swap.h"
#include "Op_enter_sub.h"
#include "Op_start_prog.h"
#include "Op_exit.h"
#include "Op_negate.h"
#include "Op_add.h"
#include "Words.h"

InstructionMemory::InstructionMemory(std::string fName, std::string binName){
  // std::cout << "gets here";
  static const int OP_JUMP = 0x00000010;
  static const int OP_JUMPZERO = 0x00000011;
  static const int OP_JUMPNZERO = 0x00000012;
  static const int OP_GOSUB = 0x00000013;
  static const int OP_RETURN = 0x00000014;
  static const int OP_ENTER_SUBROUTINE = 0x00000015;
  static const int OP_EXIT_SUBROUTINE = 0x00000016;
  static const int OP_START_PROGRAM = 0x00000017;
  static const int OP_EXIT_PROGRAM = 0x00000018;
  static const int OP_PUSHSCALAR = 0x00000020;
  static const int OP_PUSHARRAY = 0x00000021;
  static const int OP_PUSHI = 0x00000022;
  static const int OP_POPSCALAR = 0x00000030;
  static const int OP_POPARRAY = 0x00000031;
  static const int OP_POP = 0x00000032;
  static const int OP_DUP = 0x00000040;
  static const int OP_SWAP = 0x00000041;
  static const int OP_ADD = 0x00000050;
  static const int OP_NEGATE = 0x00000051;
  static const int OP_MUL = 0x00000052;
  static const int OP_DIV = 0x00000053;
  static const int OP_PRINTS = 0x00000060;
  static const int OP_PRINTTOS = 0x00000061;

  std::ifstream file;
  std::ifstream binFile;
  char byte;
  file.open(fName);
  binFile.open(binName, std::ios::binary);
  

  std::string line;
  std::vector<std::string> vec_of_strings;

  //dump string buffer
  int num_strings = 0;
  // int temp1;
  // int temp2;
  // int temp3;
  
  binFile.read((char*)&num_strings, sizeof(int));
  // std::cout << num_strings << std::endl;
  if(num_strings != 0){
    for(int k = 0; k < num_strings; k++){
      int str_len;
      binFile.read((char*) &str_len, sizeof(int));
      char char_str[str_len];
      binFile.read(char_str, str_len);
      std::string s(char_str, str_len);
      str_buff.push_back(s);
    }
  }
  // binFile.read((char*)&temp1, sizeof(int));
  // binFile.read((char*)&temp2, sizeof(int));
  // binFile.read((char*)&temp3, sizeof(int));
  // std::cout << temp1 << " " << temp2 << " " << temp3 << std::endl;


  int num_lines = 0;

  // while(getline(file,line)){
  //   vec_of_strings.push_back(line);
  //   num_lines++;
  // }
  
  while(!binFile.eof()){
    int op_code;
    binFile.read((char*)&op_code, sizeof(int));
    // std::cout << op_code << std::endl;
  
    if(op_code == OP_JUMPNZERO){
      int opnd;
      binFile.read((char*)&opnd, sizeof(int));
      std::shared_ptr<Stmt> my_ptr(new Op_jumpnzero(opnd));
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_JUMPZERO){
      int opnd;
      binFile.read((char*)&opnd, sizeof(int));
      std::shared_ptr<Stmt> my_ptr(new Op_jumpzero(opnd));
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_JUMP){
      int opnd;
      binFile.read((char*)&opnd, sizeof(int));
      std::shared_ptr<Stmt> my_ptr(new Op_jump(opnd));
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_ENTER_SUBROUTINE){
      int opnd;
      binFile.read((char*)&opnd, sizeof(int));
      std::shared_ptr<Stmt> my_ptr(new Op_enter_sub(opnd));
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_GOSUB){
      int opnd;
      binFile.read((char*)&opnd, sizeof(int));
      std::shared_ptr<Stmt> my_ptr(new Op_gosub(opnd));
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_RETURN){
      std::shared_ptr<Stmt> my_ptr(new Op_return());
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_PUSHSCALAR){
      int opnd;
      binFile.read((char*)&opnd, sizeof(int));
      std::shared_ptr<Stmt> my_ptr(new Op_pushscalar(opnd));
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_PUSHARRAY){
      int opnd;
      binFile.read((char*)&opnd, sizeof(int));
      std::shared_ptr<Stmt> my_ptr(new Op_pusharray(opnd));
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_PUSHI){
      int opnd;
      binFile.read((char*)&opnd, sizeof(int));
      std::shared_ptr<Stmt> my_ptr(new Op_pushi(opnd));
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_POPSCALAR){
      int opnd;
      binFile.read((char*)&opnd, sizeof(int));
      std::shared_ptr<Stmt> my_ptr(new Op_pop_scalar(opnd));
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_POPARRAY){
      int opnd;
      binFile.read((char*)&opnd, sizeof(int));
      std::shared_ptr<Stmt> my_ptr(new Op_pop_array(opnd));
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_POP){
      std::shared_ptr<Stmt> my_ptr(new Op_pop());
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_DUP){
      std::shared_ptr<Stmt> my_ptr(new Op_dup());
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_SWAP){
      std::shared_ptr<Stmt> my_ptr(new Op_swap());
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_ADD){
      std::shared_ptr<Stmt> my_ptr(new Op_add());
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_NEGATE){
      std::shared_ptr<Stmt> my_ptr(new Op_negate());
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_MUL){
      std::shared_ptr<Stmt> my_ptr(new Op_mul());
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_DIV){
      std::shared_ptr<Stmt> my_ptr(new Op_div());
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_PRINTS){
      int opnd;
      binFile.read((char*)&opnd, sizeof(int));
      std::shared_ptr<Stmt> my_ptr(new Op_prints(opnd));
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_PRINTTOS){
      std::shared_ptr<Stmt> my_ptr(new Op_printtos( ));
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_START_PROGRAM){
      int opnd;
      binFile.read((char*)&opnd, sizeof(int));
      std::shared_ptr<Stmt> my_ptr(new Op_start_prog(opnd));
      i_buffer.push_back(my_ptr);
    }
    else if(op_code == OP_EXIT_PROGRAM){
      std::shared_ptr<Stmt> my_ptr(new Op_exit());
      i_buffer.push_back(my_ptr);
      break;
    }
    // std::cout << "HITS HERE3" << std::endl;
  }





  // for(int i = 0; i < num_lines; i++){
  //   std::string inst = vec_of_strings[i];
  //   if(inst.substr(0,9) == "JumpNZero"){
  //     int opnd = stoi(inst.substr(10));
  //     std::shared_ptr<Stmt> my_ptr(new Op_jumpnzero(opnd));
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,8) == "JumpZero"){
  //     int opnd = stoi(inst.substr(9));
  //     std::shared_ptr<Stmt> my_ptr(new Op_jumpzero(opnd));
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,4) == "Jump") {
  //     int opnd = stoi(inst.substr(5));
  //     std::shared_ptr<Stmt> my_ptr(new Op_jump(opnd));
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,10) == "GoSubLabel") {
  //     int opnd = stoi(inst.substr(11));
  //     std::shared_ptr<Stmt> my_ptr(new Op_enter_sub(opnd));
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,5) == "GoSub"){
  
  //     int opnd = stoi(inst.substr(6));
  //     std::shared_ptr<Stmt> my_ptr(new Op_gosub(opnd));
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,6) == "Return"){
  //     std::shared_ptr<Stmt> my_ptr(new Op_return());
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,10) == "PushScalar"){
  //     int opnd = stoi(inst.substr(11));
  //     std::shared_ptr<Stmt> my_ptr(new Op_pushscalar(opnd));
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,9) == "PushArray"){
  //     int opnd = stoi(inst.substr(10));
  //     std::shared_ptr<Stmt> my_ptr(new Op_pusharray(opnd));
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,5) == "PushI"){
  //     int opnd = stoi(inst.substr(6));
  //     std::shared_ptr<Stmt> my_ptr(new Op_pushi(opnd));
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,9) == "PopScalar"){
  //     int opnd = stoi(inst.substr(10));
  //     std::shared_ptr<Stmt> my_ptr(new Op_pop_scalar(opnd));
  //     i_buffer.push_back(my_ptr);
  //   }

  //    else if(inst.substr(0,8) == "PopArray"){
  //     int opnd = stoi(inst.substr(9));
  //     std::shared_ptr<Stmt> my_ptr(new Op_pop_array(opnd));
  //     i_buffer.push_back(my_ptr);
  //    }

  //   else if(inst.substr(0,3) == "Pop"){
  
  //     std::shared_ptr<Stmt> my_ptr(new Op_pop());
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,3) == "Dup"){
  //     std::shared_ptr<Stmt> my_ptr(new Op_dup());
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,4) == "Swap"){
  //     std::shared_ptr<Stmt> my_ptr(new Op_swap());
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,3) == "Add"){
  //     std::shared_ptr<Stmt> my_ptr(new Op_add());
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,6) == "Negate"){
  //     std::shared_ptr<Stmt> my_ptr(new Op_negate());
  //     i_buffer.push_back(my_ptr);
  //   }
    
  //   else if(inst.substr(0,3) == "Mul"){
  //     std::shared_ptr<Stmt> my_ptr(new Op_mul());
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,3) == "Div") {
  //     std::shared_ptr<Stmt> my_ptr(new Op_div());
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,6) == "Prints"){
  //     int opnd = stoi(inst.substr(7));
  //     std::shared_ptr<Stmt> my_ptr(new Op_prints(opnd));
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,8) == "PrintTOS"){
  //     std::shared_ptr<Stmt> my_ptr(new Op_printtos( ));
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,5) == "Start") {
  //     int opnd = stoi(inst.substr(6));
  //     std::shared_ptr<Stmt> my_ptr(new Op_start_prog(opnd));
  //     i_buffer.push_back(my_ptr);
  //   }

  //   else if(inst.substr(0,4) == "Exit") {
  //     std::shared_ptr<Stmt> my_ptr(new Op_exit());
  //     i_buffer.push_back(my_ptr);
  //   }
  //   else{
  //     std::shared_ptr<Stmt> my_ptr(new Words(inst));
  //     s_buff.push_back(my_ptr);
  //   }
  // }
}

std::vector<std::shared_ptr<Stmt>> InstructionMemory::getInstructionMemory(){
  return i_buffer;
}

std::vector<std::shared_ptr<Stmt>> InstructionMemory::getStringBuffer(){
  return s_buff;
}

std::vector<std::string> InstructionMemory::getStrings(){
  return str_buff;
}
void InstructionMemory::printIMem(){
  for(int i = 0; i < i_buffer.size(); i++){
    std::shared_ptr<Stmt> cur_op = i_buffer[i];
    std::cout << cur_op->name_buffer << std::endl;
  }
}
