#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../lib/json.hpp"
#include "../lib/column.hpp"
#include "../lib/options.h"

int main(int argc, char *argv[]){
    
    string name;
    string pass;
    string nameBDD;
    string nameTable;
    string nameColumn;

    Options o;

    o.command(argc,argv);
    return 0;
}
