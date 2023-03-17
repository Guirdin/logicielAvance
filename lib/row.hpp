#include "../lib/json.hpp"
#include <iostream>
#include <fstream>
#include <string>

using std::string;
using nlohmann::json;

class row
{
    private:
        string path;
        string _nameBDD;
        string _nameTable;
        json data;
    
    public:
        row(string idUser, string nameBDD, string nameTable){
            path = "../data/"+idUser+".json";
            _nameBDD = nameBDD;
            _nameTable = nameTable;
        };
        ~row(){};

        void create(string name){
            std::ifstream readFile(path);
            readFile >> data; 
            readFile.close();
            
	        std::cout << "data[_nameBDD]: " << data[_nameBDD] << std::endl;
	        std::cout << "(data[_nameBDD])[_nameTable]: " << data[_nameBDD][_nameTable] << std::endl;
            if (!data[_nameBDD][_nameTable].contains(name)) { // vérifie si la row n'existe pas

                json row = json::object();
                data[_nameBDD][_nameTable].emplace(name, row);
                std::ofstream writeFile(path);
                writeFile << data.dump(4);
                writeFile.close();
                std::cout << "row created successfully: " << name << std::endl;
            }
            else {
                std::cout << "row " << name << " already exists." << std::endl;
            }
        }

        void read(string name){
            std::ifstream readFile(path);
            readFile >> data;
            readFile.close();

            // Get the value of "name"
            std::cout << "row - " << name << ": " << data[_nameBDD][_nameTable][name] << std::endl;
        }

        void remove(string name){
            // ouvrir le fichier en mode lecture
            std::ifstream readFile(path);
            readFile >> data;
            readFile.close();

            std::cout << "Delete row: "<< name << std::endl;
            data[_nameBDD][_nameTable].erase(name);

            std::cout << "After deleting: " << data[_nameBDD][_nameTable].dump(4) << std::endl;

            // ouvrir le fichier en mode ecriture
            std::ofstream writeFile(path);

            // ecrire le contenu mis a jour dans le fichier
            writeFile << data.dump(4);
            writeFile.close();
        }
};