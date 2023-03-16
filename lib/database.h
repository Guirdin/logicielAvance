#include "../lib/json.hpp"
#include <iostream>
#include <fstream>
#include <string>

using std::string;
using nlohmann::json;

// std::ifstream f("example.json");
// json data = json::parse(f);

class database
{
    private:
        /* data */
        string idUser;
        json data;

    public:
        database(string id){
            idUser = id;

            std::ifstream file("../data/"+idUser+".json");
            if(!file.good()){
                json myJsonObject;
                std::cout << "Create json file :" << std::endl;

                std::ofstream createFile("../data/"+idUser+".json");
                createFile << myJsonObject;
            }
        };
        ~database(){};
         
        void create(string name){
            std::ifstream readFile("../data/"+idUser+".json");
            readFile >> data;
            if (!data.contains(name)) // vérifie si la bdd n'existe pas
            {
                json nameBdd = {name: {}};
                data.emplace(name, nameBdd);
                std::ofstream file("../data/"+idUser+".json");
                file << data;
                std::cout << "File created successfully: "<< name << std::endl;
            }
            

            std::cout << "After creation: " << data.dump() << std::endl;

        }

        void read(string name){
            // Get the value of "name"
            std::string database = data[name];
            std::cout << "database: " << database << std::endl;
        }

        // void modify(string name){
            // patch
        //     std::cout << "Modification: " << name << endl;
        //     std::cout << "After modification: " << data.dump() << std::endl;
        // }

        void remove(string name){
            data.erase(name);
            std::cout << "Delete database: "<< name << std::endl;
            std::cout << "After deleting: " << data.dump() << std::endl;
        }

        
};
    
