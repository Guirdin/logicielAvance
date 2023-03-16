#include "json-develop/include/nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <string>

using std::string;

using json = nlohmann::json;

// std::ifstream f("example.json");
// json data = json::parse(f);

class database
{
    private:
        /* data */
        string idUser;
        json data;

    public:
        database(string idUser){
            std::ifstream file("../data/"+idUser+".json");
            file >> data;
            file.close();
        };
        ~database(){};
         
        void create(string name){
            if (!data[name]) // vérifie si la bdd n'existe pas
            {
                json nameBdd = {name: {}};
                data.emplace(name, nameBdd);
    //             std::ofstream output("data.json");
    // output << std::setw(4) << data << std::endl;
                std::cout << "File created successfully: "<< name << endl;
            }
            

            std::cout << "After creation: " << data.dump() << std::endl;

        }

        void read(string name){
            // Get the value of "name"
            std::string database = data[name];
            std::cout << "database: " << database << std::endl;
        }

        // void modify(string name){
        //     std::cout << "Modification: " << name << endl;
        //     std::cout << "After modification: " << data.dump() << std::endl;
        // }

        void remove(string name){
            data.erase(name);
            std::cout << "Delete database: "<< name << endl;
            std::cout << "After deleting: " << data.dump() << std::endl;
        }

        
};
    
