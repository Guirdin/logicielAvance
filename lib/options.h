#include <iostream>
#include <string.h>
#include <vector>
#include "database.hpp"
#include "table.hpp"

struct User {
    std::string id;
    std::string name;
    std::string password;
};

class Options{
    private:
        std::string id_user;
        std::vector<std::string> short_flag;
        
        std::string long_flag[7] = {"--login", "--username", "--password", "--format", "--version", "--sql", "--help"};

        std::string userId;
        std::string userName;
        std::string userPassword; 

        std::string selectedDB;
         

        void (Options::*options_function[7])(std::string str) = {&Options::case_login, &Options::case_username, &Options::case_password, &Options::case_format, &Options::case_version, &Options::case_sql, &Options::case_help};

    public:
        void case_help(std::string str){
            std::cout << "Usage : sequel [-u|--username] <username> [-p|--password] <password> <options>" << std::endl << std::endl
                      << "Options :" << std::endl 
                      << "[-h|--help] : Display help" << std::endl
                      << "[-v|--version] : Display version" << std::endl
                      << "[-l|--login] : Check if credentials are valid" << std::endl
                      << "[-f|--format] <sql|csv|visual> : Choose format of return'"<< std::endl
                      << "[-s|--sql] <query> : Send a query to the DB" << std::endl << std::endl;
        };
        void case_format(std::string str){};
        void case_version(std::string str){
            std::cout << "Sequel version v0.0.1 " << std::endl;
        };
        void case_login(std::string str){
            std::cout << "ok " << std::endl;
        };
        void case_username(std::string str){
            userName = str;
        };
        void case_password(std::string str){
            userPassword = str;
        };
        void case_sql(std::string str){
            std::string delimiter = " ";
            size_t pos = 0;
            std::string token;
    
            std::vector<std::string> query;

            while ((pos = str.find(delimiter)) != std::string::npos) {
                token = str.substr(0, pos);
                query.push_back(token);
                str.erase(0, pos + delimiter.length());
            }
            query.push_back(str);

            connexionBDD(this->userName,this->userPassword);

            if(userId.length()!=0){
                if(query.at(0)=="create"){
                    if(query.at(1)=="database"){
                        database db(userId);
                        if (query.at(2)!=""){
                            db.create(query.at(2));
                        }    
                    }
                }
                if(query.at(0)=="delete"){
                    if(query.at(1)=="database"){
                        database db(userId);
                        if (query.at(2)!=""){
                            db.remove(query.at(2));
                    }
                }
            }
        }
        }

        
        bool connexionBDD(string name, string pass){
            std::vector<User> users;

            std::ifstream readfile("../data/identifiants.txt");
            if (readfile.is_open()) {
                std::string line;
                while (std::getline(readfile, line)) {
                    std::istringstream iss(line);
                    User user;
                    if (std::getline(iss, user.id, ',') &&
                        std::getline(iss, user.name, ',') &&
                        std::getline(iss, user.password, ',')) {
                        users.push_back(user);
                    }
                }
            } else {
                std::cerr << "Error: Could not open file." << std::endl;
                return false;
            }
            for (const auto& user : users) {
                if(user.name==name && user.password==pass){
                    userId = user.id;
                    userName = user.name;
                    userPassword = user.password;
                    std::cout << "Login success" << std::endl;
                    return true;
                }
            }
            std::cout << "Login failed" << std::endl;
            return false;
        }

        void command(int argc, char* argv[]){
            
            short_flag.insert(short_flag.end(), {"-l", "-u", "-p", "-f", "-v", "-s","-h"});
            if(argc>5){
                for(size_t i = 0; i < argc; i++){
                    for(size_t short_increment=0; short_increment < short_flag.size(); short_increment++){
                        if(argv[i]==short_flag[short_increment]||argv[i]==long_flag[short_increment]){
                            if(i == argc-1){
                                (this->*(options_function[short_increment]))(argv[i]);
                            }
                            (this->*(options_function[short_increment]))(argv[i+1]);

                        }
                    }
                }
            }
            else{
                this->connexionBDD(argv[2],argv[4]);
                if(userId.length()!=0){
                    std::string prompt;
                    std::string str;
                    do{
                        std::cout << "Inserez votre commande : ";
                        std::cin >> prompt;
                        std::cout << std::endl;
                        if(prompt=="help"){
                            help();
                        }
                        if(prompt=="version"){
                            version();
                        }
                        if(prompt=="show"){
                            list();
                        }
                        if(prompt=="create"){
                            create();
                        }
                        if(prompt=="use"){
                            use();
                        }
                        if(prompt=="delete"){
                            _delete();
                        }
                        if(prompt=="select"){
                            select();
                        }

                    
                    }
                    while(prompt!="exit");
                }
                
            }
        };

        void help(){
            std::cout << "Liste des commandes : " << std::endl
                      << std::endl
                      <<"help : Affiche la liste des commandes" << std::endl
                      <<"version : Affiche la version" << std::endl
                      <<"show : Affiche la liste des database/tables" << std::endl
                      <<"use : Choisir une database" << std::endl
                      <<"create : Creer une database/table" << std::endl
                      <<"delete : Supprimer une database/table" << std::endl
                      <<"select : Afficher les données d\'une table" << std::endl
                      <<"exit : Quitter le programme" << std::endl << std::endl;
        }

        void version(){
            std::cout << "Sequel version v0.0.1" << std::endl << std::endl;
        }

        void list(){
            std::string prompt;
            do{
                std::cout << "Database ou Tables ? : ";
                std::cin >> prompt;
                std::cout << std::endl << std::endl;
                if(prompt=="database"){
                    list_db();
                    break;
                }
                if(prompt=="tables"){
                    list_tables();
                    break;
                }
            }
            while(prompt!="database"||prompt!="tables");
        }

        void list_db(){
            std::cout << "db list TODO" << std::endl << std::endl;
        }

        void list_tables(){
            std::cout << "table list TODO" << std::endl << std::endl;
        }

        void use_db(std::string db){
            this->selectedDB = db;
            std::cout << "Database choisie : " << this->selectedDB << std::endl << std::endl;
        }

        void create(){
            std::string prompt;
            do{
                std::cout << "Database ou Table ? : ";
                std::cin >> prompt;
                std::cout << std::endl << std::endl;
                if(prompt=="database"){
                    create_db();
                    break;
                }
                if(prompt=="table"){
                    create_table();
                    break;
                }
            }
            while(prompt!="database"||prompt!="table");
        }

        void create_db(){
            std::string prompt;
            std::cout << "Quel est le nom de la database ? : ";
            std::cin >> prompt; 
            database db(this->userId);
            db.create(prompt);
            std::cout << std::endl << "database crée "<< std::endl;
        }

        void create_table(){
            if(this->selectedDB.length()!=0){
                std::string prompt;
                std::cout << "Quel est le nom de la table ? : ";
                std::cin >> prompt; 
                table table(this->userId, this->selectedDB);
                table.create(prompt);
                std::cout << std::endl << "table crée "<< std::endl;
            }
            else{
                std::cout << "Pas de database selectionnée " << std::endl << std::endl;
            }
            
        }

        void use(){
            std::string prompt;
            std::cout << "Quel est le nom de la database a utiliser ? : ";
            std::cin >> prompt;
            this->selectedDB = prompt; // check si table existe
        }

        void _delete(){
             std::string prompt;
            do{
                std::cout << "Database ou Table ? : ";
                std::cin >> prompt;
                std::cout << std::endl << std::endl;
                if(prompt=="database"){
                    delete_db();
                    break;
                }
                if(prompt=="table"){
                    delete_table();
                    break;
                }
            }
            while(prompt!="database"||prompt!="table");

        }

        void delete_db(){
            std::string prompt;
            std::cout << "Quel est le nom de la database ? : ";
            std::cin >> prompt; 
            database db(this->userId);
            db.remove(prompt);
            std::cout << std::endl << "Database suprimée "<< std::endl;
        }

        void delete_table(){
            if(this->selectedDB.length()!=0){
                std::string prompt;
                std::cout << "Quel est le nom de la table ? : ";
                std::cin >> prompt; 
                table table(this->userId, this->selectedDB);
                table.remove(prompt);
                std::cout << std::endl << "Table suprimée "<< std::endl;
            }
            else{
                std::cout << "Pas de database selectionnée " << std::endl << std::endl;
            }
            
        }

        void select(){
            if(this->selectedDB.length()!=0){
                std::string prompt;
                std::cout << "Quel est le nom de la table ? : ";
                std::cin >> prompt; 
                table table(this->userId, this->selectedDB);
                table.read(prompt);
            }
            else{
                std::cout << "Pas de database selectionnée " << std::endl << std::endl;
            }
        }
};
