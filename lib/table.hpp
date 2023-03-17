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
            // if(nameBase && idUser){
                path = "../data/"+idUser+".json";
                nameBase = nameBDD;
            // }
            // else{
            //     std::cerr << "Database or user id does not exists." << std::endl;
            //     std::cerr << "Table couldn't be created" << std::endl;
            // }
        };
        ~table(){};

        void create(string name, std::vector<std::string> columns){
            
            std::ifstream readFile(path);
            readFile >> data; 
            readFile.close();

            
            

            if (!data[nameBase].contains(name)) { // vérifie si la table n'existe pas

                json table = json::object();
                json column = json::array();
                data[nameBase].emplace(name, table);
                for (int i = 0; i < columns.size(); i++)
                {
                    data[nameBase][name].emplace(columns[i], column);
                }
                
                std::ofstream writeFile(path);
                writeFile << data.dump(4);
                writeFile.close();
                std::cout << "Table created successfully: " << name << std::endl;
            }
            else
                std::cout << "Table " << name << " already exists." << std::endl;
            
            
        }

        void read(string name){
            std::ifstream readFile(path);
            readFile >> data;
            readFile.close();

            // std::vector<std::string> tables;
            // for (auto& el : data[nameBase][name].items()) {
            //     tables.push_back(el.key());
            // }
            
            // // Get the value of "name"

            // // Affichage des données sous forme de tableau trié par table
            // std::cout << "Tableau de la base de donnes" << nameBase << ": " << std::endl;
            // for (int i = 0; i < tables.size(); i++)
            // {
            //     std::cout << "+------------";
            // }
            // std::cout << "+" << std::endl;
            // std::cout << "| Table " << name << " ";
            // for (int i = 0; i < tables.size(); i++)
            // {
            //     if(i == 0)
            //         std::cout << "  ";
            //     else
            //         std::cout << "            ";

            // }
            // std::cout << std::endl;
            // for (int i = 0; i < tables.size(); i++)
            // {
            //     std::cout << "+------------";
            // }
            // std::cout << "+" << std::endl;

            // for (int i = 0; i < tables.size(); i++)
            // {
            //     std::cout << "| " << tables[i] << "       ";
            // }
            // std::cout << std::endl;

            // for (int i = 0; i < tables.size(); i++)
            // {
            //     std::cout << "+------------";
            // }
            // std::cout << "+" << std::endl;

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