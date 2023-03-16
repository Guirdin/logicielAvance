#include "../lib/json.hpp"
#include <iostream>
#include <fstream>
#include <string>

using std::string;
using nlohmann::json;

class database
{
    private:
        /* data */
        string path;
        json data;

    public:
        database(string idUser){
            path = "../data/"+idUser+".json";

            std::ifstream readFile(path);
            if(!readFile.good()){
                std::cout << "Create json file :" << std::endl;

                std::ofstream createFile(path);
                createFile << json::object();
                createFile.close();

            }
            readFile.close();
        };
        ~database(){};
         
        void create(string name){
            std::ifstream readFile(path);
            readFile >> data;
            readFile.close();
            
            if (!data.contains(name)) // vérifie si la bdd n'existe pas
            {
                json nameBdd = {name: {}};
                data.emplace(name, nameBdd);
                std::ofstream writeFile(path);
                writeFile << data.dump(4);
                writeFile.close();
                std::cout << "File created successfully: "<< name << std::endl;
            }
            
            std::cout << "After creation: " << data.dump(4) << std::endl;
        }

        void read(string name){
            std::ifstream readFile(path);
            readFile >> data;
            readFile.close();

            // Get the value of "name"
            std::cout << "database - " << name << ": " << data[name] << std::endl;
        }

        // void modify(string name){
            // patch
        //     std::cout << "Modification: " << name << endl;
        //     std::cout << "After modification: " << data.dump() << std::endl;
        // }

        void remove(string name){
            // ouvrir le fichier en mode lecture
            std::ifstream readFile(path);
            readFile >> data;
            readFile.close();

            std::cout << "Delete database: "<< name << std::endl;
            data.erase(name);

            std::cout << "After deleting: " << data.dump(4) << std::endl;

            // ouvrir le fichier en mode ecriture
            std::ofstream writeFile(path);

            // ecrire le contenu mis a jour dans le fichier
            writeFile << data.dump(4);
            writeFile.close();
        }

        
};
    
