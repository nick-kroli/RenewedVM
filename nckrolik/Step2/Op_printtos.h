#include "Stmt.h"
#include "RunTime.h"
#include <fstream>


class Op_printtos : public Stmt{
public:
    Op_printtos( );
    void operation(RunTime *rt, std::ofstream& file);
};