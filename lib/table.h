#include "../lib/json.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "database.h"

using std::string;
using nlohmann::json;

class table:database
{
    private:
        json tables;
        std::ifstream f;
        std::ofstream o;
    public:
        table(){
            f.open("tables.json");
            if (f.good()) {
                tables = json::parse(f);
            }
            else {
                std::cout << "Error: tables.json does not exist." << std::endl;
            }
        };
        ~table(){
            o.open("tables.json");
            o << std::setw(4) << tables;
            o.close();
        };

        void create(string name, string columns){
            if (!tables[name]) {
                json table = json::array();
                table.push_back(columns);
                tables.emplace(name, table);
                std::cout << "Table created successfully: " << name << std::endl;
            }
            else {
                std::cout << "Table " << name << " already exists." << std::endl;
            }
        }

        void read(string name){
                if (tables[name]) {
                    std::cout << "Columns in table " << name << ":" << std::endl;
                    std::cout << tables[name][0] << std::endl;
                    std::cout << "Data in table " << name << ":" << std::endl;
                    for (size_t i = 1; i < tables[name].size(); i++) {
                        std::cout << tables[name][i] << std::endl;
                    }
                }
                else {
                    std::cout << "Table " << name << " does not exist." << std::endl;
                }
        }

        // void modify(string name, string columns){
        //     if (tables[name]) {
        //         tables[name][0] = columns;
        //         std::cout << "Table " << name << " modified successfully." << std::endl;
        //     }
        //     else {
        //         std::cout << "Table " << name << " does not exist." << std::endl;
        //     }
        // }

        void remove(string name){
            if (tables[name]) {
                tables.erase(name);
                std::cout << "Table " << name << " deleted successfully." << std::endl;
            }
            else {
                std::cout << "Table " << name << " does not exist." << std::endl;
            }
        }
};