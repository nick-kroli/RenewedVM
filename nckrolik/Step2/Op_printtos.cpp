#include "Op_printtos.h"
#include <iostream>

Op_printtos::Op_printtos( ) {
    name_buffer = "printtos";
}

void Op_printtos::operation(RunTime* rt, std::ofstream& file) { 
  // std::cout << "start" << std::endl;
  // rt->printEl();
  // std::cout << "end" << std::endl;
  int val =  rt->getLast();
  //std::cout << val << std::endl;
  file << std::to_string(val) << "\n";
  rt->eraseBack( );
}


