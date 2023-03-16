#include "json-develop/include/nlohmann/json.hpp"
#include <iostream>
#include <string>
#include "database.h"

using std::string;
using json = nlohmann::json;

std::ifstream f("example.json");
json data = json::parse(f);

class table:database
{
    private:
        /* data */
    public:
        table(){};
        ~table();

        void create(string name, string colones){
            std::cout << "Creation table:" << name << endl;
            std::cout << "After creation: " << data.dump() << std::endl;
        }

        void read(string name){
        }

        void modify(string name, ){
            std::cout << "Modification table:" << name << endl;
            std::cout << "After modification: " << data.dump() << std::endl;
        }

        void remove(string name){
            data.erase(name);
            std::cout << "Delete table:" << name << endl;
            std::cout << "After deleting: " << data.dump() << std::endl;
        }
};