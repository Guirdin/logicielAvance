#include "../lib/json.hpp"
#include <iostream>
#include <fstream>
#include <string>

using std::string;
using nlohmann::json;

class table
{
    private:
        string path;
        string nameBase;
        json data;
    
    public:
        table(string idUser, string nameBDD){
            path = "../data/"+idUser+".json";
            nameBase = nameBDD;
        };
        ~table(){};

        void create(string name){
            std::ifstream readFile(path);
            readFile >> data; 
            readFile.close();

            if (!data[nameBase].contains(name)) { // vérifie si la table n'existe pas
                std::cout << "data[nameBase].contains(name): " << data[nameBase].contains(name) << std::endl;

                json table = json::array();
                data[nameBase].emplace(name, table);
                std::ofstream writeFile(path);
                writeFile << data.dump(4);
                writeFile.close();
                std::cout << "Table created successfully: " << name << std::endl;
            }
            else {
                std::cout << "Table " << name << " already exists." << std::endl;
            }
        }

        void read(string name){
            std::ifstream readFile(path);
            readFile >> data;
            readFile.close();

            // Get the value of "name"
            std::cout << "Table - " << name << ": " << data[nameBase][name] << std::endl;
        }

        void remove(string name){
            // ouvrir le fichier en mode lecture
            std::ifstream readFile(path);
            readFile >> data;
            readFile.close();

            std::cout << "Delete table: "<< name << std::endl;
            data[nameBase].erase(name);

            std::cout << "After deleting: " << data[nameBase].dump(4) << std::endl;

            // ouvrir le fichier en mode ecriture
            std::ofstream writeFile(path);

            // ecrire le contenu mis a jour dans le fichier
            writeFile << data.dump(4);
            writeFile.close();
        }
};